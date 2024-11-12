#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <QWidget>
#include "QDebug"
#include "libro.h"
#include "socio.h"
#include "empleado.h"
#include <QDate>

namespace Ui {
class Prestamo;
}

class Prestamo : public QWidget
{
    Q_OBJECT

public:
    explicit Prestamo(QWidget *parent = nullptr);
    ~Prestamo();

    int getIdPrestamo();
    Libro getLibro();
    Socio getSocio();
    int getCantidad();
    Empleado getEmpleado();
    QDate getFechaPrestamo();
    QDate getFechaDevolucion();
    void setIdPrestamo(int idPrestamo);
    void setLibro(Libro libro);
    void setSocio(Socio socio);
    void setCantidad(int cantidad);
    void setEmpleado(Empleado empledo);
    void setFechaPrestamo(QDate fechaPrestamo);
    void setFechaDevolucion(QDate fechaDevolucion);

private slots:
  //  void fecha(QDate fecha); // Busca los libros en cierta fecha?
  //  void fechaDevolucion(Qdate fecha); // ?
    vector buscarPrestamoSocio(Socio socio); // Para buscar los prestamos a un socio
 //   void cantidad(int cantidad);
    bool solicitarLibro();  //Agregar o solicitar un prestamo
    bool devolverLibro();   //Devuelve un libro o libros
    bool modificarPrestamo(); // Para modificar un prestamo

private:
    Ui::Prestamo *ui;
    int idPrestamo;
    Libro libro;
    Socio socio;
    int cantidad;
    Empleado empleado;
    QDate fechaPrestamo;
    QDate fechaDevolucion;

};

#endif // PRESTAMO_H
