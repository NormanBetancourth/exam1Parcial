//
// Created by norma on 2/5/2021.
//

#include "Funcion.h"



Funcion::~Funcion() {
    delete sala;
    delete peli;
    delete fecha;
}

Funcion::Funcion(Pelicula *p, Sala *s, Fecha *f, int asientos) {
    sala=s;
    peli=p;
    asientosVendidos=asientos;
    fecha=f;
}

string Funcion::toString() {
    stringstream s;
    s<<"Funcion"<<endl;
    s<<peli->toString()<<endl;
    s<<sala->tostring()<<endl;
    return s.str();
}

Pelicula *Funcion::getPeli() const {
    return peli;
}

int Funcion::getAsientosVendidos() const {
    return asientosVendidos;
}

Sala *Funcion::getSala() const {
    return sala;
}

Fecha *Funcion::getFecha() const {
    return fecha;
}

void Funcion::setPeli(Pelicula *peli) {
    Funcion::peli = peli;
}

void Funcion::setAsientosVendidos(int asientosVendidos) {
    Funcion::asientosVendidos = asientosVendidos;
}

void Funcion::setSala(Sala *sala) {
    Funcion::sala = sala;
}

void Funcion::setFecha(Fecha *fecha) {
    Funcion::fecha = fecha;
}
