#include <stdio.h>
#include <stdlib.h>
//listas doblemente enlasadas

struct elemento{
    int dato;
    struct elemento *siguiente;
    struct elemento *anterior;
};

int insertarInicio(struct elemento **inicio, struct elemento **fin, int datoNuevo);
void imprimirAsc(struct elemento *inicio);
void imprimirDesc(struct elemento *fin);


int main(){

}

int insertarInicio(struct elemento **inicio, struct elemento **fin, int datoNuevo){
    struct elemento *nuevo;
    nuevo = (struct elemento *)malloc(sizeof(struct elemento));
    nuevo->dato = datoNuevo;
    nuevo->siguiente = *inicio;
    nuevo->anterior = NULL;
    if(*inicio == NULL){
        *fin = nuevo;
        }
    else{
        (*inicio)->anterior = nuevo;
        }
    *inicio = nuevo;
}



