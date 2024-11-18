#ifndef FORMULARIOUSUARIO_H
#define FORMULARIOUSUARIO_H

#include <QDialog>
#include <usuario.h>
#include <QMessageBox>

namespace Ui {
class FormularioUsuarios;
}

class FormularioUsuarios : public QDialog
{
    Q_OBJECT

public:
    explicit FormularioUsuarios(QWidget *parent = nullptr);
    ~FormularioUsuarios();
    Usuario obtenerUsuario() const;
    void establecerUsuarioEditar(QString nombreUsuario, QString contraseña);

private slots:
    void on_aceptar();

private:
    Ui::FormularioUsuarios *ui;
    Usuario usuario;
};

#endif // FORMULARIOUSUARIO_H
