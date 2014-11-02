/*
    The Breakout class holds all of the game logic. It is derived from the QWidget class to allow it to display in a Qt window.
    It handles all input events, game updates, and painting events. It also handles the current game state.
*/
#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "ball.h"
#include "brick.h"
#include "paddle.h"
#include <QWidget>
#include <QKeyEvent>

class Breakout : public QWidget
{
    Q_OBJECT

public:
    //Constructor and Destructor
    Breakout(QWidget *parent = 0);
    ~Breakout();
protected:
    //Events
    void paintEvent(QPaintEvent* event);
    void timerEvent(QTimerEvent* event);
    void keyPressEvent(QKeyEvent* event);

    //Functions dependent on the current game state
    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    
    //Function to check for collision of GameObjects
    void checkCollision();
private:
    //Variable to keep track of QTimerId 
    int timerId;
    
    //The GameObjects
    Ball* ball;
    Paddle* paddle;
    std::vector<Brick*> bricks;
    
    //The game states
    bool gameOver, gameWon, gameStarted, paused;
};

#endif // BREAKOUT_H
