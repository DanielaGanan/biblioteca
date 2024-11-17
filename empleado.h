#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <QWidget>
#include "QDebug"
#include "vector"
#include "agregarempleado.h"
//#include "persona.h"

namespace Ui {
class Empleado;
}

class Empleado : public QWidget
{
    Q_OBJECT

public:
    explicit Empleado(QWidget *parent = nullptr);
    ~Empleado();

    /*Empleado( QString nombre, QString apellido, QString dni, QString direccion,
             QString telefono, int idEmpleado, QString usuario, QString contrasenia,
             QWidget *parent = nullptr);*/

  /*  Empleado(int idEmpleado, QString usuario, QString contrasenia,
             QWidget *parent = nullptr);*/

    Empleado(int idEmpleado, QWidget *parent = nullptr);


    int getIdEmpleado();
  //  QString getUsuario();
//    QString getContrasenia();
    void setIdEmpleado(int idEmpleado);
 //   void setUsuario(QString usuario);
 //   void setContrasenia(QString contrasenia);
    void mostrarEmpleados();
    // Empleado* buscarEmpleado(int dni, int idEmpleado);
    Empleado* buscarEmpleado(int idEmpleado);

private slots:
    bool agregarEmpleadoNuevo();
    bool eliminarEmpleado();
    bool modificarEmpleado();

private:
    Ui::Empleado *ui;
    int idEmpleado;
    agregarEmpleado agregar;
    QVector <Empleado*> vecEmpleados;
//  QString usuario;
  //  QString contrasenia;
};

#endif // EMPLEADO_H
