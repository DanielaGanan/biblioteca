#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <QWidget>
#include "QDebug"

namespace Ui {
class Empleado;
}

class Empleado : public QWidget
{
    Q_OBJECT

public:
    explicit Empleado(QWidget *parent = nullptr);
    ~Empleado();

private slots:

private:
    Ui::Empleado *ui;
};

#endif // EMPLEADO_H
