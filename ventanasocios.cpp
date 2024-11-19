#include "ventanasocios.h"
#include "ui_ventanasocios.h"
#include "archivo.h"
#include "socio.h"

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

    Socio *socioD = new Socio("","",0,"","","");
    this->cargarArchivo(socioD);
    this->cargarTabla(socioD);
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
void VentanaSocios::cargarArchivo(Socio *socio)
{
    qDebug() << "Cargando archivo";
    Archivo *archivo = new Archivo("socios.csv");
    socio->setSocios(archivo->leerArchivo());
    qDebug() << "Se cargo el archivo";
}

//Método para cargar datos en la tabla
void VentanaSocios::cargarTabla(Socio *socio)
{
    QTableWidget *tabla = ui->tbSocios;
    QVector<QStringList> datosSocios;
    datosSocios = socio->getSocios();
    tabla->setRowCount(datosSocios.size());
    qDebug() << datosSocios.size();

    for (int fila = 0; fila < datosSocios.size(); fila++)
    {
        if (fila == 0)
        {
            tabla->setHorizontalHeaderLabels(datosSocios[fila]);
        }
        else
        {
            for (int columna = 0; columna < datosSocios[fila].size(); ++columna)
            {
                tabla->setItem(fila - 1, columna, new QTableWidgetItem(datosSocios[fila][columna]));
            }
        }
    }

}
