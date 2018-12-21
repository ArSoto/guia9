#include <iostream>
#include <time.h>
#include "Busqueda.h"

using namespace std;

int main() {
    int max = 20;
    char eleccion = 'f';

    Nodo *nodo[max];
    Busqueda busqueda(max, eleccion, *nodo);

    srand(time(NULL));
    int tmp;
    int tmpLista[max];

    for (int i = 0; i < max ; ++i) {
        tmp = rand() % 25;
        tmpLista[i]= tmp;
        busqueda.setLista2(tmp);


    }

    for (int j = 0; j < max ; ++j) {
        cout << tmpLista[j] << " ";
    }



    return 0;
}