#ifndef SELECTSOCIO_H
#define SELECTSOCIO_H

#include <QDialog>

namespace Ui {
class SelectSocio;
}

class SelectSocio : public QDialog
{
    Q_OBJECT

public:
    explicit SelectSocio(QWidget *parent = nullptr);
    ~SelectSocio();

    void setSocios(QVector<QStringList> &socios);
    void setId(int &id);
    QStringList getSocio();
    void buscar();
    void actualizarTabla(QVector<QStringList> &socios);

private slots:
    void on_aceptar();

private:
    Ui::SelectSocio *ui;
    QVector<QStringList> socios;
    QVector<QStringList> resultado;
    int id;
};

#endif // SELECTSOCIO_H
