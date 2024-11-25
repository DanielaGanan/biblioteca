#include "selectsocio.h"
#include "ui_selectsocio.h"

#include <QMessageBox>

SelectSocio::SelectSocio(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SelectSocio)
{
    ui->setupUi(this);

    //Setear el nombre de la ventana
    this->setWindowTitle("Seleccionar Socio");

    //Setear las propiedades de la tabla
    ui->tbSocios->setColumnCount(3);
    ui->tbSocios->setHorizontalHeaderLabels({"Nombre", "Apellido", "DNI"});
    ui->tbSocios->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tbSocios->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Conectar botones
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SelectSocio::on_aceptar);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &SelectSocio::reject);
    connect(ui->txtBuscar, &QLineEdit::textChanged, this, &SelectSocio::buscar);

}

SelectSocio::~SelectSocio()
{
    delete ui;
}

void SelectSocio::setSocios(QVector<QStringList> &socios)
{
    this->socios = socios;
    this->resultado = socios;
    actualizarTabla(socios);
}

void SelectSocio::actualizarTabla(QVector<QStringList> &socios)
{
    QTableWidget *tabla = ui->tbSocios;
    tabla->setRowCount(socios.size());

    for (int fila = 0; fila < socios.size(); ++fila)
    {
        for (int columna = 0; columna < 3; ++columna)
        {
            tabla->setItem(fila, columna, new QTableWidgetItem(socios[fila][columna]));
        }
    }
}

void SelectSocio::setId(int &id)
{
    this->id = id;
}

QStringList SelectSocio::getSocio()
{
    QStringList socio;

    socio.append({
        resultado[id][0],
        resultado[id][1],
        resultado[id][2]
    });

    return socio;
}

void SelectSocio::on_aceptar()
{
    int id = ui->tbSocios->currentRow();

    if (id < 0)
    {
        QMessageBox::warning(this, "Advertencia", "Debe seleccionar un socio.");
        return;
    }

    setId(id);

    accept();
}

void SelectSocio::buscar()
{
    QString buscar = ui->txtBuscar->text();

    if (buscar.size() == 0)
    {
        actualizarTabla(socios);
        this->resultado = socios;
    }
    else
    {
        resultado.clear();
        for (int i = 0; i < socios.size(); ++i)
        {
            bool condicion = socios[i][0].startsWith(buscar, Qt::CaseInsensitive)
                             || socios[i][1].startsWith(buscar, Qt::CaseInsensitive);
            if (condicion)
            {
                resultado.append(socios[i]);
            }
        }
        actualizarTabla(resultado);
    }
}
