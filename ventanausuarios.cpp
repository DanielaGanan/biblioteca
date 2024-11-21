#include "ventanausuarios.h"
#include "mainwindow.h"
#include "ui_ventanausuarios.h"

VentanaUsuarios::VentanaUsuarios(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VentanaUsuarios)
{
    ui->setupUi(this);

    this->setWindowTitle("Gestionar usuarios");

    // La tabla se ajusta al ancho de la venta
    ui->tabla->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Al seleccionar una celda, se selecciona toda la fila
    ui->tabla->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Establecemos la cantidad de columnas y las etiquetas de cada una
    ui->tabla->setColumnCount(7);
    ui->tabla->setHorizontalHeaderLabels({
        "Nombre",
        "Apellido",
        "DNI",
        "Dirección",
        "Telefono"
        "Usuario",
        "Contraseña"
    });

    // Agregar usuario administrador
    admin.setNombreUsuario("admin");
    admin.setContraseña("1234");

    mainWindow->usuarios.append(admin);

    ui->tabla->insertRow(0);
    ui->tabla->setItem(0, 0, new QTableWidgetItem(admin.obtenerNombre()));
    ui->tabla->setItem(0, 1, new QTableWidgetItem(admin.obtenerApellido()));
    ui->tabla->setItem(0, 2, new QTableWidgetItem(admin.obtenerDni()));
    ui->tabla->setItem(0, 3, new QTableWidgetItem(admin.obtenerDireccion()));
    ui->tabla->setItem(0, 4, new QTableWidgetItem(admin.obtenerTelefono()));
    ui->tabla->setItem(0, 5, new QTableWidgetItem(admin.getNombreUsuario()));
    ui->tabla->setItem(0, 6, new QTableWidgetItem(admin.getContraseña()));

    // Conectamos los botones
    connect(ui->botAgregar, &QPushButton::clicked, this, &VentanaUsuarios::on_agregarUsuario);
    connect(ui->botEditar, &QPushButton::clicked, this, &VentanaUsuarios::on_editarUsuario);
    connect(ui->botEliminar, &QPushButton::clicked, this, &VentanaUsuarios::on_eliminarUsuario);
    connect(ui->botCerrar, &QPushButton::clicked, this, &VentanaUsuarios::on_cerrarUsuario);
}

VentanaUsuarios::~VentanaUsuarios()
{
    delete ui;
}


void VentanaUsuarios::on_agregarUsuario() {
    FormularioUsuarios *formulario = new FormularioUsuarios;

    formulario->setWindowTitle("Agregar usuario");

    if (formulario->exec() == QDialog::Accepted) {

        Usuario usuario = formulario->getUsuario();

        // Verificar si el usuario ya existe
        for (int i = 0; i < mainWindow->usuarios.length(); i++){
            if(mainWindow->usuarios[i].getNombreUsuario() == usuario.getNombreUsuario()) {
                QMessageBox::warning(this, "Agregar usuario", "Este usuario ya existe", QMessageBox::Ok);
                formulario->deleteLater();
                return;
            }

            if(mainWindow->usuarios[i].obtenerDni() == usuario.obtenerDni()) {
                QMessageBox::warning(this, "Agregar usuario", "Este dni ya existe", QMessageBox::Ok);
                formulario->deleteLater();
                return;
            }
        }
        // Si no existe, agregar el nuevo usuario
        mainWindow->usuarios.append(usuario);

        llenarTabla(usuario);
    }
    formulario->deleteLater();
}

void VentanaUsuarios::on_editarUsuario() {
    FormularioUsuarios *formulario = new FormularioUsuarios;
    formulario->setWindowTitle("Editar usuario");

    int indice = ui->tabla->currentRow();
    if (indice == -1) {
        QMessageBox::warning(this, "Advertencia", "Debe seleccionar una fila primero.", QMessageBox::Ok);
        return;
    }

    QString usuario = mainWindow->usuarios[indice].getNombreUsuario();
    QString contraseña = mainWindow->usuarios[indice].getContraseña();
    formulario->setUsuarioEditar(usuario, contraseña);

    if (formulario->exec() == QDialog::Accepted) {
        Usuario usuario = formulario->getUsuario();

        for (int i = 0; i < mainWindow->usuarios.length(); i++){
            if(mainWindow->usuarios[i].getNombreUsuario() == usuario.getNombreUsuario()) {
                QMessageBox::warning(this, "Agregar usuario", "Este usuario ya existe", QMessageBox::Ok);
                formulario->deleteLater();
                return;
            }
        }
        mainWindow->usuarios[indice] = usuario;

        ui->tabla->setItem(indice, 0, new QTableWidgetItem(usuario.getNombreUsuario()));
        ui->tabla->setItem(indice, 1, new QTableWidgetItem(usuario.getContraseña()));
    }
    formulario->deleteLater();

}

void VentanaUsuarios::on_eliminarUsuario() {
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

void VentanaUsuarios::on_cerrarUsuario() {
    this->close();
}

void VentanaUsuarios::setVentanaMainWindow(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
}

void VentanaUsuarios::llenarTabla(Usuario usuari)
{
    int fila = ui->tabla->rowCount();
    ui->tabla->insertRow(fila);

    ui->tabla->setItem(fila, 0, new QTableWidgetItem(usuari.obtenerNombre()));
    ui->tabla->setItem(fila, 1, new QTableWidgetItem(usuari.obtenerApellido()));
    ui->tabla->setItem(fila, 2, new QTableWidgetItem(QString::number(usuari.obtenerDni())));
    ui->tabla->setItem(fila, 3, new QTableWidgetItem(usuari.obtenerDireccion()));
    ui->tabla->setItem(fila, 4, new QTableWidgetItem(usuari.obtenerTelefono()));
    ui->tabla->setItem(fila, 5, new QTableWidgetItem(usuari.getNombreUsuario()));
    ui->tabla->setItem(fila, 6, new QTableWidgetItem(usuari.getContraseña()));
}
