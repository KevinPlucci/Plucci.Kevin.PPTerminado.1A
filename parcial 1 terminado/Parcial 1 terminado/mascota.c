#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "mascota.h"
#include "dataStore.h"
#include "tipos.h"
#include "colores.h"

// MASCOTAS
int menu()
{
    int opcion;
    system("cls");

    printf("************************ ABM *********************\n\n");
    printf("1 Alta\n");
    printf("2 Modificar\n");
    printf("3 Baja\n");
    printf("4 Listar Mascotas\n");
    printf("5 Listar tipos\n");
    printf("6 Listar colores\n");
    printf("7 Listar servicios\n");
    printf("8 Alta trabajo.\n");
    printf("9 Listar trabajos\n");
    printf("10 Informes de las mascotas\n");

    printf("11 Salir\n\n");
    opcion= getInt("Ingrese opcion: ", "Error. Reingrese opcion: ",1,11);

    return opcion;
}

int buscarEspacioLibre(eMascota mascotas[],int tamM)
{
    //debe ser un entero que no sea un indice posible x eso se usa -1
    int indice= -1;
    int i;

    for(i=0; i < tamM; i++)
    {
        if(mascotas[i].isEmpty==1)// si esta vacia
        {
            indice= i;
            break;// a penas busque la primera para.
        }
    }

    return indice;
}

int altaMascota(eMascota mascotas[], int tamM, int idM ,eColor colores[], int tamC ,eTipo tipos[], int tamT)
{
    int todoOk= -1;
    int indice;
    int idColor;
    int idTipo;
    int stringOk;
    int auxInt;
    char auxCadena[30];
    eMascota nuevaMascota;

    if(mascotas != NULL && tamM > 0 && idM >0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0)
    {
        indice = buscarEspacioLibre(mascotas, tamM);

        if(indice == -1)
        {
            printf("Sistema completo.\n");
        } else {

            nuevaMascota.isEmpty = 0;
            nuevaMascota.id=idM;   //Se le pasa el id generado


            stringOk= getString(auxCadena,"Ingrese nombre: ", "Error. Reingrese nombre: ",20);
            if(stringOk==1)
            {
                strcpy(nuevaMascota.nombre,auxCadena);
            }

            auxInt= getInt("Edad: ", "Error.Reingrese edad: ",1,20);
            nuevaMascota.edad= auxInt;

            mostrarColores(colores,tamC);
            idColor= getInt("Ingrese id color: ", "Error. Rreingrese color:",5000,6000);

            while(validarIdColor(colores,tamC,idColor))
            {
                printf("Error. Reingrese el id del color: ");
                idColor= getInt("Ingrese id color: ", "Error. Rreingrese color:",5000,6000);

            }
            nuevaMascota.idColor= idColor;

            mostrarTipos(tipos, tamT);
            idTipo=getInt("Ingrese id tipo: ","Error. Reingrese id tipo: ",1000,6000);
            while(validarIdTipo(tipos,tamT,idTipo))
            {
                idTipo=getInt("Ingrese id tipo: ","Error. Reingrese id tipo: ",1000,6000);

            }
            nuevaMascota.idTipo= idTipo;
            mascotas[indice] =nuevaMascota; //Se pasa la persona creada a la lista
            todoOk=1; //Todo ok

        }
    }
    return todoOk;
}

void mostrarMascota(eMascota unaMascota, eColor colores[],int tamC, eTipo tipos[], int tamT)
{
    char nombreColor[20];
    char nombreTipo[20];

    cargarDescripcionColor(colores,nombreColor, unaMascota.idColor, tamC);
    cargarDescripcionTipo(tipos, nombreTipo, unaMascota.idTipo,tamT);


    printf("%4d %15s %6d %15s %15s \n", unaMascota.id, unaMascota.nombre,unaMascota.edad,nombreColor,nombreTipo);
}

void mostrarMascotas(eMascota mascotas[],int tamM,eColor colores[],int tamC,eTipo tipos[],int tamT)
{

    int flag=0;

    if( mascotas != NULL && tamM >0 && colores != NULL && tamC > 0 && tipos != NULL && tamT >0)
    {
        printf("************************Lista de Mascotas*************************************\n");
        printf("*  ID |      NOMBRE    | EDAD |    COLOR    |          TIPO                 |*\n");
        printf("******************************************************************************\n");

        for (int i=0; i < tamM; i++)
        {
            if(mascotas[i].isEmpty==0)
            {
                mostrarMascota(mascotas[i],colores,tamC, tipos, tamT);
                flag=1; // Flag para ver si estan vacios
            }
        }

        if(!flag) //flag==0;
        {
            printf("       No hay mascotas en la lista.\n");
        } else {
            printf("\n\n");
        }

    }

}
int buscarMascotaById(eMascota mascotas[], int tamM, int id)  //PONER ISEMPTY
{
    int indice= -1;

    for(int i=0;  i < tamM ; i++)
    {
        if(mascotas[i].id == id && mascotas[i].isEmpty == 0)
        {
            indice= i;
            break;
        }
    }
    return indice;
}

int bajaMascota(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int indice;
    char confirma;
    int id;
    int huboBaja=0;


    if( mascotas != NULL && tamM >0 && colores != NULL && tamC > 0 && tipos != NULL && tamT >0)
    {

        system("cls");
        printf("************Baja**************\n\n");
        mostrarMascotas(mascotas, tamM, colores, tamC, tipos, tamT);
        id = getInt("Ingrese ID de mascota a eliminar: ", "Error. Reingrese id: ", 1,100);
        indice= buscarMascotaById(mascotas, tamM, id); //le paso el id para ver si existe

        if(indice == -1)
        {
            printf("no hay ninguna mascota con ese legajo.\n");
        } else {
                // printf("nombre edad etc ");
                mostrarMascota(mascotas[indice], colores, tamC,tipos, tamT);

                printf("Confirma la baja?(s/n) : \n"); // VALIDAR!!!
                fflush(stdin);
                scanf("%c",&confirma);
                if(confirma == 's')
                {
                    mascotas[indice].isEmpty=1;
                     printf("Se ha realizado la baja con exito\n\n");
                     huboBaja=1;
                } else {
                    printf("Se cancelo la baja\n\n");
                }
              }
    }
    return huboBaja;
}

