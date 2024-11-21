#include "archivo.h"
#include <QFile>
#include <QDebug>

Archivo::Archivo(const QString &ruta) : rutaArchivo(ruta) {}

QVector<QStringList> Archivo::leerArchivo()
{
    QFile archivo(rutaArchivo);

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: No se pudo abrir el archivo";
        return datos;
    }

    QTextStream entrada(&archivo);
    while (!entrada.atEnd())
    {
        QString linea = entrada.readLine();
        QStringList columnas = linea.split(",");
        datos.append(columnas);
    }

    archivo.close();

    return datos;
}

bool Archivo::guardarArchivo()
{
    QVector<QStringList> datos;
    datos.append(QStringList({"Nuevo", "Dato", "Fila"}));
    QFile archivo(rutaArchivo);

    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "No se pudo abrir el archivo para escritura: " << rutaArchivo;
        return false;
    }

    QTextStream salida(&archivo);
    for (const QStringList &fila : datos)
    {
        salida << fila.join(',') << "\n";
    }
    archivo.close();
    return true;

}
