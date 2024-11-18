#include "formulariousuario.h"
#include "ui_formulariousuario.h"

FormularioUsuarios::FormularioUsuarios(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormularioUsuarios)
{
    ui->setupUi(this);
    connect(ui->botones, &QDialogButtonBox::accepted, this, &FormularioUsuarios::on_aceptar);
    connect(ui->botones, &QDialogButtonBox::rejected, this, &FormularioUsuarios::reject);

}

FormularioUsuarios::~FormularioUsuarios()
{
    delete ui;
}

void FormularioUsuarios::on_aceptar() {
    if (ui->nombreUsuario->text().isEmpty() || ui->contrasena->text().isEmpty()){
        QMessageBox::warning(this, "Advertencia", "Los campos no pueden estar vacios");
        reject();
        return;
    }
    if (ui->contrasena->text() != ui->recontrasena->text()){
        QMessageBox::warning(this, "Advertencia", "Las contraseñas no coinciden.");
        reject();
        return;
    }
    usuario.establecerNombreUsuario(ui->nombreUsuario->text());
    usuario.establecerContraseña(ui->contrasena->text());

    accept();
}

Usuario FormularioUsuarios::obtenerUsuario() const {
    return usuario;
}

void FormularioUsuarios::establecerUsuarioEditar(QString user, QString pass) {
    ui->nombreUsuario->setText(user);
    ui->contrasena->setText(pass);
}
