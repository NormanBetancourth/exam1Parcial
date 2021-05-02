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
    s<<"Asientos vendidos: "<<getAsientosVendidos()<<endl;
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

bool Funcion::Buscado(string x) {
    if (x==sala->getId()){
        return true;
    }
    return false;
}

bool Funcion::busquedaFecha(int d, int m, int a) {
    if (d== fecha->getDia() and m== fecha->getMes()and a== fecha->getAnnio() ){
        return true;
    }

}

string Funcion::verAsientos() {
    return sala->tostringSilla();
}

string Funcion::toStringCompleto() {
    return getSala()->tostringCompleto();
}

float Funcion::recaudado() {
    return asientosVendidos * peli->getPrecio();
}

void Funcion::recalcularPrecio() {
    if (sala->getTipo() == "3D"){
        peli->setPrecio(peli->getPrecio() + (peli->getPrecio()* 0.2));
    }
    if (sala->getTipo() == "IMAX3D"){
        peli->setPrecio(peli->getPrecio() + (peli->getPrecio()* 0.5));
    }
    if (sala->getTipo() == "Aire"){
        peli->setPrecio(peli->getPrecio() + (peli->getPrecio()* 0.1));
    }
}

void Funcion::reservarAsientos(int x) {
    getSala()->reservar(x);
}

bool Funcion::espacio(int x) {
    return getSala()->espacio(x);

}

void Funcion::guardar(ofstream &c) {
    //sala
    c << getSala()->getId() << endl
      << getSala()->getTipo() << endl
      << getSala()->getNombre() << endl
      //peli
      <<getPeli()->getId() << endl
      <<getPeli()->getNombre() << endl
      <<getPeli()->getPrecio() << endl
      //fecha
      <<getFecha()->getDia() << endl
      <<getFecha()->getMes() << endl
      <<getFecha()->getAnnio() << endl

      << getAsientosVendidos() << endl;
}

Funcion *Funcion::leer(ifstream & estFile) {
    string IDsala, Tiposala,Nombresala;
    string Idpeli, Nombrepeli,precioPeli;
    string dia, mes,annio,asientos;
    Fecha* fecha1;
    Pelicula* peli;
    Sala* sala1;
    Matrix* m1;


    if (!(estFile>>IDsala)) { return nullptr; }
    if (!(estFile>>Tiposala)) { return nullptr; }
    if (!(estFile>>Nombresala)) { return nullptr; }
    if (!(estFile>>Idpeli)) { return nullptr; }
    if (!(estFile>>Nombrepeli)) { return nullptr; }
    if (!(estFile>>precioPeli)) { return nullptr; }
    if (!(estFile>>dia)) { return nullptr; }
    if (!(estFile>>mes)) { return nullptr; }
    if (!(estFile>>annio)) { return nullptr; }
    if (!(estFile>>asientos)) { return nullptr; }
    sala1= new Sala(Tiposala,IDsala,Nombresala);
    peli= new Pelicula(Idpeli,Nombrepeli, stof(precioPeli));
    fecha1 = new Fecha(stoi(dia),stoi(mes), stoi(annio));
    return new Funcion(peli,sala1,fecha1,stoi(asientos));
}
