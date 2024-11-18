#include "usuario.h"

Usuario::Usuario(const QString& nombre,
                 const QString& apellido,
                 const int& dni,
                 const QString& direccion,
                 const QString& telefono,
                 const QString& nombreUsuario,
                 const QString& contraseña)
    : Persona(nombre, apellido, dni, direccion, telefono) {
    establecerNombreUsuario(nombreUsuario);
    establecerContraseña(contraseña);
}

Usuario::~Usuario() {}

QString Usuario::obtenerNombreUsuario() const {
    return NombreUsuario;
}

void Usuario::establecerNombreUsuario(QString user) {
    NombreUsuario = user;
}

QString Usuario::obtenerContraseña() const {
    return Contraseña;
}

void Usuario::establecerContraseña(QString contraseña) {
    Contraseña = contraseña;
}
