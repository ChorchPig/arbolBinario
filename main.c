#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void padreSumaDeHijos(binTree*, int*);

int main(){
    binTree *arbol=NULL;
    agregaValor(&arbol, 10);
    agregaValor(&arbol, 4);
    agregaValor(&arbol, 6);
    agregaValor(&arbol, 1);
    agregaValor(&arbol, 3);
    char formato='i';
    btn_preorder(arbol, imprimirValor, &formato);
    printf("\n");
    int booleano=1;
    padreSumaDeHijos(arbol, &booleano);
    printf("%d\n", booleano);
    eliminarArbol(&arbol, restarDosEnteros);
    return 0;
}

void padreSumaDeHijos(binTree *arbol, int *booleano){
    if(!arbol)return;
    if(arbol->value!=arbol->left->value+arbol->right->value)*booleano=0;
    if(*booleano){
        padreSumaDeHijos(arbol->left, booleano);
        padreSumaDeHijos(arbol->right, booleano);
    }
}
