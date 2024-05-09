#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

binTree* btn_new(t_elem_btree value){
    binTree *nuevoNodo=(binTree*)malloc(sizeof(binTree));
    if(nuevoNodo){
        nuevoNodo->value=value;
        nuevoNodo->left=NULL;
        nuevoNodo->right=NULL;
    }
    return nuevoNodo;
}

void eliminarArbol(binTree **arbol, int cmp(t_elem_btree, t_elem_btree)){
    while(*arbol) free(quitarNodo(arbol, (*arbol)->value, cmp));
}

binTree* quitarNodo(binTree** node, t_elem_btree data, int cmp(t_elem_btree, t_elem_btree)){
    binTree* result = NULL;
    binTree** found = btn_find(node, data, cmp);
    if (*found != NULL) {
        result = *found;
        btn_insert(&(*found)->left, (*found)->right);
        *found = (*found)->left;
        result->left = NULL;
        result->right = NULL;
    }
    return result;
}

binTree** btn_find(binTree** node, t_elem_btree valor, int cmp(t_elem_btree, t_elem_btree)){
    if(!*node || (*node)->value==valor) return node;
    binTree **aux=node;
    while (*aux&&(*aux)->value!=valor){
        if(cmp(valor, (*aux)->value)<0)aux=&(*aux)->left;
        else aux=&(*aux)->right;
    }
    return aux;
}

binTree** binTreeFind2(binTree **node, t_elem_btree value){
    binTree** result=NULL;
    if(*node){
        if((*node)->value==value)result=node;
        else{
            result=binTreeFind2(&(*node)->left, value);
            if(!result) result=binTreeFind2(&(*node)->right, value);
        }
    }
    return result;
}

int btn_isLeaf(binTree *node){
    int esHoja=0;
    if(node&&!node->left&&!node->right)esHoja=1;
    return esHoja;
}

void btn_insert(binTree **node, binTree *newNode){
    if(!newNode)return;
    binTree **aux=btn_find(node, newNode->value, restarDosEnteros);
    if(!*aux)*aux=newNode;
}

int btn_insert_value(binTree **node, int value){
    int insertado=0;
    binTree **aux=btn_find(node, value, restarDosEnteros);
    if(!*aux){
        binTree *nuevoNodo=btn_new(value);
        *aux=nuevoNodo;
        insertado=1;
    }
    return insertado;
}

int btn_level(binTree* root, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree)){
    if(!root) return -1;
    int nivel=-1;
    binTree **aux=btn_find(&root, value, cmp);
    if(*aux){
        nivel=0;
        if(root->value!=value){
            aux=btn_find(&root->left, value, cmp);
            if(*aux)nivel=1+btn_level(root->left, value, cmp);
            else nivel=1+btn_level(root->right, value, cmp);
        }
    }
    return nivel;
}

t_elem_btree btn_height(binTree *node){
    int result = -1;
    if(node){
        result=_max(btn_height(node->left), btn_height(node->right))+1;
    }
    return result;
}

void btn_inorder(binTree *node, void btn_do(binTree*, void*), void *contexto){
    if(!node) return;
    btn_inorder(node->left, btn_do, contexto);
    btn_do(node, contexto);
    btn_inorder(node->right, btn_do, contexto);
}

void btn_postorder(binTree *node, void btn_do(binTree*, void*), void *contexto){
    if (!node) return;
    btn_postorder(node->left, btn_do, contexto);
    btn_postorder(node->right, btn_do, contexto);
    btn_do(node, contexto);
}

void btn_preorder(binTree *node, void btn_do(binTree*, void*), void *contexto){
    if (!node) return;
    btn_do(node, contexto);
    btn_preorder(node->left, btn_do, contexto);
    btn_preorder(node->right, btn_do, contexto);
}

void contarNodos(binTree *arbol, int *cantNodos){
    if(!arbol)return;
    (*cantNodos)++;
}

binTree **obtenerMinimoDeArbol(binTree **arbol, binTree **funcionComp(binTree**,binTree**)){
    if(!*arbol)return arbol;
    binTree **nodoMinimo=NULL;
    binTree **aux1=obtenerMinimoDeArbol(&(*arbol)->right, funcionComp);
    binTree **aux2=obtenerMinimoDeArbol(&(*arbol)->left, funcionComp);
    nodoMinimo=funcionComp(aux1, aux2);
    return funcionComp(nodoMinimo, arbol);
}

binTree **minimo(binTree **ptr1, binTree **ptr2){
    if(!*ptr1)return ptr2;
    if(!*ptr2)return ptr1;
    return ((*ptr1)->value<(*ptr2)->value)? ptr1 : ptr2;
}

int existeEnArbol(binTree **arbol, t_elem_btree valor, int cmp(t_elem_btree, t_elem_btree)){
    binTree **existe=btn_find(arbol, valor, cmp);
    return (*existe)? 1 : 0;
}

void agregaValor(binTree **arbol, t_elem_btree valor){
    binTree *nuevoNodo=btn_new(valor);
    agregaNodo(arbol, nuevoNodo);
}

void agregaNodo(binTree **arbol, binTree *nuevoNodo){
    if(!*arbol)(*arbol)=nuevoNodo;
    else{
        if(!(*arbol)->left) (*arbol)->left=nuevoNodo;
        else if(!(*arbol)->right) (*arbol)->right=nuevoNodo;
        else agregaNodo(&(*arbol)->left, nuevoNodo);
    }
}

void sumarElementos(binTree *arbol, int *total){ (*total)+=arbol->value; }
int restarDosEnteros(int a, int b) { return a-b; }
int _max(int a, int b) { return (a > b) ? a : b; }
void imprimirValor(binTree *arbol, char *caracter){
    switch(*caracter){
        case 'i' : printf("%d ", arbol->value); break;
        case 'f' : printf("%.2f ", arbol->value); break;
        case 'c' : printf("%c ", arbol->value); break;
        case 's' : printf("%s ", arbol->value); break;
    }
}
