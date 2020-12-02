#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[100];//20 antes andaba
}eTipo;




#endif // TIPOS_H_INCLUDED
/** \brief muestra un tipo
 *
 */

void mostrarUnTipo(eTipo unTipo);

/** \brief muestra la lista de tipos
 *
 * \param array tipos
 * \param tamaño array tipos
 *
 */

void mostrarTipos(eTipo tipos[], int tamT);


/** \brief carga la descripcion de tipo
 *
 * \param array tipo
 * \param descripcion del tipo
 * \param id tipo
 * \param tamaño array tipo
 * \return 1 errro 0 no hubo error
 *
 */

int cargarDescripcionTipo(eTipo tipos[], char descripcionTipo[], int idTipo,int tamT);


/** \brief valida id del tipo
 *
 * \param array tipo
 * \param tamaño array tipo
 * \return 1 error 0 no hubo error
 *
 */

int validarIdTipo(eTipo tipos[], int tamT, int idTipo);
