#include <iostream>
#include "prototipos.h"

nodo *crearNodo(int numero, nodo *padre){
    nodo *nuevoNodo=new nodo();
    nuevoNodo->dato=numero;
    nuevoNodo->nodoIzquierdo=NULL;
    nuevoNodo->nodoDerecho=NULL;
    nuevoNodo->nodoPadre=padre;
    return nuevoNodo;
}

void insertarNodo(nodo *&arbol, int numero, nodo *padre){
    if(!arbol){
        nodo *nuevoNodo=crearNodo(numero, padre);
        arbol=nuevoNodo;
    }
    else{
        (numero<arbol->dato)?insertarNodo(arbol->nodoIzquierdo, numero, arbol) : insertarNodo(arbol->nodoDerecho, numero, arbol);
    }
}

void quitarNodoDelArbol(nodo *&arbol, int valorAEliminar){
    nodo *nodoAEliminar=obtenerNodoAEliminar(arbol, valorAEliminar);
    if(!nodoAEliminar)return;
    if(nodoAEliminar->nodoIzquierdo && nodoAEliminar->nodoDerecho){
        nodo *minimo=obtenerValorMinimo(nodoAEliminar->nodoDerecho);
        nodoAEliminar->dato=minimo->dato;
        reemplazarNodo(minimo, minimo->nodoDerecho);
    }
    else if(nodoAEliminar->nodoIzquierdo){
        if(nodoAEliminar->nodoPadre){
            reemplazarNodo(nodoAEliminar, nodoAEliminar->nodoIzquierdo);
            eliminarNodo(nodoAEliminar);
        }
        else {
            nodo *aux=arbol;
            arbol=arbol->nodoIzquierdo;
            arbol->nodoPadre=NULL;
            eliminarNodo(aux);
        }
    }
    else if(nodoAEliminar->nodoDerecho){
        if(nodoAEliminar->nodoPadre){
            reemplazarNodo(nodoAEliminar, nodoAEliminar->nodoDerecho);
            eliminarNodo(nodoAEliminar);
        }
        else {
            nodo *aux=arbol;
            arbol=arbol->nodoDerecho;
            arbol->nodoPadre=NULL;
            eliminarNodo(aux);
        }
    }
    else {
        if(nodoAEliminar->nodoPadre){
            reemplazarNodo(nodoAEliminar, NULL);
            eliminarNodo(nodoAEliminar);
        }
        else {
            nodo *aux=arbol;
            arbol=NULL;
            eliminarNodo(aux);
        }
    }
}

nodo* obtenerNodoAEliminar(nodo *&arbol, int numero){
    nodo *nodoAEliminar=arbol;
    if(!arbol)nodoAEliminar=NULL;
    else if(numero<nodoAEliminar->dato)nodoAEliminar=obtenerNodoAEliminar(nodoAEliminar->nodoIzquierdo, numero);
    else if(numero>nodoAEliminar->dato)nodoAEliminar=obtenerNodoAEliminar(nodoAEliminar->nodoDerecho, numero);
    return nodoAEliminar;
}

void reemplazarNodo(nodo *valorViejo, nodo *valorNuevo){
    if(valorViejo->nodoPadre){
        if(valorViejo->dato==valorViejo->nodoPadre->nodoIzquierdo->dato){
            valorViejo->nodoPadre->nodoIzquierdo=valorNuevo;
        }
        else{
            valorViejo->nodoPadre->nodoDerecho=valorNuevo;
        }
        if(valorNuevo)valorNuevo->nodoPadre=valorViejo->nodoPadre;
    }
}

void eliminarNodo(nodo *&nodoAEliminar){
    nodoAEliminar->nodoDerecho=NULL;
    nodoAEliminar->nodoIzquierdo=NULL;
    nodoAEliminar->nodoPadre=NULL;
    delete nodoAEliminar;
}

nodo *obtenerValorMinimo(nodo *arbol){
    if(!arbol)return NULL;
    if(arbol->nodoIzquierdo)return obtenerValorMinimo(arbol->nodoIzquierdo);
    else return arbol;
}

void recorrerArbolEnPreOrden(nodo *arbol){
    if(!arbol)return;
    std::cout<<arbol->dato<<" - ";
    recorrerArbolEnPreOrden(arbol->nodoIzquierdo);
    recorrerArbolEnPreOrden(arbol->nodoDerecho);
}

void confirmarSalida(int *option){
    std::cout<<"You are about to exit the program, to confirm this action press 0: ";
    std::cin>>*option;
}
