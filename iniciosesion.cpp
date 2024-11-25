#include "iniciosesion.h"
#include "ui_iniciosesion.h"
#include "mainwindow.h"

InicioSesion::InicioSesion(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InicioSesion)
{
    ui->setupUi(this);
    this->setWindowTitle("Iniciar sesion - Biblioteca");

    connect(ui->botInicioSesion, &QPushButton::clicked, this, &InicioSesion::on_iniciarSesion);
}

InicioSesion::~InicioSesion()
{
    delete ui;
}

void InicioSesion::setVentanaMainWindow(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
}

void InicioSesion::on_iniciarSesion() {
    QString nombreUsuario = ui->usuarioLineEdit->text();
    QString contraseña = ui->contrasenaLineEdit->text();

    if (nombreUsuario.isEmpty() || contraseña.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "Por favor ingrese un usuario y una contraseña.");
        return;
    }

    for (const QStringList &usuario : mainWindow->usuarios) {

        qDebug() << "Datos del usuario:" << usuario;

        if (usuario.size() > 6 && usuario[5] == nombreUsuario && usuario[6] == contraseña) {
            QMessageBox::information(this, "Login exitoso", "¡Bienvenido!");
            this->close();
            mainWindow->show();
            ui->usuarioLineEdit->clear();
            ui->contrasenaLineEdit->clear();
            return;
        }
    }
    QMessageBox::warning(this, "Error de inicio de sesión", "El usuario o contraseña son inválidos.");
    ui->usuarioLineEdit->clear();
    ui->contrasenaLineEdit->clear();
}
