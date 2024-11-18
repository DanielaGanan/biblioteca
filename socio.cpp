#include "socio.h"
#include "persona.h"

Socio::Socio(const QString& nombre, const QString& apellido, const QString& libroPrestado) : Persona(nombre, apellido) {
    this->establecerLibroPrestado(libroPrestado);
}

Socio::~Socio() {}

QString Socio::obtenerLibroPrestado() const {
    return libroPrestado;
}

void Socio::establecerLibroPrestado(QString libro) {
    this->libroPrestado= libro;
}
