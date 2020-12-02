#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "mascota.h"
#include "validaciones.h"
#include "trabajo.h"
#include "servicios.h"
#include "fecha.h"


int buscarEspacioLibreTrabajo(eTrabajo trabajos[],int tam)
{
    int indice= -1;

    for(int i=0; i < tam; i++)
    {
        if(trabajos[i].isEmpty==1)// si esta vacia
        {
            indice= i;
            break;// a penas busque la primera para.
        }
    }

    return indice;
}

int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int error=1; //suponemos q hay error

    if(trabajos != NULL && tam > 0) //valida los ingresos.
    {
        for (int i=0; i < tam; i++)
        {
            trabajos[i].isEmpty= 1; //esta vacio
        }
        error=0;
    }
    return error;
}

int altaTrabajo(eTrabajo trabajos[], int tamTR, int idTrabajo ,eServicio servicios[], int tamS ,eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[],int tamT)
{
    int error=1;
    int indice;
    int idServicio;
    int idMascota;
    eFecha auxFecha;
    eTrabajo nuevoTrabajo;

    if(trabajos != NULL && tamTR > 0 && idTrabajo >0 && servicios != NULL && tamS > 0 && mascotas != NULL && tamM >0)
    {
        indice = buscarEspacioLibreTrabajo(trabajos, tamTR);

        if(indice == -1)
        {
            printf("Sistema completo.\n");
        } else {

            nuevoTrabajo.isEmpty = 0;
            nuevoTrabajo.id=idTrabajo;   //Se le pasa el id generado

            mostrarMascotas(mascotas, tamM, colores, tamC, tipos,tamT);
            idMascota=getInt("Ingrese id mascota: ", "Error. reingrese id mascota: ",1,1000);


            while(validarIdMascota(mascotas,tamM,idMascota))
            {
                idMascota=getInt("Ingrese id mascota: ", "Error. reingrese id mascota: ",1,1000);
            }
            nuevoTrabajo.idMascota= idMascota;

            mostrarServicios(servicios, tamS);
            idServicio= getInt("Ingrese id servicio:" ,"Error. REingres eid servico: ",20000,30000);
            while(validarIdServicio(servicios,tamS,idServicio))
            {
               idServicio= getInt("Ingrese id servicio:" ,"Error. REingres eid servico: ",20000,30000);

            }
            nuevoTrabajo.idServicio= idServicio;

            auxFecha.dia= getInt("Ingrese el dia :","Error.Reingrese dia: ",1,30);
            auxFecha.mes= getInt("Ingrese el mes :","Error. Reingrese mes: ",1,12);
            auxFecha.anio= getInt("Ingrese el año :","Error. Reingrese año:",2020,2050);
            nuevoTrabajo.fecha= auxFecha;

            trabajos[indice] = nuevoTrabajo; //Se pasa la persona creada a la lista

            error=0; //Todo ok

        }
    }
    return error;
}

void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[],int tamS, eMascota mascotas[], int tamM)
{
    char descripcionServicio[25];
    char nombreMascota[20];

    cargarDescripcionServicio(servicios, unTrabajo.idServicio, descripcionServicio, tamS);
    cargarDescripcionMascota(mascotas, unTrabajo.idMascota, nombreMascota,tamM);

    printf("%4d %20s %20s   %2d/%2d/%2d \n",unTrabajo.id,nombreMascota,descripcionServicio ,
                                                                               unTrabajo.fecha.dia,
                                                                               unTrabajo.fecha.mes,
                                                                               unTrabajo.fecha.anio);

}


int cargarDescripcionMascota(eMascota mascotas[],int idMascota, char nombreMascota[], int tamM)
{
    int error= 1;
    if(mascotas != NULL && tamM >0 && idMascota > 0 && nombreMascota != NULL)
    {
        for (int i=0; i < tamM ;i++)
        {   //Si en el array deportes.id se encuentra el IDdeporte q se esta buscando
            if (mascotas[i].id == idMascota)
            {//Entonces copio en DescripcionDeporte la descripcion de deportes[i].desc
                strcpy(nombreMascota,mascotas[i].nombre);
                //printf("dentro %s", nombreMascota);
                error=0;
                break;
            }
        }
    }
    return error;
}


void mostrarTrabajos(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS, eMascota mascotas[], int tamM)
{
    int flag=0;

    if(trabajos != NULL && tamT >0 && servicios != NULL && tamS > 0)
    {
        system("cls");
        printf("\n*****LISTADO DE TRABAJOS *****\n");
        printf("  ID             MASCOTA            SERVICIO          FECHA\n");

        for (int i=0; i < tamT; i++)
        {
            if(trabajos[i].isEmpty==0 && mascotas[i].isEmpty==0) //
            {
                mostrarTrabajo(trabajos[i],servicios,tamS, mascotas, tamM);
                flag=1; // Flag para ver si estan vacios
            }
        }
        if(!flag) //flag==0;
        {
            printf("       No hay trabajs en la lista.\n");
        } else {
            printf("\n\n");
        }

    }
}
