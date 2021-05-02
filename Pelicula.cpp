//
// Created by norma on 2/5/2021.
//

#include "Pelicula.h"

Pelicula::Pelicula(string id, string nombre, float precio) {
    this->id=id;
    this->nombre=nombre;
    this->precio=precio;

}

Pelicula::~Pelicula() {
}

void Pelicula::setId(const string &id) {
    Pelicula::id = id;
}

void Pelicula::setNombre(const string &nombre) {
    Pelicula::nombre = nombre;
}

void Pelicula::setPrecio(float precio) {
    Pelicula::precio = precio;
}

const string &Pelicula::getId() const {
    return id;
}

const string &Pelicula::getNombre() const {
    return nombre;
}

float Pelicula::getPrecio() const {
    return precio;
}

string Pelicula::toString() {
    stringstream s;
    s<<"Pelicula"<<endl;
    s<<"ID: "<<getId()<<endl;
    s<<"Nombre: "<<getNombre()<<endl;
    s<<"Precio: "<<getPrecio()<<endl;
    return  s.str();
}
