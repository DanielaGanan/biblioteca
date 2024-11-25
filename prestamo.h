#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <QWidget>
#include "QDebug"
#include "agregarprestamo.h"
#include "archivo.h"
#include "mainwindow.h"


class MainWindow;

namespace Ui {
class Prestamo;
}

class Prestamo : public QWidget
{
    Q_OBJECT

public:
    explicit Prestamo(QWidget *parent = nullptr);
    ~Prestamo();

    void setVentanaMainWindow(MainWindow *mainWindow);

    // Clases de archivo
    void cargarArchivo();
    void guardarArchivo();

    int buscarIndexPorId(QString &id);
    void buscarPorFiltro(QString &texto, int columna);

    void limpiarFiltros();

    void llenarTabla(QVector<QStringList> datos);


private slots:
    void on_agregarPrestamo();
    void on_editarPrestamo();
    void on_eliminarPrestamo();
    void on_cerrarPrestamo();
    void on_buscarPrestamo();


private:
    Ui::Prestamo *ui;
    MainWindow *mainWindow;
    clasePrestamo *clasePrestamos;

};

#endif // PRESTAMO_H
