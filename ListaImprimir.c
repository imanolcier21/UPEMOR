#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int dato;
    struct elemento *sig;
};

int insertarInicio(struct elemento **inicio,struct elemento **fin, int datoNuevo);
int insertarFinal(struct elemento **inicio,struct elemento **fin, int datoNuevo);
int insertarMedio(struct elemento *anterior,int datoNuevo);
void imprimirLista(struct elemento *inicio);

int eliminarInicio(struct elemento **inicio, struct elemento **fin);
int eliminarFinal(struct elemento **inicio, struct elemento **fin);
int eliminarMedio(struct *anterior);

int main()
{
    printf("Hello World");

    return 0;
}

int insertarInicio(struct elemento **inicio,struct elemento **fin, int datoNuevo){
    struct elemento *nuevo;
    nuevo=(struct elemento*)malloc(sizeof(struct elemento));
    if(nuevo==NULL){
        return 0;
    }
    nuevo->dato=datoN;
    nuevo->sig=*inicio;
    if(*inicio==NULL && *fin==NULL){
        *fin=nuevo;
    }
    *inicio=nuevo;
    return 1;
}
int insertarFinal(struct elemento **inicio,struct elemento **fin, int datoNuevo){
    struct elemento *nuevo;
    nuevo=(struct elemento*)malloc(sizeof(struct elemento));
    if(nuevo==NULL){
        return 0;
    }
    nuevo->dato=datoN;
    nuevo->sig=NULL
    if(*inicio=NULL){
        *inicio=nuevo;
    }else{
        (*fin)->sig=nuevo;
    }
    *fin=nuevo;
    return 1;
}
int insertarMedio(struct elemento *anterior,int datoNuevo){
    struct elemento *nuevo;
    nuevo=(struct elemento*)malloc(sizeof(struct elemento));
    if(nuevo==NULL){
        return 0;
    }
    nuevo->dato=datoN;
    nuevo->sig=anterior->sig;
    anterior->sig=nuevo;
    return 1;
}

void imprimirLista(struct elemento *inicio){
    printf("\n");
    while(inicio!=NULL){
        printf("%d->", inicio->dato);
        inicio=inicio->sig;
    }
}