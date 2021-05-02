//
// Created by norma on 2/5/2021.
//

#ifndef EXAM_IPARCIAL_MENUMANTENIMIENTO_H
#define EXAM_IPARCIAL_MENUMANTENIMIENTO_H
#include "Funcion.h"
#include "Lista.cpp"

class MenuMantenimiento {

public:
    MenuMantenimiento();
    ~MenuMantenimiento();

    void opcion1(Lista<Funcion>*);//add sala a una funcion
    void opcion2(Lista<Funcion>*);//add peli a funcion
    string opcion3(Lista<Funcion>*);//add nueva funcion

};


#endif //EXAM_IPARCIAL_MENUMANTENIMIENTO_H
