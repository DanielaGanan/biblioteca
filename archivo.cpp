#include "archivo.h"
#include <QFile>
#include <QDebug>

Archivo::Archivo(const QString &ruta) : rutaArchivo(ruta) {}

QVector<QStringList> Archivo::leerArchivo()
{
    QFile archivo(rutaArchivo);

    if (!archivo.exists()) {
        qDebug() << "El archivo no existe. Se procede a crearlo";
        archivo.open(QIODevice::WriteOnly | QIODevice::Text);
        archivo.close();
    }

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: No se pudo abrir el archivo";
        return datos;
    }

    QTextStream entrada(&archivo);

    bool primeraFila = true;
    while (!entrada.atEnd())
    {
        QString linea = entrada.readLine();
        QStringList columnas = linea.split(",");

        if (primeraFila)
        {
            primeraFila = !primeraFila;
            continue;
        }

        datos.append(columnas);
    }

    archivo.close();

    return datos;
}

bool Archivo::guardarArchivo(QVector<QStringList> &datos)
{
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
