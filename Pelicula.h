//
// Created by norma on 2/5/2021.
//

#ifndef EXAM_IPARCIAL_PELICULA_H
#define EXAM_IPARCIAL_PELICULA_H
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Pelicula {
private:
    string id;
    string nombre;
    float precio;
public:
    Pelicula(string id="indef", string nombre="indef", float precio=0);
    ~Pelicula();

    const string &getId() const;
    const string &getNombre() const;
    float getPrecio() const;

    void setId(const string &id);
    void setNombre(const string &nombre);
    void setPrecio(float precio);
    string toString();



};


#endif //EXAM_IPARCIAL_PELICULA_H
