#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QWidget>
#include <iostream>

#include "ui_searchform.h"
#include "msearchcontroller.h"
#include "extractdata.h"

using namespace std;

namespace Ui {
class SearchForm;
}

class SearchForm : public QWidget
{
    Q_OBJECT

public:
    explicit SearchForm(QWidget *parent = nullptr);
    ~SearchForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SearchForm *ui;
};

#endif // SEARCHFORM_H
