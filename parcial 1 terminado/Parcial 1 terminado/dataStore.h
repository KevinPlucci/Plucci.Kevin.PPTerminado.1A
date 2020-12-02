#include "trabajo.h"
#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED
char nombresMascotas[10][20] ={"Pepito","Zolio", "Cafe","Dobby","AmigoFiel","Lupita","Magali","Valen", "Andrea","Analia"};
char sexos [10] ={'m','m','m','m','m','f','f','f','f','f'};
int legajos[10] ={1000, 1001,1002,1003,1004,1005,1006,1007,1008,1009};
int ids[10]={1,2,3,4,5,6,7,8,9,10};
int edades[12]={18,15,14,13,12,20,24,36,40,56,60,45};
char coloresChar[][15]={"Negro", "Blanco", "Gris", "Azul","verde","Rojo","Violeta"};

float alturas[10] ={1.80,1.88,1.70,1.99,1.87, 1.60, 1.50, 1.40, 1.55, 1.45};

eFecha fechas[10]= {
                    {30,9,2020},
                    {12,5,2000},
                    {15,9,1997},
                    {10,5,1997},
                    {24,4,1990},
                    {23,7,1990},
                    {15,9,1991},
                    {13,6,1998},
                    {22,5,1997},
                    {20,2,1996},
                    };


int idDeportes[]={2001,2002,2001,2003,2004,2001,2005,2000,2002,2003};
int idTipos[5]= {1000,1001,1002,1003, 1004};
int idColores[5]= {5000,5000,5002,5003,5004};
#endif // DATASTORE_H_INCLUDED
