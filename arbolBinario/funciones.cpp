#include <iostream>
#include <cstdlib>
#include<math.h>
#include "prototipos.h"

void instertarArbol(nodo *&);
void instertarArbol(nodo *&raiz){
    nodo *aux=raiz;
    int numero=0;
    std::cout<<"Element to insert: ";
    std::cin>>numero;
    bool condicion=true;
    while (condicion){
        if(aux->valor>numero&&aux->izquierdo==NULL)condicion=false;
        else if(aux->valor<=numero&&aux->derecho==NULL)condicion=false;
        else (aux->valor>numero)?aux=aux->izquierdo : aux=aux->derecho;
    }
    (aux->valor>numero)?crearNodo(aux->izquierdo, numero) : crearNodo(aux->derecho, numero);
}

void crearNodo(nodo *&nodoPadre, int valor){
    nodo *nuevoNodo=new nodo();
    verificarMemoria(nuevoNodo, 1);
    nuevoNodo->valor=valor;
    nuevoNodo->izquierdo=NULL;
    nuevoNodo->derecho=NULL;
    (nodoPadre->valor>nuevoNodo->valor)?nodoPadre->izquierdo=nuevoNodo : nodoPadre->derecho=nuevoNodo;
}

void quitarArbol(){

}

void eliminarNodo(){

}
void confirmarSalida(int *option){
    std::cout<<"You are about to exit the program, to confirm this action press 0.\n";
    std::cin>>*option;
}

void verificarMemoria(void *ptr, int llamado){
    if(!ptr){
        std::cout<<"Error occurd in the "<<llamado<<" call.\n";
        exit(EXIT_FAILURE);
    }
}
