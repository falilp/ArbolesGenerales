#include "agen.h"
#include <iostream>

#pragma region Ejercicio1
//Implementa un subprograma que dado un árbol general nos calcule su grado.

template <typename T>
unsigned int RecGradoMax(const Agen<T>& A,const typename Agen<T>::nodo nodo){
    if(nodo == A.NODO_NULO){
        return 0;
    }else{
        unsigned int grado=0;
        typename Agen<T>::nodo nodoAux = A.hijoIzqdo(nodo);

        while(nodoAux != A.NODO_NULO){
            grado++;
            nodoAux = A.hermDrcho(nodoAux);
        }

        nodoAux = A.hijoIzqdo(nodo);

        while(nodoAux != A.NODO_NULO){
            grado = std::max(grado,RecGradoMax(A,nodoAux));
            nodoAux = A.hermDrcho(nodoAux);
        }

        return grado;
    }
}

template <typename T>
unsigned int GradoMax(const Agen<T>& A){
    if(A.arbolVacio()){
        return 0;
    }else{
        return RecGradoMax(A,A.raiz());
    }
}

#pragma endregion

#pragma region Ejercicio2
//Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine la profundidad de éste nodo en el árbol. 

template <typename T>
unsigned int ProfundidadNodoAgen(const Agen<T>& A,const typename Agen<T>::nodo nodo){
    if(A.arbolVacio() || A.NODO_NULO == nodo || A.padre(nodo) == A.NODO_NULO){
        return 0;
    }else{
        return 1 + ProfundidadNodoAgen(A,A.padre(nodo));
    }
}

#pragma endregion

#pragma region Ejercicio3
/*Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas de los subárboles
más bajo y más alto de cada nivel. Implementa un subprograma que calcule el grado de desequilibrio de un árbol general.*/

#pragma endregion

#pragma region Ejercicio4
/*Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice la poda
de A a partir de x. Se asume que no hay elementos repetidos en A.*/

#pragma endregion
/*
Code by Falilp
*/