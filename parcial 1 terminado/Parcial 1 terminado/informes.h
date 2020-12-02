#include "trabajo.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
char menuInformes();
void informesDeMascotas(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT,eTrabajo trabajos[], int tamTR, int idTrabajo ,eServicio servicios[], int tamS);
void informarMascotasPorColorSelec(eMascota mascotas[], int tamM, eColor colores[],int tamC,eTipo tipos[], int tamT);
void informarMascotasPorTipoSelec(eMascota mascotas[], int tamM, eColor colores[],int tamC,eTipo tipos[], int tamT );
void informarMascotaMenores(eMascota mascotas[], int tamM, eColor colores[],int tamC,eTipo tipos[], int tamT);
void mostrarMascotasPorTipo(eMascota mascotas[],int tamM,eColor colores[], int tamC, eTipo tipos[],int tamT);
void elegirColorTipoYContar(eMascota mascotas[],int tamM,eColor colores[], int tamC, eTipo tipos[],int tamT);
void mostrarColoresMasElegidos(eMascota mascotas[],int tamM,eColor colores[], int tamC);
//BONUS TRACK


void mostrarColoresMasElegidos(eMascota mascotas[],int tamM,eColor colores[], int tamC);
void mostrarSumaServiciosDeMascotaSelec(eTrabajo trabajos[], int tamTR, int idTrabajo ,eServicio servicios[], int tamS,
                                 eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[],int tamT);

void mostrarTrabajosDeMascotaSelec(eTrabajo trabajos[], int tamTR, int idTrabajo ,eServicio servicios[], int tamS,
                                   eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[],int tamT);

void mostrarMascotasDeServicioSelec(eTrabajo trabajos[], int tamTR, int idTrabajo ,eServicio servicios[], int tamS, eMascota mascotas[], int tamM);
