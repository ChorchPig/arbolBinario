#include <iostream>
#include "prototipos.h"

//TO DO: Existe un output infinito si la raíz no tiene nodos hijos y
// el programa colapsa eventualmente si se elimina la raíz de forma reiterativa
int main(){
    nodo *arbol=NULL;
    int option=1;
    int valorVariable=0;
    while(option){
        std::cout<<"Select an option \n\t";
        std::cout<<"1. Add data to the tree\n\t2. Remove data from the tree";
        std::cout<<"\n\t3. Show tree";
        std::cout<<"\n\t0. Exit program \n";
        std::cin>>option;
        switch(option){
            case 0: confirmarSalida(&option); break;
            case 1: {
                std::cout<<"Number to add: ";
                std::cin>>valorVariable;
                insertarNodo(arbol, valorVariable, NULL);
            }break;
            case 2: {
                std::cout<<"Number to remove: ";
                std::cin>>valorVariable;
                quitarNodoDelArbol(arbol, valorVariable);
            }break;
            case 3: {
                recorrerArbolEnPreOrden(arbol);
                std::cout<<"\n";
            } break;
            default : std::cout<<"No option selected\n";
        }
    }
    return 0;
}
