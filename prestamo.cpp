#include <prestamo.h>
#include "mainwindow.h"
#include <ui_prestamo.h>
#include "archivo.h"

Prestamo::Prestamo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Prestamo)
{
    ui->setupUi(this);

    this->setWindowTitle("Gestionar Prestamo");

    // La tabla se ajusta al ancho de la venta
    ui->tablaPrestamo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Al seleccionar una celda, se selecciona toda la fila
    ui->tablaPrestamo->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Establecemos la cantidad de columnas y las etiquetas de cada una
    ui->tablaPrestamo->setColumnCount(7);
    ui->tablaPrestamo->setHorizontalHeaderLabels({
        "IdPrestamo",
        "Cantidad",
        "Libro",
        "Socio",
        "Usuario",
        "Fecha Prestamo",
        "Fecha Devolucion"
    });

    // Conectamos los botones y qline
    connect(ui->boton_agregar, &QPushButton::clicked, this, &Prestamo::on_agregarPrestamo);
    connect(ui->boton_editar, &QPushButton::clicked, this, &Prestamo::on_editarPrestamo);
    connect(ui->boton_eliminar, &QPushButton::clicked, this, &Prestamo::on_eliminarPrestamo);
    connect(ui->boton_cerrar, &QPushButton::clicked, this, &Prestamo::on_cerrarPrestamo);

    connect(ui->line_buscar, &QLineEdit::textEdited, this, &Prestamo::on_buscarPrestamo);
}

Prestamo::~Prestamo()
{
    delete ui;
}

void Prestamo::on_agregarPrestamo(){

    agregarPrestamo *formulario = new agregarPrestamo;

    formulario->llenarComboBoxUsuario(mainWindow->usuarios);
    formulario->llenarComboBoxSocio(mainWindow->socios);
    formulario->llenarComboBoxLibros(mainWindow->libros);

    formulario->setWindowTitle("Agregar prestamo");

    if (formulario->exec() == QDialog::Accepted) {

        QStringList prestamoNuevo = formulario->getPrestamo();

        for (const QStringList &prestamo : mainWindow->prestamos) {
            if (prestamo[0].toInt() == prestamoNuevo[0].toInt()) {
                QMessageBox::warning(this, "Usuario Existente", "El idUsuario que intenta agregar ya existe.");
                formulario->deleteLater();
                return;
            }
        }

        // Si no existe, agregar el nuevo prestamos
        mainWindow->prestamos.append(prestamoNuevo);

        guardarArchivo();

        llenarTabla(mainWindow->prestamos);

        qDebug() << "nuevo prestamo" << prestamoNuevo;
    }
    formulario->deleteLater();
}

void Prestamo::on_editarPrestamo(){
    agregarPrestamo *formulario = new agregarPrestamo;

    formulario->setWindowTitle("Editar prestamo");

    int filaSeleccionada = ui->tablaPrestamo->currentRow();

    if (filaSeleccionada == -1) {
        QMessageBox::warning(this, "Advertencia", "Debe seleccionar una fila primero.", QMessageBox::Ok);
        return;
    }

    // Obtener el índice del usuario seleccionado
    QString id = ui->tablaPrestamo->item(filaSeleccionada, 0)->text();
    int indice = buscarIndexPorId(id);

    if (indice < 0 || indice >= mainWindow->prestamos.length()) {
        // Mensaje si no se encuentra el prestamo
        QMessageBox::warning(this, "Error", "No se pudo encontrar el prestamo seleccionado.", QMessageBox::Ok);
        formulario->deleteLater();
        return;
    }

    formulario->llenarComboBoxUsuario(mainWindow->usuarios);
    formulario->llenarComboBoxSocio(mainWindow->socios);
    formulario->llenarComboBoxLibros(mainWindow->libros);

    // Cargar los datos del usuario en el formulario
    QStringList prestamoActual = mainWindow->prestamos[indice];
    formulario->setPrestamoEditar(prestamoActual);

    // Abrir el formulario y procesar los cambios si se aceptan
    if (formulario->exec() == QDialog::Accepted) {
        QStringList prestamoNuevo = formulario->getPrestamo();

        // Validar si el nuevo id ya existe
        for (int i = 0; i < mainWindow->prestamos.length(); i++) {
            if (i != indice) { // Excluir el usuario actual de la validación
                if (mainWindow->prestamos[i][0] == prestamoNuevo[0]) {
                    QMessageBox::warning(this, "Id Prestamo Existente", "El id que intenta agregar ya existe.");
                    formulario->deleteLater();
                    return;
                }
            }
        }

        // Reemplazar el usuario y actualizar la tabla
        mainWindow->prestamos.replace(indice, prestamoNuevo);
        guardarArchivo();
        llenarTabla(mainWindow->prestamos);
        limpiarFiltros();
    }

    // Liberar el formulario
    formulario->deleteLater();
}

