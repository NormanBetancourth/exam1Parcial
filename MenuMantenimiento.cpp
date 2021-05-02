//
// Created by norma on 2/5/2021.
//

#include "MenuMantenimiento.h"

MenuMantenimiento::MenuMantenimiento() {
}

MenuMantenimiento::~MenuMantenimiento() {
}

void MenuMantenimiento::opcion1(Lista<Funcion>* lista) {
    if (lista->estaVacia()== false){
        cout<<"Asignacion de sala para una funcion\n\t";
        cout<<lista->toString();
        cout<<"Elija la funcion que desea modificar\n\t";
        string x;
        cin>>x;
        if (lista->busqueda(x)){
            string tipo;
            string id;
            string nombre;
            Matrix* M=new Matrix();
            cout<<"Ingrese el tipo de sala(normal, 3D, IMAX 3D, Aire)\n\t";
            getline(cin,tipo);
            cout<<"Ingrese el nombre de la nueva sala\n\t";
            getline(cin,nombre);
            cout<<"Ingrese el id de la nueva sala\n\t";
            getline(cin,id);
            Sala* s=new Sala(tipo,id,nombre, M);
            lista->acceso(x)->setSala(s);

        } else{
            cout<<"esa funcion no existe\n\t";
        }
    } else{
        cout<<"No existen funciones disponibles para asignarles una sala\n\t";
    }

}

void MenuMantenimiento::opcion2(Lista<Funcion>* lista) {
    if (lista->estaVacia()== false){
        cout<<"Asignacion de Pelicula para una funcion\n\t";
        cout<<lista->toString();
        cout<<"Elija la funcion que desea modificar\n\t";
        string x;
        cin>>x;
        if (lista->busqueda(x)){
            float precio;
            string id;
            string nombre;
            cout<<"Ingrese el id de la pelicula\n\t";
            getline(cin,id);
            cout<<"Ingrese el nombre de la Pelicula\n\t";
            getline(cin,nombre);
            cout<<"Ingrese el costo del voleto\n\t";
            cin>>precio;
            Pelicula *P=new Pelicula(id,nombre, precio);
            lista->acceso(x)->setPeli(P);

        } else{
            cout<<"esa funcion no existe\n\t";
        }
    } else{
        cout<<"No existen funciones disponibles para asignarles una pelicula\n\t";
    }


}

string MenuMantenimiento::opcion3(Lista<Funcion>* lista) {
    cout<<"Creacion de una nueva Funcion\n\t";
    string x;
    cin>>x;
    if (lista->busqueda(x)== false){

        //crear peli
        float precio;
        string id;
        string nombre;
        cout<<"Ingrese el id de la pelicula\n\t";
        getline(cin,id);
        cout<<"Ingrese el nombre de la Pelicula\n\t";
        getline(cin,nombre);
        cout<<"Ingrese el costo del voleto\n\t";
        cin>>precio;
        Pelicula *P=new Pelicula(id,nombre, precio);
        //crear sala
        string tipo;
        string idsala;
        string nombresala;
        Matrix* M=new Matrix();
        cout<<"Ingrese el tipo de sala(normal, 3D, IMAX 3D, Aire)\n\t";
        getline(cin,tipo);
        cout<<"Ingrese el nombre de la nueva sala\n\t";
        getline(cin,nombre);
        cout<<"Ingrese el id de la nueva sala\n\t";
        getline(cin,id);
        Sala* s=new Sala(tipo,idsala,nombresala, M);
        //crear fecha
        int dia;
        int mes;
        int annio;
        cout<<"Ingrese el dia de la funcion\n\t";
        cin>>dia;
        cout<<"Ingrese el mes de la funcion\n\t";
        cin>>mes;
        cout<<"Ingrese el annio de la funcion\n\t";
        cin>>annio;
        Fecha* f= new Fecha(dia,mes,annio);
        Funcion* F= new Funcion(P,s,f,0);
        lista->agregarFinal(F);


    } else{
        cout<<"Ya existe una funcion con ese id\n\t";
    }
}
