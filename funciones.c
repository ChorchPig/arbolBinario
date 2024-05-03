#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

binTree* btn_new(t_elem_btree value){
    binTree *nuevoNodo=(binTree*)malloc(sizeof(binTree));
    if(binTree){
        nuevoNodo->value=value;
        nuevoNodo->left=NULL;
        nuevoNodo->right=NULL;
    }
    return binTree;
}

void btn_free(binTree** node){
    if(!*node)return;
    binTree *nodoAEliminar=*node;
    if(!btn_isLeaf(nodoAEliminar)){
    /*...*/
    }
    else *node=NULL;
    free(nodoAEliminar);
}

binTree** btn_find(binTree** node, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree)){
    if(!*node || *node->value==value) return node;
    binTree **aux=node;
    while (*aux&&*aux->value!=value){
        if(cmp(value, *aux->value)<0)aux=&(*aux)->left;
        else aux=&(*aux)->right;
    }
    return aux;
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

int btn_insert(binTree **node, binTree *newNode){
    binTree **aux=btn_find(node, newNode->value, restarDosEnteros);
    *aux=newNode;
}

int btn_insert_value(binTree **node, int value){
    binTree *nuevoNodo=btn_new(value);
    binTree **aux=btn_find(node, nuevoNodo->value, restarDosEnteros);
    *aux=nuevoNodo;
}

int _btn_level(binTree *node, t_elem_btree value, int level, int cmp(t_elem_btree, t_elem_btree)) {
    /*...*/
}

int btn_level(binTree* root, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree)){
    /*...*/
}

t_elem_btree btn_height(binTree *node){
    int result = -1;
    /*...*/
    return result;
}

void btn_inorder(binTree *node, void btn_do(binTree*, void*), void* ctx) {
    if(!node) return;
    btn_inorder(node->left, btn_do, ctx);
    btn_do(node, ctx);
    btn_inorder(node->right, btn_do, ctx);
}

void btn_postorder(binTree *node, void btn_do(binTree*, void*), void* ctx) {
    if (!node) return;
    btn_postorder(node->left, btn_do, ctx);
    btn_postorder(node->right, btn_do, ctx);
    btn_do(node, ctx);
}

void btn_preorder(binTree *node, void btn_do(binTree*, void*), void* ctx){
    if (!node) return;
    btn_do(node, ctx);
    btn_preorder(node->left, btn_do, ctx);
    btn_preorder(node->right, btn_do, ctx);
}

int restarDosEnteros(int a, int b) { return a-b; }
int _max(int a, int b) { return (a > b) ? a : b; }
