//
// Created by norma on 17/4/2021.
//

#include "Lista.h"
template<class T>
Lista<T>::Lista() {
    raiz=nullptr;
    aux=nullptr;
}
template<class T>
Lista<T>::~Lista() {
    Nodo<T> * anterior= nullptr;
    if (raiz->getSig()== nullptr){
        delete raiz;
    } else{
        while (aux->getSig()!= nullptr){
            aux=raiz->getSig();
            while (aux->getSig()!= nullptr){
                anterior= aux;
                aux =aux->getSig();
            }
            anterior->setSig(nullptr);
            delete aux;

        }
    }
}
template<class T>
void Lista<T>::agregarIni(T *P) {
    raiz = new Nodo<T>(P, raiz);
}
template<class T>
string Lista<T>::toString() {
    aux = raiz;
    stringstream s;
    while (aux != NULL) {
        s << aux->toString() << endl;
        aux= aux->getSig();
    }
    return s.str();
}

template<class T>
void Lista<T>::agregarFinal(T *P) {
    aux=raiz;
    if (estaVacia()){
        raiz =new Nodo<T>(P, nullptr);
    } else{
        while (aux->getSig()!= nullptr){
            aux =aux->getSig();
        }
        aux->setSig(new Nodo<T>(P, nullptr));
    }
}

template<class T>
bool Lista<T>::estaVacia() {
    return raiz== nullptr? true:false;
}

template<class T>
bool Lista<T>::eliminarEspecifico(string x) {
    Nodo<T>* anterior = nullptr;
    aux=raiz;
    if (raiz == nullptr){
        return false;
    }
    if (raiz->Buscado(x)){
        aux =aux->getSig();
        delete raiz;
        raiz =aux;
    }
    while (aux != nullptr and aux->Buscado(x) == false){
        anterior = aux;
        aux= aux->getSig();
    }
    if (aux== nullptr){
        return false;
    } else{
        anterior->setSig(aux->getSig());
        delete aux;
        return true;
    }
    return false;
}

template<class T>
//Compara con respecto a un int de edad,
// se peude poner como un comparador de strings???
void Lista<T>::ordenarLista() {
    aux =raiz;
    Nodo<T> *temp = nullptr;
    T* P= nullptr;
    while (aux->getSig()!= nullptr){
        temp = aux->getSig();
        while (temp!= nullptr){
            if (aux->datoOrdenar() > temp->datoOrdenar()){
                P = temp->getInfo();
                temp->setInfo(aux->getInfo());
                aux->setInfo(P);

            }
            temp=temp->getSig();
        }
        aux=aux->getSig();
    }
}

template<class T>
bool Lista<T>::eliminarIni() {
    if (estaVacia()){
        return false;
    } else{
        aux=raiz;
        raiz = raiz->getSig();
        delete aux;
        return true;
    }
}

template<class T>
bool Lista<T>::eliminaFinal() {
    aux = raiz;
    Nodo<T>* anterior= nullptr;
    if (estaVacia()) {
        return false;
    }
    else {
        while (aux->getSig() != nullptr) {
            anterior = aux;
            aux = aux->getSig();

        }
        anterior->setSig(nullptr);
        delete aux;
        aux = anterior;
        return true;
    }
}

template<class T>
int Lista<T>::cuentaNodos() {
    int cont = 0;
    aux = raiz;
    while (aux != nullptr) {
        aux = aux->getSig();
        cont++;
    }
    return cont;
}

template<class T>
bool Lista<T>::busqueda(string x) {
    aux = raiz;
    if (estaVacia()) {
        return false;
    }
    else {
        while (aux != nullptr) {
            if (aux->Buscado(x)) {
                return true;
            }
            aux = aux->getSig();
        }
        return false;
    }
}

template<class T>
T *Lista<T>::acceso(string x) {
    if (estaVacia()) {
        return nullptr;
    }
    else {
        if (busqueda(x) != false) {
            return aux->getPersona();
        }
        return nullptr;
    }
}

template<class T>
void Lista<T>::guardar() {
    aux = raiz;
    ofstream c;
    c.open("Clientes.txt", ios::out);

    while (aux != NULL) {
        aux->guardar(c);
        aux = aux->getSig();
    }
    c.close();

}

template<class T>
Lista<T> *Lista<T>::Leer() {
    ifstream c;
    c.open("Clientes.txt", ios::in);
    Lista<T>* L = new Lista<T>();
    T* C = NULL;
    while (c.good())
    {
        C = T::leer(c);
        if (C != NULL)
        {

            L->agregarFinal(C);
        }
    }
    c.close();
    return L;
}
