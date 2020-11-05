#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
3. Definir una estructura de tipo empleado que contendrá los siguientes campos:
i. número de legajo.
ii. nombre [30]
iii. apellido [30]
iv. cargo [30]
v. salario
vi. sexo
vii. antigüedad
Se deberán definir un array de tipo empleado y realizar las siguientes funciones:
● Función de carga del array
● Función que imprima todos los empleados que tienen un cargo
determinado, que deberá ser pasado como parámetro.
● Función que determine el monto total pagado a los empleados del array
● Función que imprima todos los empleados
● Agregar una función que realice una Búsqueda Binaria por número de
legajo (Realizando previamente el ordenamiento del array )

*/

typedef struct
{
    int Legajo;
    char Nombre[30];
    char Apellido[30];
    char Cargo[30];
    int Salario;
    char Sexo;
    int Antiguedad;

}Empleado;

int i;
int j;
int Empleados;

int main()
{
    int legajobuscado;

    Empleado vec[100];

    printf("Cuantos empleados quiere cargar?\n");
    scanf("%d" , &Empleados);

    cargaEmpleados(vec);
    system("cls");
    imprimirPorCargo(vec);
    system("cls");
    montoTotal(vec);
    system("cls");
    imprimirEmpleados(vec);
    system("cls");
    ordenarEmpleados(vec);
    printf("Empleados ordenados por legajo.\n");
    printf("\n");
    imprimirEmpleados(vec);

    system("cls");

    printf("Que legajo quieres buscar?\n");
    scanf("%d" , &legajobuscado);

    int legajoencontrado = BusquedaBinaria(legajobuscado, vec);

    if (legajoencontrado != -1)
        printf("El legajo se encontro en la posicion %d del vector de empleados." , legajoencontrado );
    else
        printf("El legajo no se encontro.");

    return 0;
}


void cargaEmpleados(Empleado vec[Empleados])
{
    for(i=0;i<Empleados;i++)
    {
        system("cls");
        printf("Empleado %d\n" , i+1);
        printf("\n");
        fflush(stdin);
        printf("Ingrese el numero de legajo del empleado.\n");
        scanf("%d" , &vec[i].Legajo);
        fflush(stdin);
        printf("Ingrese el nombre del empleado.\n");
        scanf("%s" , &vec[i].Nombre);
        fflush(stdin);
        printf("Ingrese el apellido del empleado.\n");
        scanf("%s" , &vec[i].Apellido);
        fflush(stdin);
        printf("Ingrese el cargo del empleado.\n");
        fgets(vec[i].Cargo,sizeof(vec[i].Cargo),stdin);
        fflush(stdin);
        printf("Ingrese el salario del empleado.\n");
        scanf("%d" , &vec[i].Salario);
        fflush(stdin);
        printf("Ingrese el sexo del empleado [M/F]\n");
        scanf("%c" , &vec[i].Sexo);
        fflush(stdin);
        printf("Ingrese la antiguedad del empleado (en anios)\n");
        scanf("%d" , &vec[i].Antiguedad);
    }
    system("pause");
}

void imprimirPorCargo(Empleado vec[Empleados])
{
    char cargobuscado[30];
    int encontrado = 1;
    fflush(stdin);
    printf("Que cargo quieres buscar?\n");
    fgets(cargobuscado,sizeof(cargobuscado),stdin);
    fflush(stdin);
    system("cls");
    for(i=0;i<Empleados;i++)
    {
        if(strcmp(cargobuscado, vec[i].Cargo) == 0)
        {
            encontrado = 0;
            printf("Empleado %d\n" , i+1);
            printf("\n");
            printf("Legajo: %d\n" , vec[i].Legajo);
            printf("Nombre: %s\n" , vec[i].Nombre);
            printf("Apellido: %s\n" , vec[i].Apellido);
            printf("Cargo: %s" , vec[i].Cargo);
            printf("Salario: $%d\n" , vec[i].Salario);
            printf("Sexo: %c\n" , vec[i].Sexo);
            printf("Antiguedad: %d\n", vec[i].Antiguedad);
            printf("\n");
            printf("-------------------------------\n");
        }
    }
    if(encontrado != 0)
        printf("No se encontro el cargo.\n");
    system("pause");
}

void montoTotal(Empleado vec[Empleados])
{
    int montototal = 0;

    for(i=0;i<Empleados;i++)
    {
        montototal = montototal + vec[i].Salario;
    }

    printf("Se paga un total de $%d entre todos los empleados." , montototal);
}

void imprimirEmpleados(Empleado vec[Empleados])
{
    for(i=0;i<Empleados;i++)
    {
        printf("Empleado %d\n" , i+1);
        printf("\n");
        printf("Legajo: %d\n" , vec[i].Legajo);
        printf("Nombre: %s\n" , vec[i].Nombre);
        printf("Apellido: %s\n" , vec[i].Apellido);
        printf("Cargo: %s" , vec[i].Cargo);
        printf("Salario: $%d\n" , vec[i].Salario);
        printf("Sexo: %c\n" , vec[i].Sexo);
        printf("Antiguedad: %d\n", vec[i].Antiguedad);
        printf("\n");
        printf("-------------------------------\n");
    }
    system("pause");
}

void ordenarEmpleados(Empleado vec[Empleados])
{
    Empleado aux;

    for(i=1;i<Empleados;i++)
    {
        for(j=0;j<Empleados-1;j++)
        {
            if(vec[j].Legajo > vec[j+1].Legajo)
            {
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
}

int BusquedaBinaria (int legajobuscado, Empleado vec[Empleados])
{
    int centro;
    int sup = Empleados - 1;
    int inf = 0;

    while(inf <= sup)
    {
        centro = (inf+sup)/2;

        if (vec[centro].Legajo == legajobuscado)
        {
            return centro;
        }
        else if(legajobuscado < vec[centro].Legajo)
        {
            sup = centro - 1;
        }
        else
        {
            inf = centro + 1;
        }
    }

    return -1;
}
