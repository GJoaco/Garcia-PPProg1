#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char procesador[10];
    char marca[10];
    float precio;
}eNotebook;

float descuento(float precio);
int contarCaracteres(char cadena[], char caracter);
void ordenarArrays (eNotebook notebooks[], int tam);


int main()
{
    float precio=1000;
    float precioFinal;
    int pruebaInt;
    char cadena[] = "robooerto";
    char caracter = 'o';
    eNotebook notebooks[5] = {{1000,"i5","Asus",40000},{1001,"i7","HP",65000},{1002,"Ryzen 3","Asus",35000},{1003,"Ryzen 7","HP",56000},{1004,"i3","Samsung",40000}};


    precioFinal=descuento(precio);
    pruebaInt=contarCaracteres(cadena,caracter);
    ordenarArrays(notebooks,5);

    printf("%.2f\n",precioFinal);
    printf("%d\n",pruebaInt);


    for(int i=0; i<5;i++)
    {
        printf("%d %s %s %.2f\n",notebooks[i].id,notebooks[i].procesador,notebooks[i].marca,notebooks[i].precio);
    }

    return 0;
}

float descuento(float precio)
{
    float porcentaje = 5;

    precio= precio - precio*porcentaje /100;

    return precio;
}

int contarCaracteres(char cadena[], char caracter)
{
    int contador=0;

    for(int i=0; cadena[i]!='\0';i++)
    {
        if(cadena[i]==caracter)
        {
            contador++;
        }
    }

    return contador;
}

void ordenarArrays (eNotebook notebooks[], int tam)
{
    eNotebook aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(notebooks[i].marca, notebooks[j].marca) > 0)
            {
                aux=notebooks[i];
                notebooks[i]=notebooks[j];
                notebooks[j]=aux;
            }
            else if(strcmp(notebooks[i].marca, notebooks[j].marca) == 0 && notebooks[i].precio > notebooks[j].precio)
            {
                aux=notebooks[i];
                notebooks[i]=notebooks[j];
                notebooks[j]=aux;
            }
        }
    }
}
