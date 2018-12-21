#include <iostream>
#include <time.h>
#include "Busqueda.h"

using namespace std;

int main() {
    int max = 20;
    char eleccion = 'L';
    bool band = true;
    int numero;

    Nodo *nodo[max];
    Busqueda busqueda(max, eleccion);


    while(band){
        cin >> numero;

        busqueda.setLista(numero);

        busqueda.imprimir();



    }



    return 0;
}