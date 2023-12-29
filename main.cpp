#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.setWindowTitle("Login");
    mainWindow.setFixedSize(600, 350);
    mainWindow.show();
    return a.exec();
}
