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

    int getIdEmpleado();
    QString getUsuario();
    QString getContrasenia();
    void setIdEmpleado(int idEmpleado);
    void setUsuario(QString usuario);
    void setContrasenia(QString contrasenia);

private slots:
    bool agregarEmpleado();
    bool eliminarEmpleado();
    bool modificarEmpleado();

private:
    Ui::Empleado *ui;
    int idEmpleado;
    QString usuario;
    QString contrasenia;
};

#endif // EMPLEADO_H
