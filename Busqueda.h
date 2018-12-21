#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <iostream>
#include "Nodo.h"
using  namespace std;

class Busqueda {
private:
    int lista[20];
    int  max = 20;
    char selector;
    int divisor = 19;
    int vacio = -1;
    Nodo listaNodo[20];

    int hash(int);
    int hashSecundario(int);

    int  selectorDeReasignacion(int);
    int  verificadorColisiones(int);

    int busquedaReasignacionLineal(int);
    int insertarReasignacionLineal(int);

    int busquedaReasigancionCuadratica(int);
    int insertarReasignacionCuadratica(int);

    int busquedaReasignacionDobleHash(int);
    int insertarReasignacionDobleHash(int);

    int busquedaEncadenamiento(int);
    int insertarEncadenamiento(int);




public:

     Busqueda( char);
    void setLista(int);
    void getBuscar(int);
    void imprimir();





};


#endif