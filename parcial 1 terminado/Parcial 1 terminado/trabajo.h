#include "mascota.h"
#include "fecha.h"
#include "servicios.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;


#endif // TRABAJO_H_INCLUDED
/** \brief busca espacio libre en array de trabajo
 *
 * \param array trabajo
 * \param tamaño array trabajo
 * \return -1 sino encuentra el idice, o devuelve el indice encontrado
 *
 */
int buscarEspacioLibreTrabajo(eTrabajo trabajos[],int tam);

/** \brief inicializa el array con la propiedad isEmpty en 1 (libre)
 *
 * \param array a recorrer
 * \param tamaño del array
 * \return 0 si se pudo inicializar 1 si hubo error
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tam);

/** \brief crea una nuevo trabajo y la carga a la lista
 *
 * \param array trabajo
 * \param tamaño del array trabaja
 * \param id trabajo
 * \param array servicios
 * \param tamaño array servicios
 * \param array de mascotas
 * \param tamaño del array mascotas
 * \param id mascota
 * \param array color
 * \param tamaño array color
 * \param array tipos
 * \param tamaño array tipo
 * \return
 *
 */

int altaTrabajo(eTrabajo trabajos[], int tamTR, int idTrabajo ,eServicio servicios[], int tamS ,eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[],int tamT);

/** \brief muestra un trabajo
 *
 * \param tipo de dato trabajo
 * \param array servicios
 * \param tamaño array servicios
 * \param array de mascotas
 * \param tamaño del array mascotas
 *
 */
void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[],int tamS, eMascota mascotas[], int tamM);

/** \brief muestra toda la lista de trabajos
  * \param tipo de dato trabajo
  * \param array servicios
  * \param tamaño array servicios
  * \param array de mascotas
  * \param tamaño del array mascotas
 */
void mostrarTrabajos(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS, eMascota mascotas[], int tamM);

/** \brief carga el noombre de la masctoa
 *
 * \param array de masctoa
 * \param id de la mascota
 * \param nombre de la mascota
 * \param tamaño del array mascota
 * \return error 0 sino hubo error | 1 s hubo error
 *
 */
int cargarDescripcionMascota(eMascota mascotas[],int idMascota, char nombreMascota[], int tamM);
