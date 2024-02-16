#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

struct nodo{
    int dato;
    nodo* nodoIzquierdo, *nodoDerecho, *nodoPadre;
};

nodo *crearNodo(int, nodo *);
void insertarNodo(nodo *&, int, nodo *);
nodo* obtenerNodoAEliminar(nodo *&, int);
void quitarNodoDelArbol(nodo *&, int);
void reemplazarNodo(nodo *, nodo*);
void eliminarNodo(nodo *&);
nodo *obtenerValorMinimo(nodo *);
void recorrerArbolEnPreOrden(nodo *);
void confirmarSalida(int *);

#endif // PROTOTIPOS_H_INCLUDED
