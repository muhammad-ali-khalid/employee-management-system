#include <QApplication>
#include "loginwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.setWindowTitle("Login");
    w.showFullScreen();
    return a.exec();
}
