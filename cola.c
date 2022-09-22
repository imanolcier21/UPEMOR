//cola
#include <stdlib.h>
#include <stdio.h>

struct elemento{
    int dato;
    struct elemento *sig;
};

struct cola{
    struct elemento *inicio;
    struct elemento *fin;
};

int insertar (struct elemento **inicio, struct elemento **fin, int datoNuevo);
int insertar2(struct cola *fila, int datoNuevo);
int eliminar(struct elemento **inicio, struct elemento **fin);
int vacia(struct elemento *inicio);
int verPrimero(struct elemento *inicio);

int main()
{
    struct elemento *inicio=NULL, *fin=NULL;
    int i;
    for(i=1; i <=10; i++){
        insertar(&inicio, &fin, i);
        }
        while(!vacia(inicio)){
        printf("%d, ", eliminar(&inicio, &fin));
        
        }
    printf("\n");

    return 0;
}

int insertar (struct elemento **inicio, struct elemento **fin, int datoNuevo){
    struct elemento *nuevo;
    nuevo=(struct elemento*)malloc(sizeof(struct elemento));
    if(nuevo==NULL){
        return 0;
    }
    nuevo->dato=datoNuevo;
    nuevo->sig=NULL;
    if(*inicio==NULL && *fin==NULL){
        *inicio=nuevo;
    }else{
        (*fin)->sig=nuevo;
    }
    *fin=nuevo;
    return 1;
}

int insertar2(struct cola *fila, int datoNuevo){
    struct elemento *nuevo;
    nuevo=(struct elemento*)malloc(sizeof(struct elemento));
    if(nuevo==NULL){
        return 0;
    }
    nuevo->dato=datoNuevo;
    nuevo->sig=NULL;
    if(fila->inicio==NULL && fila->fin==NULL){
        fila->inicio=nuevo;
    }else{
        fila->fin=nuevo;
        return 1;
    }
    }
int eliminar(struct elemento **inicio, struct elemento **fin){
    if(*inicio==NULL){
        return -1;
    }
    struct elemento *nodoElim= *inicio;
    int datoElim=nodoElim->dato;
    //IICIO=()
    *inicio=nodoElim->sig;
    if (inicio==NULL){
        *fin=NULL;
    }
    
    free(nodoElim);
    return datoElim;
}

int vacia(struct elemento *inicio){
    if(inicio==NULL){
        return 1;
     }
     return 0;
}
int verPrimero(struct elemento *inicio){
    if(inicio==NULL){
        return -1;
    }
    return inicio->dato;
}