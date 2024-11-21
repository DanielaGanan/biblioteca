#ifndef FORMULARIOUSUARIO_H
#define FORMULARIOUSUARIO_H

#include <QDialog>
#include <usuario.h>
#include <QMessageBox>
#include "QLineEdit"

namespace Ui {
class FormularioUsuarios;
}

class FormularioUsuarios : public QDialog
{
    Q_OBJECT

public:
    explicit FormularioUsuarios(QWidget *parent = nullptr);
    ~FormularioUsuarios();
    Usuario getUsuario() const;
    void setUsuarioEditar(QString nombreUsuario, QString contraseña);
    int validarNumero(QLineEdit* num);

private slots:
    void on_aceptar();

private:
    Ui::FormularioUsuarios *ui;
    Usuario usuario;
};

#endif // FORMULARIOUSUARIO_H
