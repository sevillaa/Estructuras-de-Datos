//
//  main.cpp
//  Ejercicio17
//
//  Created by Miguel Sevilla on 4/3/25.
//

#include <iostream>
#include <vector>
#include "lista.h"

// Función auxiliar para comparar la lista con un vector de valores esperados.
template<typename T>
bool listaIgual(const Lista<T>& lista, const std::vector<T>& esperado) {
    if(lista.longitud() != esperado.size())
        return false;
    for (unsigned i = 0; i < esperado.size(); i++){
        if(lista.elem(i) != esperado[i])
            return false;
    }
    return true;
}

int main() {
    int testsTotales = 0;
    int testsCorrectos = 0;
    
    // Test 1: Ambas listas vacías.
    {
        Lista<int> l1;
        Lista<int> l2;
        l1.concatena(l2);
        testsTotales++;
        if(listaIgual(l1, {})){
            std::cout << "Test 1 OK" << std::endl;
            testsCorrectos++;
        } else {
            std::cout << "Test 1 Fallo" << std::endl;
        }
    }
    
    // Test 2: l1 vacía, l2 no vacía.
    {
        Lista<int> l1;
        Lista<int> l2;
        l2.pon_final(1);
        l2.pon_final(2);
        l2.pon_final(3);
        l1.concatena(l2);
        testsTotales++;
        if(listaIgual(l1, {1,2,3})){
            std::cout << "Test 2 OK" << std::endl;
            testsCorrectos++;
        } else {
            std::cout << "Test 2 Fallo" << std::endl;
        }
    }
    
    // Test 3: l1 no vacía, l2 vacía.
    {
        Lista<int> l1;
        l1.pon_final(1);
        l1.pon_final(3);
        l1.pon_final(5);
        Lista<int> l2;
        l1.concatena(l2);
        testsTotales++;
        if(listaIgual(l1, {1,3,5})){
            std::cout << "Test 3 OK" << std::endl;
            testsCorrectos++;
        } else {
            std::cout << "Test 3 Fallo" << std::endl;
        }
    }
    
    // Test 4: l1 con elementos mayores y l2 con elementos menores.
    {
        Lista<int> l1;
        l1.pon_final(5);
        l1.pon_final(6);
        l1.pon_final(7);
        Lista<int> l2;
        l2.pon_final(1);
        l2.pon_final(2);
        l2.pon_final(3);
        l1.concatena(l2);
        testsTotales++;
        // Orden esperado: 1,2,3,5,6,7
        if(listaIgual(l1, {1,2,3,5,6,7})){
            std::cout << "Test 4 OK" << std::endl;
            testsCorrectos++;
        } else {
            std::cout << "Test 4 Fallo" << std::endl;
        }
    }
    
    // Test 5: l1 con elementos menores y l2 con elementos mayores.
    {
        Lista<int> l1;
        l1.pon_final(1);
        l1.pon_final(2);
        l1.pon_final(3);
        Lista<int> l2;
        l2.pon_final(4);
        l2.pon_final(5);
        l2.pon_final(6);
        l1.concatena(l2);
        testsTotales++;
        // Orden esperado: 1,2,3,4,5,6
        if(listaIgual(l1, {1,2,3,4,5,6})){
            std::cout << "Test 5 OK" << std::endl;
            testsCorrectos++;
        } else {
            std::cout << "Test 5 Fallo" << std::endl;
        }
    }
    
    // Test 6: Elementos intercalados.
    {
        Lista<int> l1;
        l1.pon_final(2);
        l1.pon_final(4);
        l1.pon_final(6);
        Lista<int> l2;
        l2.pon_final(1);
        l2.pon_final(3);
        l2.pon_final(5);
        l1.concatena(l2);
        testsTotales++;
        // Orden esperado: 1,2,3,4,5,6
        if(listaIgual(l1, {1,2,3,4,5,6})){
            std::cout << "Test 6 OK" << std::endl;
            testsCorrectos++;
        } else {
            std::cout << "Test 6 Fallo" << std::endl;
        }
    }
    
    // Test 7: Elementos duplicados.
    {
        Lista<int> l1;
        l1.pon_final(2);
        l1.pon_final(4);
        l1.pon_final(6);
        Lista<int> l2;
        l2.pon_final(2);
        l2.pon_final(5);
        l2.pon_final(7);
        l1.concatena(l2);
        testsTotales++;
        // Orden esperado: 2,2,4,5,6,7
        if(listaIgual(l1, {2,2,4,5,6,7})){
            std::cout << "Test 7 OK" << std::endl;
            testsCorrectos++;
        } else {
            std::cout << "Test 7 Fallo" << std::endl;
        }
    }
    
    std::cout << "Tests correctos: " << testsCorrectos << " de " << testsTotales << std::endl;
    return 0;
}
