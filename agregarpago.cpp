#include "agregarpago.h"
#include "ui_agregarpago.h"
#include <QMessageBox>
#include <QDate>
#include "selectsocio.h"

agregarPago::agregarPago(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::agregarPago)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &agregarPago::on_aceptar);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &agregarPago::reject);
    connect(ui->btnSelectSocio, &QPushButton::clicked, this, &agregarPago::on_selectSocio);
}

agregarPago::~agregarPago()
{
    delete ui;
}

void agregarPago::on_aceptar()
{
    bool condicion = ui->txtDniUsuario->text().isEmpty() ||
                     ui->txtNombreUsuario->text().isEmpty() ||
                     ui->txtApellidoUsuario->text().isEmpty() ||
                     ui->txtDniSocio->text().isEmpty() ||
                     ui->txtNombreSocio->text().isEmpty() ||
                     ui->txtApellidoSocio->text().isEmpty() ||
                     ui->sbIdPago->value() <= 0 ||
                     ui->sbMonto->value() <= 0;

    if (condicion)
    {
        QMessageBox::warning(this, "Advertencia", "Debe completar todos los datos.");
        reject();
        return;
    }
    else
    {
        pago.setIdPago(ui->sbIdPago->value());
        qDebug() << pago.getIdPago();
        pago.setDniUsuario(ui->txtDniUsuario->text().toInt());
        qDebug() << pago.getDniUsuario();
        pago.setDniSocio(ui->txtDniSocio->text().toInt());
        qDebug() << pago.getDniSocio();
        pago.setMonto(ui->sbMonto->value());
        qDebug() << pago.getMonto();
        pago.setFechaPago(ui->dtFechaPago->date());
        qDebug() << pago.getFechaPago();
        pago.setFechaRegistro(QDate::currentDate());
        qDebug() << pago.getFechaRegistro();

        accept();
    }
}

QStringList agregarPago::getDatosPago() const
{
    QStringList datosPago;

    datosPago.append({QString::number(this->pago.getIdPago()),
                      QString::number(this->pago.getDniUsuario()),
                      QString::number(this->pago.getDniSocio()),
                      QString::number(this->pago.getMonto()),
                      this->pago.getFechaPago().toString("dd/MM/yyyy"),
                      this->pago.getFechaRegistro().toString("dd/MM/yyyy")});

    return datosPago;
}

void agregarPago::setNuevoId(int &id)
{
    ui->sbIdPago->setValue(id);
    ui->dtFechaPago->setDate(QDate::currentDate());
}

void agregarPago::setSocios(QVector<QStringList> &socios)
{
    this->socios = socios;
}

void agregarPago::setUsuario(QStringList &usuario)
{
    ui->txtDniUsuario->setText(usuario[2]);
    ui->txtNombreUsuario->setText(usuario[0]);
    ui->txtApellidoUsuario->setText(usuario[1]);
}

void agregarPago::on_btnBuscarDni_clicked()
{
    if (ui->txtDniSocio->text().isEmpty())
    {
        QMessageBox::warning(this, "Advertencia", "Primero debe completar el campo DNI");
        ui->txtDniSocio->setFocus();
        return;
    }

    QString dni = ui->txtDniSocio->text();
    QStringList socio;

    for (int fila = 0; fila < this->socios.size(); ++fila)
    {
        if (this->socios[fila][2] == dni)
        {
            socio.append(this->socios[fila]);
        }
    }

    if (socio.size() == 0)
    {
        QString mensaje = "El socio con DNI " + dni + " no existe";
        QMessageBox::warning(this, "Advertencia", mensaje);
        ui->txtDniSocio->clear();
        ui->txtDniSocio->setFocus();
        return;
    }

    ui->txtNombreSocio->setText(socio[0]);
    ui->txtApellidoSocio->setText(socio[1]);
}

void agregarPago::setPagoEditar(QStringList &pago)
{
    ui->txtDniSocio->setText(pago[2]);
    ui->sbIdPago->setValue(pago[0].toInt());
    ui->sbMonto->setValue(pago[3].toDouble());
    qDebug() << pago[4];
    ui->dtFechaPago->setDate(QDate::fromString(pago[4], "dd/MM/yyyy"));
}

void agregarPago::on_selectSocio()
{
    SelectSocio *form = new SelectSocio;

    form->setSocios(socios);

    if (form->exec() == QDialog::Accepted)
    {
        QStringList nuevoSocio = form->getSocio();
        ui->txtDniSocio->setText(nuevoSocio[2]);
        ui->txtNombreSocio->setText(nuevoSocio[0]);
        ui->txtApellidoSocio->setText(nuevoSocio[1]);
    }

    form->deleteLater();
}