void modificarMascota(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int indice;
    char confirma;
    int id; //ID de la mascota
    int edadAux;
    int idTipoAux;

    if( mascotas != NULL && tamM >0 && colores != NULL && tamC > 0 && tipos != NULL && tamT >0)
    {
        system("cls");
        printf("************Modificar**************\n\n");
        mostrarMascotas(mascotas, tamM, colores, tamC, tipos, tamT);
        id= getInt("Ingrese id mascota a modificar: ", "Reingrese id mascota modificar: ",1,1000);
        indice= buscarMascotaById(mascotas, tamM, id); //le paso el id para ver si existe

        if(indice == -1)
        {
            printf("no hay ninguna mascota con ese legajo.\n");
        } else {
                // printf("nombre edad etc ");
                mostrarMascota(mascotas[indice], colores, tamC,tipos, tamT);

                confirma=getCharacter("Confirma modificacion?(s):","Error, reingrese(s/n):",'a','z');

                if(confirma=='s')
                {
                    switch(menuModif())
                    {
                        case 'a':
                            mostrarTipos(tipos, tamT);

                            idTipoAux= getInt("Ingrese id tipo: ", "Error. Rreingre tipo:",1000,6000);

                            while(validarIdTipo(tipos,tamT,idTipoAux))
                            {
                                idTipoAux= getInt("Ingrese id tipo: ", "Error. Rreingre tipo:",1000,6000);
                            }
                            mascotas[indice].idTipo= idTipoAux;

                            break;
                        case 'b':
                            edadAux= getInt("Ingrese edad: ", "Error. Reingrese edad: ",1,20);
                            mascotas[indice].edad= edadAux;

                            break;
                        case 'c':
                            printf("\n\nSe cancelo la operacion");
                            break;
                        default:
                            printf("\n\nIngrese una opcion valida.");
                    }
                } else {
                            printf("\n\nSe cancelo la operacion\n\n");
                        }
               }//fin else
        }//fin if grande
}
char menuModif()
{
    char opcion;

    printf("\n\n **Menu modificaciones**\n\n");
    printf("a-Tipo\n");
    printf("b-Edad\n");
    printf("c-Cancelar.\n");

    opcion= getCharacter("Ingrese opcion: ", "Error.Reingrese opcion:",'a','z');


    return opcion;

}

int inicializarMascotas(eMascota mascotas[], int tamM)
{
    int error=1; //suponemos q hay error

    if(mascotas != NULL && tamM > 0) //valida los ingresos.
    {
        for (int i=0; i < tamM; i++)
        {
            mascotas[i].isEmpty= 1; //esta vacio
        }
        error=0;
    }
    return error;
}

int validarIdMascota(eMascota mascotas[], int tamM, int idMascota) //IS EMPTY
{
    int error=1;
    for (int i =0; i < tamM ;i++)
    {
        if(mascotas[i].id ==idMascota && mascotas[i].isEmpty==0)
        {
            error=0;
            break;
        }
    }

    return error;
}

int isEmpty(eMascota mascotas[], int tam)
{

    int isEmpty = 1;

    for(int i=0; i<tam; i++)
    {
        if(mascotas[i].isEmpty == 0)
        {
            isEmpty = 0;
            break;
        }
    }
    return isEmpty;
}

void ordenarMascotasPorTipoYNombre(eMascota mascotas[], int tamM, int idM ,eColor colores[], int tamC ,eTipo tipos[], int tamT)
{
    eMascota mascotaAux;
    char descripcionTipoI[20];
    char descripcionTipoJ[20];

    if(mascotas!= NULL && tamM >0)
    {
        for(int i =0; i < tamM- 1; i++)
        {
            for (int j= i+1; j <tamM;j++)
            {
                cargarDescripcionTipo(tipos,descripcionTipoI,mascotas[i].idTipo,tamT);
                cargarDescripcionTipo(tipos,descripcionTipoJ,mascotas[j].idTipo,tamT);
                if (strcmp(descripcionTipoI,descripcionTipoJ)>0)
                {
                    mascotaAux =mascotas[i];
                    mascotas[i]=mascotas[j];
                    mascotas[j]= mascotaAux;
                }
                else if((strcmp(descripcionTipoI,descripcionTipoJ)==0) && strcmp(mascotas[i].nombre,mascotas[j].nombre)>0)
                {
                    mascotaAux =mascotas[i];
                    mascotas[i]=mascotas[j];
                    mascotas[j]= mascotaAux;
                }
            }
        }
    }
    mostrarMascotas(mascotas,tamM,colores,tamC,tipos,tamT);
}

int hardcodearMascotas(eMascota mascotas[], int tam, int cant)
{
    int retorno=1;

    if(mascotas != NULL && tam >0 && cant <= tam)
    {   retorno=0;

        for(int i = 0; i < cant ; i++)
        {

            mascotas[i].id= ids[i];
            strcpy(mascotas[i].nombre, nombresMascotas[i]);
            mascotas[i].idTipo=idTipos[i];
            mascotas[i].edad= edades[i];
            mascotas[i].idColor= idColores[i];
            mascotas[i].isEmpty=0;
            retorno++;
        }
    }

    return retorno;
}
