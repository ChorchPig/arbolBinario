#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

struct nodo{
    int valor;
    nodo *izquierdo, *derecho;
};

void crearNodo(nodo *&, int);
void quitarArbol();
void eliminarNodo();
void confirmarSalida(int *);
void verificarMemoria(void *, int);

#endif // PROTOTIPOS_H_INCLUDED
