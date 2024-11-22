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
        // Si no existe, agregar el nuevo prestamos
        mainWindow->prestamos.append(prestamo);

        //llenarTabla(mainWindow->prestamos);
    }
    formulario->deleteLater();
}

void Prestamo::on_editarPrestamo(){

}

void Prestamo::on_eliminarPrestamo(){

}

void Prestamo::on_cerrarPrestamo(){

}

void Prestamo::on_buscarPrestamo(){

}


void Prestamo::setVentanaMainWindow(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
}





