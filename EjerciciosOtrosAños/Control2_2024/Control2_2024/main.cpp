//
//  main.cpp
//  Control2_2024
//
//  Created by Miguel Sevilla on 13/3/25.
//

#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS



// Reemplaza cada secuencia de caracteres no vocales consecutivos
// por su inversa. 'mensaje' se deber· modificar con el resultado
// de realizar dicho proceso.
void codifica(Lista<char> &mensaje) {
    // A IMPLEMENTAR
}

 
// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
    Lista<char>::ConstIterator it = l.cbegin();
    while (it != l.cend()) {
        cout << it.elem();
        it.next();
    }
    cout << endl;
}


  // Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
    for(unsigned int i=0; i < linea.size(); i++)
        mensaje.pon_final(linea[i]);
}

int main() {
    string linea;
    while(getline(cin,linea)) {
       Lista<char> mensaje;
       construyeMensaje(linea,mensaje);
       codifica(mensaje);
       imprime(mensaje);
    }
    return 0;
}

