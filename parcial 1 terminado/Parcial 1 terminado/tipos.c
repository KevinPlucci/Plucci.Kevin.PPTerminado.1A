#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

//TIPOS

void mostrarUnTipo(eTipo unTipo)
{
    printf("%d     %20s\n", unTipo.id, unTipo.descripcion);
}

void mostrarTipos(eTipo tipos[], int tamT)
{

    if(tipos != NULL && tamT > 0)
    {
       printf("   ****Lista de TIPOS***\n");
       printf("ID   |  DESCRIPCION\n");
       printf("---------------------------\n");
     for (int i=0; i < tamT; i++)
     {
         mostrarUnTipo(tipos[i]);
     }

    }

}

int cargarDescripcionTipo(eTipo tipos[], char descripcionTipo[], int idTipo,int tamT)
{
    int error= 1;
    if(tipos != NULL && tamT >0 && idTipo > 0 && descripcionTipo != NULL)
    {
        for (int i=0; i < tamT ;i++)
        {   //Si en el array deportes.id se encuentra el IDdeporte q se esta buscando
            if (tipos[i].id == idTipo)
            {//Entonces copio en DescripcionDeporte la descripcion de deportes[i].desc
                strcpy(descripcionTipo,tipos[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}

int validarIdTipo(eTipo tipos[], int tamT, int idTipo)
{
    int error=1;
    for (int i =0; i < tamT ;i++)
    {
        if(tipos[i].id ==idTipo)
        {
            error=0;
            break;
        }
    }

    return error;

}
