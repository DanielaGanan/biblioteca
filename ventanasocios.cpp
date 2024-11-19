#include "ventanasocios.h"
#include "ui_ventanasocios.h"

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
