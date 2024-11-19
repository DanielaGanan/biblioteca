#ifndef INICIOSESION_H
#define INICIOSESION_H

#include <QWidget>
#include <ventanausuarios.h>

class MainWindow;

namespace Ui {
class InicioSesion;
}

class InicioSesion : public QWidget
{
    Q_OBJECT

public:
    explicit InicioSesion(QWidget *parent = nullptr);
    ~InicioSesion();
    void setVentanaMainWindow(MainWindow *mainWindow);

private slots:
    void on_iniciarSesion();

private:
    Ui::InicioSesion *ui;
    MainWindow *mainWindow;
};

#endif // INICIOSESION_H
