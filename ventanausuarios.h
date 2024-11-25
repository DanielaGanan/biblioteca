#ifndef VENTANAUSUARIOS_H
#define VENTANAUSUARIOS_H

#include <QDialog>
#include <formulariousuario.h>
#include "usuario.h"

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

    // Clases de archivo
    void cargarArchivo();
    void guardarArchivo();

    // Llenar la tabla con valores usuarios
    void llenarTabla(QVector<QStringList> datos);

    QStringList buscarUsuarioDni(int dni);
    QStringList buscarPorUsuario(QString &usuarioEnviado);
    void buscarPorFiltro(QString &texto, int columna);

    int buscarIndexPorDni(QString &dni);

    bool validarSiExisteUsuario(QString nuevoUsu);
    bool validarSiExisteDni(QString nuevoDni);

    void limpiarFiltros();

private slots:
    void on_agregarUsuario();
    void on_editarUsuario();
    void on_eliminarUsuario();
    void on_cerrarUsuario();
    void on_buscarUsuario();

private:
    Ui::VentanaUsuarios *ui;
    Usuario *usuario;
    MainWindow *mainWindow;
};

#endif // VENTANAUSUARIOS_H
