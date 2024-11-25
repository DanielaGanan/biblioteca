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
                    const QString& libro = " ",
                    const QString& socio = " ",
                    const QString& usuario = " ",
                    const QDate& fechaPrestamo = QDate::currentDate(),
                    const QDate& fechaDevolucion = QDate::currentDate());

    ~clasePrestamo();

    // Getters
    QVector<QStringList> getClasePrestamo() const;

    int getIdPrestamo() const;
    int getCantidad() const;
    QDate getFechaPrestamo() const;
    QDate getFechaDevolucion() const;
    QString getlibro() const;
    QString getsocio() const;
    QString getUsuario() const;


    // Setters
    void setIdPrestamo(int nuevoidPrestamo);
    void setCantidad(int nuevaCantidad);
    void setFechaPrestamo(const QDate& nuevaFechaPrestamo);
    void setFechaDevolucion(const QDate& nuevaFechaDevolucion);
    void setlibro(QString nuevolibro);
    void setsocio(QString nuevoSocio);
    void setUsuario(QString nuevoUsuario);


private:
    int idPrestamo;
    int cantidad;
    QDate fechaPrestamo;
    QDate fechaDevolucion;
    QString usuario;
    QString socio;
    QString libro;
    QVector<QStringList> Prestamos;


};

#endif // CLASEPRESTAMO_H
