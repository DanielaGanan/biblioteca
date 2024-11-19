#ifndef VENTANASOCIOS_H
#define VENTANASOCIOS_H

#include <QWidget>
#include "socio.h"

namespace Ui {
class VentanaSocios;
}

class VentanaSocios : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaSocios(QWidget *parent = nullptr);
    ~VentanaSocios();

    void cargarArchivo(Socio *socio);
    void cargarTabla(Socio *socio);

private slots:
    void on_agregar();
    void on_modificar();
    void on_eliminar();
    void on_cerrar();

private:
    Ui::VentanaSocios *ui;
    Socio *socio;
};

#endif // VENTANASOCIOS_H
