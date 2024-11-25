#include "ventanasocios.h"
#include "ui_ventanasocios.h"
#include "archivo.h"
#include "mainwindow.h"
#include "agregarsocio.h"

VentanaSocios::VentanaSocios(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VentanaSocios)
{
    ui->setupUi(this);

    //Setear el titulo de la ventana
    this->setWindowTitle("Administrar Socios");

    //Setear las propiedades de la tabla
    ui->tbSocios->setColumnCount(6);
    ui->tbSocios->setHorizontalHeaderLabels({"Nombre", "Apellido", "DNI",
                                             "Dirección", "Telefono", "Estado"});
    ui->tbSocios->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tbSocios->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Conectar metodos con botones o acciones
    connect(ui->btnAgregar, &QPushButton::clicked, this, &VentanaSocios::on_agregar);
    connect(ui->btnModificar, &QPushButton::clicked, this, &VentanaSocios::on_modificar);
    connect(ui->btnEliminar, &QPushButton::clicked, this, &VentanaSocios::on_eliminar);
    connect(ui->btnCerrar, &QPushButton::clicked, this, &VentanaSocios::on_cerrar);
    connect(ui->btnLimpiar, &QPushButton::clicked, this, &VentanaSocios::limpiar);
    connect(ui->txtBuscar, &QLineEdit::textChanged, this, &VentanaSocios::buscar);
}

VentanaSocios::~VentanaSocios()
{
    delete ui;
}

//Método para agegar un nuevo socio
void VentanaSocios::on_agregar()
{
    //Instancia de un nuevo formulario para agregar socio
    AgregarSocio *form = new AgregarSocio;
    form->setWindowTitle("Agregar Nuevo Socio");

    //Verificar que se aceptó el formulario
    if (form->exec() == QDialog::Accepted)
    {
        //Obtengo los datos pasados por el formulario
        QStringList nuevoSocio = form->getSocio();

        //Valida si el DNI del nuevo socio ya existe
        if (validarSiExisteDni(nuevoSocio[2]))
        {
            QMessageBox::warning(this, "Usuario Existente", "El usuario que intenta agregar ya existe");
            form->deleteLater();
            return;
        }

        //Agregar el nuevo socio al vector y mostrarlo
        mainWindow->socios.append(nuevoSocio);
        actualizarTabla(mainWindow->socios);
        guardarArchivo();
    }

    form->deleteLater();
}

//Método para modificar un socio existente
void VentanaSocios::on_modificar()
{
    //Instancia de un nuevo formulario para modificar un socio
    AgregarSocio *form = new AgregarSocio;
    form->setWindowTitle("Modificar Socio");

    //Obtengo el índice de la fila de la tabla
    int indice = ui->tbSocios->currentRow();

    //Si se intenta modificar sin seleccionar un socio muestra mensaje
    if (indice >= 0)
    {
        //Con el indice de la tabla actual busco el dni
        QString dni = ui->tbSocios->item(indice, 2)->text();

        //Con el dni busco el indice en el vector original
        indice = buscarIndexPorDni(dni);

        //Obtengo todos los datos y los paso al formulario
        QStringList socio = mainWindow->socios[indice];
        form->setSocioEditar(socio);

        //Verificar que se aceptó el formulario
        if (form->exec() == QDialog::Accepted)
        {
            //Gurado los datos editados desde el formulario
            QStringList nuevoSocio = form->getSocio();
            mainWindow->socios.replace(indice, nuevoSocio);
            guardarArchivo();
            limpiar();
        }
    }
    else
    {
        QMessageBox::warning(this, "Advertencia", "Primero debe seleccionar el socio que desea modificar.", QMessageBox::Ok);
        return;
    }

    form->deleteLater();
}

