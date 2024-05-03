#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#define t_elem_btree int

typedef struct _btn {
    t_elem_btree value;
    struct _btn *left;
    struct _btn *right;
} binTree;

binTree* btn_new(t_elem_btree);
void btn_free(binTree**);
binTree** btn_find(binTree**, t_elem_btree, int());
int btn_isLeaf(binTree*);
int btn_count(binTree*);
int btn_insert(binTree**,binTree*);
int btn_insert_value(binTree**,int);
int _btn_level(binTree*, t_elem_btree,int,int());
int btn_level(binTree*,t_elem_btree,int());
t_elem_btree btn_height(binTree*);
void btn_inorder(binTree*,void(), void*);
void btn_preorder(binTree*,void(),void*);

int restarDosEnteros(int,int);
int _max(int,int);

#endif // PROTOTIPOS_H_INCLUDED
