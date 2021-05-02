//
// Created by norma on 17/4/2021.
//

#ifndef LISTASIMPLE_LISTA_H
#define LISTASIMPLE_LISTA_H
#include <sstream>
#include <string>
#include <fstream>
#include "Nodo.cpp"
template<class T>
class Lista {
private:
    Nodo<T>* raiz;
    Nodo<T>* aux;
public:
    Lista();
    ~Lista();
    void agregarIni(T*);
    void agregarFinal(T *);
    string toString();
    bool estaVacia();
    bool eliminarEspecifico(string);
    void ordenarLista();//ordena con respecto a un id
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busqueda(string);
    T* acceso(string);
    void guardar();
    static Lista<T>* Leer();

};

#endif //LISTASIMPLE_LISTA_H
