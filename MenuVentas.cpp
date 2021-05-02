//
// Created by norma on 2/5/2021.
//

#include "MenuVentas.h"

MenuVentas::MenuVentas(Lista<Funcion> *L) {
    lista=L;

}

MenuVentas::~MenuVentas() {
    delete lista;
}
