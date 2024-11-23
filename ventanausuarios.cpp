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
        "Telefono",
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

    // Conectamos los botones y qline
    connect(ui->botAgregar, &QPushButton::clicked, this, &VentanaUsuarios::on_agregarUsuario);
    connect(ui->botEditar, &QPushButton::clicked, this, &VentanaUsuarios::on_editarUsuario);
    connect(ui->botEliminar, &QPushButton::clicked, this, &VentanaUsuarios::on_eliminarUsuario);
    connect(ui->botCerrar, &QPushButton::clicked, this, &VentanaUsuarios::on_cerrarUsuario);

    connect(ui->lineBuscar, &QLineEdit::textEdited, this, &VentanaUsuarios::on_buscarUsuario);
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
                QMessageBox::warning(this, "Agregar usuario", "Dni inválido", QMessageBox::Ok);
                formulario->deleteLater();
                return;
            }
        }
        // Si no existe, agregar el nuevo usuario
        mainWindow->usuarios.append(usuario);

        llenarTabla(mainWindow->usuarios);
    }
    formulario->deleteLater();
}

void VentanaUsuarios::on_editarUsuario() {
    FormularioUsuarios *formulario = new FormularioUsuarios;

    formulario->setWindowTitle("Editar usuario");

    int filaSeleccionada = ui->tabla->currentRow();

    if (filaSeleccionada == -1) {
        QMessageBox::warning(this, "Advertencia", "Debe seleccionar una fila primero.", QMessageBox::Ok);
        return;
    }

    QString usuarioSeleccionado = ui->tabla->item(filaSeleccionada, 5)->text();
    int indice;

    for (int i = 0; i< mainWindow->usuarios.length(); i ++){
        if (mainWindow->usuarios[i].getNombreUsuario() == usuarioSeleccionado){
            indice = i;
        }
    }

    // Para mostrar los datos en el formulario
    QString nombre = mainWindow->usuarios[indice].obtenerNombre();
    QString apellido = mainWindow->usuarios[indice].obtenerApellido();
    int dni = mainWindow->usuarios[indice].obtenerDni();
    QString direccion = mainWindow->usuarios[indice].obtenerDireccion();
    QString telefono = mainWindow->usuarios[indice].obtenerTelefono();
    QString usuario = mainWindow->usuarios[indice].getNombreUsuario();
    QString contraseña = mainWindow->usuarios[indice].getContraseña();

    formulario->setUsuarioEditar(nombre, apellido, dni, direccion, telefono, usuario, contraseña);

    // si se acepta se agrega un usuario
    if (formulario->exec() == QDialog::Accepted) {

        Usuario usuario = formulario->getUsuario();

        for (int i = 0; i < mainWindow->usuarios.length(); i++){
            if (i != indice) { // Excluir el indice del usuario actual
                if(mainWindow->usuarios[i].getNombreUsuario() == usuario.getNombreUsuario()) {
                    QMessageBox::warning(this, "Agregar usuario", "Este usuario ya existe", QMessageBox::Ok);
                    formulario->deleteLater();
                    return;
                }

                if(mainWindow->usuarios[i].obtenerDni() == usuario.obtenerDni()) {
                    QMessageBox::warning(this, "Agregar usuario", "Dni inválido", QMessageBox::Ok);
                    formulario->deleteLater();
                    return;
                }
            }
        }

        mainWindow->usuarios[indice] = usuario;

        llenarTabla(mainWindow->usuarios);
    }

    formulario->deleteLater();
}

