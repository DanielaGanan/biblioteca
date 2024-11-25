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
    void buscarPorFiltro(QString &buscar, int columna);
    QStringList buscarSocioDni(QString &dni);
    int obtenerUltimoIdPago();
    int buscarIndexPorIdPago(QString &id);
    void limpiar();
    void verficarPagos();

private slots:
    void on_btnAgregar_clicked();
    void on_modificar();
    void on_eliminar();
    void on_cerrar();

private:
    Ui::VentanaPagosCuotas *ui;
    PagosCuotas *pagosCuotas;
    MainWindow *mainWindow;
    QTableWidget *tabla;
};

#endif // VENTANAPAGOSCUOTAS_H
