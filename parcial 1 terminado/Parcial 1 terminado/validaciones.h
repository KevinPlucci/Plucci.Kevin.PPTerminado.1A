#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/** \brief pide un numero int y lo valida entre maximo y minimo
 *
 * \param mensaje pide dato
 * \param mensaje error
 * \param minimo
 * \param maximo
 * \return el numero validado
 *
 */
int getInt(char texto[],char textoError[], int minimo, int maximo);

/** \brief pide un numero float y lo valida entre maximo y minimo
 *
 * \param mensaje pide dato
 * \param mensaje error
 * \param minimo
 * \param maximo
 * \return el numero validado
 *
 */
float getFloat(char texto[],char textoError[], float minimo, float maximo);
/** \brief recibe un char y lo valida
 *
 * \param mensaje pide el char
 * \param mensaje error
 * \return devuelve el char validado
 *
 */
int getString(char dato[], char mensaje[], char mensajeError[], int len);
/** \brief verifica si son letras
 *
 * \param recibe un tipo de dato char

 * \return todoOk 1 error todo ok 0
 *
 */

int isString(char datoAux[]);
/** \brief recibe una cadena y pone en mayuscula la primera letra y de encontrar un espacio pone en mayuscula la siguiente
 *
 * \param cadena
 *
 */
void wordsFirstCharToUpper(char cadena[]);
/** \brief recibe un char y lo valida
 *
 * \param mensaje pide el char
 * \param mensaje error
 * \return devuelve el char validado
 *
 */
char getCharacter(char mensaje[], char mensajeError[], char minimo, char maximo);

#endif // VALIDACIONES_H_INCLUDED
