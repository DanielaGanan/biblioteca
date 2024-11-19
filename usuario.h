#ifndef USUARIO_H
#define USUARIO_H

#include <QString>
#include <persona.h>

class Usuario : public Persona
{
public:
    Usuario(const QString& nombre = "",
            const QString& apellido = "",
            const int& dni = 0,
            const QString& direccion = "",
            const QString& telefono = "",
            const QString& nombreUsuario = "",
            const QString& contraseña = ""
            );
    ~Usuario();

    QString obtenerNombreUsuario() const;
    void establecerNombreUsuario(QString user);

    QString obtenerContraseña() const;
    void establecerContraseña(QString pass);

private:
    QString NombreUsuario;
    QString Contraseña;
};

#endif // USUARIO_H
