//listas circulares
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento{
    int dato;
    struct elemento *siguiente;
};

int insertarInicio(struct elemento **inicio, int datoNuevo);



int main(){

}

int insertarInicio(struct elemento **inicio, int datoNuevo){
    struct elemento *nuevo, *aux;
    nuevo = (struct elemento *)malloc(sizeof(struct elemento));
    nuevo->dato = datoNuevo;
    if(*inicio == NULL){
        nuevo->siguiente = nuevo;
    }else{
        nuevo->siguiente = *inicio;
        aux = *inicio;
        while(aux->siguiente != *inicio){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    *inicio = nuevo;
}