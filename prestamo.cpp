#include "prestamo.h"
#include "ui_prestamo.h"

Prestamo::Prestamo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Prestamo)
{
    ui->setupUi(this);

    this->setWindowTitle("Formulario Prestamo");
/*
    connect(this, ui->botonAgregarPrestamo, &QPushButton::clicked, this, &Prestamo::solicitarLibro);
    connect(this, ui->botonModificarPrestamo, &QPushButton::clicked, this, &Prestamo::modificarPrestamo);
    connect(this, ui->botonEliminarPrestamo, &QPushButton::clicked, this, &Prestamo::devolverLibro);
*/
}

/*Prestamo::Prestamo(int idPrestamo, Libro libro,
        Socio socio, int cantidad, Empleado empleado,
        QDate fechaPrestamo, QDate fechaDevolucion)
    : QWidget(parent)
    , ui(new Ui::Prestamo)
{
    ui->setupUi(this);
    this->idPrestamo = idPrestamo;
    this->libro = libro;
    this->socio = socio;
    this->cantidad = cantidad;
    this->empleado = empleado;
    this->fechaPrestamo = fechaPrestamo;
    this->fechaDevolucion = fechaDevolucion;
} */

Prestamo::Prestamo(int idPrestamo, QVector<libro*> libros, int cantidad,
        QVector<Empleado*> empleados, QDate fechaPrestamo, QDate fechaDevolucion, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Prestamo)
{
    ui->setupUi(this);
    this->idPrestamo = idPrestamo;
    this->libros = libros;
    this->cantidad = cantidad;
    this->empleados = empleados;
    this->fechaPrestamo = fechaPrestamo;
    this->fechaDevolucion = fechaDevolucion;
}


Prestamo::~Prestamo()
{
    delete ui;
}


// Metodos getters
int Prestamo::getIdPrestamo()
{
    return idPrestamo;
}

QVector<libro*> Prestamo::getLibros()
{
    return libros;
}

/*Socio Prestamo::getSocio()
{
    return Socio;
}*/

int Prestamo::getCantidad()
{
    return cantidad;
}

QVector<Empleado*> Prestamo::getEmpleados()
{
    return empleados;
}

QDate Prestamo::getFechaPrestamo()
{
    return fechaPrestamo;
}

QDate Prestamo::getFechaDevolucion()
{
    return fechaDevolucion;
}

// Metodos setters
void Prestamo::setIdPrestamo(int idPrestamo)
{
    this->idPrestamo = idPrestamo;
}

void Prestamo::setLibro(QVector<libro*> libros)
{
    this->libros = libros;
}

/*void Prestamo::setSocio(Socio socio)
{
    this->socio = socio;
}*/

void Prestamo::setCantidad(int cantidad)
{
    this->cantidad = cantidad;
}

void Prestamo::setEmpleado(QVector <Empleado*> empleados)
{
    this->empleados = empleados;
}

void Prestamo::setFechaPrestamo(QDate fechaPrestamo)
{
    this->fechaPrestamo = fechaPrestamo;
}

void Prestamo::setFechaDevolucion(QDate fechaDevolucion)
{
    this->fechaDevolucion = fechaDevolucion;
}

/*
void Prestamo::mostrarPrestamo()
{
    // limpia la tabla
    ui->tablaPrestamo->setRowCount(0);

    // Recorre el vector y muestra cada prestamo en una nueva fila en la tabla
    for (const Prestamo* prestamo : prestamos) {

        // almacenamos la cantidad de filas
        int row = ui->tablaPrestamo->rowCount();

        ui->tablaEmpleado->insertRow(row);

        // Agrega en la fila los datos que corresponden en la columna
        ui->tablaPrestamo->setItem(row, 0, new QTableWidgetItem(QString::number(prestamo->idPrestamo));
    //    ui->tablaPrestamo->setItem(row, 1, new QTableWidgetItem(prestamo->libro.getNombre);
        ui->tablaPrestamo->setItem(row, 2, new QTableWidgetItem(QString::number(prestamo->cantidad));
        ui->tablaPrestamo->setItem(row, 3, new QTableWidgetItem(prestamo->empleados.getEmpleado);
        ui->tablaPrestamo->setItem(row, 4, new QTableWidgetItem(prestamo->getFechaPrestamo());
        ui->tablaPrestamo->setItem(row, 5, new QTableWidgetItem(prestamo->getFechaDevolucion());
    }
}*/


// Para buscar los prestamos a un socio
/*QVector Prestamo::buscarPrestamoSocio(Socio socio)
{
    return QVector;
}*/

//Agregar o solicitar un prestamo
bool Prestamo::solicitarLibro()
{    
    return false;
}

//Devuelve un libro
bool Prestamo::devolverLibro()
{
    return false;
}

// Para modificar un prestamo
bool Prestamo::modificarPrestamo()
{
    return false;
}







