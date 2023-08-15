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
/*Arboles similares son aquellos que sus hojas coinciden en posición y elemento*/

template <typename T>
bool Hoja(const Agen<T> &A, const typename Agen<T>::nodo nodo){
    if(A.NODO_NULO == A.hijoIzqdo(nodo)){
        return true;
    }else{
        return false;
    }
}

template <typename T>
bool RecAgenSimilares(const Agen<T> &A, const Agen<T> &B, const typename Agen<T>::nodo nodoA, const typename Agen<T>::nodo nodoB){
    if((nodoA == A.NODO_NULO) && (nodoB == B.NODO_NULO)){
        return true;
    }else if((nodoA == A.NODO_NULO) || (nodoB == B.NODO_NULO)){
        return false;
    }else if(Hoja(A,nodoA) && Hoja(B,nodoB) && (A.elemento(nodoA) != B.elemento(nodoB))){
        return false;
    }else{
        bool similares = true;
        typename Agen<T>::nodo nodoAuxA = A.hijoIzqdo(nodoA);
        typename Agen<T>::nodo nodoAuxB = B.hijoIzqdo(nodoB);

        while((nodoAuxA != A.NODO_NULO) && (nodoAuxB != B.NODO_NULO)){
            similares = similares && RecAgenSimilares(A,B,nodoAuxA,nodoAuxB);
            nodoAuxA = A.hermDrcho(nodoAuxA);
            nodoAuxB = B.hermDrcho(nodoAuxB);
        }
        return similares;
    }
}

template <typename T>
bool AgenSimilares(const Agen<T> &A, const Agen<T> &B){
    if(A.arbolVacio() && B.arbolVacio()){
        return true;
    }else if(A.arbolVacio() || B.arbolVacio()){
        return false;
    }else{
        return RecAgenSimilares(A,B);
    }
}

#pragma endregion

#pragma region Ejercicio3
/*El desequilibrio de un arbol general es la maxima diferencia pesos de los subarboles de N, el peso del nodo es numero de nodos hojas*/



#pragma endregion
/*
Code by Falilp
*/