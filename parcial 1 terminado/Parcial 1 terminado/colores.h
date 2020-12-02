#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];

}eColor;


#endif // COLORES_H_INCLUDED
/** \brief muestra la lista de colores
 *
 * \param array color
 * \param tamaño array color
 *
 */

void mostrarColores(eColor colores[], int tamC);
/** \brief muestra un color
 *
 */

void mostrarUnColor(eColor unColor);


/** \brief carga la descripcion de color
 *
 * \param array color
 * \param descripcion del color
 * \param id color
 * \param tamaño array color
 * \return 1 errro 0 no hubo error
 *
 */

int cargarDescripcionColor(eColor colores[], char nombreColor[], int idColor,int tamC);


/** \brief valida id del color
 *
 * \param array color
 * \param tamaño array color
 * \return 1 error 0 no hubo error
 *
 */
int validarIdColor(eColor colores[], int tamC, int idColor);
