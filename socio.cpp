#include "socio.h"
#include "persona.h"

Socio::Socio(const QString& nombre,
             const QString& apellido,
             const int& dni,
             const QString& direccion,
             const QString& telefono,
             const QString& estado)
    : Persona(nombre, apellido, dni, direccion, telefono) {
    this->setEstadoSocio(estado);
}

Socio::~Socio() {}

//Getters
QString Socio::getEstadoSocio() const
{
    return EstadoSocio;
}

QVector<QStringList> Socio::getSocios() const
{
    return Socios;
}

//Setters
void Socio::setEstadoSocio(QString estado)
{
    this->EstadoSocio = estado;
}

void Socio::setSocios(const QVector<QStringList> socios)
{
    this->Socios = socios;
}
