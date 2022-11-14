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
struct nodo * eliminarCola(struct elemento **inicio, struct elemento **fin);
int vacia(struct elemento *inicio);
struct nodo * verPrimero(struct elemento *inicio);

int insertar(int dato, struct nodo **raiz);
void preorden(struct nodo *raiz);
void inorden(struct nodo *raiz);
void postorden(struct nodo *raiz);
void recorridoPorAmplitud(struct nodo *raiz);

int buscar(int datoBuscado, struct nodo *raiz);
int eliminar(struct nodo **raiz, int datoBuscado);


int main(){
    struct nodo *raiz = NULL;
    int dato, opcion;
    do{
        printf(" 1. Insertar un nodo en el arbol binario\n" );
        printf(" 2. Recorrido preorden\n" );
        printf(" 3. Recorrido inorden\n" );
        printf(" 4. Recorrido postorden\n" );
        printf(" 5. Recorrido por amplitud\n" );
        printf(" 6. Buscar un dato en el arbol\n" );
        printf(" 7. Eliminar un nodo del arbol\n" );
        printf(" 8. Salir\n" );
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
                printf(" Recorri do inorden: " );
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
                printf(" Ingrese el dato a buscar: " );
                scanf("%d", &dato);
                if(buscar(dato, raiz))
                    printf(" El dato %d se encuentra en el arbol \n " , dato);
                else
                    printf(" El dato %d no se encuentra en el arbol \n " , dato);
                break;
            case 7:
                printf(" Ingrese el dato a eliminar: " );
                scanf("%d", &dato);
                if(eliminar(&raiz, dato))
                    printf(" El dato %d se elimino del arbol \n " , dato);
                else
                    printf(" El dato %d no se encuentra en el arbol \n " , dato);
                break;
            case 8:
                printf(" Fin del programa " );
                break;
            default:
                printf(" Opcion incorrecta " );
                break;
        }
}
    while(opcion !=8 );
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


struct nodo * eliminarCola(struct elemento **inicio, struct elemento **fin){
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
    aux=eliminarCola(&inicio, &fin);
    printf("%d ", aux->dato);
    if(aux->izq!=NULL){
        insertarcola(&inicio, &fin, aux->izq);
    }
    if(aux->der!=NULL){
        insertarcola(&inicio, &fin, aux->der);
    }
    }
}

int buscar(int datoBuscado, struct nodo *raiz){
    if(raiz==NULL){
        return 0;
    }
    if(raiz->dato==datoBuscado){
        return 1;
    }
    if(raiz->dato>datoBuscado){
        return buscar(datoBuscado, raiz->izq);
    }else{
        return buscar(datoBuscado, raiz->der);
    }
}

/*int eliminar(int datoBuscado, struct nodo **raiz){
    if(raiz==NULL){
        return 0;
    }
    if((*raiz)->dato == datoBuscado){
        struct nodo nodoELim = *raiz;
        int datoELim=nodoELim->dato;
        if((*raiz)->izq==NULL && (*raiz)->der==NULL){
            *raiz=NULL;
        }
        free(*raiz);
        return datoELim;
    }  
}*/
int eliminar(struct nodo **raiz, int datoBuscado){
    if(*raiz==NULL){
        return -1;
    }
    if((*raiz) -> dato == datoBuscado){
        struct nodo *nodoElim = *raiz, *aux, *aux2;
        int datoElim = nodoElim -> dato;
        if((*raiz) -> izq == NULL && (*raiz) -> der == NULL){
            //Este caso es para cuando es una hoja.
            *raiz = NULL;
        }else{
            if((*raiz) -> der == NULL){
                //Tiene un hijo izquierdo
                *raiz = (*raiz) -> izq;
            }else{
                if((*raiz) -> izq == NULL){
                    //Tiene un hijo derecho
                    *raiz = (*raiz) -> der;
                }else{
                    aux2=*raiz;
                    aux = (*raiz) -> izq; // Se va solo una vez a la izquierda
                    while(aux -> der != NULL){
                        aux2=aux;
                        aux = aux -> der;//Después de ir a la izquierda, se va todo a la derecha
                        // esto permite encontrar el mayor en la
                    }
                    aux2 -> der = aux -> izq;//
                    aux -> der = (*raiz) -> der;
                    aux -> izq = (*raiz) -> izq;
                    *raiz = aux;
                }
            }
        }
        free(nodoElim);
        return datoElim;
    }
    if((*raiz) -> dato > datoBuscado){
        return eliminar(&((*raiz) -> izq), datoBuscado);
    }else{
        return eliminar(&((*raiz) -> der), datoBuscado);
    }
}

