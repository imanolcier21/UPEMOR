#include <stdio.h>
#include <time.h>

//crear un struct de dos enteros y un flotante
struct datos{
    int entero;
    float flotante;
    int entero2;
};

int main(){
    return 0;
} 

//crear metodo de ordenamiento de insercion para el struct de datos
void ordenamientoInsercion(struct datos *datos, int n){
    int i, j;
    struct datos aux;
    for(i=1; i<n; i++){
        aux = datos[i];
        j = i-1;
        while(j>=0 && datos[j].flotante > aux.flotante){
            datos[j+1] = datos[j];
            j--;
        }
        datos[j+1] = aux;
    }
}

//crear metodo de ordenamiento de burbuja para el struct de datos
void ordenamientoBurbuja(struct datos *datos, int n){
    int i, j;
    struct datos aux;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(datos[j].flotante > datos[j+1].flotante){
                aux = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = aux;
            }
        }
    }
}

//crear metodo de ordenamiento rapido para el struct de datos (quicksort)
void ordenamientoRapido(struct datos *datos, int primero, int ultimo){
    int i, j, central;
    struct datos pivote, aux;
    central = (primero+ultimo)/2;
    pivote = datos[central];
    i = primero;
    j = ultimo;
    do{
        while(datos[i].flotante < pivote.flotante && i<ultimo){
            i++;
        }
        while(datos[j].flotante > pivote.flotante && j>primero){
            j--;
        }
        if(i<=j){
            aux = datos[i];
            datos[i] = datos[j];
            datos[j] = aux;
            i++;
            j--;
        }
    }while(i<=j);
    if(primero<j){
        ordenamientoRapido(datos, primero, j);
    }
    if(i<ultimo){
        ordenamientoRapido(datos, i, ultimo);
    }
}

//calcular tiempo de ejecucion de los metodos de ordenamiento para el struct de datos (usar clock())
void calcularTiempo(){
    clock_t t;
    t = clock();
    //codigo a medir
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("El programa tardó %f segundos en ejecutarse", time_taken);
}


