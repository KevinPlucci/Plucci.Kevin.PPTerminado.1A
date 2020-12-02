#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    float precio;

}eServicio;


#endif // SERVICIOS_H_INCLUDED
/** \brief mostrar servicios
 *
 * \param array servicios
 * \param tamaño servicios
 *
 */
void mostrarServicios(eServicio servicios[],int tamS);

/** \brief valida el id de servicio
 *
 * \param array servicios
 * \param tamaño array servicios
 * \return 1 error 0 no hubo error
 *
 */

int validarIdServicio(eServicio servicios[], int tamS, int idServicio);


/** \brief carga la descripcion del servicio
 *
 * \param id servicio
 * \param descripcion del servicio
 * \param tamaño array servicio
 * \return 1 eeror 0 no hubo error
 *
 */

int cargarDescripcionServicio(eServicio servicios[], int idServicio, char descripcionServicio[], int tamS);
