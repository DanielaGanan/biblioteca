#ifndef PERSONA_H
#define PERSONA_H

#include <QString>

class Persona
{
protected:
    QString Nombre;
    QString Apellido;
    int Dni;
    QString Direccion;
    QString Telefono;

public:
    Persona(QString nombre, QString apellido, int dni, QString direccion, QString telefono);
    ~Persona();

    //Getters
    QString obtenerNombre() const;
    QString obtenerApellido() const;
    int obtenerDni() const;
    QString obtenerDireccion() const;
    QString obtenerTelefono() const;

    //Setters
    void establecerNombre(QString nombre);
    void establecerApellido(QString apellido);
    void establecerDni(int dni);
    void establecerDireccion(QString direccion);
    void establecerTelefono(QString telefono);
};

#endif // PERSONA_H
