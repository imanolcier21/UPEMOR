#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int dato;
    struct elemento *sig;
};

//funciones de pila
int insertar(struct elemento **cima, int nuevo);//doble apuntador por que se modifica la cima
int eliminar(struct elemento **cima);
int insertar2(struct elemento **cima, int nuevo);//doble apuntador por que se modifica la cima
int eliminar2(struct elemento **cima);
int verPrimerpila(struct elemento *cima); // apuntador normal por que no se modifica la cima
int vacia(struct elemento *cima);

int main(){
    printf("\n");
    return 0;
}
