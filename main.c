#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"



int main(){
    binTree *arbol=NULL;
    btn_insert_value(&arbol, 20);
    btn_insert_value(&arbol, 10);
    btn_insert_value(&arbol, 15);
    btn_insert_value(&arbol, 30);
    btn_inorder(arbol, imprimirValor);
    printf("\n");
    eliminarArbol(&arbol, restarDosEnteros);
    return 0;
}
