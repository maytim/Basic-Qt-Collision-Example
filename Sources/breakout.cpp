#include "breakout.h"
#include <QPainter>
#include <QApplication>

//Breakout constructor
Breakout::Breakout(QWidget *parent) : QWidget(parent)
{
    //Set up points
    points = 0;
    
    //Set up the game states
    gameOver = false;
    gameWon = false;
    paused = false;
    gameStarted = false;
    
    //Create the GameObjects
    ball = new Ball();
    paddle = new Paddle();
    
    for(int i=0; i<CONSTANTS::BRICK_ROWS; i++){
        for(int j=0; j<CONSTANTS::BRICK_COLS; j++){
            bricks.push_back(new Brick(j*CONSTANTS::BRICK_WIDTH_INTERVAL+CONSTANTS::BRICK_MARGIN,
                                       i*CONSTANTS::BRICK_HEIGHT_INTERVAL+CONSTANTS::BRICK_MARGIN));
        }
    }
}

//Destructor
Breakout::~Breakout()
{
    delete ball;
    delete paddle;
    for(auto& b : bricks){
        delete b;
    }
}

//Overloaded paintEvent
void Breakout::paintEvent(QPaintEvent* event){
    QPainter painter(this);

    //Display the appropriate text if in the game over or game won states
    if(gameOver)
        writeToPainter(&painter,"Game Over");
    else if(gameWon)
        writeToPainter(&painter,"Victory");
    //Otherwise draw the GameObjects
    else{
        painter.drawImage(*ball->getRect(), *ball->getImage());
        painter.drawImage(*paddle->getRect(), *paddle->getImage());

        for(const auto& b : bricks){
            if(!b->isDestroyed())
                painter.drawImage(*b->getRect(), *b->getImage());
        }
    }
}

//For every timerEvent move the ball, then check for collisions, and finally repaint
void Breakout::timerEvent(QTimerEvent* event){
    ball->autoMove();
    checkCollision();
    repaint();
}

//Function to handle key events
void Breakout::keyPressEvent(QKeyEvent* event){
    switch(event->key()){
        //For left key input move the Paddle left. You move it multiple times to make it smoother
        case Qt::Key_Left:
            {
                int x = paddle->getRect()->x();
                for(int i=1; i<=5; i++){
                    paddle->moveLeft(x--);
                }
                break;
            }
        //For right key input move the Paddle right. You move it multiple times to make it smoother
        case Qt::Key_Right:
            {
                int x = paddle->getRect()->x();
                for(int i=1; i<=5; i++){
                    paddle->moveRight(x++);
                }
                break;
            }
        //The 'p' key will pause the game
        case Qt::Key_P:
            {
                pauseGame();
                break;
            }
        //The space key starts the game 
        case Qt::Key_Space:
            {
                startGame();
                break;
            }
        //The escape key closes the application
        case Qt::Key_Escape:
            {
                qApp->exit();
                break;
            }
        default:
            QWidget::keyPressEvent(event);
    }
}

//Function to start the game
void Breakout::startGame(){
    if(!gameStarted){
        //Reset the GameObjects
       ball->resetState();
       paddle->resetState();

       for(auto& b : bricks){
           b->setDestroyed(false);
       }
       
       //Update the game states
       gameOver = false;
       gameWon = false;
       gameStarted = true;
       
       //Start the game timer
       timerId = startTimer(10);
    }
}

//Function to pause the current game
void Breakout::pauseGame(){
    //Restart the game if already paused
    if(paused){
        timerId = startTimer(10);
        paused = false;
    }
    //Pause the game by killing the current QTimer
    else{
        paused = true;
        killTimer(timerId);
    }
}

//Function to end the game
void Breakout::stopGame(){
    //End the current QTimer and update the game states
    killTimer(timerId);
    gameOver = true;
    gameStarted = false;
    points = 0;
}

//Function to handle winning the game
void Breakout::victory(){
    //End the QTimer and update the game states
    killTimer(timerId);
    gameWon = true;
    gameStarted = false;
    points = 0;
}

