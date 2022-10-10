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
int menu();

int main(){
    struct elemento *inicioL1=NULL, *finL1=NULL;
    int opc=0;
    int datoNuevo;
    do{
        opc=menu();
        switch (opc)
        {
        case 1:
            printf("Introduce el dato: ");
            scanf("%d", &datoNuevo);
            if(insertarInicio(&inicioL1, &finL1, datoNuevo));
            printf("Elemento insertado\n");
            break;
        case 2:
            imprimirAsc(inicioL1);
            break;
        case 3:
            imprimirDesc(finL1);
            break;
        default:
            break;
        }
    }while(opc!=0);
    return 0;
}

int menu(){
    int opc;
    printf("opciones:\n");
    printf("1. Insertar inicio\n");
    printf("2. Imprimir ascendente\n");
    printf("3. Imprimir descendente\n");
    printf("0. Salir\n");
    printf("Introduce la opción: ");
    scanf("%d", &opc);
    return opc;

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
    return 1;
}

void imprimirAsc(struct elemento *inicio){
    printf("\n");
    while(inicio!=NULL){
        printf("%d -> ", inicio->dato);
        inicio=inicio->siguiente;
        }
    }

void imprimirDesc(struct elemento *fin){
    printf("\n");
    while(fin!=NULL){
        printf("%d -> ", fin->dato);
        fin = fin->anterior;
        }
    }






