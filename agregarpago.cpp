#include "agregarpago.h"
#include "ui_agregarpago.h"
#include <QMessageBox>

agregarPago::agregarPago(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::agregarPago)
{
    ui->setupUi(this);
    ui->dtFechaPago->setDate(QDate::currentDate());
}

agregarPago::~agregarPago()
{
    delete ui;
}

void agregarPago::on_buttonBox_accepted()
{
    bool condicion = false; /*ui->txtDniUsuario->text().isEmpty() ||
                     ui->txtDniSocio->text().isEmpty() ||
                     ui->sbIdPago->text().isEmpty() ||
                     ui->sbMonto->text().isEmpty();*/

    if (condicion)
    {
        QMessageBox::warning(this, "Advertencia", "Debe completar todos los datos.");
        reject();
        return;
    }
    else
    {
        pago->setDniUsuario(ui->txtDniUsuario->text().toInt());
        pago->setDniSocio(ui->txtDniSocio->text().toInt());
        pago->setIdPago(ui->sbIdPago->value());
        pago->setFechaPago(ui->dtFechaPago->date());

        accept();
    }
}

QStringList agregarPago::getDatosPago() const
{
    QStringList datosPago;

    datosPago.append({QString::number(this->pago->getIdPago()),
                      QString::number(this->pago->getDniUsuario()),
                      QString::number(this->pago->getDniSocio()),
                      QString::number(this->pago->getMonto()),
                      this->pago->getFechaPago().toString(),
                      this->pago->getFechaRegistro().toString()});

    return datosPago;
}

void agregarPago::setDatosPago(QStringList &datosPago)
{
    ui->txtDniUsuario->setText(datosPago[0]);
    ui->txtNombreUsuario->setText(datosPago[1]);
    ui->txtApellidoUsuario->setText(datosPago[2]);
    ui->txtDniSocio->setText(datosPago[3]);
    ui->txtNombreSocio->setText(datosPago[4]);
    ui->txtApellidoSocio->setText(datosPago[5]);
    ui->sbIdPago->setValue(datosPago[6].toInt());
    ui->sbMonto->setValue(datosPago[7].toDouble());
    ui->dtFechaPago->setDate(QDate::fromString(datosPago[8]));
}

void agregarPago::setNuevoId(int &id)
{
    ui->sbIdPago->setValue(id);
}

void agregarPago::setSocios(QVector<QStringList> &socios)
{
    this->socios = socios;
    qDebug() << this->socios.size();
    qDebug() << socios.size();
}

void agregarPago::on_pushButton_clicked()
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