void VentanaUsuarios::on_eliminarUsuario() {
    int filaSeleccionada = ui->tabla->currentRow();

    if (filaSeleccionada < 0) {
        QMessageBox::warning(this, "Error", "Debe seleccionar un usuario para eliminar", QMessageBox::Ok);
        return; // Salir del método si no hay selección
    }

    QString usuarioSeleccionado = ui->tabla->item(filaSeleccionada, 5)->text();
    int indice;

    for (int i = 0; i< mainWindow->usuarios.length(); i ++){
        if (mainWindow->usuarios[i].getNombreUsuario() == usuarioSeleccionado){
            indice = i;
        }
    }
/*
    if (indice < 0) {
        QMessageBox::warning(this, "Error", "Debe seleccionar un usuario para eliminar", QMessageBox::Ok);
    }*/

    QMessageBox::StandardButton advertencia;
    advertencia = QMessageBox::critical(this, "Eliminar usuario", "¿Esta seguro de que quiere eliminar este usuario?", QMessageBox::Yes|QMessageBox::No);

    if(advertencia == QMessageBox::Yes){
        ui->tabla->removeRow(indice);
        mainWindow->usuarios.removeAt(indice);
    }

    llenarTabla(mainWindow->usuarios);
}

Usuario VentanaUsuarios::buscarUsuarioDni(int dni){

    for (int i = 0; i < mainWindow->usuarios.length(); ++i) {
        if(mainWindow->usuarios[i].obtenerDni() == dni) return mainWindow->usuarios[i];
    }
}


void VentanaUsuarios::on_buscarUsuario(){

    // que radiobutton se selecciono
    int columna = -1;

    if (ui->button_dni->isChecked()) {
        columna = 0;
    } else if (ui->button_Nombre->isChecked()) {
        columna = 1;
    } else if (ui->button_Apellido->isChecked()) {
        columna = 2;
    } else if (ui->botton_usuario->isChecked()) {
        columna = 3;
    }

    if (columna == -1) return;

    QString texto = ui->lineBuscar->text();

    QList<Usuario> usuariosFiltrados;

    // buscar los usuarios que coincidan con el texto en la columna seleccionada
    for (int i = 0; i < mainWindow->usuarios.length(); ++i) {

        Usuario usuario = mainWindow->usuarios[i];

        bool coincide = false;

        switch (columna) {
        case 0:
            coincide = QString::number(usuario.obtenerDni()).contains(texto, Qt::CaseInsensitive);
            break;
        case 1:
            coincide = usuario.obtenerNombre().contains(texto, Qt::CaseInsensitive);
            break;
        case 2:
            coincide = usuario.obtenerApellido().contains(texto, Qt::CaseInsensitive);
            break;
        case 3:
            coincide = usuario.getNombreUsuario().contains(texto, Qt::CaseInsensitive);
            break;
        }

        // Si coincide agregar el usuario a la lista filtrada
        if (coincide) {
            usuariosFiltrados.append(usuario);
        }
    }

    llenarTabla(usuariosFiltrados);
}

void VentanaUsuarios::on_cerrarUsuario(){
    this->close();
}

void VentanaUsuarios::setVentanaMainWindow(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
}

void VentanaUsuarios::llenarTabla(const QList<Usuario>& usuarios)
{
    // Limpiar la tabla antes de llenarla
    ui->tabla->setRowCount(0);

    for (int i = 0; i < usuarios.length(); i++){

        ui->tabla->insertRow(i);

        ui->tabla->setItem(i, 0, new QTableWidgetItem(usuarios[i].obtenerNombre()));
        ui->tabla->setItem(i, 1, new QTableWidgetItem(usuarios[i].obtenerApellido()));
        ui->tabla->setItem(i, 2, new QTableWidgetItem(QString::number(usuarios[i].obtenerDni())));
        ui->tabla->setItem(i, 3, new QTableWidgetItem(usuarios[i].obtenerDireccion()));
        ui->tabla->setItem(i, 4, new QTableWidgetItem(usuarios[i].obtenerTelefono()));
        ui->tabla->setItem(i, 5, new QTableWidgetItem(usuarios[i].getNombreUsuario()));
        ui->tabla->setItem(i, 6, new QTableWidgetItem(usuarios[i].getContraseña()));
    }
}
