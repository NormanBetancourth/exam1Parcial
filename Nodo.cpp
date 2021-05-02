//
// Created by norma on 17/4/2021.
//
#include "Nodo.h"
template<class T>
Nodo<T>::Nodo(T * info, Nodo<T> * sig) {
    this->sig = sig;
    this->info = info;
}

template<class T>
void Nodo<T>::setInfo(T * info) {
    this->info = info;
}

template<class T>
T *Nodo<T>::getInfo() {
    return info;
}

template<class T>
void Nodo<T>::setSig(Nodo<T> * sig) {
    this->sig=sig;
}

template<class T>
Nodo<T> *Nodo<T>::getSig() {
    return sig;
}

template<class T>
string Nodo<T>::toString() {
    return getInfo()->toString();
}

template<class T>
Nodo<T>::~Nodo() {
    delete info;
}

template<class T>
bool Nodo<T>::Buscado(string x) {
    if (x == getInfo()->getId()) {
        return true;
    } else{
        return false;
    }
}

template<class T>
string Nodo<T>::datoOrdenar() {
    return getInfo()->getId();
}

template<class T>
void Nodo<T>::guardar(ofstream & c) {
    getInfo()->guardar(c);
}

