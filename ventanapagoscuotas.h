#ifndef VENTANAPAGOSCUOTAS_H
#define VENTANAPAGOSCUOTAS_H

#include <QWidget>
#include <QTableWidget>
#include "pagoscuotas.h"

class MainWindow;

namespace Ui {
class VentanaPagosCuotas;
}

class VentanaPagosCuotas : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaPagosCuotas(QWidget *parent = nullptr);
    ~VentanaPagosCuotas();

    void setVentanaMainWindow(MainWindow *mainWindow);

    //Métodos
    void cargarArchivo();
    void guardarArchivo();
    void actualizarTabla(QVector<QStringList> &datos);
    void buscar();
    QStringList buscarSocioDni(QString &dni);
    int obtenerUltimoIdPago();

private slots:
    void on_btnAgregar_clicked();

private:
    Ui::VentanaPagosCuotas *ui;
    PagosCuotas *pagosCuotas;
    MainWindow *mainWindow;
    QTableWidget *tabla;
};

#endif // VENTANAPAGOSCUOTAS_H
