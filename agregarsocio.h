#ifndef AGREGARSOCIO_H
#define AGREGARSOCIO_H

#include <QDialog>
#include <QMessageBox>
#include "socio.h"

namespace Ui {
class AgregarSocio;
}

class AgregarSocio : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarSocio(QWidget *parent = nullptr);
    ~AgregarSocio();

    QStringList getSocio() const;
    void setSocioEditar(QStringList socio);

private slots:
    void on_aceptar();

private:
    Ui::AgregarSocio *ui;
    Socio socio;
};

#endif // AGREGARSOCIO_H
