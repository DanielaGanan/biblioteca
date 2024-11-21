#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <QWidget>
#include "QDebug"
#include "libro.h"
#include "socio.h"
#include <QDate>
#include<vector>
#include "agregarprestamo.h"


namespace Ui {
class Prestamo;
}

class Prestamo : public QWidget
{
    Q_OBJECT

public:
    explicit Prestamo(QWidget *parent = nullptr);
   /* Prestamo(int idPrestamo, Libro libro, Socio socio, int cantidad,
             Empleado empleado, QDate fechaPrestamo, QDate fechaDevolucion);
    */

    Prestamo(int idPrestamo, QVector<libro*> libros, int cantidad, QDate fechaPrestamo, QDate fechaDevolucion, QWidget *parent);

    ~Prestamo();



private slots:
    bool solicitarLibro();  //Agregar o solicitar un prestamo
    bool devolverLibro();   //Devuelve un libro o libros
    bool modificarPrestamo(); // Para modificar un prestamo


private:
    Ui::Prestamo *ui;

};

#endif // PRESTAMO_H
