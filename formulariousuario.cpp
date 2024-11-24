#include "formulariousuario.h"
#include "ui_formulariousuario.h"

FormularioUsuarios::FormularioUsuarios(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormularioUsuarios)
{
    // Colocar nombre a ventana
    this->setWindowTitle("Agregar nuevo usuario");

    ui->setupUi(this);
    connect(ui->botones, &QDialogButtonBox::accepted, this, &FormularioUsuarios::on_aceptar);
    connect(ui->botones, &QDialogButtonBox::rejected, this, &FormularioUsuarios::reject);

}

FormularioUsuarios::~FormularioUsuarios()
{
    delete ui;
}

int FormularioUsuarios::validarNumero(QLineEdit* num)
{
    // Para verificar que el texto se pudo convertir en un numero
    bool esNumero;

    int numero = num->text().toInt(&esNumero);

    // Verifica si el numero se pudo convertir y que sea positivo
    if (esNumero && numero >= 0) {
        qDebug () << "Se ingreso el numero: " << numero;
        return numero;

    } else {
        qDebug() << "Numero no valido";
        num->clear();
        return -1;
    }
}

void FormularioUsuarios::on_aceptar() {
    if (ui->line_nombreUsuario->text().isEmpty() || ui->line_contrasena->text().isEmpty()){
        QMessageBox::warning(this, "Advertencia", "Los campos no pueden estar vacios");
        reject();
        return;
    }
    if (ui->line_contrasena->text() != ui->line_recontrasena->text()){
        QMessageBox::warning(this, "Advertencia", "Las contraseñas no coinciden.");
        reject();
        return;
    }

    usuario.establecerNombre(ui->line_nombre->text());
    usuario.establecerApellido(ui->line_apellido->text());

    if(validarNumero(ui->line_dni) == -1)      return; // retorna si el dni no es valido
    usuario.establecerDni(validarNumero(ui->line_dni));

    usuario.establecerDireccion(ui->line_direccion->text());
    usuario.establecerTelefono(ui->line_telefono->text());
    usuario.setNombreUsuario(ui->line_nombreUsuario->text());
    usuario.setContraseña(ui->line_contrasena->text());

    accept();
}

Usuario FormularioUsuarios::getUsuario() const {
    return usuario;
}

void FormularioUsuarios::setUsuarioEditar(QString nom, QString apell, int dni, QString dire, QString tel, QString user, QString pass) {

    ui->line_nombre->setText(nom);
    ui->line_apellido->setText(apell);
    ui->line_dni->setText(QString::number(dni));
    ui->line_direccion->setText(dire);
    ui->line_telefono->setText(tel);
    ui->line_nombreUsuario->setText(user);
    ui->line_contrasena->setText(pass);
}
