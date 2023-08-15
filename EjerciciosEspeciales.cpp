#include "agen.h"
#include <iostream>

#pragma region Ejercicio1
/*Dado un arbol binario de un tipo generico T , calcular el numero de nodos que siendo hermanos entre si tienen la misma raiz y sus subarboles son reflejados.
Reflejados es que tenga la misma estructura de ramificacion.*/

template <typename T>
bool ReflejoAgen(const Agen<T> &A, const typename Agen<T>::nodo nodo1, const typename Agen<T>::nodo nodo2){
    if(nodo1 == A.NODO_NULO && A.NODO_NULO == nodo2){
        return true;
    }else if(nodo1 == A.NODO_NULO || A.NODO_NULO == nodo2){
        return false;
    }else{
        bool reflejo = true;
        while(nodo1 != A.NODO_NULO){
            while(nodo2 != A.NODO_NULO){
                reflejo = reflejo && Reflejo(A,nodo1,nodo2);
                nodo2 = A.hermDrcho(nodo2);
            }
            nodo1 = A.hermDrcho(nodo1);
        }
        return reflejo;
    }
}

template <typename T>
unsigned int RecAgenReflejados(const Agen<T> &A, const typename Agen<T>::nodo nodo){
    if(nodo != A.NODO_NULO){
        return 0;
    }else{
        unsigned int Nreflejados = 0;
        const typename Agen<T>::nodo nodoAux1 = A.hijoIzqdo(nodo);
        const typename Agen<T>::nodo nodoAux2 = A.hermDrcho(nodoAux1);

        while(nodoAux1 != A.NODO_NULO){
            while(nodoAux1 != A.NODO_NULO){
                if(Reflejo(A,nodoAux1,nodoAux2)){
                   Nreflejados++; 
                }
                nodoAux2 = A.hermDrcho(nodoAux2);
            }
            nodoAux1 = A.hermDrcho(nodoAux1);
        }
        
    }
}

template <typename T>
unsigned int AgenReflejados(const Agen<T> &A){
    if(A.arbolVacio()){
        return 0;
    }else{
        return RecAgenReflejados(A,A.raiz());
    }
}

#pragma endregion

#pragma region Ejercicio2

#pragma endregion

#pragma region Ejercicio3

#pragma endregion

#pragma region Ejercicio4

#pragma endregion
/*
Code by Falilp
*/