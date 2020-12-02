#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "validaciones.h"
#include "mascota.h"
#include "trabajo.h"



char menuInformes()
{
    char opcion;
    system("cls");
    printf("**** Menu de Informes ****\n\n");
    printf("a- Mostrar las mascotas del color seleccionado.\n");
    printf("b- Mostrar mascotas de un tipo seleccionado.\n");
    printf("c- Informar la o las mascotas de menor edad\n");
    printf("d- Listar de las mascotas separadas por tipo.\n");
    printf("e- Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo.\n");
    printf("f- Mostrar el o los colores con mas cantidad de mascotas\n");
    printf("g- Mostrar trabajos de una mascota seleccionada\n");
    printf("h- Mostrar suma de servicios de una mascota seleccionada\n");
    printf("i- Mostrar mascotas con fecha y servicio seleccionado.\n");
    printf("z- Salir\n\n");
    fflush(stdin);
    opcion=getCharacter("Ingrese opcion del menu: ","Error. Reingrese opcion: ",'a','z');

    return opcion;
}

void informesDeMascotas(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT,
        eTrabajo trabajos[], int tamTR,

                        int idTrabajo ,eServicio servicios[], int tamS)
{
    char seguir ='s';
    char confirma;

    do
    {
        switch(menuInformes())
        {
        case 'a':
            //INFORMAR POR COLOR SELECCIONADO
            informarMascotasPorColorSelec(mascotas,tamM,colores,tamC,tipos,tamT);
            system("pause");
            break;

        case 'b':
            //INFORMAR POR TIPO SELECCIONADO
            informarMascotasPorTipoSelec(mascotas,tamM,colores,tamC,tipos,tamT);
            system("pause");
            break;

        case 'c':
            //INFORMAR MENORES EDAD
            informarMascotaMenores(mascotas,tamM,colores,tamC,tipos,tamT);
            system("pause");
            break;
        case 'd':
            //LISTADO SEPARADO POR TIPO
            mostrarMascotasPorTipo(mascotas,tamM,colores,tamC,tipos,tamT);
            system("pause");
            break;
        case 'e':
            //INFORMAR CANTIDAD POR COLOR Y TIPO
            elegirColorTipoYContar(mascotas,tamM,colores,tamC,tipos,tamT);
            system("pause");
            break;
        case 'f':
            //INFORMAR EL O LOS COLORES MAS ELEGIDOS
            mostrarColoresMasElegidos(mascotas,tamM,colores,tamC);
            system("pause");
            break;

         case 'g': //BONUS TRACK
            //Trabajos a una mascota seleccionada
            mostrarTrabajosDeMascotaSelec(trabajos,tamTR,idTrabajo,servicios,tamS,mascotas,tamM,colores,tamC,tipos,tamT);
            system("pause");
            break;
         case 'h':
            //Importe de servicios a una mascota seleccionada
            mostrarSumaServiciosDeMascotaSelec(trabajos,tamTR,idTrabajo,servicios,tamS,mascotas,tamM,colores,tamC,tipos,tamT);
            system("pause");
            break;
         case 'i':
            mostrarMascotasDeServicioSelec(trabajos,tamTR,idTrabajo,servicios,tamS,mascotas,tamM);
            system("pause");
            break;

        case 'z':
            confirma=getCharacter("Confirmar salida?(s/n): ","Error.Reingrese (s/n):",'a','z');
            if(confirma=='s')
            {
                seguir='n';
            }
            break;
        }
    }
    while(seguir =='s');
}

void informarMascotasPorColorSelec(eMascota mascotas[], int tamM, eColor colores[],int tamC,eTipo tipos[], int tamT)
{
    int idColor;
    int flag=0;

    system("cls");
    printf("*********************************************************************\n");
    printf("************ Informe mascotas por un color ***********\n\n");
    mostrarColores(colores,tamC);
    idColor= getInt("Ingrese id del color: ", "Error. Reingrese id del color:",5000,6000);
    printf("ID         |MASCOTA      |  EDAD  | COLOR   | TIPO  \n\n"); //DEPENDE QUE HAY QUE MOSTRAR

    for(int i=0; i < tamM; i++)
    {
        if(mascotas[i].isEmpty == 0 && mascotas[i].idColor == idColor)
		{
			mostrarMascota(mascotas[i],colores,tamC,tipos,tamT);
			flag = 1;
		}
    }
    if(flag==0)
    {
        printf("\nNo hay mascotas para listar\n\n");
    }
}

void informarMascotasPorTipoSelec(eMascota mascotas[], int tamM, eColor colores[],int tamC,eTipo tipos[], int tamT)
{
    int idTipo;
    int flag=0;

    system("cls");
    printf("*********************************************************************\n");
    printf("************ Informe mascotas por un color ***********\n\n");
    mostrarTipos(tipos,tamT);
    idTipo= getInt("Ingrese id del tipo: ", "Error. Reingrese id del tipo:",1000,6000);
    printf("ID         |MASCOTA      |  EDAD  | TIPO    | COLOR    |\n\n"); //DEPENDE QUE HAY QUE MOSTRAR

    for(int i=0; i < tamT; i++)
    {
        if(mascotas[i].isEmpty == 0 && mascotas[i].idTipo == idTipo)
		{
			mostrarMascota(mascotas[i],colores,tamC,tipos,tamT);
			flag = 1;
		}
    }
    if(flag==0)
    {
        printf("\nNo hay mascotas para listar\n\n");
    }
}

