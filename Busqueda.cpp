//
// Created by arturing on 19-12-18.
//

#include "Busqueda.h"
#include <math.h>

Busqueda::Busqueda(int tamanio, char eleccion) {

    max = tamanio;
    lista = new int [tamanio];
    selector = eleccion;

    for (int i = 0; i <tamanio ; ++i) {

        lista[i] = vacio;

    }

}

Busqueda::Busqueda(int tamanio, char eleccion, Nodo *nodo) {

    max = tamanio;
    selector = eleccion;

    for (int i = 0; i < tamanio ; ++i) {
        Nodo tmp;
        tmp.numero = vacio;
        listaNodo[i].numero = vacio;

    }


}


void Busqueda::setLista(int numero) {
    int poscion = hash(numero);

    if (lista[poscion] != vacio ){
        IngresoReasignacionLineal(numero);
    } else{
        lista[poscion] = numero;
    }

}


int  Busqueda::hash(int numero) {

    int posicion;
    bool band = true;

    posicion = numero % divisor;

    while (band) {
        if (posicion >= max) {

            posicion = posicion / 10;

        } else{
            band = false;
        }
    }

    return posicion;
}





void Busqueda::selectorDeReasignacion(int numero) {

    switch (selector){

        //case 'f': reasigancionCuadratica();

    }

}

int Busqueda::busquedaReasignacionLineal(int numero) {

    int D;
    int DX;

    D = hash(numero);


    DX = D + 1;

    while(DX <= max && lista[DX] != vacio && lista[DX] != numero && DX != D) {

        DX++;

        if (DX == max + 1) {         // la busqueda comienza desde el primer elemento
            DX = -1;
        }
    }

    if(lista[DX] == vacio || DX == D){
        return vacio;

    } else{
        return DX;

    }



}

int Busqueda::IngresoReasignacionLineal(int numero) {

    int D;
    int DX = vacio;

    D = hash(numero);
    DX = D + 1;

    while(DX <= max && lista[DX] != vacio && lista[DX] != numero && DX != D) {

        DX++;

        if (DX == max + 1) {         // la busqueda comienza desde el primer elemento
            DX = -1;
        }
    }

    if(lista[DX] == vacio){
        lista[DX] = numero;

    }

    return DX;




}


int Busqueda::encadenamiento(int numero) {

    int D;
    int DX;
    int cont = 0;
    Nodo *Q;


    D = hash(numero);
    Q = listaNodo[D].sig;

    while(Q->numero != vacio  && Q->numero != numero){
        Q = Q->sig;
        cont++;
    }

    if (Q->numero == vacio ){
        return -1;
    } else{
        return cont;
    }

}

int Busqueda::insertarEncadenamiento(int numero){

    int D;
    Nodo *Q;
    int cont = 0;

    D = hash(numero);


    Q = &listaNodo[D];

    while(Q->sig != NULL  && Q->numero != numero){
        cont ++;
        Q = Q->sig;
    }

    Q->sig = new Nodo{numero, NULL};

    return cont;
}

void Busqueda::setLista2(int numero) {

    int posicion = hash(numero);

    if (listaNodo[posicion].numero == vacio){
        listaNodo[posicion].numero = numero;

    } else{
        insertarEncadenamiento(numero);
    }

}

int Busqueda::hashSecundario(int numero) {

    int cont = 0;
    int cont2;
    int *digitos;
    int posicion;

    numero = numero * numero;


    while(numero >= 0){     //cuenta la cantidad de digitos que tiene el numero
        numero = numero /10;
        cont++;
    }

    digitos = new int[cont]; //almacenará los cada digito del numero
    cont2 = cont -1;

    for (int i = 0; i < cont ; ++i) {

        digitos[i] = numero / pow(10, cont2--);

    }

    posicion = (digitos[(cont/2) -1] *10) + digitos[cont/2];

    return posicion;

}

void Busqueda::reasigancionCuadratica(int numero) {

    int  D;
    int DX;
    int I;

    D = hash(numero);

    if(lista[D] != vacio && lista[D] == numero){
        cout << "La informacion esta en la poscion " << D << endl;

    } else{

        I = 1;
        DX = (D + (I*I));


        while (lista[DX] != vacio && lista[DX] != numero){
            I++;
            DX = D + (I*I);

            if(DX > max){

                I = 0;
                DX = -1;
                D = 1;

            }
        }

        if (lista[DX] == vacio){
            cout << "La informacion no se encuentra en el arregolo" << endl;

        } else{
            cout << "La informacion esta en la pocion " << endl;
        }

    }

}

void Busqueda::BusquedaReasignacionDobleHash(int numero) {

    int D;
    int DX;

    D = hash(numero);

    if(lista[D] != vacio  && lista[D] == numero ){
        cout << "La informacion esta en la posion " << D << endl;
    } else{
        DX = hashSecundario(D);

        while (DX <= max && lista[DX] != numero && DX != D){
            DX = hashSecundario(DX);
        }

        if (lista[DX] == vacio || lista[DX] != numero){
            cout << " La informacion no se encuentra en el arreglo" << endl;
        } else{
            cout << "La informacion está en la posicion "<< DX;
        }
    }


}

void Busqueda::insercionReasignacionCuadratica(int numero) {



    int  D;
    int DX;
    int I;

    D = hash(numero);

    if(lista[D] != vacio && lista[D] == numero){
        cout << "La informacion  ya se encuentra en el arreglo y esta en la poscion " << D << endl;

    } else{

        I = 1;
        DX = (D + (I*I));


        while (lista[DX] != vacio && lista[DX] != numero){
            I++;
            DX = D + (I*I);

            if(DX > max){

                I = 0;
                DX = -1;
                D = 1;

            }
        }

        if (lista[DX] == vacio){
            lista[DX] = numero;

        } else{
            cout << "La informacion  ya se encuentra en el arreglo y esta en la poscion " << endl;
        }

    }

}

void Busqueda::insertarReasignacionDobleHash(int numero) {

    int D;
    int DX;

    D = hash(numero);

    if(lista[D] != vacio  && lista[D] == numero ){
        cout << "La informacion ya se encuentra en la poscion en la posion " << D << endl;
    } else{
        DX = hashSecundario(D);

        while (DX <= max && lista[DX] != numero && DX != D){
            DX = hashSecundario(DX);
        }

        if (lista[DX] == vacio || lista[DX] != numero){
            lista[DX] = numero;

        } else{
            cout << "La informacion está en la posicion "<< DX;
        }
    }


}

