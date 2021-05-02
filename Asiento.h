//
// Created by norma on 2/5/2021.
//

#ifndef EXAM_IPARCIAL_ASIENTO_H
#define EXAM_IPARCIAL_ASIENTO_H
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
class Asiento {
private:
    int id;
    string estado;//Disponible, Bloqueado, Vendido
public:
    Asiento(int id=0,string estado="Disponible");
    ~Asiento();

    //gets
    const int &getId() const;
    const string &getEstado() const;

    //sets
    void setId(const int &id);
    void setEstado(const string &estado);

    string toString();

};


#endif //EXAM_IPARCIAL_ASIENTO_H
