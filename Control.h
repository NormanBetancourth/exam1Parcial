//
// Created by norma on 2/5/2021.
//

#ifndef EXAM_IPARCIAL_CONTROL_H
#define EXAM_IPARCIAL_CONTROL_H
#include "Lista.cpp"
#include "Funcion.h"

class Control {
private:
    Lista<Funcion>* lista;

public:
    Control();
    ~Control();



    Lista<Funcion> *getLista() const;
    void setLista(Lista<Funcion> *lista);

    void Menu();
    void opcion_1_1();
    void opcion_1_2();
    void opcion_1_3();

    void opcion_2_1();
    void opcion_2_2();
    void opcion_2_3();
    void opcion_2_4();

    void opcion_3_1();
    void opcion_3_2();
    void opcion_3_3();
    void opcion_3_4();


    void subMantenimiento();
    void subVentas();
    void subAdmin();


};


#endif //EXAM_IPARCIAL_CONTROL_H
