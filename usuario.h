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

    // Getters
    QString getNombreUsuario() const;
    QString getContraseña() const;

    // Setters
    void setNombreUsuario(QString user);
    void setContraseña(QString pass);

private:
    QString NombreUsuario;
    QString Contraseña;
};

#endif // USUARIO_H
