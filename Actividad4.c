#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
4. Un hotel recibe huéspedes de distintos puntos del país, y desea almacenar la
información de sus huéspedes en un array. Cada elemento del array, deberá ser un
registro con los siguientes campos:
i. nombre [30]
ii. apellido [30]
iii. id del huésped
iv. cantidad de días que se va hospedar
v. importe abonar por los días de hospedaje.
vi. tipo de servicio:
a. Pensión Completa
b. Media Pensión
c. Solo Desayuno
d. Sólo Habitación
vii. Ciudad de origen del huésped, supongamos que solo pueden ser de tres
ciudades(Córdoba-La Rioja - San Luis).

El programa deberá realizar lo siguiente:
● Función de carga del array
● Función que determine la cantidad de huéspedes por cada
ciudad.
● Determinar el importe total obtenido por el hotel de los
huéspedes con pensión completa que provienen de Córdoba.
*/


typedef struct
{
    char Nombre[30];
    char Apellido[30];
    int ID;
    int Dias;
    int Importe;
    char TipoServicio;
    char CiudadOrigen[30];
}Huesped;

int i;
int Huespedes;

int main()
{
    Huesped vec[100];

    printf("Cuantos huespedes quiere cargar?\n");
    scanf("%d" , &Huespedes);

    cargarHuespedes(vec);
    system("cls");
    imprimirHuespedes(vec);
    system("cls");
    huespedesPorCiudad(vec);
    system("cls");
    importeTotal(vec);
}

void cargarHuespedes(Huesped vec[Huespedes])
{
    for(i=0;i<Huespedes;i++)
    {
        system("cls");
        printf("Huesped %d\n" , i+1);
        printf("\n");
        fflush(stdin);
        printf("Ingrese el nombre del huesped.\n");
        scanf("%s" , &vec[i].Nombre);
        fflush(stdin);
        printf("Ingrese el apellido del huesped.\n");
        scanf("%s" , &vec[i].Apellido);
        fflush(stdin);
        printf("Ingrese el ID del huesped.\n");
        scanf("%d" , &vec[i].ID);
        fflush(stdin);
        printf("Ingrese la cantidad de dias que se hospedara.\n");
        scanf("%d" , &vec[i].Dias);
        fflush(stdin);
        printf("Ingrese el importe a abonar por los dias de hospedaje.\n");
        scanf("%d" , &vec[i].Importe);
        fflush(stdin);
        printf("Ingrese el tipo de servicio.\n");
        printf("A. Pension Completa\n");
        printf("B. Media Pension\n");
        printf("C. Solo Desayuno\n");
        printf("D. Solo Habitacion\n");
        scanf("%c" , &vec[i].TipoServicio);
        fflush(stdin);
        printf("Ingrese la ciudad de origen del huesped (solo Cordoba, San Luis, y La Rioja).\n");
        gets(vec[i].CiudadOrigen);
        fflush(stdin);
    }

    system("pause");
}

void imprimirHuespedes(Huesped vec[Huespedes])
{
    for(i=0;i<Huespedes;i++)
    {
        printf("Huesped %d\n" , i+1);
        printf("\n");
        printf("Nombre: %s\n" , vec[i].Nombre);
        printf("Apellido: %s\n" , vec[i].Apellido);
        printf("ID: %d\n" , vec[i].ID);
        printf("Dias de hospedaje: %d\n" , vec[i].Dias);
        printf("Importe a abonar: $%d\n" , vec[i].Importe);
        printf("Tipo de servicio: %c\n" , vec[i].TipoServicio);
        printf("Ciudad de origen: %s\n" , vec[i].CiudadOrigen);
        printf("\n");
        printf("-----------------------------------\n");
    }
    system("pause");
}

void huespedesPorCiudad(Huesped vec[Huespedes])
{

    int hlarioja = 0;
    int hsanluis = 0;
    int hcordoba = 0;


    for(i=0;i<Huespedes;i++)
    {
        if(strcmp("La Rioja", vec[i].CiudadOrigen) == 0)
        {
            hlarioja = hlarioja + 1;
        }
        else if(strcmp("San Luis", vec[i].CiudadOrigen) == 0)
        {
            hsanluis = hsanluis + 1;
        }
        else
        {
            hcordoba = hcordoba + 1;
        }
    }

    printf("Hay %d huespedes de La Rioja.\n" , hlarioja);
    printf("Hay %d huespedes de San Luis.\n" , hsanluis);
    printf("Hay %d huespedes de Cordoba.\n" , hcordoba);

    system("pause");
}

void importeTotal(Huesped vec[Huespedes])
{
    int importetotal = 0;

    for(i=0;i<Huespedes;i++)
    {
        if(vec[i].TipoServicio == 'A' && strcmp("Cordoba", vec[i].CiudadOrigen) == 0)
        {
            importetotal = importetotal + vec[i].Importe;
        }
    }

    printf("El importe total de los huespedes con pension completa y de Cordoba es de $%d.\n" , importetotal);
    system("pause");
}
