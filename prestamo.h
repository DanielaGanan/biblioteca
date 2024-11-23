#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <QWidget>
#include "QDebug"
#include <agregarprestamo.h>
#include <claseprestamo.h>

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
    void llenarTabla(const QList<clasePrestamo> &prestamos);


private slots:
    void on_agregarPrestamo();
    void on_editarPrestamo();
    void on_eliminarPrestamo();
    void on_cerrarPrestamo();
    void on_buscarPrestamo();


private:
    Ui::Prestamo *ui;
   // clasePrestamo *clasPrestamo;
    MainWindow *mainWindow;

};

#endif // PRESTAMO_H