void informarMascotaMenores(eMascota mascotas[], int tamM, eColor colores[],int tamC,eTipo tipos[], int tamT)
{
    int menorMascota;
    int flag=0;

    for(int i=0; i<tamM; i++)
    {
        if(mascotas[i].isEmpty == 0 && i==0)
        {
            menorMascota = mascotas[i].edad;
        } else if(mascotas[i].isEmpty==0 && mascotas[i].edad < menorMascota)
            {
                 menorMascota = mascotas[i].edad;
            }

    }

    system("cls");
    printf("*********************************************************************\n");
    printf("************ Informe mascotas mas jovenes (menor edad) ***********\n\n");
    printf("ID         |MASCOTA      |  EDAD  | TIPO    | COLOR    |\n\n");

     for(int i=0; i<tamM; i++)
     {
            if(mascotas[i].edad == menorMascota)
            {
                mostrarMascota(mascotas[i], colores,tamC,tipos,tamT);
                flag=1;
            }
    }
    if(flag==0)
    {
        printf("\nNo hay mascotas para listar\n\n");
    }

}

void mostrarMascotasPorTipo(eMascota mascotas[],int tamM,eColor colores[], int tamC, eTipo tipos[],int tamT)
{

    int flag =0;
    char descripcionTipo[20];

    if(mascotas != NULL && tamM > 0 && tipos != NULL && tamT > 0)
    {

        system("cls");
        printf("*********************************************************************\n");
        printf("*************************Informe mascotas por Tipo*******************\n");
        printf("NOMBRE         TIPO\n");
        printf("----------------------------------------\n");

        for(int i=0;i<tamT;i++) //FOR QUE RECORRE TIPOS
        {
                cargarDescripcionTipo(tipos,descripcionTipo,tipos[i].id,tamT);
                printf("\nListado de mascotas de tipo %s\n\n",descripcionTipo);

            for(int j=0;j<tamM;j++) //FOR QUE RECORRE A LAS MASCOTAS
            {

               if(mascotas[j].idTipo == tipos[i].id && mascotas[j].isEmpty ==0)
                {
                mostrarMascota(mascotas[j],colores,tamC,tipos,tamT);
                flag=1;
                }
            }
            if(flag==0)
            {
                printf("No hay mascotas de ese tipo.\n");
            }
        }
    }

}

void elegirColorTipoYContar(eMascota mascotas[],int tamM,eColor colores[], int tamC, eTipo tipos[],int tamT)
{

    int idColor;
    int idTipo;
    int contadorMascotas=0;
    int flag=0;
    char nombreColor[20];
    char descripcionTipo[20];

    mostrarTipos(tipos, tamT);
    idTipo=getInt("Ingrese id tipo: ","Error. Reingrese id tipo: ",1000,5000);
    while(validarIdTipo(tipos,tamT,idTipo))
    {
      idTipo=getInt("Ingrese id tipo: ","Error. Reingrese id tipo: ",1000,5000);
    }

    mostrarColores(colores, tamC);
    idColor=getInt("Ingrese id color: ","Error. Reingrese id color: ",5000,6000);
    while(validarIdColor(colores,tamC,idColor))
    {
      idColor=getInt("Ingrese id color: ","Error. Reingrese id color: ",5000,6000);
    }

    system("cls");
    printf("*********************************************************************\n");
    printf("******************INFORMAR MASCOTAS POR TIPO Y COLOR ****************\n");
    printf("ID           MASCOTA          TIPO           COLOR\n\n");


    for(int i=0; i<tamM; i++)
    {
        if(mascotas[i].isEmpty == 0 && mascotas[i].idTipo == idTipo && mascotas[i].idColor == idColor)
        {
            flag=1;
            contadorMascotas++;
            mostrarMascota(mascotas[i],colores,tamC,tipos,tamT);
        }
    }

    cargarDescripcionColor(colores,nombreColor,idColor,tamC);
    cargarDescripcionTipo(tipos,descripcionTipo,idTipo,tamT);
    if(flag==0)
    {
        printf("\nNo hay mascotas que listar\n\n");
    } else if(flag==1)
    {
        printf("\n\nLa cantidad de mascotas de color %s y tipo %s son: %d\n\n",nombreColor,descripcionTipo,contadorMascotas);
    }
}


