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

int btn_count(binTree *node){
    int result = 0;
    if (node != NULL) {
        result = 1 + btn_count(node->left) + btn_count(node->right);
    }
    return result;
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

int _btn_level(binTree *node, t_elem_btree value, int level, int cmp(t_elem_btree, t_elem_btree)) {
    /*...*/
    return 0;
}

int btn_level(binTree* root, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree)){
    /*...*/
    return 0;
}

t_elem_btree btn_height(binTree *node){
    int result = -1;
    /*...*/
    return result;
}

void btn_inorder(binTree *node, void btn_do(binTree*)){
    if(!node) return;
    btn_inorder(node->left, btn_do);
    btn_do(node);
    btn_inorder(node->right, btn_do);
}

void btn_postorder(binTree *node, void btn_do(binTree*)){
    if (!node) return;
    btn_postorder(node->left, btn_do);
    btn_postorder(node->right, btn_do);
    btn_do(node);
}

void btn_preorder(binTree *node, void btn_do(binTree*)){
    if (!node) return;
    btn_do(node);
    btn_preorder(node->left, btn_do);
    btn_preorder(node->right, btn_do);
}

int restarDosEnteros(int a, int b) { return a-b; }
int _max(int a, int b) { return (a > b) ? a : b; }
void imprimirValor(binTree *arbol){ printf("%d ", arbol->value); }

