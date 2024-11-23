#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <QString>
#include <QVector>
#include <QStringList>

class Archivo
{
public:
    Archivo(const QString &rutaArchivo);

    //Método para leer archivo
    QVector<QStringList> leerArchivo();

    //Método para guardar archivo
    bool guardarArchivo(QVector<QStringList> &datos);

private:
    QString rutaArchivo;
    QVector<QStringList> datos;
};

#endif // ARCHIVO_H
