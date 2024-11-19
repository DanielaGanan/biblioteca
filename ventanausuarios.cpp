#include "ventanausuarios.h"
#include "mainwindow.h"
#include "ui_ventanausuarios.h"

VentanaUsuarios::VentanaUsuarios(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VentanaUsuarios)
{
    ui->setupUi(this);

    this->setWindowTitle("Gestionar usuarios");
    ui->tabla->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // La tabla se ajusta al ancho de la venta
    ui->tabla->setSelectionBehavior(QAbstractItemView::SelectRows); // Al seleccionar una celda, se selecciona toda la fila
    // Establecemos la cantidad de columnas y las etiquetas de cada una
    ui->tabla->setColumnCount(2);
    ui->tabla->setHorizontalHeaderLabels({
        "Usuario",
        "Contraseña"
    });

    // Agregar usuario administrador
    admin.establecerNombreUsuario("admin");
    admin.establecerContraseña("1234");
    mainWindow->usuarios.append(admin);
    ui->tabla->insertRow(0);
    ui->tabla->setItem(0, 0, new QTableWidgetItem(admin.obtenerNombreUsuario()));
    ui->tabla->setItem(0, 1, new QTableWidgetItem(admin.obtenerContraseña()));

    // Conectamos los botones
    connect(ui->botAgregar, &QPushButton::clicked, this, &VentanaUsuarios::on_agregar);
    connect(ui->botEditar, &QPushButton::clicked, this, &VentanaUsuarios::on_editar);
    connect(ui->botEliminar, &QPushButton::clicked, this, &VentanaUsuarios::on_eliminar);
    connect(ui->botCerrar, &QPushButton::clicked, this, &VentanaUsuarios::on_cerrar);
}

VentanaUsuarios::~VentanaUsuarios()
{
    delete ui;
}

void VentanaUsuarios::on_agregar() {
    FormularioUsuarios *formulario = new FormularioUsuarios;
    formulario->setWindowTitle("Agregar usuario");
    if (formulario->exec() == QDialog::Accepted) {
        Usuario usuario = formulario->obtenerUsuario();

        // Verificar si el usuario ya existe
        for (int i = 0; i < mainWindow->usuarios.length(); i++){
            if(mainWindow->usuarios[i].obtenerNombreUsuario() == usuario.obtenerNombreUsuario()) {
                QMessageBox::warning(this, "Agregar usuario", "Este usuario ya existe", QMessageBox::Ok);
                formulario->deleteLater();
                return;
            }
        }
        // Si no existe, agregar el nuevo usuario
        mainWindow->usuarios.append(usuario);

        int fila = ui->tabla->rowCount();
        ui->tabla->insertRow(fila);
        ui->tabla->setItem(fila, 0, new QTableWidgetItem(usuario.obtenerNombreUsuario()));
        ui->tabla->setItem(fila, 1, new QTableWidgetItem(usuario.obtenerContraseña()));
    }
    formulario->deleteLater();


}

void VentanaUsuarios::on_editar() {
    FormularioUsuarios *formulario = new FormularioUsuarios;
    formulario->setWindowTitle("Editar usuario");

    int indice = ui->tabla->currentRow();
    if (indice == -1) {
        QMessageBox::warning(this, "Advertencia", "Debe seleccionar una fila primero.", QMessageBox::Ok);
        return;
    }

    QString usuario = mainWindow->usuarios[indice].obtenerNombreUsuario();
    QString contraseña = mainWindow->usuarios[indice].obtenerContraseña();
    formulario->establecerUsuarioEditar(usuario, contraseña);

    if (formulario->exec() == QDialog::Accepted) {
        Usuario usuario = formulario->obtenerUsuario();

        for (int i = 0; i < mainWindow->usuarios.length(); i++){
            if(mainWindow->usuarios[i].obtenerNombreUsuario() == usuario.obtenerNombreUsuario()) {
                QMessageBox::warning(this, "Agregar usuario", "Este usuario ya existe", QMessageBox::Ok);
                formulario->deleteLater();
                return;
            }
        }
        mainWindow->usuarios[indice] = usuario;

        ui->tabla->setItem(indice, 0, new QTableWidgetItem(usuario.obtenerNombreUsuario()));
        ui->tabla->setItem(indice, 1, new QTableWidgetItem(usuario.obtenerContraseña()));
    }
    formulario->deleteLater();

}

void VentanaUsuarios::on_eliminar() {
    int indice = ui->tabla->currentRow();
    if (indice < 0) {
        QMessageBox::warning(this, "Error", "Debe seleccionar un usuario para eliminar", QMessageBox::Ok);
    } else if (indice == 0) {
        QMessageBox::warning(this, "Error", "Al menos debe haber 1 usuario registrado", QMessageBox::Ok);
    }
    QMessageBox::StandardButton advertencia;
    advertencia = QMessageBox::critical(this, "Eliminar usuario", "¿Está seguro de que quiere eliminar este usuario?", QMessageBox::Yes|QMessageBox::No);
    if(advertencia == QMessageBox::Yes){
        ui->tabla->removeRow(indice);
        mainWindow->usuarios.removeAt(indice);
    }
}

void VentanaUsuarios::on_cerrar() {
    this->close();
}

void VentanaUsuarios::setVentanaMainWindow(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
}
