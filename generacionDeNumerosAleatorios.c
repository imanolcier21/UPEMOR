#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Intercambios//
void burbuja(int lista[], int tam); //Burbuja es un algoritmo de ordenamiento//
void burbujaMej(int lista[], int tam);
int* inicializaAleat(int tam); //Funcion de devolver arreglo//
void imprimir(int lista[], int tam);

int main()
{
    int* lista; //(* es un apuntador)//
    int tam=10;
    srand(time(NULL)); //Con cada ejecución los números son diferentes//
    lista=inicializaAleat(tam);
    imprimir(lista, tam);
    burbuja(lista, tam);
    imprimir(lista, tam);
    printf("\n");
   
    return 0;
}

void imprimir(int lista[], int tam){
    int i;
            for(i=0;i<tam;i++){
                printf("%d, ", lista[i]);
        }
        printf("\n");
}

//"Se regresa el apuntador de la memoria solicitada"//
int* inicializaAleat(int tam){
    int* arreglo;
    arreglo=(int*)malloc(sizeof(int)*tam); //Se solicita memoria suficiente//
    int i;
    for(i=0;i<tam;i++){
        arreglo[i]=rand()%100+1; //Con el módulo se sabe el numero aleatorio generada// 
        //arreglo[i]=rand()%(max-min+1)+min Rango de datos//
    }
    return arreglo;                                                                                                                                                                                                                                                                                                                                                  
}

void burbuja(int lista[], int tam){
    int i,j;
    int temp; //Temp es para intercambiar//
    
    //"Esta se hará siempre"//
    for(i=1;i<tam;i++){ //Idealización//
        for(j=0;j<tam-1;j++){ 
            
            //"Esta no se hará siempre"//
            if(lista[j]>lista[j+1]){ //Comparacion de veces de j//
                    temp=lista[j];
                        lista[j]=lista[j+1];
                            lista[j+1]=temp;
            }    
        } 
    
    }
}

void burbujaMej(int lista[], int tam){
    int i,j;
    int temp; //Temp es para intercambiar//
    
    //"Esta se hará siempre"//
    for(i=1;i<tam;i++){ //Idealización//
        for(j=0;j<tam-i;j++){ 
            
            //"Esta no se hará siempre"//
            if(lista[j]>lista[j+1]){ //Comparacion de veces de j//
                    temp=lista[j];
                        lista[j]=lista[j+1];
                            lista[j+1]=temp;
            }    
        } 
    
    }
}