//Método para eliminar un socio
void VentanaSocios::on_eliminar()
{
    //Obtengo el índice de la fila de la tabla actual
    int indice = ui->tbSocios->currentRow();

    //Si se intenta eliminar sin seleccionar un socio muestra mensaje
    if (indice >= 0)
    {
        //Con el indice de la tabla actual busco el dni
        QString dni = ui->tbSocios->item(indice, 2)->text();

        //Con el dni busco el indice en el vector original
        indice = buscarIndexPorDni(dni);

        //Definir el mensaje que se mostrará
        QString Mensaje = "¿Desea eliminar el socio con DNI " + dni + "?";
        QMessageBox::StandardButton advertencia;
        advertencia = QMessageBox::critical(this, "Confirmar Eliminación", Mensaje, QMessageBox::Yes|QMessageBox::No);

        //Si confirma se elimina el socio
        if (advertencia == QMessageBox::Yes)
        {
            mainWindow->socios.remove(indice);
            guardarArchivo();
            limpiar();
        }
    }
    else
    {
        QMessageBox::warning(this, "Advertencia", "Primero debe seleccionar el socio que desea eliminar.", QMessageBox::Ok);
        return;
    }
}

//Método para cerrar la ventana
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

//Método para guardar el archivo
void VentanaSocios::guardarArchivo()
{
    Archivo *archivo = new Archivo("socios.csv");

    if (!archivo->guardarArchivo(mainWindow->socios))
    {
        QMessageBox::critical(this, "Error", "No se pudo guardar el archivo");
    }
}

//Método para cargar datos en la tabla
void VentanaSocios::actualizarTabla(QVector<QStringList> datos)
{
    QTableWidget *tabla = ui->tbSocios;
    tabla->setRowCount(datos.size());

    for (int fila = 0; fila < datos.size(); ++fila)
    {
        for (int columna = 0; columna < datos[fila].size(); ++columna)
        {
            tabla->setItem(fila, columna, new QTableWidgetItem(datos[fila][columna]));
        }
    }

}

//Método para validar existe el dni
bool VentanaSocios::validarSiExisteDni(QString nuevoDni)
{
    //Obtengo los socios existentes
    QVector<QStringList> socios;
    socios.append(mainWindow->socios);

    //Recorrer el DNI de los socios existentes y compara con el nuevo DNI
    for (int i = 0; i < socios.length(); i++)
    {
        //Si el DNI del socio ya existe se muestra mensaje
        if (socios[i][2] == nuevoDni)
        {
            return true;
        }
    }

    return false;
}

//Métdos de búsqueda
void VentanaSocios::buscar()
{
    //Obtener el estado de los radio buttons
    bool porNombre = ui->rbNombre->isChecked();
    bool porApellido = ui->rbApellido->isChecked();
    bool porDni = ui->rbDni->isChecked();
    bool porEstado = ui->rbEstado->isChecked();

    //Obtener el texto a buscar
    QString texto = ui->txtBuscar->text();

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
    else if (porEstado)
    {
        buscarPorFiltro(texto, 5);
    }
}

//Métodos de búsqueda por filtro
void VentanaSocios::buscarPorFiltro(QString &texto, int columna)
{
    QVector<QStringList> resultado;

    if (texto.size() == 0)
    {
        actualizarTabla(mainWindow->socios);
    }
    else
    {
        for (int i = 0; i < mainWindow->socios.size(); ++i)
        {
            if (mainWindow->socios[i][columna].startsWith(texto, Qt::CaseInsensitive))
            {
                resultado.append(mainWindow->socios[i]);
            }
        }
        actualizarTabla(resultado);
    }
}

//Retorna el indice del vector original buscando con el dni
int VentanaSocios::buscarIndexPorDni(QString &dni)
{
    for (int i = 0; i < mainWindow->socios.size(); ++i)
    {
        if (mainWindow->socios[i][2] == dni)
        {
            return i;
        }
    }
    return -1;
}

//Limpiar filtros
void VentanaSocios::limpiar()
{
    ui->txtBuscar->clear();
    ui->rbNombre->setChecked(true);
    actualizarTabla(mainWindow->socios);
    ui->txtBuscar->setFocus();
}

void VentanaSocios::setVentanaMainWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
}
