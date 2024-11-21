#ifndef SOCIO_H
#define SOCIO_H

#include "persona.h"
#include <QVector>

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
    QVector<QStringList> getSocios() const;

    //Setters
    void setEstadoSocio(const QString estado);
    void setSocios(const QVector<QStringList> socios);

private:
    QString EstadoSocio;
    QVector<QStringList> Socios;
};


#endif // SOCIO_H
