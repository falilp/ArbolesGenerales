#include "agen.h"
#include <iostream>

#pragma region Ejercicio1
/*Dado un arbol binario de un tipo generico T , calcular el numero de nodos que siendo hermanos entre si tienen la misma raiz y sus subarboles son reflejados.
Reflejados es que tenga la misma estructura de ramificacion.*/

template <typename T>
bool Reflejo(const Agen<T> &A, const typename Agen<T>::nodo nodo1, const typename Agen<T>::nodo nodo2){
    /*if(nodoD == abin.NODO_NULO && abin.NODO_NULO == nodoI){
        return true;
    }else if(nodoD == abin.NODO_NULO || abin.NODO_NULO == nodoI){
        return false;
    }else{
        return abin.elemento(nodoI) == abin.elemento(nodoD) && Reflejo(abin,abin.hijoIzqdo(nodoI),abin.hijoDrcho(nodoD)) && Reflejo(abin,abin.hijoDrcho(nodoI),abin.hijoIzqdo(nodoD));
    }*/
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