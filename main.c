#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

binTree **minimo(binTree**,binTree**);
binTree **obtenerMinimoDeArbol(binTree**, binTree**());

int main(){
    binTree *arbol=NULL;
    btn_insert_value(&arbol, 20);
    btn_insert_value(&arbol, 10);
    btn_insert_value(&arbol, 30);
    btn_insert_value(&arbol, 15);
    btn_insert_value(&arbol, 25);
    btn_insert_value(&arbol, 35);
    btn_insert_value(&arbol, 22);
    btn_insert_value(&arbol, 27);
    btn_insert_value(&arbol, 9);
    char formato='i';
    btn_inorder(arbol, imprimirValor, &formato);
    printf("\n");
    binTree **nodoMinimo=obtenerMinimoDeArbol(&arbol, minimo);
    int valor=(*nodoMinimo)->value;
    printf("%d\n", valor);
    eliminarArbol(&arbol, restarDosEnteros);
    return 0;
}

binTree **obtenerMinimoDeArbol(binTree **arbol, binTree **funcionComp(binTree**,binTree**)){
    if(!*arbol)return NULL;
    if(btn_isLeaf(*arbol)) return arbol;
    binTree **nodoMinimo=NULL;
    binTree **aux1=obtenerMinimoDeArbol(&(*arbol)->right, funcionComp);
    binTree **aux2=obtenerMinimoDeArbol(&(*arbol)->left, funcionComp);
    nodoMinimo=funcionComp(aux1, aux2);
    return funcionComp(nodoMinimo, arbol);
}

binTree **minimo(binTree **ptr1, binTree **ptr2){
    if(!*ptr1&&!*ptr2)return NULL;
    if(!*ptr1)return ptr2;
    if(!*ptr2)return ptr1;
    return ((*ptr1)->value<(*ptr2)->value)? ptr1 : ptr2;
}
