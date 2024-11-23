#include <claseprestamo.h>

clasePrestamo::clasePrestamo(const int& idPrestamo, const int& cantidad,
                             const QDate& fechaPrestamo, const QDate& fechaDevolucion,
                             Usuario* usuario)
    : idPrestamo(idPrestamo), cantidad(cantidad),
    fechaPrestamo(fechaPrestamo), fechaDevolucion(fechaDevolucion), usuario(usuario) {}


clasePrestamo::~clasePrestamo() {}


// Getters
int clasePrestamo::getIdPrestamo() const{
    return idPrestamo;
}

int clasePrestamo::getCantidad() const{
    return cantidad;
}

QDate clasePrestamo::getFechaPrestamo() const{
    return fechaPrestamo;
}

QDate clasePrestamo::getFechaDevolucion() const{
    return fechaDevolucion;
}

/*
libro clasePrestamo::getlibro() const{
    return libro;
}


Socio clasePrestamo::getsocio(){
    return socio;
}*/

Usuario *clasePrestamo::getUsuario() const{
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

