#ifndef USUARIO_H
#define USUARIO_H

#include <QString>
#include <persona.h>
#include <Qvector>

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
    QVector<QStringList> getUsuarios() const;

    // Setters
    void setNombreUsuario(QString user);
    void setContraseña(QString pass);
    void setUsuarios(const QVector<QStringList> usuarios);

private:
    QString NombreUsuario;
    QString Contraseña;
    QVector<QStringList> Usuarios;
};

#endif // USUARIO_H
