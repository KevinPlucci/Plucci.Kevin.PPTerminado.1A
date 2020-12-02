#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"
//SERVICIOS
void mostrarServicios(eServicio servicios[],int tamS)
{

    printf("\nLista de servicios\n");
    printf("id              Descripcion     Precio \n");
    printf("-----------------------------------------\n");

    for(int i=0; i<tamS; i++)
    {
        printf("%5d      %15s      $%2.f \n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);
    }

}

int validarIdServicio(eServicio servicios[], int tamS, int idServicio)
{
    int error=1;
    for (int i =0; i < tamS ;i++)
    {
        if(servicios[i].id ==idServicio)
        {
            error=0;
            break;
        }
    }

    return error;
}

int cargarDescripcionServicio(eServicio servicios[], int idServicio, char descripcionServicio[], int tamS)
{
    int error=1;
    if(servicios != NULL && tamS >0 && idServicio > 0 && descripcionServicio != NULL)
    {
        for (int i=0; i < tamS ;i++)
        {   //Si en el array deportes.id se encuentra el IDdeporte q se esta buscando
            if (servicios[i].id == idServicio)
            {//Entonces copio en DescripcionDeporte la descripcion de deportes[i].desc
                strcpy(descripcionServicio,servicios[i].descripcion);
                error=0;
                //break;
            }
        }
    }
    return error;
}
