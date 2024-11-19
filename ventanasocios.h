#ifndef VENTANASOCIOS_H
#define VENTANASOCIOS_H

#include <QWidget>

namespace Ui {
class VentanaSocios;
}

class VentanaSocios : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaSocios(QWidget *parent = nullptr);
    ~VentanaSocios();

private slots:
    void on_agregar();
    void on_modificar();
    void on_eliminar();
    void on_cerrar();

private:
    Ui::VentanaSocios *ui;
};

#endif // VENTANASOCIOS_H
