//
// Created by norma on 2/5/2021.
//

#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int annio) {
    this->dia=dia;
    this->mes=mes;
    this->annio=annio;
}

Fecha::~Fecha() {
}

int Fecha::getDia() const {
    return dia;
}

int Fecha::getMes() const {
    return mes;
}

int Fecha::getAnnio() const {
    return annio;
}

void Fecha::setDia(int dia) {
    Fecha::dia = dia;
}

void Fecha::setMes(int mes) {
    Fecha::mes = mes;
}

void Fecha::setAnnio(int annio) {
    Fecha::annio = annio;
}

string Fecha::toString() {
    stringstream  s;
    s<<"("<<getDia()<<"/"<<getMes()<<"/"<<getAnnio()<<")";
    return s.str();
}
