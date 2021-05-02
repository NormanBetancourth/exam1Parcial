//
// Created by norma on 2/5/2021.
//

#include "Control.h"

Control::Control() {
    lista =new Lista<Funcion>();
    mAdmin = new MenuAdmin(lista);
    mVentas = new MenuVentas(lista);
}

Control::~Control() {
    delete lista;
    delete mAdmin;
    delete mMant;
    delete mVentas;
}

Lista<Funcion> *Control::getLista() const {
    return lista;
}

void Control::setLista(Lista<Funcion> *lista) {
    Control::lista = lista;
}

void Control::Menu() {
    int option;
    cout << "-----------Menu General----------\n\n";
    cout << "\t1. Menu Mantenimiento\n";
    cout << "\t2. Menu Ventas\n";
    cout << "\t3. Menu Administrador\n";
    cout << "\t4. Exit\n";
    cout << "\n\tEnter your option: "; cin >> option;

    while(cin.fail()){
        cout << "-----------Menu General----------\n\n";
        cout << "\t1. Menu Mantenimiento\n";
        cout << "\t2. Menu Ventas\n";
        cout << "\t3. Menu Administrador\n";
        cout << "\t4. Exit\n";
        cout << "\n\tEnter your option: "; cin >> option;
    }

    while (option!=4){
        switch(option){
            case 1:
                subMantenimiento();
                break;
            case 2:
                subVentas();
                break;
            case 3:
                subAdmin();
                break;
            case 4:
                cout<<"Saliendo..."<<endl;
                option = 4;
                break;
            default:
                cout<<"opcion incorrecta"<<endl;
                break;
        }
    }

}

MenuMantenimiento *Control::getMMant() const {
    return mMant;
}

MenuAdmin *Control::getMAdmin() const {
    return mAdmin;
}

MenuVentas *Control::getMVentas() const {
    return mVentas;
}

void Control::setMMant(MenuMantenimiento *mMant) {
    Control::mMant = mMant;
}

void Control::setMAdmin(MenuAdmin *mAdmin) {
    Control::mAdmin = mAdmin;
}

void Control::setMVentas(MenuVentas *mVentas) {
    Control::mVentas = mVentas;
}


void Control::opcion_1_1() {
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

void Control::opcion_1_2() {
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

void Control::opcion_1_3() {

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













void Control::subMantenimiento() {
    int option;
    cout << "-----------Menu Mantenimiento----------\n\n";
    cout << "\t1. Anadir sala a una funcion\n";
    cout << "\t2. Anadir pelicula a una funcion\n";
    cout << "\t3. Crear una nueva funcion\n";
    cout << "\t4. Volver al menu Principal\n";
    cout << "\n\tEnter your option: "; cin >> option;

    while(cin.fail()){
        cout << "-----------Menu Mantenimiento----------\n\n";
        cout << "\t1. Anadir sala a una funcion\n";
        cout << "\t2. Anadir pelicula a una funcion\n";
        cout << "\t3. Crear una nueva funcion\n";
        cout << "\t4. Volver al menu Principal\n";
        cout << "\n\tEnter your option: "; cin >> option;
    }

    switch(option){
        case 1:
            opcion_1_1();
            break;
        case 2:
            opcion_1_2();
            break;
        case 3:
            opcion_1_3();
            break;
        case 4:
            cout<<"Saliendo..."<<endl;
            option = 4;
            break;
        default:
            cout<<"opcion incorrecta"<<endl;
            break;
    }

}

void Control::subVentas() {

    int option;
    cout << "-----------Menu Ventas----------\n\n";
    cout << "\t1. Mostrar Las fucniones\n";//en una fecha
    cout << "\t2. Mostrar asientos\n";
    cout << "\t3. Seleccionar una funcion\n";
    cout << "\t4. Venta de Asiento<s>\n";
    cout << "\t5. Volver al menu Principal\n";
    cout << "\n\tEnter your option: "; cin >> option;

    while(cin.fail()){
        cout << "-----------Menu Ventas----------\n\n";
        cout << "\t1. Mostrar Las fucniones\n";//en una fecha
        cout << "\t2. Mostrar asientos\n";
        cout << "\t3. Seleccionar una funcion\n";
        cout << "\t4. Venta de Asiento<s>\n";
        cout << "\t5. Volver al menu Principal\n";
        cout << "\n\tEnter your option: "; cin >> option;
    }

    switch(option){
        case 1:
            opcion_2_1();
            break;
        case 2:
            opcion_2_2();
            break;
        case 3:
            opcion_2_3();
            break;
        case 4:
            opcion_2_4();
            break;
        case 5:
            cout<<"Saliendo..."<<endl;
            Menu();
            break;
        default:
            cout<<"opcion incorrecta"<<endl;
            break;
    }
}

void Control::subAdmin() {

    int option;
    cout << "-----------Menu Administrador----------\n\n";
    cout << "\t1. Cambiar marcador de Lentes\n";//en una fecha
    cout << "\t2. Ver recaudación de 1 Función\n";
    cout << "\t3. Ver recaudación total de 1 día\n";
    cout << "\t4. Ver recaudación total entre fechas\n";
    cout << "\t5. Volver al menu Principal\n";
    cout << "\n\tEnter your option: "; cin >> option;

    while(cin.fail()){
        cout << "-----------Menu Administrador----------\n\n";
        cout << "\t1. Cambiar marcador de Lentes\n";//en una fecha
        cout << "\t2. Ver recaudación de 1 Función\n";
        cout << "\t3. Ver recaudación total de 1 día\n";
        cout << "\t4. Ver recaudación total entre fechas\n";
        cout << "\t5. Volver al menu Principal\n";
        cout << "\n\tEnter your option: "; cin >> option;
    }


        switch(option){
            case 1:
                opcion_3_1();
                break;
            case 2:
                opcion_3_2();
                break;
            case 3:
                opcion_3_3();
                break;
            case 4:
                opcion_3_4();
                break;
            case 5:
                cout<<"Saliendo..."<<endl;
                Menu();
                break;
            default:
                cout<<"opcion incorrecta"<<endl;
                break;
        }


}






