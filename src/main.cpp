/*
    Buali Sina university of Hamedan
    Advanced Programming Course
    exercise 5 : graphical ToDo
    Group Contributes:
        Mohammad Moradi
        Amir Ghazi Khani
        Erfan Ghaem Panah
*/

#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
