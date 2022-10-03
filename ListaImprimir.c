#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int dato;
    struct elemento *sig;
};

int insertarInicio(struct elemento **inicio,struct elemento **fin, int datoNuevo);
int insertarFinal(struct elemento **inicio,struct elemento **fin, int datoNuevo);
int insertarMedio(struct elemento *anterior,int datoNuevo);
int insertarOrdenado(struct elemento **inicio, struct elemento **fin, int datoNuevo);

void imprimirLista(struct elemento *inicio);

int eliminarInicio(struct elemento **inicio, struct elemento **fin);
int eliminarFinal(struct elemento **inicio, struct elemento **fin);
int eliminarMedio(struct elemento *anterior);

int menu();
int main()
{
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
            printf("Introduce el dato: ");
            scanf("%d", &datoNuevo);
            if(insertarFinal(&inicioL1, &finL1, datoNuevo));
            printf("\nElemento insertado\n");
            break;
        case 3:
            eliminarInicio(&inicioL1,&finL1);
            printf("Elemento eliminado\n");
            break;
        case 4:
            eliminarFinal(&inicioL1, &finL1);
            printf("Elemento eliminado\n");
        case 5:
        imprimirLista(inicioL1);
        break;
        case 0:
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
    printf("2. Insertar final\n");
    printf("3. Eliminar inicio\n");
    printf("4. Eliminar final\n");
    printf("5. Mostrar\n");
    printf("0. Salir\n");
    printf("Introduce la opción: ");
    scanf("%d", &opc);
    return opc;

}

int insertarInicio(struct elemento **inicio,struct elemento **fin, int datoNuevo){
    struct elemento *nuevo;
    nuevo=(struct elemento*)malloc(sizeof(struct elemento));
    if(nuevo==NULL){
        return 0;
    }
    nuevo->dato=datoNuevo;
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
    nuevo->dato=datoNuevo;
    nuevo->sig=NULL;
    if(*inicio==NULL){
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
    nuevo->dato=datoNuevo;
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

int eliminarInicio(struct elemento **inicio, struct elemento **fin){
    int datoElim= -1;
    if(*inicio==NULL){
        return datoElim;
    }
    struct elemento *nodoElim= *inicio;
    datoElim=nodoElim->dato;
    //IICIO=()
    *inicio=nodoElim->sig;
    if (inicio==NULL){
        *fin=NULL;
    }
    free(nodoElim);
    return datoElim;
}

int eliminarFinal(struct elemento **inicio, struct elemento **fin){
    int datoElim = -1;
    if(*inicio==NULL){
        return datoElim;
    }
    struct elemento *nodoElim, *aux;
    nodoElim = *fin;
    datoElim = nodoElim -> dato;
    
    if(*inicio==*fin){
        *inicio=NULL;
        *fin=NULL;
    }else{
            aux=*inicio;
        while(aux -> sig != *fin){
            aux = aux -> sig;
        }
        aux -> sig = NULL;
        *fin=aux;
    }
    free(nodoElim);
    return(datoElim);
}

/*eliminarMedio(struct elemento *anterior){
    struct elemento *nodoElim, *aux;
    nodoElim=anterior->sig;
    int datoElim=nodoElim->sig;
    anterior->sig=nodoElim->sig;
    free(nodoElim);
    return datoElim;
}*/