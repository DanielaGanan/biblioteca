#ifndef SOCIO_H
#define SOCIO_H

#include <persona.h>
//#include "qwidget.h"

class Socio

{

public:
    explicit Socio();
    ~Socio();

private slots:
    bool consultarEstado();

private:
    //Ui::Socio *ui;
    Persona persona; // Composición para tener disponibles los métodos de Persona
    int idSocio;
    bool estado;

    //Getters
    int getIdSocio() const;
    bool getEstado() const;

    //Setters
    void setIdSocio(const int idSocio);
    void setEstado(const bool estado);
};

#endif // SOCIO_H
