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

    int  selectorDeReasignacion(int);
    int  verificadorColisiones(int);

    int busquedaReasignacionLineal(int);
    int insertarReasignacionLineal(int);

    int reasigancionCuadratica(int);
    int insertarReasignacionCuadratica(int);

    int BusquedaReasignacionDobleHash(int);
    int insertarReasignacionDobleHash(int);

    int busquedaEncadenamiento(int);
    int insertarEncadenamiento(int);




public:

     Busqueda(int, char);
     Busqueda(int, char, Nodo[]);
    void setLista(int);
    void getBuscar(int);





};


#endif