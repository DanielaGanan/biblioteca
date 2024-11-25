#ifndef AGREGARPRESTAMO_H
#define AGREGARPRESTAMO_H

#include <QDialog>
#include <libro.h>
#include <socio.h>
#include <usuario.h>
#include "QMessageBox"
#include "QLineEdit"
#include "QDate"
#include "QDebug"
#include <mainwindow.h>
#include "claseprestamo.h"



namespace Ui {
class agregarPrestamo;
}

class agregarPrestamo : public QDialog
{
    Q_OBJECT

public:
    explicit agregarPrestamo(QWidget *parent = nullptr);
    ~agregarPrestamo();


    QStringList getPrestamo() const;

   /* void setPrestamoEditar(int idPrestamo, int cantidad, libro* libro, Socio* socio,
                           Usuario* usuario,
                           const QDate& fechaPrestamo,
                           const QDate& fechaDevolucion);*/

    void setPrestamoEditar(QStringList prestamo);

    int validarNumero(QLineEdit* num);
    void llenarComboBox(QVector<QStringList> lista);
    void llenarComboBoxUsuario(const QVector<QStringList>& usuarios);
    void llenarComboBoxSocio(const QVector<QStringList>& socios);
    void llenarComboBoxLibros(const QList<libro>& libros);


public slots:
    void on_aceptar();

private:
    Ui::agregarPrestamo *ui;
    clasePrestamo clasePrestamos;
    Usuario* usuario;
    Socio* socio;
    // Libro libro;
    MainWindow *mainWindow;

};

#endif // AGREGARPRESTAMO_H
