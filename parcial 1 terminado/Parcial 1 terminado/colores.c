#include <stdio.h>
#include <stdlib.h>
#include "colores.h"



void mostrarColores(eColor colores[], int tamC)
{

    if(colores != NULL && tamC > 0)
    {
       printf("   ****Lista de COLORES***\n");
       printf("ID     DESCRIPCION\n");
       printf("---------------------------\n");
     for (int i=0; i < tamC; i++)
     {
         mostrarUnColor(colores[i]);
     }

    }

}

void mostrarUnColor(eColor unColor)
{
    printf("%d     %10s\n", unColor.id, unColor.nombreColor);
}

int cargarDescripcionColor(eColor colores[], char nombreColor[], int idColor,int tamC)
{
    int error= 1;
    if(colores != NULL && tamC >0 && idColor > 0 && nombreColor != NULL)
    {
        for (int i=0; i < tamC ;i++)
        {   //Si en el array deportes.id se encuentra el IDdeporte q se esta buscando
            if (colores[i].id == idColor)
            {//Entonces copio en DescripcionDeporte la descripcion de deportes[i].desc
                strcpy(nombreColor,colores[i].nombreColor);
                error=0;
            }
        }
    }
    return error;
}

int validarIdColor(eColor colores[], int tamC, int idColor)
{
    int error=1;
    for (int i =0; i < tamC ;i++)
    {
        if(colores[i].id ==idColor)
        {
            error=0;
            break;
        }
    }

    return error;
}
