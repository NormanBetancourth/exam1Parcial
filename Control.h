//
// Created by norma on 2/5/2021.
//

#ifndef EXAM_IPARCIAL_CONTROL_H
#define EXAM_IPARCIAL_CONTROL_H
#include "MenuMantenimiento.h"
#include "MenuAdmin.h"
#include "MenuVentas.h"

class Control {
private:
    Lista<Funcion>* lista;
    MenuMantenimiento* mMant;
    MenuAdmin* mAdmin;
    MenuVentas* mVentas;
public:
    Control();
    ~Control();

    //gets
    MenuMantenimiento *getMMant() const;
    MenuAdmin *getMAdmin() const;
    MenuVentas *getMVentas() const;

    //sets
    void setMMant(MenuMantenimiento *mMant);
    void setMAdmin(MenuAdmin *mAdmin);
    void setMVentas(MenuVentas *mVentas);

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
