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
    void llenarTabla(Usuario usuari);

private slots:
    void on_agregarUsuario();
    void on_editarUsuario();
    void on_eliminarUsuario();
    void on_cerrarUsuario();

private:
    Ui::VentanaUsuarios *ui;
    Usuario admin;
    MainWindow *mainWindow;
};

#endif // VENTANAUSUARIOS_H
