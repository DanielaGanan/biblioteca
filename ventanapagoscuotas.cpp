#include "ventanapagoscuotas.h"
#include "ui_ventanapagoscuotas.h"
#include "archivo.h"
#include "mainwindow.h"
#include "agregarpago.h"

VentanaPagosCuotas::VentanaPagosCuotas(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VentanaPagosCuotas)
{
    ui->setupUi(this);

    //Setear el título de la ventana
    this->setWindowTitle("Administrar pagos");

    //Setear propiedades de la tabla
    this->tabla = ui->tbPagos;
    this->tabla->setColumnCount(9);
    this->tabla->setHorizontalHeaderLabels({"Id Pago", "DNI Usuario", "Nombre Usuario",
                                            "Apellido Usuario", "DNI Socio", "Nombre Socio",
                                            "Apellido Socio", "Monto Cuota", "Fecha Pago"});
    this->tabla->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->tabla->setSelectionBehavior(QAbstractItemView::SelectRows);
}

VentanaPagosCuotas::~VentanaPagosCuotas()
{
    delete ui;
}

//Método para la carga de archivo CSV
void VentanaPagosCuotas::cargarArchivo()
{
    Archivo *archivo = new Archivo("pagosCuotas.csv");
    mainWindow->pagosCuotas.append(archivo->leerArchivo());
}

//Método para mostrar datos en la tabla
void VentanaPagosCuotas::actualizarTabla(QVector<QStringList> &datos)
{
    this->tabla->setRowCount(datos.size());

    for (int fila = 0; fila < datos.size(); ++fila)
    {
        for (int columna = 0; columna < datos[fila].size(); ++columna)
        {
            this->tabla->setItem(fila, columna, new QTableWidgetItem(datos[fila][columna]));
        }
    }
}

//Método para buscar un Socio determinado en base su DNI
QStringList VentanaPagosCuotas::buscarSocioDni(QString &dni)
{
    QStringList resultado;
    for (int fila = 0; fila < mainWindow->socios.size(); ++fila)
    {
        if (mainWindow->socios[fila][2] == dni)
        {
            resultado = mainWindow->socios[fila];
            return resultado;
        }
    }
    return resultado;
}

void VentanaPagosCuotas::setVentanaMainWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
}


void VentanaPagosCuotas::on_btnAgregar_clicked()
{
    agregarPago *nuevoPago = new agregarPago();
    nuevoPago->show();
}

