#include "persona.h"

Persona::Persona(QString nombre, QString apellido) {
    this->establecerNombre(nombre);
    this->establecerApellido(apellido);
}

Persona::~Persona() {}

QString Persona::obtenerNombre() const {
    return Nombre;
}
void Persona::establecerNombre(QString nombre) {
    this->Nombre = nombre;
}

QString Persona::obtenerApellido() const {
    return Apellido;
}

void Persona::establecerApellido(QString apellido) {
    this->Apellido = apellido;
}
