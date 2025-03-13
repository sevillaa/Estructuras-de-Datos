/*
 Grupo 7
    - Candela Esquinas
    - Miguel Sevilla
 Practica 2 -> Evaluando expresiones en notación posfija
 TAD Empleado -> Pila (Nodos enlazados)
 */


#include <iostream>
#include<string>
using namespace std;
#include "pila.h"

//Hemos resuelto el problema de la siguiente forma:
//1. Almacenamos los numeros en una pila hasta encontrar un caracter que sea el de una operación.
//2. Una vez encontrado la operacion ya tenemos por lo menos dos numeros en la pila asi que los sacamos en el orden correspondiente y operamos segun la operacion que se haya leido.
//3 Almacenamos el resultado de la operacion en la pila para poder ser usado nuevamente en nuevas operaciones y actualizamos su valor

//Casos especiales -> Solo un caracter: Almacenamos en resultado el primer valor una vez leido

int evaluar(string exp) {
    Pila<int> pila = Pila<int>();
    int operador1 = 0, operador2 = 0;
    int respuesta = 0;
    int i = 0;
    
    if(exp.size() == 1){ //Caso Especial
        respuesta = exp[i] - 48;
    }else{
        while (i < exp.size()) {
            if (!isdigit(exp[i])) { //Operador
                operador2 = pila.cima();
                pila.desapila();
                if (!pila.esVacia()) {
                    operador1 = pila.cima();
                    pila.desapila();
                    
                    if (exp[i] == '+')
                        respuesta = operador1 + operador2;
                    else if (exp[i] == '-')
                        respuesta = operador1 - operador2;
                    else if (exp[i] == '*')
                        respuesta = operador1 * operador2;
                    else
                        respuesta = operador1 / operador2;
                    
                    pila.apila(respuesta);
                }
                else
                    respuesta = operador2;
            }
            else { //Numero
                int numero = exp[i] - 48;
                pila.apila(numero);
            }
            i++;
        }
    }
    
    return respuesta;
}

int main() {
    string expresion;
    while (cin >> expresion)
        cout << evaluar(expresion) << endl;

    return 0;
}
