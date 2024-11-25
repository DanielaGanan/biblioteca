#include <prestamo.h>
#include "mainwindow.h"
#include <ui_prestamo.h>

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
/*
    agregarPrestamo *formulario = new agregarPrestamo;

    formulario->llenarComboBox(mainWindow->usuarios);

    formulario->setWindowTitle("Agregar prestamo");

    if (formulario->exec() == QDialog::Accepted) {

        clasePrestamo prestamo = formulario->getPrestamo();

        // Verificar si el prestamos ya existe
        for (int i = 0; i < mainWindow->prestamos.length(); i++){
            if(mainWindow->prestamos[i].getIdPrestamo() == prestamo.getIdPrestamo()) {
                QMessageBox::warning(this, "Agregar prestamos", "Este idprestamos ya existe", QMessageBox::Ok);

                formulario->deleteLater();
                return;
            }
        }

        if(prestamo.getFechaPrestamo() < prestamo.getFechaDevolucion()){
            QMessageBox::warning(this, "Agregar prestamo", "La fecha de prestamo no puede ser despues de la fecha de devolucion", QMessageBox::Ok);
            formulario->deleteLater();
            return;
        }

        // Si no existe, agregar el nuevo prestamos
        mainWindow->prestamos.append(prestamo);

        llenarTabla(mainWindow->prestamos);
    }
    formulario->deleteLater();*/
}

void Prestamo::on_editarPrestamo(){/*

    agregarPrestamo *formulario = new agregarPrestamo;

    formulario->setWindowTitle("Editar prestamo");

    int filaSeleccionada = ui->tablaPrestamo->currentRow();

    if (filaSeleccionada == -1) {
        QMessageBox::warning(this, "Advertencia", "Debe seleccionar una fila primero.", QMessageBox::Ok);
        return;
    }

    QString prestamoSeleccionado = ui->tablaPrestamo->item(filaSeleccionada, 0)->text();
    int indice;

    int prestamoId = prestamoSeleccionado.toInt();

    for (int i = 0; i< mainWindow->prestamos.length(); i ++){
        if (mainWindow->prestamos[i].getIdPrestamo() == prestamoId){
            indice = i;
        }
    }

    // Para mostrar los datos en el formulario
    int id = mainWindow->prestamos[indice].getIdPrestamo();
    int cant = mainWindow->prestamos[indice].getCantidad();
    QDate fprestamo = mainWindow->prestamos[indice].getFechaPrestamo();
    QDate fdevolucion = mainWindow->prestamos[indice].getFechaDevolucion();
 //   libro* lib = mainWindow->prestamos[indice].getUsuario();
    Usuario* usu = mainWindow->prestamos[indice].getUsuario();

    formulario->setPrestamoEditar();

    // si se acepta se agrega un usuario
    if (formulario->exec() == QDialog::Accepted) {

        clasePrestamo prestamo = formulario->getPrestamo();

        for (int i = 0; i < mainWindow->prestamos.length(); i++){
            if (i != indice) { // Excluir el indice del usuario actual
                if(mainWindow->prestamos[i].getIdPrestamo() == prestamo.getIdPrestamo()) {
                    QMessageBox::warning(this, "Agregar prestamo", "Este id ya existe", QMessageBox::Ok);
                    formulario->deleteLater();
                    return;
                }
            }
        }

        mainWindow->prestamos[indice] = prestamo;

        llenarTabla(mainWindow->prestamos);
    }

    formulario->deleteLater();*/
}

void Prestamo::on_eliminarPrestamo(){
    int filaSeleccionada = ui->tablaPrestamo->currentRow();

    if (filaSeleccionada < 0) {
        QMessageBox::warning(this, "Error", "Debe seleccionar un prestamo para eliminar", QMessageBox::Ok);
        return; // Salir del método si no hay selección
    }

    QString prestamoSeleccionado = ui->tablaPrestamo->item(filaSeleccionada, 0)->text();
    int indice;

    int prestamoId = prestamoSeleccionado.toInt();

    for (int i = 0; i< mainWindow->prestamos.length(); i ++){
        if (mainWindow->prestamos[i].getIdPrestamo() == prestamoId){
            indice = i;
        }
    }

    QMessageBox::StandardButton advertencia;
    advertencia = QMessageBox::critical(this, "Eliminar prestamo", "¿Esta seguro de que quiere eliminar este prestamo?", QMessageBox::Yes|QMessageBox::No);

    if(advertencia == QMessageBox::Yes){
        ui->tablaPrestamo->removeRow(indice);
        mainWindow->prestamos.removeAt(indice);
    }

    llenarTabla(mainWindow->prestamos);
}

void Prestamo::on_cerrarPrestamo(){
    this->close();
}

void Prestamo::on_buscarPrestamo(){
    // que radiobutton se selecciono
    int columna = -1;

    if (ui->botidPrestamo->isChecked()) {
        columna = 0;
    } else if (ui->botusuario->isChecked()) {
        columna = 1;
    } else if (ui->botlibro->isChecked()) {
        columna = 2;
    } else if (ui->botsocio->isChecked()) {
        columna = 3;
    }

    if (columna == -1) return;

    QString texto = ui->line_buscar->text();

    QList<clasePrestamo> prestamoFiltrados;

    // buscar los usuarios que coincidan con el texto en la columna seleccionada
    for (int i = 0; i < mainWindow->prestamos.length(); ++i) {

        clasePrestamo prestamo = mainWindow->prestamos[i];

        bool coincide = false;

        switch (columna) {
        case 0:
            coincide = QString::number(prestamo.getIdPrestamo()).contains(texto, Qt::CaseInsensitive);
            break;
        case 1:
            coincide = prestamo.getUsuario()->obtenerNombre().contains(texto, Qt::CaseInsensitive);
            break;
        }

        // Si coincide agregar el prestamo a la lista filtrada
        if (coincide) {
            prestamoFiltrados.append(prestamo);
        }
    }
    llenarTabla(prestamoFiltrados);
}


void Prestamo::setVentanaMainWindow(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
}


void Prestamo::llenarTabla(const QList<clasePrestamo> &prestamos)
{
    // Limpiar la tabla antes de llenarla
    ui->tablaPrestamo->setRowCount(0);

    for (int i = 0; i < prestamos.length(); i++){

        ui->tablaPrestamo->insertRow(i);

        ui->tablaPrestamo->setItem(i, 0, new QTableWidgetItem(QString::number(prestamos[i].getIdPrestamo())));
        ui->tablaPrestamo->setItem(i, 1, new QTableWidgetItem(QString::number(prestamos[i].getCantidad())));
        ui->tablaPrestamo->setItem(i, 5, new QTableWidgetItem(prestamos[i].getFechaPrestamo().toString("dd/MM/yyyy")));
        ui->tablaPrestamo->setItem(i, 6, new QTableWidgetItem(prestamos[i].getFechaDevolucion().toString("dd/MM/yyyy")));
        ui->tablaPrestamo->setItem(i, 4, new QTableWidgetItem(prestamos[i].getUsuario()->obtenerNombre()));
    }
}


