#include "prestamo.h"
#include "ui_prestamo.h"

Prestamo::Prestamo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Prestamo)
{
    ui->setupUi(this);

    this->setWindowTitle("Formulario Prestamo");

}


Prestamo::Prestamo(int idPrestamo, QVector<libro*> libros, int cantidad, QDate fechaPrestamo, QDate fechaDevolucion, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Prestamo)
{
    ui->setupUi(this);

}


Prestamo::~Prestamo()
{
    delete ui;
}

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