void mostrarColoresMasElegidos(eMascota mascotas[],int tamM,eColor colores[], int tamC) //Mayor cantidad color
{

    int contadores[tamC];
    int mayor=0;
    int flag=0;

    if(mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {

        printf("*****************Mostrar el/los colores con mas cantidad de mascotas*********\n");


        for(int i=0; i<tamC; i++)
        {
            contadores[i]=0;
        }

        for(int c=0; c<tamC; c++) //recorro colores
        {
            for(int m=0; m<tamM; m++)
            {
                if(mascotas[m].isEmpty==0 && mascotas[m].idColor == colores[c].id)
                {
                    contadores[c] = contadores[c] + 1;

                }
            }
        }
        for(int i=0; i<tamC; i++) //busco contador mayor
        {
            if(contadores[i]> mayor ||flag ==0)
            {
                mayor=contadores[i];
                flag=1;
            }
        }
        printf("El o los tipos mas elegidos son : \n");
        for(int i=0; i<tamC; i++)
        {
            if(contadores[i] ==mayor)
            {
                printf("%s\n",colores[i].nombreColor);
            }
        }
        printf("\n\n");

    }

}


void mostrarTrabajosDeMascotaSelec(eTrabajo trabajos[], int tamTR, int idTrabajo ,eServicio servicios[], int tamS,
                                   eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[],int tamT
                                  )

{

    int idMascota;
    int flag=0;
    system("cls");
    printf("*********************************************************************\n");
    printf("*****************MOSTRAR TRABAJOS DE UNA MASCOTA*********************\n\n");
    printf("*********************************************************************\n");
    mostrarMascotas(mascotas, tamM, colores, tamC, tipos, tamT);
    idMascota= getInt("Ingrese id mascota: ", "Reingrese id mascota: ",1,1000);
    while(validarIdMascota(mascotas,tamM,idMascota))
    {
        idMascota= getInt("Ingrese id mascota: ", "Reingrese id mascota: ",1,1000);
    }

    for(int i=0; i <tamTR ;i++)
    {
        if(trabajos[i].isEmpty==0 &&trabajos[i].idMascota== idMascota)
        {
            printf("  ID    |         MASCOTA       |     SERVICIO |    FECHA\n");
            mostrarTrabajo(trabajos[i],servicios,tamS,mascotas,tamM);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No hay mascotas en la lista\n");
    }
}

void mostrarSumaServiciosDeMascotaSelec(eTrabajo trabajos[], int tamTR, int idTrabajo ,eServicio servicios[], int tamS,
                                 eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[],int tamT
                                 )
{
    system("cls");
    printf("*********************************************************************\n");
    printf("*****************IMPORTE TOTAL SERVICIO DE UNA MASCOTA*********************\n\n");
    printf("*********************************************************************\n");
    int idMascota;
    char nombreMascota[20];
    float acumuladorServicios;

    mostrarMascotas(mascotas, tamM, colores, tamC, tipos, tamT);
    idMascota= getInt("Ingrese id mascota: ", "Reingrese id mascota: ",1,1000);
    while(validarIdMascota(mascotas,tamM,idMascota))
    {
        idMascota= getInt("Ingrese id mascota: ", "Reingrese id mascota: ",1,1000);
    }
    cargarDescripcionMascota(mascotas,idMascota,nombreMascota,tamM);

    for(int i=0;i<tamTR;i++)
    {
        if(trabajos[i].isEmpty==0 && trabajos[i].idMascota==idMascota)
        {
            for(int j=0;j<tamS;j++)
            {
                if(trabajos[i].idServicio==servicios[j].id)
                {
                    acumuladorServicios+=servicios[j].precio;
                }
            }
        }
    }
    printf("Suma de los servicios de la mascota:%12s es de: $%.2f \n",nombreMascota,acumuladorServicios);
}

//9-	Pedir un servicio y mostrar las mascotas a las que se les realizo ese servicio y la fecha.
void mostrarMascotasDeServicioSelec(eTrabajo trabajos[], int tamTR, int idTrabajo ,eServicio servicios[], int tamS, eMascota mascotas[], int tamM)
{
    int idServicio;
    char descripcionServicio[20];
    char nombreMascota[20];
    int flag=0;
    system("cls");
    printf("*********************************************************************\n");
    printf("***************MOSTRAR MASCOTAS DE UN SERVICIO Y FECHA***************\n\n");
    printf("*********************************************************************\n");

    mostrarServicios(servicios,tamS);
    idServicio= getInt("Ingrese id servicio: ", "Reingrese id servicioma: ",20000,30000);
    while(validarIdServicio(servicios,tamS,idServicio))
    {
         idServicio= getInt("Ingrese id servicio: ", "Reingrese id servicioma: ",20000,30000);
    }
    cargarDescripcionServicio(servicios,idServicio,descripcionServicio,tamS);

    printf("*****Mascotas que realizaron el servicio %10s :\n\n",descripcionServicio);
    for(int i=0; i <tamTR ;i++)
    {
        if(trabajos[i].isEmpty==0 && trabajos[i].idServicio== idServicio)
        {
            cargarDescripcionMascota(mascotas,trabajos[i].idMascota,nombreMascota,tamM);
            printf("      MASCOTA      FECHA\n");
            printf("%10s   %2.d/%2.d/%d\n\n",nombreMascota,trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No hay mascotas en la lista\n");
    }
}
