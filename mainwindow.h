#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <libro.h>
#include <tablalibros.h>
#include <agregarnuevolibro.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Abrir ventana de libros
    void on_abrirVentanaLibros_clicked();
    void on_abrirVentanaUsuarios_clicked();
    void on_abrirVentanaPrestamos_clicked();
    void on_abrirVentanaDevoluciones_clicked();
    void on_abrirVentanaPagos_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
