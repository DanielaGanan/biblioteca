#include "persona.h"

Persona::Persona(QString nombre, QString apellido, int dni, QString direccion, QString telefono) {
    this->establecerNombre(nombre);
    this->establecerApellido(apellido);
    this->establecerDni(dni);
    this->establecerDireccion(direccion);
    this->establecerTelefono(telefono);
}

Persona::~Persona() {}

//Getters
QString Persona::obtenerNombre() const {
    return Nombre;
}

QString Persona::obtenerApellido() const {
    return Apellido;
}

int Persona::obtenerDni() const {
    return Dni;
}

QString Persona::obtenerDireccion() const {
    return Direccion;
}

QString Persona::obtenerTelefono() const {
    return Telefono;
}

//Setters
void Persona::establecerNombre(QString nombre) {
    this->Nombre = nombre;
}

void Persona::establecerApellido(QString apellido) {
    this->Apellido = apellido;
}

void Persona::establecerDni(int dni) {
    this->Dni = dni;
}

void Persona::establecerDireccion(QString direccion) {
    this->Direccion = direccion;
}

void Persona::establecerTelefono(QString telefono) {
    this->Telefono = telefono;
}
