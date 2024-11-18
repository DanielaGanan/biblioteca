#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <QWidget>
#include "QDebug"
#include "libro.h"
#include "socio.h"
#include "empleado.h"
#include <QDate>
#include<vector>


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

    Prestamo(int idPrestamo, QVector<libro*> libros, int cantidad,
             QVector<Empleado*> empleados, QDate fechaPrestamo, QDate fechaDevolucion, QWidget *parent);

    ~Prestamo();

    // Metodos getters
    int getIdPrestamo();
    QVector<libro*> getLibros();
  //  Socio getSocio();
    int getCantidad();
    QVector <Empleado*> getEmpleados();
    QDate getFechaPrestamo();
    QDate getFechaDevolucion();

    // Metodos setters
    void setIdPrestamo(int idPrestamo);
    void setLibro(QVector<libro*> libros);
  //  void setSocio(Socio socio);
    void setCantidad(int cantidad);
    void setEmpleado(QVector <Empleado*> empledo);
    void setFechaPrestamo(QDate fechaPrestamo);
    void setFechaDevolucion(QDate fechaDevolucion);

  //  QVector buscarPrestamoSocio(Socio socio); // Para buscar los prestamos a un socio
    bool solicitarLibro();  //Agregar o solicitar un prestamo
    bool devolverLibro();   //Devuelve un libro o libros
    bool modificarPrestamo(); // Para modificar un prestamo
private slots:


private:
    Ui::Prestamo *ui;
    int idPrestamo;
    QVector <libro*> libros;
   //QVector <Socio*> Socios;
    int cantidad;
    QVector <Empleado*> empleados;
    QDate fechaPrestamo;
    QDate fechaDevolucion;

};

#endif // PRESTAMO_H
