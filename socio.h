#ifndef SOCIO_H
#define SOCIO_H

#include "persona.h"

class Socio : public Persona
{
public:
    Socio(const QString& nombre, const QString& apellido, const QString& libroPrestado);
    ~Socio();
    QString obtenerLibroPrestado() const;
    void establecerLibroPrestado(QString libro);

private:
    // QList<Libro> librosPrestados = [];
    QString libroPrestado;
};


#endif // SOCIO_H
