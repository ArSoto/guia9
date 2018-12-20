#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <iostream>
#include "Nodo.h"
using  namespace std;

class Busqueda {
private:
    int *lista;
    int  max;
    char selector;
    int divisor=19;
    int vacio = -2;
    Nodo listaNodo[20];

    int hash(int);
    int hashSecundario(int);

    int busquedaReasignacionLineal(int);
    void IngresoReasignacionLineal(int);


    void reasigancionCuadratica(int);
    void insercionReasignacionCuadratica(int);

    void BusquedaReasignacionDobleHash(int);
    void insertarReasignacionDobleHash(int);

    void encadenamiento(int);
    void insertarEncadenamiento(int);

    void selectorDeReasignacion(int);
    void verificadorColisiones(int);


public:

     Busqueda(int, char);
     Busqueda(int, char, Nodo*);
    void setLista(int);
    void setLista2(int);
    int getBuscar(int);





};


#endif