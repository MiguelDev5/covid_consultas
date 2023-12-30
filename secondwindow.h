#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPushButton>
#include <QLabel>
#include "mainwindow.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_actionSalir_triggered();

    void on_actionAcerca_de_triggered();

    void on_export_2_triggered();

private:
    Ui::SecondWindow *ui;

    QTabWidget *tabWidget;
    QVBoxLayout *menuLayout;

    QLabel *content1;
    QLabel *content2;
    QLabel *content3;
};

#endif // SECONDWINDOW_H
