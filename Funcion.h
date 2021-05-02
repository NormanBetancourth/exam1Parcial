//
// Created by norma on 2/5/2021.
//

#ifndef EXAM_IPARCIAL_FUNCION_H
#define EXAM_IPARCIAL_FUNCION_H
#include "Sala.h"
#include "Pelicula.h"
#include "Fecha.h"

class Funcion {
private:
    Pelicula* peli;
    int asientosVendidos;
    Sala* sala;
    Fecha* fecha;
public:
    Pelicula *getPeli() const;

    void setPeli(Pelicula *peli);

    void setAsientosVendidos(int asientosVendidos);

    void setSala(Sala *sala);

    void setFecha(Fecha *fecha);

    int getAsientosVendidos() const;

    Sala *getSala() const;

    Fecha *getFecha() const;

    Funcion(Pelicula* p= nullptr, Sala* s= nullptr,Fecha* f= nullptr,int asientos=0 );
    ~Funcion();
    string toString();
    string toStringCompleto();
    bool Buscado(string x);
    bool busquedaFecha(int, int,int);
    string verAsientos();
    float recaudado();
};


#endif //EXAM_IPARCIAL_FUNCION_H
