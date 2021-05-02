//
// Created by norma on 2/5/2021.
//

#include "Control.h"

Control::Control() {
    lista =new Lista<Funcion>();

}

Control::~Control() {
    delete lista;

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


    int bam= 1;

    while (bam==1){
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
                bam=0;
                exit(0);
                cout<<"Saliendo..."<<endl;
                break;
            default:
                cout<<"opcion incorrecta"<<endl;
                break;
        }
    }

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


        //crear peli
        float precio;
        string id;
        string nombre;
        cout<<"Ingrese el id de la pelicula\n\t";
        cin>>id;
        cout<<"Ingrese el nombre de la Pelicula\n\t";
        cin.get();
        getline(cin,nombre);
        cout<<"Ingrese el costo del voleto\n\t";
        cin>>precio;

        Pelicula *P=new Pelicula(id,nombre, precio);
        //crear sala
        string tipo;
        string idsala;
        string nombresala;
        Matrix* M=new Matrix();
        cout<<"Ingrese el id de la nueva sala\n\t";
        cin>>idsala;
        cout<<"Ingrese el tipo de sala(normal, 3D, IMAX3D, Aire)\n\t";
        cin>>tipo;
        cin.get();
        cout<<"Ingrese el nombre de la nueva sala\n\t";
        getline(cin,nombresala);
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
        cout<<lista->toString();
}

void Control::opcion_2_1() {//TODO test
    cout<<"Funciones en una Fecha"<<endl;
    int dia, mes ,anio;
    cout<<"ingrese el dia que quiere ver"<<endl;
    cin>>dia;
    cout<<"ingrese el mes que quiere ver"<<endl;
    cin>>mes;
    cout<<"ingrese el annio que quiere ver"<<endl;
    cin>>anio;
    if (lista->buscarFecha(dia,mes,anio)->estaVacia()== false){
        cout<<lista->buscarFecha(dia,mes,anio)->toString();
    } else{
        cout<<"No hayy ninguna funcion para ese dia"<<endl;
    }
}

void Control::opcion_2_2() {//todo test
    if (lista->estaVacia()== false){
        cout<<"Asientos de una Funcion"<<endl;
        cout<<"Ingrese el id de la Sala de la fucnion"<<endl;
        string id;
        cin>>id;
        cout<<lista->acceso(id)->verAsientos();
    } else{
        cout<<"NO hay funciones disponibles"<<endl;
    }

}

void Control::opcion_2_3() {//todo test
    if (lista->estaVacia()== false){
        cout<<"Sellecionar Funcion"<<endl;
        cout<<lista->toString();
        cout<<"Ingrese el id de la funcion"<<endl;
        string id;
        cin>>id;
        if (lista->acceso(id)!= nullptr){
            cout<<"Sun funcion es:"<<endl<<endl;
            cout<<lista->acceso(id)->toStringCompleto();
            cout<<"Cuantos voletos desea comprar?"<<endl;
            int cant=0;
            cin>>cant;
            float subtot=0;
            float total=0;
            float costoVoleto=lista->acceso(id)->getPeli()->getPrecio();
            if (lista->acceso(id)->getSala()->getTipo() == "3D"){
                subtot = subtot + subtot*0.2;

            }
            if (lista->acceso(id)->getSala()->getTipo() == "IMAX3D"){
                subtot = subtot + subtot*0.5;
            }
            if (lista->acceso(id)->getSala()->getTipo() == "Aire"){
                subtot = subtot + subtot*0.1;
            }
            lista->acceso(id)->setAsientosVendidos(lista->acceso(id)->getAsientosVendidos()+cant);
            total = cant * subtot;

            cout<<"Usted ha comprado "<<cant<<"voletos"<<endl;
            cout<<"El total al pagar es "<<total<<endl;
            cout<<"Su funcion es"<<lista->acceso(id)->toString()<<endl;


        } else{
            cout<<"No hay ninguna funcion con ese id"<<endl;
        }
    } else{
        cout<<"NO hay funciones disponibles"<<endl;
    }
}

void Control::opcion_2_4() {//todo test
    cout<<"Asientos de la cartelera: "<<endl;
    cout<< lista->toStringCompleto();
}

void Control::opcion_3_1() {
    cout<<"NO implementado"<<endl;
}

void Control::opcion_3_2() {
    if (lista->estaVacia()== false){
        cout<<"Ver la recaudacion de una funcion"<<endl;
        cout<<lista->toString();
        cout<<"Cual funcion desea ver?"<<endl;
        string id;
        cin>>id;
        if (lista->acceso(id)!= nullptr){
            float total=0;
            total=lista->acceso(id)->getAsientosVendidos()* lista->acceso(id)->getPeli()->getPrecio();
            cout<<"El total generado en esa funcion fue: "<<total<<endl;

        } else{
            cout<<"NO existe funcion con tal id"<<endl;
        }

    }
    else{
        cout<<"NO hay funciones disponibles"<<endl;

    }

}

void Control::opcion_3_3() {

    if (lista->estaVacia()== false){
        cout<<"Ver la recaudacion en una fecha"<<endl;
        cout<<lista->toString();
        cout<<"Cual fecha desea ver?"<<endl;
        int dia, mes, annio;
        cout<<"Dia"<<endl;
        cin>>dia;
        cout<<"Mes"<<endl;
        cin>>mes;
        cout<<"Annio"<<endl;
        cin>>annio;
        cout<<"el total recaudado "<<"("<<dia<<"/"<<mes<<"/"<<annio<<")"<<" es: "<<lista->buscarFecha(dia,mes,annio)->sumatoria();
        if (lista->buscarFecha(dia,mes,annio)->estaVacia()== false){
            cout<<"las funciones fueron: "<<endl;
            cout<<lista->buscarFecha(dia,mes,annio)->toString();
        }



    }
    else{
        cout<<"NO hay funciones disponibles"<<endl;

    }


}

void Control::opcion_3_4() {
    cout<<"TODO"<<endl;
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
           //exit(4);
           Menu();
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
    cout << "\t2. Mostrar asientos de una funcion\n";
    cout << "\t3. Seleccionar una funcion\n";
    cout << "\t4. Asientos disponibles en una funcion\n";
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
            //exit(5);
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

