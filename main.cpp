#include <iostream>
#include <time.h>
#include "Busqueda.h"

using namespace std;

int main(int argc , char *argv[]) {

    /**
     * validacion de parametros de entrada
     * */

    char eleccion;

    if(argc == 1){      //Valida la cantidad de parametros de entrada
        eleccion = *argv[1];


    }else{      //Si la cantidad parametros no es la adecuada el programa debe reiniciarse

        cout << "\n cantidad de datos ingresados es erroneo , reinicie el programa" << endl;
        return 1;
    }


    if(eleccion != 'E' && eleccion != 'C' && eleccion != 'D' && eleccion != 'L'){       //verifica que el caracter ingresado sea valido
        cout << " El caracter ingresado no es valido, reinicie el programa " << endl;
        return 1;
    }

    /**
     * inicializacion de objetos y variables
     * */

    Busqueda busqueda(eleccion);
    int opcion = 0;
    int numero;

    /**
     * Indicar al usuario cual fue el metodo elegido
     *
     * */

    switch (eleccion){
        case 'L':
            cout << "Ha elegido el metodo de reoganizacion prueba Lineal " << endl;
            break;

        case 'D':
            cout << "Ha elegido el metodo de reoganizacion de Doble direccion hash" << endl;
            break;

        case 'C':
            cout << "Ha eligido el metodo de reorganizacion prueba cuadratica " <<endl;
            break;

        case 'E':
            cout << "Ha elegido el metodo de reorganizacion de Encadenamiento" << endl;
    }

    /**
     * Menu de opciones del usuario
     * */

    while (opcion != 9){

        cout << "       MENU    " << endl;
        cout << endl;
        cout << "[1] Agregar Numero" << endl;
        cout << "[2] Buscar Numero" << endl;
        cout << "[9] Salir" << endl;

        cin >> opcion;

        switch (opcion){

            case 1:
                cout << "Indique el numero que desea agregar "<< endl;
                cin >> numero;
                busqueda.setLista(numero);
                break;

            case 2 :
                cout << "Indique el numero que desea buscar " << endl;
                cin >> numero;
                busqueda.getBuscar(numero);
                break;

            case 9:
                continue;

            default:
                cout <<"La opcion ingresada no es valida " << endl;
        }



    }


    return 0;
}