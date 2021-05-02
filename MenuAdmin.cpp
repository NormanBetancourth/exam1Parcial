//
// Created by norma on 2/5/2021.
//

#include "MenuAdmin.h"

MenuAdmin::MenuAdmin(Lista<Funcion> *l) {
    lista=l;

}

MenuAdmin::~MenuAdmin() {
    delete lista;
}
