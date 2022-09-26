#include <stdio.h>
#include <stdlib.h>

struct libro{
    char titulo[50];
    char editorial[50];
    char autor[50];
    int numpag;
};

struct elemento{
    struct libro dato;
    struct elemento *sig;
};

//Funciones de pila
int insertar(struct elemento **cima, struct libro datoNuevo);
struct libro eliminar(struct elemento **cima);
struct libro verPrimero (struct elemento *cima);
int vacia(struct elemento *cima);

void capturar(struct libro *dato);
struct libro capturar2();
void imprimir(struct libro dato);

int main()
{
    struct elemento *apCima=NULL, *apCima2;
    struct libro libro1={"Libro1","Editorial1","Autor1",1};
    int i;
    for(i=1; i<=3; i++){
        libro1=capturar2();
        if(insertar(&apCima, libro1)){
            printf("Elemento insertado\n");
        }else{
            printf("Elemento no insertado\n");
        }
    }
    //Desapilar
    while(!vacia(apCima)){
        imprimir(eliminar(&apCima));
    }
    printf("\n");
    return 0;
}

int insertar(struct elemento **cima, struct libro datoNuevo){
    struct elemento *nuevo;
    nuevo=(struct elemento*)malloc(sizeof(struct elemento));
    if(nuevo==NULL){
        return 0;
    }
    nuevo->dato=datoNuevo;
    nuevo->sig=*cima;
    *cima=nuevo;
    return 1;
}
struct libro eliminar(struct elemento **cima){
    struct libro datoEliminado={"","","",0};
    if(*cima==NULL){
        return datoEliminado;
    }
    struct elemento *nodoEliminado;
    
    
    nodoEliminado=*cima;
    datoEliminado=nodoEliminado->dato;
    *cima=(*cima)->sig;
    //*cima=nodoEliminado->sig;
    free(nodoEliminado);
    return datoEliminado;
    
}

struct libro verPrimero (struct elemento *cima){
    if(cima!=NULL){
        return cima->dato;
    }else{
        struct libro aux={"","","",0};
        return aux;
    }
    
}
int vacia(struct elemento *cima){
    if (cima==NULL){
        return 1;
    }
    return 0;
}

void capturar(struct libro *dato){
    printf("Introduce el titulo");
    scanf("%[^\n]%*c", dato->titulo);
     printf("Introduce el autor");
    scanf("%[^\n]%*c", dato->autor);
     printf("Introduce la editorial");
    scanf("%[^\n]%*c", dato->editorial);
     printf("Introduce el numero de páginas");
    scanf("%d%*c", &dato->numpag);
}

struct libro capturar2(){
    struct libro dato;
     printf("Introduce el titulo: ");
    scanf("%[^\n]%*c", dato.titulo);
     printf("Introduce el autor: ");
    scanf("%[^\n]%*c", dato.autor);
     printf("Introduce el editorial: ");
    scanf("%[^\n]%*c", dato.editorial);
     printf("Introduce el numero de paginas: ");
    scanf("%d%*c", &dato.numpag);
    return dato;
}
void imprimir(struct libro dato){
    printf("Título: %s\n", dato.titulo);
    printf("Autor: %s\n", dato.autor);
    printf("Editorial: %s\n", dato.editorial);
    printf("Número de páginas: %d\n", dato.numpag);
    
}