#include "agen.h"
#include <iostream>

#pragma region Ejercicio1
//Implementa un subprograma que dado un árbol general nos calcule su grado.

//Otra Implementación de como obtener el grado maximo
/*
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
*/

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

        return std::max(grado,std::max(RecGradoMax(A,A.hijoIzqdo(nodo)),RecGradoMax(A, A.hermDrcho(nodo))));
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

//Implementración por sseparado la busqueda de las alturas minimas y maximas.
/*
template <typename T>
unsigned int RecAlturaMaxAgen(const Agen<T> &A,const typename Agen<T>::nodo nodo){
    if(A.arbolVacio() || nodo == A.NODO_NULO){
        return 0;
    }else{
        unsigned int Altura = 0;
        typename Agen<T>::nodo nodoAux = A.hijoIzqdo(nodo);
        
        while(nodoAux != A.NODO_NULO){
            Altura = std::max(Altura,RecAlturaMaxAgen(A,nodoAux));
            nodoAux = A.hermDrcho(nodoAux);
        }
        
        return 1 + Altura;
    }
}

template <typename T>
unsigned int RecAlturaMinAgen(const Agen<T> &A,const typename Agen<T>::nodo nodo){
    if(A.arbolVacio() || nodo == A.NODO_NULO){
        return 0;
    }else{
        unsigned int Altura = 999999999;
        typename Agen<T>::nodo nodoAux = A.hijoIzqdo(nodo);
        
        while(nodoAux != A.NODO_NULO){
            Altura = std::min(Altura,RecAlturaMaxAgen(A,nodoAux));
            nodoAux = A.hermDrcho(nodoAux);
        }
        
        return 1 + Altura;
    }
}
*/

template <typename T>
struct Alturas{
    unsigned int AlturaMax;
    unsigned int AlturaMin;
};

template <typename T>
Alturas<T> RecAlturasAgen(const Agen<T> &A, const typename Agen<T>::nodo nodo){
    if(nodo == A.NODO_NULO){
        return {0,0};
    }else{
        Alturas<T> alturas = {1,1};
        typename Agen<T>::nodo nodoAux = A.hijoIzqdo(nodo);

        while(nodoAux != A.NODO_NULO){
            Alturas<T> AlturaHijos = RecAlturasAgen(A,nodoAux);
            alturas.AlturaMax = std::max(alturas.AlturaMax,AlturaHijos.AlturaMax);
            alturas.AlturaMin = std::min(alturas.AlturaMin,AlturaHijos.AlturaMin);
            nodoAux = A.hermDrcho(nodoAux);
        }
        
        alturas.AlturaMax++;
        alturas.AlturaMin++;

        return alturas;
    }
}

template <typename T>
unsigned int RecDesequilibrioAgen(const Agen<T> &A,const typename Agen<T>::nodo nodo){
    if(nodo == A.NODO_NULO){
        return 0;
    }else{
        unsigned int MaxDesequilibrio = 0;
        typename Agen<T>::nodo nodoAux = A.hijoIzqdo(nodo);

        while(nodoAux != A.NODO_NULO){
            Alturas<T> alturas = RecAlturasAgen(A,nodoAux);
            MaxDesequilibrio = std::max(MaxDesequilibrio,std::abs(alturas.AlturaMax - alturas.AlturaMin));
            nodoAux = A.hermDrcho(nodoAux);
        }

        return std::max(RecDesequilibrioAgen(A,A.hijoIzqdo(nodo)),RecDesequilibrioAgen(A,A.hermDrcho(nodo)));   
    }
}

template <typename T>
unsigned int DesequilibrioAgen(const Agen<T> &A){
    if(A.arbolVacio()){
        return 0;
    }else{
        return RecDesequilibrioAgen(A,A.raiz());
    }
}

#pragma endregion

#pragma region Ejercicio4
/*Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice la poda
de A a partir de x. Se asume que no hay elementos repetidos en A.*/

template<typename T>
void BusquedaX(Agen<T> &A,T X,typename Agen<T>::nodo nodo){
    if(nodo != A.NODO_NULO){
        typename Agen<T>::nodo nodoAux = A.hijoIzqdo(nodo);

        while(nodoAux != A.NODO_NULO){
           
        }
    }
}

template<typename T>
void PodaDeX(Agen<T> &A,T X){
    if(!A.arbolVacio()){
        BusquedaX(A,X,A.raiz());
    }
}

#pragma endregion
/*
Code by Falilp
*/