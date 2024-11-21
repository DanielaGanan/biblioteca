#ifndef VENTANASOCIOS_H
#define VENTANASOCIOS_H

#include <QWidget>
#include "socio.h"

class MainWindow;

namespace Ui {
class VentanaSocios;
}

class VentanaSocios : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaSocios(QWidget *parent = nullptr);
    ~VentanaSocios();

    void setVentanaMainWindow(MainWindow *mainWindow);

    void cargarArchivo();
    void actualizarTabla(QVector<QStringList> datos);

private slots:
    void on_agregar();
    void on_modificar();
    void on_eliminar();
    void on_cerrar();

private:
    Ui::VentanaSocios *ui;
    Socio *socio;
    MainWindow *mainWindow;
};

#endif // VENTANASOCIOS_H
