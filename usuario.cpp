#include "usuario.h"

Usuario::Usuario(const QString& nombre,
                 const QString& apellido,
                 const int& dni,
                 const QString& direccion,
                 const QString& telefono,
                 const QString& nombreUsuario,
                 const QString& contraseña)
    : Persona(nombre, apellido, dni, direccion, telefono) {
    setNombreUsuario(nombreUsuario);
    setContraseña(contraseña);
}

Usuario::~Usuario() {}

QString Usuario::getNombreUsuario() const {
    return NombreUsuario;
}

QString Usuario::getContraseña() const {
    return Contraseña;
}

void Usuario::setNombreUsuario(QString user) {
    NombreUsuario = user;
}

void Usuario::setContraseña(QString contraseña) {
    Contraseña = contraseña;
}
