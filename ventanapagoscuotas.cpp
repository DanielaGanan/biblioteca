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

//Método para guardar el archivo CSV
void VentanaPagosCuotas::guardarArchivo()
{
    Archivo *archivo = new Archivo("pagosCuotas.csv");

    if (!archivo->guardarArchivo(mainWindow->pagosCuotas))
    {
        QMessageBox::critical(this, "Error", "No se pudo guardar el archivo");
    }
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
    //Instancia de un nuevo formulario para el registro de un pago
    agregarPago *form = new agregarPago();
    form->setWindowTitle("Registrar nuevo pago");

    //Seteo el nuevo idPago en el formulario
    int nuevoId = obtenerUltimoIdPago();
    form->setNuevoId(nuevoId);
    form->setSocios(mainWindow->socios);

    //Verificar que se aceptó el formulario
    if (form->exec() == QDialog::Accepted)
    {
        //Obtengo los datos pasados por el formulario
        QStringList nuevoPago = form->getDatosPago();

        //Agregar el nuevo pago al vector y mostrarlo
        mainWindow->pagosCuotas.append(nuevoPago);
        actualizarTabla(mainWindow->pagosCuotas);
        guardarArchivo();
    }

    form->deleteLater();
}

int VentanaPagosCuotas::obtenerUltimoIdPago()
{
    int nuevoId;

    //Obtengo el indice del último registro del vector
    int index = mainWindow->pagosCuotas.size();

    //Obtengo el idPago del últmo registro del vector + 1
    nuevoId = mainWindow->pagosCuotas[index - 1][0].toInt() + 1;

    return nuevoId;
}
