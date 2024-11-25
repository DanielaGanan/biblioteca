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
    if (ui->line_nombreUsuario->text().isEmpty() || ui->line_contrasena->text().isEmpty() ||
        ui->line_apellido->text().isEmpty() || ui->line_nombre->text().isEmpty() ||
        ui->line_dni->text().isEmpty() || ui->line_telefono->text().isEmpty() ||
        ui->line_direccion->text().isEmpty()){
        QMessageBox::warning(this, "Advertencia", "Los campos no pueden estar vacios");
        reject();
        return;
    }
    if (ui->line_contrasena->text() != ui->line_recontrasena->text()){
        QMessageBox::warning(this, "Advertencia", "Las contraseñas no coinciden.");
        reject();
        return;
    }

    int dni = validarNumero(ui->line_dni);
    if (dni == -1) {
        QMessageBox::warning(this, "Advertencia", "El DNI ingresado no es válido.");
        reject();
        return;
    }

    usuario.establecerDni(validarNumero(ui->line_dni));
    usuario.establecerNombre(ui->line_nombre->text());
    usuario.establecerApellido(ui->line_apellido->text());
    usuario.establecerDireccion(ui->line_direccion->text());
    usuario.establecerTelefono(ui->line_telefono->text());
    usuario.setNombreUsuario(ui->line_nombreUsuario->text());
    usuario.setContraseña(ui->line_contrasena->text());

    accept();
}

QStringList FormularioUsuarios::getUsuario() const {

    QStringList usuario;

    if (this->usuario.obtenerDni() <= 0) {
        QMessageBox::warning(nullptr, "Error", "El DNI del usuario no es válido.");
        return QStringList(); // Devuelve una lista vacía si hay error
    }

    usuario.append({this->usuario.obtenerNombre(),
                    this->usuario.obtenerApellido(),
                    QString::number(this->usuario.obtenerDni()),
                    this->usuario.obtenerDireccion(),
                    this->usuario.obtenerTelefono(),
                    this->usuario.getNombreUsuario(),
                    this->usuario.getContraseña()});
    return usuario;
}

void FormularioUsuarios::setUsuarioEditar(QStringList usuario) {

    ui->line_nombre->setText(usuario[0]);
    ui->line_apellido->setText(usuario[1]);
    ui->line_dni->setText(usuario[2]);
    ui->line_direccion->setText(usuario[3]);
    ui->line_telefono->setText(usuario[4]);
    ui->line_nombreUsuario->setText(usuario[5]);
    ui->line_contrasena->setText(usuario[6]);
}
