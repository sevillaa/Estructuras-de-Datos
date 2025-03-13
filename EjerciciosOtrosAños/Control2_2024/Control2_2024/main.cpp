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
#include "pila.h"

// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS

bool esVocal(char c){
    string vocales = "aAeEiIoOuU";
    return vocales.find(c) != string::npos;
}

// Reemplaza cada secuencia de caracteres no vocales consecutivos
// por su inversa. 'mensaje' se deber· modificar con el resultado
// de realizar dicho proceso.
void codifica(Lista<char> &mensaje) {
    // A IMPLEMENTAR
    Pila<char> consonantes;
    Lista<char>::Iterator it = mensaje.begin();
    
    while(it!= mensaje.end()){
        if(!esVocal(it.elem())){
            consonantes.apila(it.elem());
            it = mensaje.eliminar(it);
        }else{
            //Caso en el que hay consonantes en la pila
            while(!consonantes.esVacia()){
               //tienes que insertar justo a la izquierda del iterador desapilando
                mensaje.insertar(consonantes.cima(), it);
                consonantes.desapila();
            }

            it.next();
        }
    }
    while(!consonantes.esVacia()){
       //tienes que insertar justo a la izquierda del iterador desapilando
        mensaje.insertar(consonantes.cima(), it);
        consonantes.desapila();
    }

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

