#include <stdio.h>
#include <stdlib.h>

/*
1.
i. Función que me devuelva el alumno de mayor promedio.
ii. Función que me devuelva la cantidad de alumnos reprobados en el primer
parcial(notas menores a 4).
iii. Función que me imprima cuántas mujeres y cuántos varones hay.
iv. Función que me ordene de mayor a menor el array teniendo en cuenta el
número de legajo.
v. Función que haga una Búsqueda Secuencial, pasando como parametro
de busqueda el legajo del alumno
vi. Funcione que muestre el legajo y el nombre de los tres alumnos de mayor
promedio.

2.
Utilizando la estructura anterior y con las funciones completadas realizar lo siguiente:
i. Función que me devuelva el alumno de mayor promedio.
ii. Función que me devuelva la cantidad de alumnos reprobados en el primer
parcial(notas menores a 4).
iii. Función que me imprima cuántas mujeres y cuántos varones hay.
iv. Función que me ordene de mayor a menor el array teniendo en cuenta el
número de legajo.
v. Función que haga una Búsqueda Secuencial, pasando como parametro
de busqueda el legajo del alumno
vi. Funcione que muestre el legajo y el nombre de los tres alumnos de mayor
promedio.
*/

typedef struct // Definición estructura alumno.
{
    int Edad;
    char Nombre[30];
    char Apellido[30];
    int Legajo;
    char Sexo;
    int notaP1;
    int notaP2;

}Alumno;

int i; // Esta variable es para los cualquier for que hagas en una funcion.
int j;
int Alumnos; // Variable que dira cuantos alumnos se cargaran al vector.

int main()
{

    int legajobuscado;

    Alumno vec[100];
    printf("Cuantos alumnos desea cargar?\n");
    scanf("%d" , &Alumnos);
    cargarAlumnos(vec);
    system("cls");
    imprimirAlumnos(vec);
    system("cls");
    editarAlumnos(vec);
    system("cls");
    mayorPromedio(vec);
    system("cls");
    reprobadosParcialI(vec);
    system("cls");
    imprimirMujeresVarones(vec);
    system("cls");
    ordenarPorLegajo(vec);

    printf("Inserta el legajo de algun alumno.\n");
    scanf("%d" , &legajobuscado);

    int legajoencontrado = busquedaSecuencial(legajobuscado , vec);

    if(legajoencontrado != -1)
        printf("El alumno si se encontro en la posicion %d\n" , legajoencontrado);
    else
        printf("El alumno no se ha encontrado.\n");

    system("pause");
    system("cls");

    imprimirMejoresPromedios(vec);

    return 0;
}

void cargarAlumnos(Alumno vec[Alumnos]) // Funcion para cargar alumnos
{
    for(i=0;i<Alumnos;i++)
    {
        system("cls");
        fflush(stdin);
        printf("Alumno %d\n" , i+1);
        printf("\n");
        printf("Ingresar la edad del alumno\n");
        scanf("%d" , &vec[i].Edad);
        fflush(stdin);
        printf("Ingresar el nombre del alumno\n");
        scanf("%s" , &vec[i].Nombre);
        fflush(stdin);
        printf("Ingresar el apellido del alumno\n");
        scanf("%s" , &vec[i].Apellido);
        fflush(stdin);
        printf("Ingresar el legajo del alumno\n");
        scanf("%d" , &vec[i].Legajo);
        fflush(stdin);
        printf("Ingresar el sexo del alumno [M/F] \n");
        scanf("%c" , &vec[i].Sexo);
        do
        {
            printf("Ingresar la nota del primer parcial\n");
            scanf("%d" , &vec[i].notaP1);

        }while(vec[i].notaP1 < 0 || vec[i].notaP1 > 10);

        do
        {
            printf("Ingresar la nota del segundo parcial\n");
            scanf("%d" , &vec[i].notaP2);

        }while(vec[i].notaP2 < 0 || vec[i].notaP2 > 10);

    }
    system("pause");
}

void imprimirAlumnos(Alumno vec[Alumnos]) // Funcion para mostrar los alumnos por pantalla
{
    for(i=0;i<Alumnos;i++)
    {
        printf("Alumno %d:\n" , i+1);
        printf("\n");
        printf("Edad: %d\n" , vec[i].Edad);
        printf("Nombre: %s\n" , vec[i].Nombre);
        printf("Apellido: %s\n" , vec[i].Apellido);
        printf("Legajo: ELSI%d\n" , vec[i].Legajo);
        printf("Sexo: %c\n" , vec[i].Sexo);
        printf("\n");
        printf("Nota del Parcial I: %d\n" , vec[i].notaP1);
        printf("Nota del Parcial II: %d\n" , vec[i].notaP2);
        printf("\n");
        printf("-------------------------------\n");
    }
    system("pause");
}

