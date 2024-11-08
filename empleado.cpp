#include "empleado.h"
#include "ui_empleado.h"

Empleado::Empleado(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Empleado)
{
    ui->setupUi(this);
}

Empleado::~Empleado()
{
    delete ui;
}

// Metodos getters
int Empleado::getIdEmpleado()
{
    return idEmpleado;
}

QString Empleado::getUsuario()
{
    return usuario;
}

QString Empleado::getContrasenia()
{
    return contrasenia;
}

// Metodos setters
void Empleado::setIdEmpleado(int idEmpleado)
{
    this->idEmpleado = idEmpleado;
}

void Empleado::setUsuario(QString usuario)
{
    this->usuario = usuario;
}

void Empleado::setContrasenia(QString contrasenia)
{
    this->contrasenia = contrasenia;
}

// Metodo para agregar empleados
bool Empleado::agregarEmpleado()
{

}

// Metodo para eliminar empleados
bool Empleado::eliminarEmpleado()
{

}

// Metodo para modificar empleados
bool Empleado::modificarEmpleado()
{

}



