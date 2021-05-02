//
// Created by norma on 2/5/2021.
//

#ifndef EXAM_IPARCIAL_FECHA_H
#define EXAM_IPARCIAL_FECHA_H
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Fecha {
private:
    int dia,mes,annio;
public:
    Fecha(int dia=0, int mes=0, int annio=0);
    ~Fecha();

    //gets
    int getDia() const;
    int getMes() const;
    int getAnnio() const;

    //sets
    void setDia(int dia);
    void setMes(int mes);
    void setAnnio(int annio);

    string toString();


};


#endif //EXAM_IPARCIAL_FECHA_H
