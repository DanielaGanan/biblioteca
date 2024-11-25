#include "ventanausuarios.h"
#include "mainwindow.h"
#include "archivo.h"
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

        QStringList nuevoUsuario = formulario->getUsuario();

        if (validarSiExisteDni(nuevoUsuario[2]) || validarSiExisteUsuario(nuevoUsuario[5]))
        {
            QMessageBox::warning(this, "Usuario Existente", "El dni o usuario que intenta agregar ya existe");
            formulario->deleteLater();
            return;
        }

        // Si no existe, agregar el nuevo usuario
        mainWindow->usuarios.append(nuevoUsuario);

        llenarTabla(mainWindow->usuarios);

        guardarArchivo();

        limpiarFiltros();
    }
    formulario->deleteLater();
}

void VentanaUsuarios::on_editarUsuario() {

    // Crear y configurar el formulario de edición
    FormularioUsuarios *formulario = new FormularioUsuarios;
    formulario->setWindowTitle("Editar usuario");

    int filaSeleccionada = ui->tabla->currentRow();

    if (filaSeleccionada < 0) {
        // Mensaje si no se seleccionó una fila
        QMessageBox::warning(this, "Advertencia", "Primero debe seleccionar el socio que desea modificar.", QMessageBox::Ok);
        formulario->deleteLater();
        return;
    }

    // Obtener el índice del usuario seleccionado
    QString dni = ui->tabla->item(filaSeleccionada, 2)->text();
    int indice = buscarIndexPorDni(dni);

    if (indice < 0 || indice >= mainWindow->usuarios.length()) {
        // Mensaje si no se encuentra el usuario (precaución adicional)
        QMessageBox::warning(this, "Error", "No se pudo encontrar el usuario seleccionado.", QMessageBox::Ok);
        formulario->deleteLater();
        return;
    }

    // Cargar los datos del usuario en el formulario
    QStringList usuarioActual = mainWindow->usuarios[indice];
    formulario->setUsuarioEditar(usuarioActual);

    // Abrir el formulario y procesar los cambios si se aceptan
    if (formulario->exec() == QDialog::Accepted) {
        QStringList usuarioNuevo = formulario->getUsuario();

        // Validar si el nuevo DNI o usuario ya existen
        for (int i = 0; i < mainWindow->usuarios.length(); i++) {
            if (i != indice) { // Excluir el usuario actual de la validación
                if (mainWindow->usuarios[i][2] == usuarioNuevo[2]) {
                    QMessageBox::warning(this, "Usuario Existente", "El DNI que intenta agregar ya existe.");
                    formulario->deleteLater();
                    return;
                }
                if (mainWindow->usuarios[i][5] == usuarioNuevo[5]) {
                    QMessageBox::warning(this, "Usuario Existente", "El usuario que intenta agregar ya existe.");
                    formulario->deleteLater();
                    return;
                }
            }
        }

        // Reemplazar el usuario y actualizar la tabla
        mainWindow->usuarios.replace(indice, usuarioNuevo);
        guardarArchivo();
        llenarTabla(mainWindow->usuarios);
        limpiarFiltros();
    }

    // Liberar el formulario
    formulario->deleteLater();
}


void VentanaUsuarios::on_eliminarUsuario() {
   // int filaSeleccionada = ui->tabla->currentRow();

    int indice = ui->tabla->currentRow();

   if (indice >= 0)
   {
       //Con el indice de la tabla actual busco el dni
       QString dni = ui->tabla->item(indice, 2)->text();

       //Con el dni busco el indice en el vector original
       indice = buscarIndexPorDni(dni);

       //Definir el mensaje que se mostrará
       QString Mensaje = "¿Desea eliminar el usuario con DNI " + dni + "?";
       QMessageBox::StandardButton advertencia;
       advertencia = QMessageBox::critical(this, "Confirmar Eliminacion", Mensaje, QMessageBox::Yes|QMessageBox::No);

       //Si confirma se elimina el socio
       if (advertencia == QMessageBox::Yes)
       {
           mainWindow->usuarios.remove(indice);
           guardarArchivo();
           ui->tabla->removeRow(indice);
           limpiarFiltros();
       }
   }
    llenarTabla(mainWindow->usuarios);
}

//Métodos de búsqueda por nombre
void VentanaUsuarios::buscarPorFiltro(QString &texto, int columna)
{
    QVector<QStringList> resultado;

    if (texto.size() == 0)
    {
        llenarTabla(mainWindow->usuarios);
    }
    else
    {
        for (int i = 0; i < mainWindow->usuarios.size(); ++i)
        {
            if (mainWindow->usuarios[i][columna].startsWith(texto, Qt::CaseInsensitive))
            {
                resultado.append(mainWindow->usuarios[i]);
            }
        }
        llenarTabla(resultado);
    }
}


