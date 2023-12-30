#ifndef VENTANAEXPORTAR_H
#define VENTANAEXPORTAR_H

#include <QWidget>
#include <string>
namespace Ui {
class ventanaExportar;
}

class ventanaExportar : public QWidget
{
    Q_OBJECT

public:
    explicit ventanaExportar(QWidget *parent = nullptr);
    ~ventanaExportar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_expo_clicked();

private:
    Ui::ventanaExportar *ui;
};

#endif // VENTANAEXPORTAR_H
