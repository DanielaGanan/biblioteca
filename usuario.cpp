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

//Getters
QString Usuario::getNombreUsuario() const {
    return NombreUsuario;
}

QString Usuario::getContraseña() const {
    return Contraseña;
}

QVector<QStringList> Usuario::getUsuarios() const {
    return Usuarios;
}

// Setters
void Usuario::setNombreUsuario(QString user) {
    NombreUsuario = user;
}

void Usuario::setContraseña(QString contraseña) {
    Contraseña = contraseña;
}

void Usuario::setUsuarios(const QVector<QStringList> usuarios) {
    this->Usuarios = usuarios;
}