void editarAlumnos(Alumno vec[Alumnos]) // Funcion para modificar los datos de algun alumno dependiendo su legajo
{
    int Legajobuscado;

    printf("Ingrese el legajo del alumno que desea modificar:\n");
    scanf("%d" , &Legajobuscado);

    for(i=0;i<Alumnos;i++)
    {
        if(Legajobuscado == vec[i].Legajo)
        {
            Legajobuscado = -1;
            printf("Alumno %d\n" , i+1);
            printf("\n");
            printf("Ingrese la edad del alumno\n");
            scanf("%d" , &vec[i].Edad);
            fflush(stdin);
            printf("Ingrese el nombre del alumno\n");
            scanf("%s" , &vec[i].Nombre);
            fflush(stdin);
            printf("Ingrese el apellido del alumno\n");
            scanf("%s" , &vec[i].Apellido);
            fflush(stdin);
            printf("Ingrese el legajo del alumno\n");
            scanf("%d" , &vec[i].Legajo);
            fflush(stdin);
            printf("Ingrese el sexo del alumno [M/F] \n");
            scanf("%c" , &vec[i].Sexo);
            fflush(stdin);

            do
            {
                printf("Ingrese la nota del primer parcial\n");
                scanf("%d" , &vec[i].notaP1);

            }while(vec[i].notaP1 < 0 || vec[i].notaP1 > 10);

            do
            {
                printf("Ingrese la nota del segundo parcial\n");
                scanf("%d" , &vec[i].notaP2);

            }while(vec[i].notaP2 < 0 || vec[i].notaP2 > 10);

            printf("Alumno modificado satisfactoriamente!\n");

            system("pause");
            system("cls");

            printf("Alumno %d:\n" , i+1);
            printf("\n");
            printf("Edad: %d\n" , vec[i].Edad);
            printf("Nombre: %s\n" , vec[i].Nombre);
            printf("Apellido: %s\n" , vec[i].Apellido);
            printf("Legajo: ELSI%d\n" , vec[i].Legajo);
            printf("Sexo: %c\n" , vec[i].Sexo);
            printf("\n");
            printf("Nota del Parcial I: %d\n" , vec[i].notaP1);
            printf("Nota del Parcial II: %d\n" , vec[i].notaP2);

        }
    }
    if(Legajobuscado != -1)
        printf("No se encontro el alumno.\n");
    system("pause");
}

void mayorPromedio(Alumno vec[Alumnos])
{
    float mayor = 0;
    float resultado;

    for(i=0;i<Alumnos;i++)
    {
        resultado = (float) (vec[i].notaP1 + vec[i].notaP2) / 2;
        if (mayor <= resultado)
        {
            mayor = resultado;
            j = i;
        }
    }
    printf("El alumno con mayor promedio es:\n");
    printf("\n");
    printf("Alumno %d\n" , j+1);
    printf("\n");
    printf("Edad: %d\n" , vec[j].Edad);
    printf("Nombre: %s\n" , vec[j].Nombre);
    printf("Apellido: %s\n" , vec[j].Apellido);
    printf("Legajo: ELSI%d\n" , vec[j].Legajo);
    printf("Sexo: %c\n" , vec[j].Sexo);
    printf("\n");
    printf("Nota del Parcial I: %d\n" , vec[j].notaP1);
    printf("Nota del Parcial II: %d\n" , vec[j].notaP2);
    printf("Promedio: %2.1f\n" , mayor);

    system("pause");
}

void reprobadosParcialI(Alumno vec[Alumnos])
{
    int reprobados = 0;

    for(i=0;i<Alumnos;i++)
    {
        if(vec[i].notaP1 < 4)
        {
            reprobados = reprobados + 1;
        }
    }

    printf("Reprobados en el Parcial I:\n");
    printf("%d Alumnos.\n" , reprobados);
    system("pause");
}

void imprimirMujeresVarones(Alumno vec[Alumnos])
{
    int varones = 0;
    int mujeres = 0;

    for(i=0;i<Alumnos;i++)
    {
        if(vec[i].Sexo == 'M')
            varones = varones + 1;
        else
            mujeres = mujeres + 1;
    }
    printf("Hay un total de %d alumnos varones.\n" , varones);
    printf("Hay un total de %d alumnos mujeres.\n" , mujeres);
    system("pause");
}

void ordenarPorLegajo(Alumno vec[Alumnos])
{
    Alumno aux;

    for(i=1;i<Alumnos;i++)
    {
        for(j=0;j<Alumnos-1;j++)
        {
            if(vec[j].Legajo < vec[j+1].Legajo)
            {
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
}

int busquedaSecuencial(int legajobuscado , Alumno vec[Alumnos])
{
    for(i=0;i<Alumnos;i++)
    {
        if (legajobuscado == vec[i].Legajo)
        {
            return i+1;
        }
    }
    return -1;
}

void imprimirMejoresPromedios(Alumno vec[Alumnos])
{
    Alumno aux;

    float prom;

    for(i=1;i<Alumnos;i++)
    {
        for(j=0;j<Alumnos-1;j++)
        {
            if(( (float) vec[j].notaP1+vec[j].notaP2) / 2 <  ( (float) vec[j+1].notaP1+vec[j+1].notaP2) / 2)
            {
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }

        }
    }

    printf("Los alumnos con mayor promedio son:\n");
    printf("\n");

    for(i=0;i<3;i++)
    {
        prom = (float) (vec[i].notaP1+vec[i].notaP2)/2;
        printf("Nombre: %s\n" , vec[i].Nombre);
        printf("Legajo: ELSI%d\n" , vec[i].Legajo);
        printf("Promedio: %2.1f\n" , prom);
        printf("-----------------------\n");
    }
    system("pause");
}
