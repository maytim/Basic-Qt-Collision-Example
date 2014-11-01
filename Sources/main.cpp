#include "breakout.h"
#include <QDesktopWidget>
#include <QApplication>

//Function to center a QWidget relative to the users display and give the QWidget a fixed size
void setup(QWidget& widget){
    int WIDTH = 300;
    int HEIGHT = 400;

    //Create a QDesktopWidget object to get inforamtion about the userss desktop
    QDesktopWidget* desktop = QApplication::desktop();

    //Reposition the QWidget in the middle of the user's desktop
    widget.setGeometry((desktop->width() - WIDTH)/2, (desktop->height() - HEIGHT)/2, WIDTH, HEIGHT);
    widget.setFixedSize(WIDTH, HEIGHT);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Breakout window;

    window.setWindowTitle("Breakout");
    window.show();
    setup(window);

    return a.exec();
}
