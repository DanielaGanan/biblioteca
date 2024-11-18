#ifndef SOCIO_H
#define SOCIO_H

#include "persona.h"

class Socio : public Persona
{
public:
    Socio(const QString& nombre,
          const QString& apellido,
          const int& dni,
          const QString& direccion,
          const QString& telefono,
          const QString& estado
          );
    ~Socio();

    //Getters
    QString getEstadoSocio() const;

    //Setters
    void setEstadoSocio(const QString estado);

private:
    QString EstadoSocio;
};


#endif // SOCIO_H
