#ifndef PERSONA_H
#define PERSONA_H

#include <QString>

class Persona
{
protected:
    QString Nombre;
    QString Apellido;

public:
    Persona(QString nombre, QString apellido);
    ~Persona();

    QString obtenerNombre() const;
    void establecerNombre(QString nombre);
    QString obtenerApellido() const;
    void establecerApellido(QString apellido);
};

#endif // PERSONA_H
