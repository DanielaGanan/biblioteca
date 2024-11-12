#ifndef LIBRO_H
#define LIBRO_H

#include "librodatos.h"
#include <QWidget>
#include <QString>
#include <agregarnuevolibro.h>

namespace Ui {
class Libro;
}

class Libro : public QWidget
{
    Q_OBJECT

public:
    explicit Libro(QWidget *parent = nullptr);
    ~Libro();

    // Metodos
private slots:
    void onAgregarLibro();
    void onModificarLibro();
    void onEliminarLibro();
    void actualizarTabla();

private:
    QList<libroDatos> libros;
    void actualizarLibro(int fila, const Libro &libroSeleccionado);
};

#endif // LIBRO_H
