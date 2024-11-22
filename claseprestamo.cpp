#include "claseprestamo.h"


clasePrestamo::clasePrestamo(int idPrestamo, int cantidad, const QDate& fechaPrestamo,
                             const QDate& fechaDevolucion, Usuario* usuario)
            : idPrestamo(idPrestamo), cantidad(cantidad), fechaPrestamo(fechaPrestamo),
            fechaDevolucion(fechaDevolucion), usuario(usuario) {}


clasePrestamo::~clasePrestamo() {}


// Getters
int clasePrestamo::getIdPrestamo(){
    return idPrestamo;
}

int clasePrestamo::getCantidad(){
    return cantidad;
}

QDate clasePrestamo::getFechaPrestamo(){
    return fechaPrestamo;
}

QDate clasePrestamo::getFechaDevolucion(){
    return fechaDevolucion;
}

/*
libro clasePrestamo::getlibro(){
    return libro;
}

Socio clasePrestamo::getsocio(){
    return socio;
}*/

Usuario* clasePrestamo::getUsuario(){
    return usuario;
}

// Setters
void clasePrestamo::setIdPrestamo(int nuevoidPrestamo){
    this->idPrestamo = nuevoidPrestamo;
}

void clasePrestamo::setCantidad(int nuevaCantidad){
    this->cantidad = nuevaCantidad;
}

void clasePrestamo::setFechaPrestamo(const QDate& nuevaFechaPrestamo){
    this->fechaPrestamo = nuevaFechaPrestamo;
}

void clasePrestamo::setFechaDevolucion(const QDate& nuevaFechaDevolucion){
    this->fechaDevolucion = nuevaFechaDevolucion;
}
/*
void clasePrestamo::setlibro(libro* nuevolibro){
    this->libro = nuevolibro;
}

void clasePrestamo::setsocio(Socio* nuevoSocio){
    this->socio = nuevoSocio;
}*/

void clasePrestamo::setUsuario(Usuario* nuevoUsuario){
    this->usuario = nuevoUsuario;
}



