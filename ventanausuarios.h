#ifndef VENTANAUSUARIOS_H
#define VENTANAUSUARIOS_H

#include <QDialog>
#include <usuario.h>
#include <formulariousuario.h>

class MainWindow;

namespace Ui {
class VentanaUsuarios;
}

class VentanaUsuarios : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaUsuarios(QWidget *parent = nullptr);
    ~VentanaUsuarios();
    void setVentanaMainWindow(MainWindow *mainWindow);

private slots:
    void on_agregar();
    void on_editar();
    void on_eliminar();
    void on_cerrar();

private:
    Ui::VentanaUsuarios *ui;
    Usuario admin;
    MainWindow *mainWindow;
};

#endif // VENTANAUSUARIOS_H
