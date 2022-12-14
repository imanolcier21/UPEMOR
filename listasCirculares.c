//listas circulares
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento{
    int dato;
    struct elemento *siguiente;
};

int insertarInicio(struct elemento **inicio, int datoNuevo);
void recorrido(struct elemento *inicio);



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

void recorrido(struct elemento *inicio){
    struct elemento *aux;
    aux = inicio;
    if(inicio==NULL){
        return ;
    }else{
        while(aux->siguiente != inicio){
            printf("%d", aux->dato);
            aux = aux->siguiente;
        }
    }
}