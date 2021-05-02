//
// Created by norma on 2/5/2021.
//

#ifndef EXAM_IPARCIAL_MENUVENTAS_H
#define EXAM_IPARCIAL_MENUVENTAS_H
#include "Lista.cpp"
#include "Funcion.h"


class MenuVentas {
    Lista<Funcion> * lista;
public:
    MenuVentas(Lista<Funcion>*);
    ~MenuVentas();

    string opcion1();//mostrar funciones para una fecha
    string opcion2();//mostrar asientos que hay enn una funcion
    string opcion3();//escoger funcion
    string opcion4();//venta de asientos por funcion
};


#endif //EXAM_IPARCIAL_MENUVENTAS_H
