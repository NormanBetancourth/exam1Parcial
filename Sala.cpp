//
// Created by norma on 2/5/2021.
//

#include "Sala.h"

Sala::Sala(string tipo, string id, string nombre, Matrix *M) {
    this->id=id;
    this->tipo=tipo;
    this->nombre=nombre;
    this->M=M;
    M->setId(getId());
}

Sala::~Sala() {
    delete M;
}

const string &Sala::getTipo() const {
    return tipo;
}

const string &Sala::getId() const {
    return id;
}

const string &Sala::getNombre() const {
    return nombre;
}

Matrix *Sala::getM() const {
    return M;
}

void Sala::setTipo(const string &tipo) {
    Sala::tipo = tipo;
}

void Sala::setId(const string &id) {
    Sala::id = id;
}

void Sala::setNombre(const string &nombre) {
    Sala::nombre = nombre;
}

void Sala::setM(Matrix *m) {
    M = m;
}

string Sala::tostring() {
    stringstream  s;
    s<<"Sala: "<<getNombre()<<"\t\n";
    s<<"Id: "<<getId()<<"\t\n";
    s<<"Tipo: "<<getTipo()<<"\t\n";
    return s.str();
}

string Sala::tostringCompleto() {
    stringstream  s;
    s<<"Sala: "<<getNombre()<<"\t\n";
    s<<"Id: "<<getId()<<"\t\n";
    s<<"Tipo: "<<getTipo()<<"\t\n";
    if (M!= nullptr){
        s<<M->tostring();
    }
    return s.str();
}

string Sala::tostringSilla() {
    return M->tostring();
}