void Prestamo::on_eliminarPrestamo(){
    int indice = ui->tablaPrestamo->currentRow();

    if (indice >= 0) {

        QString id = ui->tablaPrestamo->item(indice, 0)->text();

        indice = buscarIndexPorId(id);;

        //Definir el mensaje que se mostrará
        QString Mensaje = "¿Desea eliminar el usuario con DNI " + id + "?";
        QMessageBox::StandardButton advertencia;
        advertencia = QMessageBox::critical(this, "Confirmar Eliminacion", Mensaje, QMessageBox::Yes|QMessageBox::No);

        //Si confirma se elimina el socio
        if (advertencia == QMessageBox::Yes)
        {
            mainWindow->prestamos.remove(indice);
            guardarArchivo();
            ui->tablaPrestamo->removeRow(indice);
            limpiarFiltros();
        }
    }

    llenarTabla(mainWindow->prestamos);
}

void Prestamo::on_cerrarPrestamo(){
    this->close();
}

void Prestamo::on_buscarPrestamo(){
    //Obtener el estado de los radio buttons
    bool porId = ui->botidPrestamo->isChecked();
    bool porLibro = ui->botlibro->isChecked();
    bool porSocio = ui->botsocio->isChecked();
    bool porUsuario = ui->botusuario->isChecked();

    //Obtener el texto a buscar
    QString texto = ui->line_buscar->text();

    //De acuerdo al que fue seleccionado ejecutar la búsqueda
    if (porId)
    {
        buscarPorFiltro(texto, 0);
    }
    else if (porLibro)
    {
        buscarPorFiltro(texto, 1);
    }
    else if (porSocio)
    {
        buscarPorFiltro(texto, 2);
    }
    else if (porUsuario)
    {
        buscarPorFiltro(texto, 5);
    }
}


void Prestamo::setVentanaMainWindow(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
}


void Prestamo::llenarTabla(QVector<QStringList> datos)
{
    // Limpiar la tabla antes de llenarla
    ui->tablaPrestamo->setRowCount(0);

    QTableWidget *tablaPrestamo = ui->tablaPrestamo;
    tablaPrestamo->setRowCount(datos.size());

    for (int fila = 0; fila < datos.size(); ++fila)
    {
        for (int columna = 0; columna < datos[fila].size(); ++columna)
        {
            tablaPrestamo->setItem(fila, columna, new QTableWidgetItem(datos[fila][columna]));
        }
    }
}


//Método para cargar el archivo
void Prestamo::cargarArchivo()
{
    Archivo *archivo = new Archivo("clasePrestamo.csv");
    mainWindow->prestamos.append(archivo->leerArchivo());
}

//Método para guardar el archivo
void Prestamo::guardarArchivo()
{
    Archivo *archivo = new Archivo("clasePrestamo.csv");

    if (!archivo->guardarArchivo(mainWindow->prestamos))
    {
        QMessageBox::critical(this, "Error", "No se pudo guardar el archivo de prestamo");
    }
}


//Retorna el indice del vector original buscando con el id
int Prestamo::buscarIndexPorId(QString &id)
{
    for (int i = 0; i < mainWindow->prestamos.size(); ++i)
    {
        if (mainWindow->prestamos[i][0] == id)
        {
            return i;
        }
    }
    return -1;
}

//Limpiar filtros
void Prestamo::limpiarFiltros()
{
    ui->line_buscar->clear();
    ui->botidPrestamo->setChecked(false);
    ui->botlibro->setChecked(false);
    ui->botsocio->setChecked(false);
    ui->botusuario->setChecked(false);
    llenarTabla(mainWindow->prestamos);
    ui->line_buscar->setFocus();
}

//Métodos de búsqueda por nombre
void Prestamo::buscarPorFiltro(QString &texto, int columna)
{
    QVector<QStringList> resultado;

    if (texto.size() == 0)
    {
        llenarTabla(mainWindow->prestamos);
    }
    else
    {
        for (int i = 0; i < mainWindow->prestamos.size(); ++i)
        {
            if (mainWindow->prestamos[i][columna].startsWith(texto, Qt::CaseInsensitive))
            {
                resultado.append(mainWindow->prestamos[i]);
            }
        }
        llenarTabla(resultado);
    }
}
