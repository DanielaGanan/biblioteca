#include "empleado.h"
#include "ui_empleado.h"

Empleado::Empleado(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Empleado)
{
    ui->setupUi(this);

    this->setWindowTitle("Formulario Empleado");

    connect(ui->botonAgregarEmpleado, &QPushButton::clicked, this, &Empleado::agregarEmpleado);
}

/*Empleado::Empleado(QString nombre, QString apellido,
    QString dni, QString direccion, QString telefono,
    int idEmpleado, QString usuario, QString contrasenia,
    QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::Empleado)*/


/*Empleado::Empleado(int idEmpleado, QString usuario, QString contrasenia,
    QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::Empleado)*/

    Empleado::Empleado(int idEmpleado, QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::Empleado)


{
    ui->setupUi(this);

  //  this->Nombre = nombre;
  //  this->Apellido = apellido;
  //  this->DNI = dni;
  //  this->Direccion = direccion;
  //  this->Telefono = telefono;
    this->idEmpleado = idEmpleado;
  //  this->usuario = usuario;
  //  this->contrasenia = contrasenia;
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

/*
QString Empleado::getUsuario()
{
    return usuario;
}

QString Empleado::getContrasenia()
{
    return contrasenia;
}*/

// Metodos setters
void Empleado::setIdEmpleado(int idEmpleado)
{
    this->idEmpleado = idEmpleado;
}

/*
void Empleado::setUsuario(QString usuario)
{
    this->usuario = usuario;
}

void Empleado::setContrasenia(QString contrasenia)
{
    this->contrasenia = contrasenia;
}
*/
// Metodo para agregar empleados
bool Empleado::agregarEmpleado()
{
    return false;
}

// Metodo para eliminar empleados
bool Empleado::eliminarEmpleado()
{
    return false;
}

// Metodo para modificar empleados
bool Empleado::modificarEmpleado()
{
    return false;
}
