#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
5. Se desea cargar un array de N elementos, con la información de los artículos en stock
de un comercio. Cada registro contiene los siguientes campos:
i. codigo del articulo
ii. nombre del artículo
iii. cantidad actual en stock de ese artículo
iv. cantidad mínima requerida
v. precio del artículo
Se pide:
● Determinar cuántos artículos del array, tienen una cantidad actual en stock
inferior a la cantidad mínima requerida para ese artículo.
● Función que me imprima un articulo, pasando como parámetro el código
del mismo.
● Función que me permita modificar el precio y la cantidad de un artículo
pasando como parámetro el código de artículo.
*/

typedef struct
{
    int Codigo;
    char Nombre[30];
    int CantidadStock;
    int CantidadMinimaRequerida;
    int Precio;
}Articulo;

int i;
int Articulos;

int main()
{
    int codigobuscado;
    Articulo vec[100];

    printf("Cuantos articulos quieres cargar?\n");
    scanf("%d" , &Articulos);
    cargarArticulos(vec);
    system("cls");
    imprimirArticulos(vec);
    system("cls");
    inferiorEnStock(vec);
    system("cls");

    printf("Ingresa el codigo del articulo que quieras imprimir por pantalla.\n");
    scanf("%d" , &codigobuscado);
    system("cls");
    imprimirPorCodigo(codigobuscado, vec);
    system("cls");

    printf("Ingresa el codigo del articulo que quieras modificar.\n");
    scanf("%d" , &codigobuscado);
    system("cls");
    modificarPorCodigo(codigobuscado, vec);
    system("cls");
    imprimirArticulos(vec);
}

void cargarArticulos(Articulo vec[Articulos])
{
    for(i=0;i<Articulos;i++)
    {
        system("cls");
        printf("Articulo %d\n" , i+1);
        printf("\n");
        fflush(stdin);
        printf("Ingrese el codigo del articulo.\n");
        scanf("%d" , &vec[i].Codigo);
        fflush(stdin);
        printf("Ingrese el nombre del articulo.\n");
        scanf("%s" , &vec[i].Nombre);
        fflush(stdin);
        printf("Ingrese la cantidad de stock del articulo.\n");
        scanf("%d" , &vec[i].CantidadStock);
        fflush(stdin);
        printf("Ingrese la cantidad minima requerida del articulo.\n");
        scanf("%d" , &vec[i].CantidadMinimaRequerida);
        fflush(stdin);
        printf("Ingrese el precio del articulo.\n");
        scanf("%d" , &vec[i].Precio);
    }
    system("pause");
}

void imprimirArticulos(Articulo vec[Articulos])
{
    for(i=0;i<Articulos;i++)
    {
        printf("Articulo %d\n" , i+1);
        printf("\n");
        printf("Codigo del articulo: %d\n" , vec[i].Codigo);
        printf("Nombre del articulo: %s\n" , vec[i].Nombre);
        printf("Cantidad en stock: %d\n" , vec[i].CantidadStock);
        printf("Cantidad minima requerida: %d\n" , vec[i].CantidadMinimaRequerida);
        printf("Precio: $%d\n" , vec[i].Precio);
        printf("\n");
        printf("--------------------------------\n");
    }
    system("pause");
}

void inferiorEnStock(Articulo vec[Articulos])
{
    int artinferioralminimo = 0;

    for(i=0;i<Articulos;i++)
    {
        if(vec[i].CantidadStock < vec[i].CantidadMinimaRequerida)
        {
            artinferioralminimo = artinferioralminimo + 1;
        }
    }

    printf("Hay un total de %d articulos en stock inferiores a la cantidad minima requerida.\n" , artinferioralminimo);

    system("pause");
}

int imprimirPorCodigo(int codigobuscado, Articulo vec[Articulos])
{
    for(i=0;i<Articulos;i++)
    {
        if(codigobuscado == vec[i].Codigo)
        {
            codigobuscado = -1;
            printf("Articulo %d\n" , i+1);
            printf("\n");
            printf("Codigo del articulo: %d\n" , vec[i].Codigo);
            printf("Nombre del articulo: %s\n" , vec[i].Nombre);
            printf("Cantidad en stock: %d\n" , vec[i].CantidadStock);
            printf("Cantidad minima requerida: %d\n" , vec[i].CantidadMinimaRequerida);
            printf("Precio: $%d\n" , vec[i].Precio);
        }
    }
    if(codigobuscado != -1)
        printf("No se encontro el articulo.\n");

    system("pause");
}

int modificarPorCodigo(int codigobuscado, Articulo vec[Articulos])
{
    for(i=0;i<Articulos;i++)
    {
        if(codigobuscado == vec[i].Codigo)
        {
            codigobuscado = -1;
            printf("Articulo %d\n" , i+1);
            printf("Nombre: %s\n" , vec[i].Nombre);
            printf("\n");
            fflush(stdin);
            printf("Ingrese la cantidad en stock del articulo.\n");
            scanf("%d" , &vec[i].CantidadStock);
            fflush(stdin);
            printf("Ingrese el precio del articulo.\n");
            scanf("%d" , &vec[i].Precio);
        }
    }
    if(codigobuscado != -1)
        printf("No se encontro el articulo.\n");

    system("pause");
}
