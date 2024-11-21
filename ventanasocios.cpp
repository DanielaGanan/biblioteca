#include "ventanasocios.h"
#include "ui_ventanasocios.h"
#include "archivo.h"
#include "mainwindow.h"

VentanaSocios::VentanaSocios(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VentanaSocios)
{
    ui->setupUi(this);

    //Setear el titulo de la ventana
    this->setWindowTitle("Administrar Socios");

    //Hacer que la tabla se ajuste al ancho de la ventana
    ui->tbSocios->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Conectar los botones
    connect(ui->btnAgregar, &QPushButton::clicked, this, &VentanaSocios::on_agregar);
    connect(ui->btnModificar, &QPushButton::clicked, this, &VentanaSocios::on_modificar);
    connect(ui->btnEliminar, &QPushButton::clicked, this, &VentanaSocios::on_eliminar);
    connect(ui->btnCerrar, &QPushButton::clicked, this, &VentanaSocios::on_cerrar);
}

VentanaSocios::~VentanaSocios()
{
    delete ui;
}

//Método para el botón agregar
void VentanaSocios::on_agregar()
{

}

//Método para el botón modificar
void VentanaSocios::on_modificar()
{

}

//Método para el botón eliminar
void VentanaSocios::on_eliminar()
{

}

//Método para el botón cerrar
void VentanaSocios::on_cerrar()
{
    this->close();
}

//Método para cargar el archivo
void VentanaSocios::cargarArchivo()
{
    Archivo *archivo = new Archivo("socios.csv");
    mainWindow->socios.append(archivo->leerArchivo());
}

//Método para cargar datos en la tabla
void VentanaSocios::actualizarTabla(QVector<QStringList> datos)
{
    QTableWidget *tabla = ui->tbSocios;
    tabla->setRowCount(datos.size());
    tabla->setRowCount(datos.size()-1);
    tabla->setColumnCount(datos[0].size());

    for (int fila = 0; fila < datos.size(); ++fila)
    {
        if (fila == 0)
        {
            tabla->setHorizontalHeaderLabels(datos[fila]);
        }
        else
        {
            for (int columna = 0; columna < datos[fila].size(); ++columna)
            {
                tabla->setItem(fila - 1, columna, new QTableWidgetItem(datos[fila][columna]));
            }
        }
    }

}

void VentanaSocios::setVentanaMainWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
}
