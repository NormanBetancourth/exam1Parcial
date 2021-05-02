//
// Created by norma on 2/5/2021.
//

#include "Asiento.h"

Asiento::~Asiento() {
}

Asiento::Asiento(int id, string estado) {
    this->estado=estado;
    this->id=id;
}

const int &Asiento::getId() const {
    return id;
}

const string &Asiento::getEstado() const {
    return estado;
}

void Asiento::setId(const int &id) {
    Asiento::id = id;
}
void Asiento::setEstado(const string &estado) {
    Asiento::estado = estado;
}

string Asiento::toString() {
    stringstream s;
    s<<"Id: "<<getId()<<",";
    s<<"Estado: "<<getEstado()<<',';
    return  s.str();
}
