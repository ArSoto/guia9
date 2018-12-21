//
// Created by arturing on 19-12-18.
//

#include "Busqueda.h"
#include <math.h>

Busqueda::Busqueda(char eleccion) {

    selector = eleccion;



    if(eleccion == 'E') {
        for (int i = 0; i < max; ++i) {
            listaNodo[i] = {vacio, NULL};

        }

    } else{
        for (int i = 0; i <max ; ++i) {
            lista[i] = vacio;

        }
    }

}

void Busqueda::setLista(int numero) {

    int posicion = hash(numero);
    int reasignacion = -1;
    bool band = true;
    Nodo *Q;

    if (selector == 'E'){

        if(listaNodo[posicion].numero == vacio){
            listaNodo[posicion] = {numero, NULL};
            band = false;

        } else{
            reasignacion = selectorDeReasignacion(numero);
        }

    }else if (lista[posicion] == vacio) {     //la posicion a ocupar esta vacia
        lista[posicion] = numero;
        band = false;

    } else {      //colicion en la lista
        reasignacion = selectorDeReasignacion(numero);

    }

    if(band  && selector != 'E' && lista[posicion] == numero && lista[reasignacion] == numero ){


        cout << "El numero ingresado ya se encontrba en la lista " << endl;
        band = false;


    }

    if (selector == 'E' && band ){
        Q = &listaNodo[posicion];
        int cont = reasignacion;

        while(Q != NULL && cont > 0){

            if (Q->numero == numero){
                cout << " El numero ingresado ya se encuentra en la lista "<< endl;
                band = false;
            }

            Q = Q->sig;
            cont--;
        }

    }



    if (band) {        //si hubo colision en la lista

        if (selector == 'E') {      //si estamos trabajando con nodos 

            cout << "Colision de los numeros:" << listaNodo[posicion].numero << " y " << numero << endl;
            cout << "\t Ubicacion de los numeros colisionados: " << endl;
            cout << "\t \t N° " << listaNodo[posicion].numero << " posicion " << posicion << " en nodo 0 "  << endl;
            cout << "\t \t N° " << numero << " posicion " << posicion << " en nodo " << reasignacion << endl;
            cout << endl;


        } else{

            cout << "Colision de los numeros: " << lista[posicion] << " y " << lista[reasignacion] << endl;
            cout << "\t Ubicacion de los numeros colisionados: " << endl;
            cout << "\t \t N° " << lista[posicion]  << " posicion " << posicion << endl;
            cout << "\t \t N° " << lista[reasignacion]  << " posicion " << reasignacion << endl;
            cout << endl;

        }

    }
}

void Busqueda::getBuscar(int numero) {

    int posicion = hash(numero);
    int reasignacion = verificadorColisiones(numero);

    if (selector != 'E') {

        if (lista[posicion] == numero){
            cout << "La posicion del numero es " << posicion << " y no hubo colision en la busqueda " << endl;

        } else if(reasignacion != vacio){

            cout << "La posicion del numero "<< numero << " es " << reasignacion;
            cout << " colisiono con  el numero " << lista[posicion] << " en posicion " << posicion << endl;

        } else{
            cout << " El numero no se encuentra en la lista " << endl;

        }

    } else {

        if (listaNodo[posicion].numero == numero){
            cout << "La posicion del numero  buscado es " << posicion << " y no hubo colision en la busqueda " << endl;

        } else if (reasignacion != vacio ){
            cout << "En la busqueda del numero hubo una colision con el numero " << listaNodo[posicion].numero << endl;
            cout << "\tLa posicion del numero "<< numero << " es " << posicion << " en el nodo " << reasignacion << endl;


        } else{
            cout << "El numero no se encuentra en la lista "<< endl;
        }

    }

}


int  Busqueda::hash(int numero) {

    int posicion = numero % divisor;


    return posicion;
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



int Busqueda::selectorDeReasignacion(int numero) {

    int posicion;

    switch (selector){

        case 'L':
            posicion = insertarReasignacionLineal(numero);
            break;

        case 'C':
            posicion = insertarReasignacionCuadratica(numero);
            break;

        case 'D':
            posicion = insertarReasignacionDobleHash(numero);
            break;

        case 'E':
            posicion = insertarEncadenamiento(numero);

    }

    return posicion;

}

int Busqueda::verificadorColisiones(int numero) {

    int posicion;

    switch (selector){

        case 'L':
            posicion = busquedaReasignacionLineal(numero);
            break;

        case 'C':
            posicion = busquedaReasigancionCuadratica(numero);
            break;

        case 'D':
            posicion = busquedaReasignacionDobleHash(numero);
            break;

        case 'E':
            posicion = busquedaEncadenamiento(numero);

    }

    return posicion;

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
        return -1;

    } else{
        return DX;

    }



}

int Busqueda::insertarReasignacionLineal(int numero) {

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

    if(lista[DX] == vacio && lista[DX -1] != numero){
        lista[DX] = numero;


    } else{
        return DX -1;
    }

    return DX;
    
}


int Busqueda::busquedaEncadenamiento(int numero) {

    int D;
    int cont = 0;
    Nodo *Q;


    D = hash(numero);
    Q = &listaNodo[D];

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
    int cont = 1;

    D = hash(numero);


    Q = &listaNodo[D];

    while(Q->sig != NULL  && Q->numero != numero){
        cont ++;
        Q = Q->sig;
    }

    if (Q->numero != numero) {
        Q->sig = new Nodo{numero, NULL}; // inserta nodo con el el nuevo valor
    }
    return cont;
}

int Busqueda::busquedaReasigancionCuadratica(int numero) {

    int  D;
    int DX;
    int I;

    D = hash(numero);

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
        return -1;

    } else{
        return DX;
    }

}

int Busqueda::busquedaReasignacionDobleHash(int numero) {

    int D;
    int DX;

    D = hash(numero);
    DX = hashSecundario(D);

    while (DX <= max && lista[DX] != numero && DX != D){
        DX = hashSecundario(DX);
    }

    if (lista[DX] == vacio || lista[DX] != numero){
        return -1;

    } else{
        return DX;
    }

}

int Busqueda::insertarReasignacionCuadratica(int numero) {

    int  D;
    int DX;
    int I;

    D = hash(numero);
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

    if (lista[DX] == vacio && lista[DX] != numero){
        lista[DX] = numero;

    }

    return DX;

}

int Busqueda::insertarReasignacionDobleHash(int numero) {

    int D;
    int DX;

    D = hash(numero);


    DX = hashSecundario(D);

    while (DX <= max && lista[DX] != numero && DX != D){
        DX = hashSecundario(DX);
    }

    if (lista[DX] == vacio && lista[DX] != numero){
        lista[DX] = numero;


    }

    return DX;


}

void Busqueda::imprimir() {

    if(selector != 'E'){

        for (int i = 0; i < max ; ++i) {

            if(lista[i] != vacio){
                cout<<"[" << lista[i] <<"] ";

            } else{
                cout << "[-] ";

            }
        }
        cout << endl;

    } else{

        Nodo *Q;
        for (int i = 0; i < max ; ++i) {

            if(listaNodo[i].numero != vacio){
                Q = &listaNodo[i];

                while(Q != NULL){
                    cout << " [" << Q->numero << "]";

                    if (Q->sig != NULL){
                        cout << " -> ";
                    }

                    Q = Q->sig;
                }

                cout << endl;

            } else{
                cout << " [-]" << endl;
            }

        }

    }
}