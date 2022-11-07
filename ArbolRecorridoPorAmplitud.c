#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
};

struct elemento{
    struct nodo *dato;
  struct elemento *sig;
};


int insertarcola(struct elemento **inicio, struct elemento **fin, struct nodo *datoNuevo);
struct nodo * eliminar(struct elemento **inicio, struct elemento **fin);
int vacia(struct elemento *inicio);
struct nodo * verPrimero(struct elemento *inicio);

int insertar(int dato, struct nodo **raiz);
void preorden(struct nodo *raiz);
void inorden(struct nodo *raiz);
void postorden(struct nodo *raiz);
void recorridoPorAmplitud(struct nodo *raiz);


int main(){
    struct nodo *raiz = NULL;
    int dato, opcion;
    do{
        printf(" 1. Insertar un nodo en el arbol binario\n" );
        printf(" 2. Recorrido preorden\n" );
        printf(" 3. Recorrido inorden\n" );
        printf(" 4. Recorrido postorden\n" );
        printf(" 5. Recorrido por amplitud\n" );
        printf(" 6. Salir\n" );
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
                printf(" Recorrido por amplitud: " );
                recorridoPorAmplitud(raiz);
                printf(" \n " );
                break;
            case 6:
                printf(" Fin del programa " );
                break;
            default:
                printf(" Opcion incorrecta " );
                break;
        }
}
    while(opcion !=6 );
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

int insertarcola(struct elemento **inicio, struct elemento **fin, struct nodo *datoNuevo){
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


struct nodo * eliminar(struct elemento **inicio, struct elemento **fin){
    struct nodo *datoElim=NULL;
    if(*inicio==NULL){
        return datoElim;
    }
    struct elemento *nodoElim= *inicio;
    datoElim=nodoElim->dato;
    *inicio=nodoElim->sig;
    if (*inicio==NULL){
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

struct nodo * verPrimero(struct elemento *inicio){
    if(inicio==NULL){
        return NULL;
    }
    return inicio->dato;
}


void recorridoPorAmplitud(struct nodo *raiz){
    if(raiz==NULL){
        return;
    }
    struct elemento *inicio=NULL;
    struct elemento *fin=NULL;
    struct nodo *aux;
    insertarcola(&inicio, &fin, raiz);
    while(!vacia(inicio)){
    aux=eliminar(&inicio, &fin);
    printf("%d ", aux->dato);
    if(aux->izq!=NULL){
        insertarcola(&inicio, &fin, aux->izq);
    }
    if(aux->der!=NULL){
        insertarcola(&inicio, &fin, aux->der);
    }
    }
}