#include <stdio.h>

#include <stdlib.h>




struct elemento {

    int dato;

    struct elemento *sig;

};




//funciones de pila

int insertar(struct elemento **cima, int datoNuevo);//doble apuntador por que se modifica la cima

int eliminar(struct elemento **cima);

int verPrimero(struct elemento *cima); // apuntador normal por que no se modifica la cima

int vacia(struct elemento *cima);




int main(){
    struct elemento *apCima=NULL, *apCima2;
    
    int i;
    
    for(i=1; i<= 10; i++){
        
        if(insertar(&apCima, i)){
            
            printf("Elemento insertado\n");
           
    }else{
        
        printf("Elemento no insertado\n");
      
    }
}

//Desapilar
    while(!vacia(apCima)){
        
     printf("%d, ", eliminar(&apCima));
}
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
    
    return 1;
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
    //*cima=nodoEliminado-sig;
    free(nodoEliminado);

    return datoEliminado;




}

int verPrimero(struct elemento *cima){
    if(cima!=NULL){
        return cima->dato;
    }else{
        return -1;
    }






}

int vacia(struct elemento *cima){
    if (cima==NULL){
        return 1;
    }

return 0;

}