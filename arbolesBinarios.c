#include <stdio.h>
#include <stdlib.h>

 struct nodo {
    int dato;
    struct nodo *izq;
    struct nodo *der;
};

int insertar(int dato, struct nodo **raiz);
void preorden(struct nodo *raiz);
void inorden(struct nodo *raiz);
void postorden(struct nodo *raiz);

int main(){
    struct nodo *raiz = NULL;
    int dato, opcion;
    do{
        printf(" 1. Insertar un nodo en el arbol binario\n" );
        printf(" 2. Recorrido preorden\n" );
        printf(" 3. Recorrido inorden\n" );
        printf(" 4. Recorrido postorden\n" );
        printf(" 5. Salir\n" );
        printf(" Ingrese una opcion: " );
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf(" Ingrese un numero: " );
                scanf("%d", &dato);
                insertar(dato, &raiz);
                break;
            case 2:
                printf(" Recorrido preorden: " );
                preorden(raiz);
                printf(" \n " );
                break;
            case 3:
                printf(" Recorrido inorden: " );
                inorden(raiz);
                printf(" \n " );
                break;
            case 4:
                printf(" Recorrido postorden: " );
                postorden(raiz);
                printf(" \n " );
                break;
            case 5:
                printf(" Fin del programa " );
                break;
            default:
                printf(" Opcion incorrecta " );
                break;
        }
}
    while(opcion != 5);
    return 0;
}


//función de insertar en arbol binario de forma recursiva 
int insertar(int dato, struct nodo **raiz){
    if(*raiz == NULL){
        struct nodo *nuevo;
        nuevo = (struct nodo *) malloc(sizeof(struct nodo));
        if(nuevo==NULL){
        return 0;
        }
        nuevo->dato = dato;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        *raiz = nuevo;
        return 1;
    }else{
        
        if((*raiz)->dato > dato){
           return insertar(dato, &(*raiz)->izq);//queremos que los menores se vayan a la izquierda
        }else{
            return insertar(dato, &(*raiz)->der);
        }
    }
}

//se puede recorrer el arbol por profundidad y por amplitud
//recorrido en profundidad, preorden, inorden y postorden

//recorrido en profundidad
void preorden(struct nodo *raiz){
    if(raiz == NULL){
        return;
    }else{
        printf("%d ", raiz->dato);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(struct nodo *raiz){
    if(raiz == NULL){
        return;
    }else{
        inorden(raiz->izq);
        printf("%d ", raiz->dato);
        inorden(raiz->der);
    }
}

void postorden(struct nodo *raiz){
    if(raiz == NULL){
        return;
    }else{
        postorden(raiz->izq);
        postorden(raiz->der);
        printf("%d ", raiz->dato);
    }
}
