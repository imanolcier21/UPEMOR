#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fecha{
    int dd;
    int mm;
    int aaaa;
};

struct Persona{
  char nombre[30];
  char curp[19];
  char genero;
  int cant;
  struct Fecha fechaNac;
};

void imprimirPersona(struct Persona persona);

void imprimirPersonas(struct Persona lista[], int tam);

void CapturarPersonas(struct Persona lista[], int tam);



int main()
{
    struct Persona pers1;
    struct Persona pers2 = {"Shephany", "MEMCO", 'H',5,{27,01,2001,}};
    
    /*printf("Introduce nombre: ");
    scanf("%[^\n]%*c",pers1.nombre);
    
    printf("Introduce curp: ");
    scanf("%[^\n]",pers1.curp);
    
    printf("Introduce cantidad: ");
    scanf("%d", &pers1.cant);
    
    imprimirPersona(pers1);
    imprimirPersona(pers2);*/
    
    int tam=3;
    struct Persona listaP[3];
    struct Persona *listaDP;
    
    listaDP=(struct Persona*)malloc(sizeof(struct Persona)*tam);
    
    CapturarPersonas(listaDP,tam);
    
    imprimirPersonas(listaDP, tam);
    
    printf("\n");


    struct Persona *apP, p1;
     apP=(struct Persona*)malloc(sizeof(struct Persona));
     p1.cant=7;
     apP->cant=6; //acceder a un miembro de la estructura, el punto es para acceder a un miembro de la estructura y la flecha es para acceder a un miembro de un puntero a estructura
     printf("\n");

     /*union  ejemplo var1;
     var1.dato1=55;
     var1.dato2=45.3;*/
    return 0;
}


void imprimirPersona(struct Persona persona){
    printf("\n");
    printf("nombre %s\n", persona.nombre);
    printf("Curp: %s\n", persona.curp);
    printf("Género: %c\n", persona.genero);
    printf("Cant: %d\n", persona.cant);
    printf("Fecha %d/%d/%d/\n ",persona.fechaNac.dd, persona.fechaNac.mm, persona.fechaNac.aaaa);
}

void imprimirPersonas(struct Persona lista[], int tam){
    int i;
    for(i=0;i<tam;i++){
        imprimirPersona(lista[i]);
        //printf("Nombre: %s\n", lista[i].nombre) como acceder a una posición especifica en el arreglo
    }
}

void CapturarPersonas(struct Persona lista[], int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("Nombre: ");
        scanf("%[^\n]%*c", lista[i].nombre);
        printf("Curp: ");
        scanf("%s%*c", lista[i].curp);
        printf("Cant: ");
        scanf("%d", &lista[i].cant);
        printf("Dia: ");
        scanf("%d", &lista[i].fechaNac.dd);
        printf("mes: ");
        scanf("%d", &lista[i].fechaNac.mm);
        printf("Año: ");
        scanf("%d%*c", &lista[i].fechaNac.aaaa);
    }
}

void burbuja(struct Persona lista[], int tam){
    int i,j;
    struct Persona temp;
    for(i=1;i<tam;i++){
        for (j=0;j<tam-1;j++){
            if(strcmp(lista[j].nombre, lista[j+1].nombre)>0){
                temp=lista[j];
                lista[j]=lista[j+1];
                lista[j+1]=temp;
            }
        }
    }
}