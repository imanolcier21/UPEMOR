#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int dato;
    struct elemento *sig;
};

//funciones de pila
int insertar(struct elemento **cima, int datoNuevo);//doble apuntador por que se modifica la cima
int eliminar(struct elemento **cima);
//int insertar2(struct elemento **cima, int nuevo);//doble apuntador por que se modifica la cima
//int eliminar2(struct elemento **cima);
int verPrimerpila(struct elemento *cima); // apuntador normal por que no se modifica la cima
int vacia(struct elemento *cima);

int main(){

    struct elemento *Cima = NULL; //si no se inicializa apunta a cualquier lado
    if(insertar(&Cima, 10))
        printf("Se inserto correctamente");
    printf("\n");
    return 0;
}
int insertar(struct elemento **cima, int datoNuevo){
    struct elemento *nuevo;
    nuevo = (struct elemento*)malloc(sizeof(struct elemento));
    if(nuevo == NULL){
        return 0;
    }
    nuevo->dato=datoNuevo;
    nuevo->sig = *cima;
    *cima = nuevo;
}
int eliminar(struct elemento **cima){
    if(*cima == NULL){
        return -1;
    }
    struct elemento *nodoEliminado;
    int datoEliminado;
    nodoEliminado = *cima;//se respalda el nodo para poderlo liberar
    datoEliminado = nodoEliminado->dato;//se respalda el dato para poderlo devolver 
    *cima = (*cima)->sig;//flecita es de campo de estructura 
    free(nodoEliminado);
    return datoEliminado;

}
int verPrimerpila(struct elemento *cima){
}
int vacia(struct elemento *cima){
}
