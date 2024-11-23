#include "agregarsocio.h"
#include "ui_agregarsocio.h"

AgregarSocio::AgregarSocio(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AgregarSocio)
{
    ui->setupUi(this);

    //Conectores de botones
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AgregarSocio::on_aceptar);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &AgregarSocio::reject);
}

AgregarSocio::~AgregarSocio()
{
    delete ui;
}

void AgregarSocio::on_aceptar()
{
    bool condicion = ui->txtNombre->text().isEmpty() ||
                     ui->txtApellido->text().isEmpty() ||
                     ui->txtDni->text().isEmpty() ||
                     ui->txtDireccion->text().isEmpty() ||
                     ui->txtTelefono->text().isEmpty();

    if (condicion)
    {
        QMessageBox::warning(this, "Advertencia", "Debe completar todos los campos.");
        reject();
        return;
    }
    else
    {
        socio.establecerNombre(ui->txtNombre->text());
        socio.establecerApellido(ui->txtApellido->text());
        socio.establecerDni(ui->txtDni->value());
        socio.establecerDireccion(ui->txtDireccion->text());
        socio.establecerTelefono(ui->txtTelefono->text());
        socio.setEstadoSocio(ui->cbxEstado->currentText());

        accept();
    }
}

QStringList AgregarSocio::getSocio() const
{
    QStringList socio;

    socio.append({this->socio.obtenerNombre(),
                  this->socio.obtenerApellido(),
                  QString::number(this->socio.obtenerDni()),
                  this->socio.obtenerDireccion(),
                  this->socio.obtenerTelefono(),
                  this->socio.getEstadoSocio()});

    return socio;
}

void AgregarSocio::setSocioEditar(QStringList socio)
{
    ui->txtNombre->setText(socio[0]);
    ui->txtApellido->setText(socio[1]);
    ui->txtDni->setValue(socio[2].toInt());
    ui->txtDireccion->setText(socio[3]);
    ui->txtTelefono->setText(socio[4]);
    ui->cbxEstado->setCurrentText(socio[5]);
}
