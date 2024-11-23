#ifndef CLASEPRESTAMO_H
#define CLASEPRESTAMO_H

#include "socio.h"
#include "usuario.h"
#include "libro.h"
#include "QDate"

class clasePrestamo
{
public:

clasePrestamo(const int& idPrestamo = 0, const int& cantidad = 0,
                  const QDate& fechaPrestamo = QDate::currentDate(),
                  const QDate& fechaDevolucion = QDate::currentDate(),
                  Usuario* usuario = nullptr);

    ~clasePrestamo();

    // Getters
    int getIdPrestamo() const;
    int getCantidad() const;
    QDate getFechaPrestamo() const;
    QDate getFechaDevolucion() const;
    //libro* getlibro() const;
    //Socio* getsocio();
    Usuario* getUsuario() const;


    // Setters
    void setIdPrestamo(int nuevoidPrestamo);
    void setCantidad(int nuevaCantidad);
    void setFechaPrestamo(const QDate& nuevaFechaPrestamo);
    void setFechaDevolucion(const QDate& nuevaFechaDevolucion);
    //void setlibro(libro* nuevolibro);
    //void setsocio(Socio* nuevoSocio);
    void setUsuario(Usuario* nuevoUsuario);


private:
    int idPrestamo;
    int cantidad;
    QDate fechaPrestamo;
    QDate fechaDevolucion;
    //libro* libro;
    //Socio* socio;
    Usuario* usuario;


};

#endif // CLASEPRESTAMO_H
