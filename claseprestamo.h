#ifndef CLASEPRESTAMO_H
#define CLASEPRESTAMO_H

#include "socio.h"
#include "usuario.h"
#include "libro.h"
#include "QDate"

class clasePrestamo
{
public:
  /*  clasePrestamo(int idPrestamo, int cantidad, const QDate& fechaPrestamo,
                  const QDate& fechaDevolucion, libro* libro, Socio* socio, Usuario* usuario);*/
    clasePrestamo(int idPrestamo, int cantidad, const QDate& fechaPrestamo,
                  const QDate& fechaDevolucion, Usuario* usuario);

    ~clasePrestamo();

    // Getters
    int getIdPrestamo();
    int getCantidad();
    QDate getFechaPrestamo();
    QDate getFechaDevolucion();
    //libro* getlibro();
    //Socio* getsocio();
    Usuario* getUsuario();


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
