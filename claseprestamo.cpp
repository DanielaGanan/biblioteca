#include <claseprestamo.h>
/*
clasePrestamo::clasePrestamo(const int& idPrestamo,
                             const int& cantidad,
                             const QDate& fechaPrestamo,
                             const QDate& fechaDevolucion,
                             Usuario* usuario,
                             Socio* socio)
    : idPrestamo(idPrestamo), cantidad(cantidad),
    fechaPrestamo(fechaPrestamo), fechaDevolucion(fechaDevolucion), usuario(usuario),
    socio(socio) {}
*/

clasePrestamo::clasePrestamo(const int& idPrestamo,
                             const int& cantidad,
                             const QString& libro,
                             const QString& socio,
                             const QString& usuario,
                             const QDate& fechaPrestamo,
                             const QDate& fechaDevolucion)
    : idPrestamo(idPrestamo), cantidad(cantidad),
        libro(libro), socio(socio), usuario(usuario),
        fechaPrestamo(fechaPrestamo), fechaDevolucion(fechaDevolucion) {}

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


QString clasePrestamo::getlibro() const{
    return libro;
}


QString clasePrestamo::getsocio() const{
    return socio;
}

QString clasePrestamo::getUsuario() const{
    return usuario;
}

QVector<QStringList> clasePrestamo::getClasePrestamo() const {
    return Prestamos;
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

void clasePrestamo::setlibro(QString nuevolibro){
    this->libro = nuevolibro;
}


void clasePrestamo::setsocio(QString nuevoSocio){
    this->socio = nuevoSocio;
}

void clasePrestamo::setUsuario(QString nuevoUsuario){
    this->usuario = nuevoUsuario;
}

