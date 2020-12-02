#include "tipos.h"
#include "colores.h"
#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
}eMascota;


#endif // MASCOTA_H_INCLUDED
/** \brief menu principal del opciones
 *
 * \return devuelve la opcion elegida
 *
 */
int menu();

/** \brief inicializa el array con la propiedad isEmpty en 1 (libre)
 *
 * \param array a recorrer
 * \param tamaño del array
 * \return 0 si se pudo inicializar 1 si hubo error
 *
 */
int inicializarMascotas(eMascota mascotas[], int tamM);

/** \brief busca un indice libre en el array
 *
 * \param array a recrrer
 * \param tamaño del array
 * \return -1 no hay indice | indice libre
 *
 */

int buscarEspacioLibre(eMascota mascotas[],int tamM);

/** \brief crea una nueva mascota y la carga a la lista
 *
 * \param array de mascotas
 * \param tamaño del array mascotas
  * \param id mascota
   * \param array color
    * \param tamaño array color
     * \param array tipos
     * \param tamaño array tipo
     * \return
     *
 * \return 1 si se realizo el alta o -1 si hubo error
 *
 */

int altaMascota(eMascota mascotas[], int tamM, int idM ,eColor colores[], int tamC ,eTipo tipos[], int tamT);
/** \brief muestra una mascota
 *
 * \param tipo de dato mascota
 * \param array color
 * \param tamaño array color
  * \param array tipo
 * \param tamaño array tipo
 *
 */

void mostrarMascota(eMascota unaMascota, eColor colores[],int tamC, eTipo tipos[], int tamT);

/** \brief muestra lista de mascotas
 * \param array mascotas
 * \param tamaño array mascotas
 * \param array color
 * \param tamaño array color
  * \param array tipo
 * \param tamaño array tipo
 *
 */
void mostrarMascotas(eMascota mascotas[],int tamM, eColor colores[],int tamC, eTipo tipos[], int tamT);

/** \brief busca mascota por id
 *
 * \param array mascotas
 * \param tamaño array mascotas
  * \param id buscado
 * \return 1 error o el indice buscado
 *
 */
int buscarMascotaById(eMascota mascotas[], int tamM, int id);

/** \brief recorre el array en caso de encontrar id de una mascota cargada la da de baja
 *
 * \param array mascotas
 * \param tamaño array mascotas
 * \param array color
 * \param tamaño array color
  * \param array tipo
 * \param tamaño array tipo
 * \return si hubo baja 1 |0 si no se dio de baja
 *
 */
int bajaMascota(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief menu para elegir la modificacion
 *
 * \return la opcion elegida
 *
 */
char menuModif();
/** \brief modifica o no a una mascota
 *
 * \param array mascotas
 * \param tamaño array mascotas
 * \param array color
 * \param tamaño array color
  * \param array tipo
 * \param tamaño array tipo
 *
 */
void modificarMascota(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief valida la existecia del id de la mascota

 * \param array mascotas
 * \param tamaño array mascotas
  * \param id a validar
 * \return error 1 si no lo encuentra 0 si lo encuentra
 *
 */
int validarIdMascota(eMascota mascotas[], int tamM, int idMascota);

/** \brief Recorre el array de mascotas para verificar si hay lugar libre
 *
 * \param array de mascotas
 * \param tamaño del array
 * \return 1:  0: ocupado| vacio 1
 */
int isEmpty(eMascota mascotas[], int tam);

/** \brief ordena el array de mascotas por tipo y nombre
 *
 * \param array mascotas
 * \param tamaño array mascotas
 * \param array color
 * \param tamaño array color
  * \param array tipo
 * \param tamaño array tipo
 *
 *
 */

void ordenarMascotasPorTipoYNombre(eMascota mascotas[], int tamM, int idM ,eColor colores[], int tamC ,eTipo tipos[], int tamT);

/** \brief harcodea mascotas
*
 * \param  array mascotas
 * \param tamaño array mascota
 * \param cant cantidad a ser harcodeada
 * \return 0 todo ok, -1 si se produjo un error
 *
 */

int hardcodearMascotas(eMascota mascotas[], int tam, int cant);
