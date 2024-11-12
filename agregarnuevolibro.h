#ifndef AGREGARNUEVOLIBRO_H
#define AGREGARNUEVOLIBRO_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class agregarNuevoLibro;
}

class agregarNuevoLibro : public QDialog
{
    Q_OBJECT

public:
    explicit agregarNuevoLibro(QWidget *parent = nullptr);
    ~agregarNuevoLibro();

    QString getTitulo() const;
    QString getAutor() const;
    QString getEditorial() const;
    int getAño() const;
    int getStock() const;

    void cargarDatos(const QString &titulo, const QString &autor, const QString &editorial, int año, int stock);

private slots:
    void on_botonAceptar_clicked();
    void on_botonCancelar_clicked();

private:
    Ui::agregarNuevoLibro *ui;
};

#endif // AGREGARNUEVOLIBRO_H
