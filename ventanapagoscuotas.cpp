#include "ventanapagoscuotas.h"
#include "ui_ventanapagoscuotas.h"
#include "archivo.h"
#include "mainwindow.h"
#include "agregarpago.h"
#include <QList>
#include <QDate>

VentanaPagosCuotas::VentanaPagosCuotas(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VentanaPagosCuotas)
{
    ui->setupUi(this);

    //Setear el título de la ventana
    this->setWindowTitle("Administrar pagos");

    //Setear propiedades de la tabla
    this->tabla = ui->tbPagos;
    this->tabla->setColumnCount(6);
    this->tabla->setHorizontalHeaderLabels({"Id Pago", "DNI Usuario", "DNI Socio",
                                            "Monto Cuota", "Fecha Pago", "Fecha Registro"});
    this->tabla->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->tabla->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Conectar metodos con botones o acciones
    connect(ui->btnModificar, &QPushButton::clicked, this, &VentanaPagosCuotas::on_modificar);
    connect(ui->btnEliminar, &QPushButton::clicked, this, &VentanaPagosCuotas::on_eliminar);
    connect(ui->btnCerrar, &QPushButton::clicked, this, &VentanaPagosCuotas::on_cerrar);
    connect(ui->btnLimpiar, &QPushButton::clicked, this, &VentanaPagosCuotas::limpiar);
    connect(ui->txtBuscar, &QLineEdit::textChanged, this, &VentanaPagosCuotas::buscar);

    //Setear el foco al LineEdit buscar
    ui->txtBuscar->setFocus();
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

//Método para agregar un nuevo Pago
void VentanaPagosCuotas::on_btnAgregar_clicked()
{
    //Instancia de un nuevo formulario para el registro de un pago
    agregarPago *form = new agregarPago();
    form->setWindowTitle("Registrar nuevo pago");

    //Seteo el nuevo idPago en el formulario
    int nuevoId = obtenerUltimoIdPago();
    form->setNuevoId(nuevoId);
    form->setSocios(mainWindow->socios);
    form->setUsuario(mainWindow->usuarioLogeado);

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

//Método para obtener el último idPago y definir el siguiente
int VentanaPagosCuotas::obtenerUltimoIdPago()
{
    int nuevoId;

    //Obtengo el indice del último registro del vector
    int index = mainWindow->pagosCuotas.size();

    //Si el vector está vacío retorno 1
    if (index == 0)
    {
        return 1;
    }

    //Obtengo el idPago del últmo registro del vector + 1
    nuevoId = mainWindow->pagosCuotas[index - 1][0].toInt() + 1;

    return nuevoId;
}

//Método para modificar un pago
void VentanaPagosCuotas::on_modificar()
{
    //Instanca de un nuevo formulario para modificar un pago
    agregarPago *form = new agregarPago;
    form->setWindowTitle("Modificar Pago");
    form->setSocios(mainWindow->socios);
    form->setUsuario(mainWindow->usuarioLogeado);

    //Obtengo el índice de la fila de la tabla
    int indice = ui->tbPagos->currentRow();

    //Si se intenta modificar sin seleccionar un pago muestra mensaje
    if (indice >= 0)
    {
        //Con el indice de la tabla actual busco el idPago
        QString idPago = ui->tbPagos->item(indice, 0)->text();

        //Con el idPago busco el indice en el vector original
        indice = buscarIndexPorIdPago(idPago);

        //Obtengo todos los datos del pago y loa paso al formulario
        QStringList pago = mainWindow->pagosCuotas[indice];
        form->setPagoEditar(pago);

        //Verificar que se aceptó el formulario
        if (form->exec() == QDialog::Accepted)
        {
            //Guardo los datos editados desde el formulario
            QStringList pagoEditado = form->getDatosPago();
            mainWindow->pagosCuotas.replace(indice, pagoEditado);
            guardarArchivo();
            limpiar();
        }
    }
    else
    {
        QMessageBox::warning(this, "Advertencia", "Primero debe seleccionar el pago que desea modificar.");
        return;
    }

    form->deleteLater();
}

//obtener el indice en el vector de acuredo al idPago
int VentanaPagosCuotas::buscarIndexPorIdPago(QString &id)
{
    for (int i = 0; i < mainWindow->pagosCuotas.size(); ++i)
    {
        if (mainWindow->pagosCuotas[i][0] == id)
        {
            return i;
        }
    }
    return -1;
}

//Limpiar filtros y actualizar tabla
void VentanaPagosCuotas::limpiar()
{
    ui->txtBuscar->clear();
    ui->rbDniSocio->setChecked(true);
    actualizarTabla(mainWindow->pagosCuotas);
    ui->txtBuscar->setFocus();
}

//Cierra la ventana
void VentanaPagosCuotas::on_cerrar()
{
    this->close();
}

//Método para eliminar un pago
void VentanaPagosCuotas::on_eliminar()
{
    //obtener fila
    int indice = ui->tbPagos->currentRow();

    //Validar que se haya seleccionado una fila
    if (indice < 0)
    {
        QMessageBox::warning(this, "Advertencia", "Primero debe seleccionar el pago que desea eliminar.");
        return;
    }

    //obtener idPago de la fila seleccionada
    QString idPago = ui->tbPagos->item(indice, 0)->text();

    //se obtiene el índice del registro en el vector global
    indice = buscarIndexPorIdPago(idPago);

    //Mostrar mensaje de confirmación para eliminar
    QString mensaje = "¿Desea eliminar el pago con Id Pago: " + idPago + " ?";
    QMessageBox::StandardButton advertencia;
    advertencia = QMessageBox::critical(this, "Confirmar Eliminación", mensaje, QMessageBox::Yes|QMessageBox::No);

    //Si confirma se elimina el pago
    if (advertencia == QMessageBox::Yes)
    {
        mainWindow->pagosCuotas.remove(indice);
        guardarArchivo();
        limpiar();
    }
}

void VentanaPagosCuotas::buscar()
{
    //obtener el estado de los radio buttons
    bool porIdPago = ui->rbIdPago->isChecked();
    bool porDniUsuario = ui->rbDniUsuario->isChecked();
    bool porDniSocio = ui->rbDniSocio->isChecked();

    //obtener el texto a buscar
    QString buscar = ui->txtBuscar->text();

    //Buscar de acuerdo al filtro seleccionado
    if (porIdPago)
    {
        buscarPorFiltro(buscar, 0);
    }
    else if (porDniUsuario)
    {
        buscarPorFiltro(buscar, 1);
    }
    else if (porDniSocio)
    {
        buscarPorFiltro(buscar, 2);
    }
}

void VentanaPagosCuotas::buscarPorFiltro(QString &buscar, int columna)
{
    //vector para guardar resultado de busqueda
    QVector<QStringList> resultado;

    //Si buscar está vacío muestro vector original
    if (buscar.size() == 0)
    {
        actualizarTabla(mainWindow->pagosCuotas);
    }
    else
    {
        //Se recorre vector original y se busca el texto en la columna indicada
        for (int i = 0; i < mainWindow->pagosCuotas.size(); ++i)
        {
            if (mainWindow->pagosCuotas[i][columna].startsWith(buscar, Qt::CaseInsensitive))
            {
                //Si se encuentra coincidencia se agega al vector resultado
                resultado.append(mainWindow->pagosCuotas[i]);
            }
        }

        //Cuando termina se actualiza la tabla
        actualizarTabla(resultado);
    }
}

//Método para verificar si hay socios con cuotas retrasadas
void VentanaPagosCuotas::verficarPagos()
{

}
