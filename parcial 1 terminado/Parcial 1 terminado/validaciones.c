#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int getInt(char texto[],char textoError[], int minimo, int maximo)
{
    int dato;

    printf("%s",texto);
    fflush(stdin);
    scanf("%d", &dato); //si dio 0 pido otra vez
    while(dato < minimo || dato > maximo)
    {
        printf("%s",textoError);
        fflush(stdin);
        scanf("%d", &dato);
    }

    return dato;
}

float getFloat(char texto[],char textoError[], float minimo, float maximo)
{

    float dato;

    printf("%s",texto);
    fflush(stdin);
    scanf("%f", &dato); //si dio 0 pido otra vez
    while(dato < minimo || dato > maximo)
    {
        printf("%s",textoError);
        fflush(stdin);
        scanf("%f", &dato);
    }

    return dato;
}

char getCharacter(char mensaje[], char mensajeError[], char minimo, char maximo)
{
    char character;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &character);
    character=tolower(character);
    while(character < minimo || character > maximo)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%c", &character);
    }

    return character;
}

int getString(char dato[], char mensaje[], char mensajeError[], int len)
{
    int todoOk= -1;

    if(dato!=NULL && len >0)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", dato);

         while(strlen(dato) >= len - 1 || (isString(dato)))
         {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%[^\n]", dato);
         }

         wordsFirstCharToUpper(dato);
        todoOk=1;
    }
    return todoOk;
}


int isString(char datoAux[])
{
    int i = 0;
    int todoOk=0;

    while(datoAux[i] != '\0')
    {

        if((datoAux[i] != ' ') && (datoAux[i] < 'a' || datoAux[i] > 'z') && (datoAux[i] < 'A' || datoAux[i] > 'Z'))
        {
            todoOk=1;
        }
        i++;
    }
    return todoOk;
}

void wordsFirstCharToUpper(char cadena[])
{
    int len;
    int i;

    strlwr(cadena);

    len= strlen(cadena);
    cadena[0]= toupper(cadena[0]); // en el indice 0 le digo toupper xq es la 1ra letra

    for(i=0; i<len; i++)
    {
        if(isspace(cadena[i]))
        {
            cadena[i+1] = toupper(cadena[i+1]);
        }
    }
}