//Function to handle collisions between GameObjects
void Breakout::checkCollision(){
    //If the Ball moves to the bottom of the screen then end the game
    if(ball->getRect()->bottom() > CONSTANTS::SCREEN_HEIGHT)
        stopGame();

    //If all of the Bricks are destroyed then end the game
    if(points == CONSTANTS::BRICK_ROWS*CONSTANTS::BRICK_COLS)
        victory();

    //First collision check: Ball and Paddle
    //Check if the Ball's rect is intersecting the Paddle's rect
    if((ball->getRect())->intersects(*paddle->getRect())){
        int paddleLPos = paddle->getRect()->left();
        int paddleW = paddle->getRect()->width();
        int ballLPos = ball->getRect()->left();

        //Setup the regions of the paddle to compare with the collision location
        //They divided the paddle into equal regions from left to right
        int first = paddleLPos + paddleW/5;
        int second = paddleLPos + (2*paddleW)/5;
        int third = paddleLPos + (3*paddleW)/5;
        int fourth = paddleLPos + (4*paddleW)/5;
        int fifth = paddleLPos + paddleW;

        //If the collision occured in the first or second region (farthest 2 regions on the left)
        //Update the ball to move NW
        if(ballLPos < first || (ballLPos >= first && ballLPos < second)){
            ball->setXDir(-1);
            ball->setYDir(-1);
        }
        //If the collision occured in the third region (middle)
        //Update the ball to move N
        if(ballLPos >= second && ballLPos < third){
            ball->setXDir(0);
            ball->setYDir(-1);
        }
        //If the collision occured in the fourth or fifth region (farthest 2 regions on the right)
        //Update the ball to move NE
        if(ballLPos >= third && ballLPos < fourth || (ballLPos >= fourth && ballLPos < fifth)){
            ball->setXDir(1);
            ball->setYDir(-1);
        }
    }

    //Second collision check: Ball and Brick
    //Iterate through all of the Bricks and check if they currently intersect with the Ball
    for(auto& b : bricks){
        if((ball->getRect())->intersects(*b->getRect())){
            int ballLeft = ball->getRect()->left();
            int ballHeight = ball->getRect()->height();
            int ballWidth = ball->getRect()->width();
            int ballTop = ball->getRect()->top();

            //Create points to check agains that correspond to the Balls bounds
            QPoint pointRightT(ballLeft + ballWidth + 1, ballTop);
            QPoint pointLeftT(ballLeft - 1, ballTop);
            QPoint pointLeftB(ballLeft - 1, ballTop + ballHeight + 1);
            QPoint pointRightB(ballLeft + ballWidth + 1, ballTop + ballHeight + 1);
            QPoint pointTopM(ballLeft + ballWidth/2, ballTop - 1);
            QPoint pointBottomM(ballLeft + ballWidth/2, ballTop + ballHeight + 1);

            //If the current Brick hasn't been destroyed then check if it's intersecting one of the points
            //and update the x and y dir accordingly
            if(!b->isDestroyed()){
                if(b->getRect()->contains(pointTopM))
                {ball->setXDir(0); ball->setYDir(1);}
                else if(b->getRect()->contains(pointBottomM))
                {ball->setXDir(0); ball->setYDir(-1);}
                else if(b->getRect()->contains(pointRightT))
                {ball->setXDir(-1); ball->setYDir(1);}
                else if(b->getRect()->contains(pointLeftT))
                {ball->setXDir(1); ball->setYDir(1);}
                else if(b->getRect()->contains(pointLeftB))
                {ball->setXDir(1); ball->setYDir(-1);}
                else if(b->getRect()->contains(pointRightB))
                {ball->setXDir(-1); ball->setYDir(-1);}
                //Finally set that Brick to be destroyed
                b->setDestroyed(true);
                points++;
                break;
            }
        }
    }
}

//Helper function for the text events when the game ends
void Breakout::writeToPainter(QPainter* p, QString s){
    //Basic text setup
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(s);

    p->setFont(font);

    //Draw the text in the middle of the screen
    p->translate(QPoint(CONSTANTS::SCREEN_WIDTH/2,CONSTANTS::SCREEN_HEIGHT/2));
    p->drawText(-textWidth/2, 0, s);
}
