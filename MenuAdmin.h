//
// Created by norma on 2/5/2021.
//

#ifndef EXAM_IPARCIAL_MENUADMIN_H
#define EXAM_IPARCIAL_MENUADMIN_H
#include "Lista.cpp"
#include "Funcion.h"


class MenuAdmin {
    Lista<Funcion> * lista;
public:
    MenuAdmin(Lista<Funcion>*);
    ~MenuAdmin();

    string opcion1();//camb marc lentes
    string opcion2();//recaudacion de 1 funcion
    string opcion3();//recaudacion de 1 dia
    string opcion4();//recaudacion de una fecha a fecha
};


#endif //EXAM_IPARCIAL_MENUADMIN_H
