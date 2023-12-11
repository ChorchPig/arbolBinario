#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

struct nodo{
    int valor;
    nodo *izquierdo, *derecho;
};

void instertarArbol(nodo *&);
void crearNodo(nodo *&, int);
void quitarArbol(nodo *&, int);
void eliminarNodo(nodo *&nodoHoja);
void mostrarNodo(nodo *&);
void confirmarSalida(int *);
void verificarMemoria(void *, int);

#endif // PROTOTIPOS_H_INCLUDED
