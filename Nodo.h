//
// Created by norma on 17/4/2021.
//

#ifndef LISTASIMPLE_NODO_H
#define LISTASIMPLE_NODO_H
#include <iostream>
#include <sstream>
using namespace std;
template <class  T>
class Nodo {
private:
    T *info;
    Nodo<T>* sig;
public:
    Nodo(T *, Nodo<T>*);
    ~Nodo();
    void setInfo(T*);
    T* getInfo();
    void setSig(Nodo<T>*);
    Nodo<T>* getSig();
    string toString();
    bool Buscado(string x);
    string datoOrdenar();
    void guardar(ofstream&);

};




#endif //LISTASIMPLE_NODO_H