QStringList VentanaUsuarios::buscarUsuarioDni(int dni){

    // Recorrer el QVector<QStringList>
    for (const QStringList &usuario : mainWindow->usuarios) {
        // Verificar que no esté vacío y que el DNI coincida
        if (!usuario.isEmpty() && usuario[2].toInt() == dni) { // Asumiendo que el DNI está en la posición 2
                return usuario;
        }
    }
     return QStringList();
}

QStringList VentanaUsuarios::buscarPorUsuario(QString &usuarioEnviado){

    // Recorrer el QVector<QStringList>
    for (const QStringList &usuario : mainWindow->usuarios) {
        // Verificar que no esté vacío y que el DNI coincida
        if (!usuario.isEmpty() && usuario[5] == usuarioEnviado) {
            return usuario;
        }
    }
    return QStringList();
}



void VentanaUsuarios::on_buscarUsuario(){

    //Obtener el estado de los radio buttons
    bool porNombre = ui->button_Nombre->isChecked();
    bool porApellido = ui->button_Apellido->isChecked();
    bool porDni = ui->button_dni->isChecked();
    bool porUsuario = ui->botton_usuario->isChecked();

    //Obtener el texto a buscar
    QString texto = ui->lineBuscar->text();

    //De acuerdo al que fue seleccionado ejecutar la búsqueda
    if (porNombre)
    {
        buscarPorFiltro(texto, 0);
    }
    else if (porApellido)
    {
        buscarPorFiltro(texto, 1);
    }
    else if (porDni)
    {
        buscarPorFiltro(texto, 2);
    }
    else if (porUsuario)
    {
        buscarPorFiltro(texto, 5);
    }
}

void VentanaUsuarios::on_cerrarUsuario(){
    this->close();
}

void VentanaUsuarios::setVentanaMainWindow(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
}

void VentanaUsuarios::llenarTabla(QVector<QStringList> datos)
{
    // Limpiar la tabla antes de llenarla
    ui->tabla->setRowCount(0);

    QTableWidget *tabla = ui->tabla;
    tabla->setRowCount(datos.size());

    for (int fila = 0; fila < datos.size(); ++fila)
    {
        for (int columna = 0; columna < datos[fila].size(); ++columna)
        {
            tabla->setItem(fila, columna, new QTableWidgetItem(datos[fila][columna]));
        }
    }
}

//Limpiar filtros
void VentanaUsuarios::limpiarFiltros()
{
    ui->lineBuscar->clear();
    ui->botton_usuario->setChecked(false);
    ui->button_Apellido->setChecked(false);
    ui->button_Nombre->setChecked(false);
    ui->button_dni->setChecked(false);
    llenarTabla(mainWindow->usuarios);
    ui->lineBuscar->setFocus();
}

//Método para validar existe el dni
bool VentanaUsuarios::validarSiExisteDni(QString nuevoDni)
{
    // Recorrer el DNI de los usuarios existentes y comparar con el nuevo DNI
    for (const QStringList &usuario : mainWindow->usuarios)
    {
        // Verifica si el DNI (campo en la posición 2) ya existe
        if (usuario.size() > 2 && usuario[2] == nuevoDni)
        {
            return true;
        }
    }
    return false;
}

bool VentanaUsuarios::validarSiExisteUsuario(QString nuevoUsu)
{
    for (const QStringList &usuario : mainWindow->usuarios)
    {
        // Verifica si el DNI (campo en la posición 2) ya existe
        if (usuario.size() > 5 && usuario[5] == nuevoUsu)
        {
            return true;
        }
    }
    return false;
}

//Retorna el indice del vector original buscando con el dni
int VentanaUsuarios::buscarIndexPorDni(QString &dni)
{
    for (int i = 0; i < mainWindow->usuarios.size(); ++i)
    {
        if (mainWindow->usuarios[i][2] == dni)
        {
            return i;
        }
    }
    return -1;
}

//Método para cargar el archivo
void VentanaUsuarios::cargarArchivo()
{
    Archivo *archivo = new Archivo("usuarios.csv");
    mainWindow->usuarios.append(archivo->leerArchivo());
}

//Método para guardar el archivo
void VentanaUsuarios::guardarArchivo()
{
    Archivo *archivo = new Archivo("usuarios.csv");

    if (!archivo->guardarArchivo(mainWindow->usuarios))
    {
        QMessageBox::critical(this, "Error", "No se pudo guardar el archivo de usuario");
    }
}
