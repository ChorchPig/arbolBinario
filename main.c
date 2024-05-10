#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){
    binTree *arbol=NULL;
    agregaValor(&arbol, 10);
    agregaValor(&arbol, 2);
    agregaValor(&arbol, 7);
    agregaValor(&arbol, 3);
    agregaValor(&arbol, 4);
    agregaValor(&arbol, 8);
    char formato='i';
    btn_preorder(arbol, imprimirValor, &formato);
    printf("\n");
    binTree **nodoMinimo=obtenerMinimoDeArbol(&arbol, minimo);
    printf("%d\n", (*nodoMinimo)->value);
    eliminarArbol(&arbol, restarDosEnteros);
    return 0;
}

binTree* espejarArbol(binTree**);
void eliminarDuplicados(binTree**);
binTree* copiarYOrdenarArbol(binTree**);
void fusionarArboles(binTree**, binTree**);
