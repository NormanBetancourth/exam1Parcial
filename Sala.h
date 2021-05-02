//
// Created by norma on 2/5/2021.
//

#ifndef EXAM_IPARCIAL_SALA_H
#define EXAM_IPARCIAL_SALA_H
#include <iostream>
#include <sstream>
#include <fstream>
#include "Matrix.h"

using namespace std;

class Sala {
private:
    string tipo;
    string id;
    string nombre;
    Matrix* M;
public:
    Sala(string tipo="indef", string id="indef", string nombre="indef", Matrix* M= nullptr);
    ~Sala();

    //gets
    const string &getTipo() const;
    const string &getId() const;
    const string &getNombre() const;

    Matrix *getM() const;
    //sets
    void setTipo(const string &tipo);
    void setId(const string &id);
    void setNombre(const string &nombre);
    void setM(Matrix *m);

    string tostring();

    string tostringCompleto();
    string tostringSilla();

};


#endif //EXAM_IPARCIAL_SALA_H
