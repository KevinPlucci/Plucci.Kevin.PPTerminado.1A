#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascota.h"
#include "validaciones.h"
#include "trabajo.h"
#include "informes.h"
#define TMASC 6 //+
#define TC 5
#define TT 5
#define TS 3
#define TTRAB 6 //+ SE PONE 100 PARA USAR EL ABM NORMAL.CUANDO NO SE USA EL HARDCODEO
//| PONER TRABAJO EN 6 CUANDO SE USA EL HARDCODEO DE TRABAJOoS



int main()
{
    char seguir = 's';
    char confirma;
    int proximoIdMascota=6;
    int proximoIdTrabajo=9005;// empieza en 5 por los q estan harcodeados
    eMascota listaMascotas[TMASC];

    int hayMascotas=1;  //1 PARA EL HARDCODEO PARA PODER USAR LAS DEMAS OPCIONES SINO PARA USO NORMAL PONER EN 0
    int flagAltaTrab=1; //1 PARA EL HARDCODEO PARA PODER USAR LAS DEMAS OPCIONES SINO PARA USO NORMAL PONER EN 0
    int retorno;

    eTipo listaTipo[5]= {{1000, "Ave"},{1001, "Perro"},{1002, "Gato"},{1003, "Roedor"},{1004, "Pez"}};
    eColor listaColor[5]= {{5000, "Negro"},{5001, "Blanco"},{5002, "Gris"},{5003, "Rojo"},{5004, "Azul"}};
    eServicio listaServicio[3]= {{20000, "Corte", 250.0},{20001, "Desparasitado", 300.0},{20002, "Castrado", 400.0}};


    if(!inicializarMascotas(listaMascotas,TMASC))
     {
         printf("Todo ok al inicializar\n");
     }

     //COMENTAR HARDCODEO PARA USO NORMAL DE ABM
     hardcodearMascotas(listaMascotas,100,5);
     //COMENTAR HARDCODEO DE TRABAJOS EN CASO DE USAR EL ABM NORMAL
     eTrabajo listaTrabajos[TTRAB] ={{9000,1,20002,{12,4,2020},0},
                                     {9001,2,20001,{23,2,2021},0},
                                     {9002,3,20000,{20,3,2020},0},
                                     {9003,4,20002,{10,4,2022},0},
                                     {9004,5,20001,{12,1,2022},0},
                                     {0,0,0,{0,0,0},1}
                                    };

       //SE COMENTA FUNCION INICIALIZAR TRABAJOS PARA EL HARDCODEO
       //PARA USO NORMAL DE ABM DESCOMENTAR INICIALIZAR TRABAJOS Y COMENTAR EL HARCODEO  DE TRABAJOS
  /*   if(!inicializarTrabajos(listaTrabajos,TTRAB))
     {

         printf("Todo ok al inicializar\n");
    }*/


    do
    {
        switch(menu())
        {

        case 1:
            if (altaMascota(listaMascotas,TMASC,proximoIdMascota,listaColor, TC, listaTipo, TT)==1)//si dio de alta.. si no dio error altaPersona
            {
                hayMascotas=1;
                proximoIdMascota++; //ACA en main o en la funcion cuando hago el alta
                printf("Alta con exito!\n"); //esto va en el case del menu

            } else {
                printf("No se pudo realizar el alta\n");
            }
            break;


        case 2:
            if(hayMascotas)
            {
               modificarMascota(listaMascotas,TMASC,listaColor,TC,listaTipo,TT);

            } else {
                mostrarMascotas(listaMascotas,TMASC, listaColor,TC,listaTipo,TT);
                printf("Primero debe ingresar una mascota.(opcion 1)\n");
            }

            break;


        case 3: //baja mascota retorna 1 si se dio de baja.
            if(hayMascotas)
            {
               retorno = bajaMascota(listaMascotas,TMASC,listaColor,TC,listaTipo,TT);
               if (retorno)
               {
                   if(isEmpty(listaMascotas,TMASC)) //Verifica que haya mascotas
                   {
                       hayMascotas=0;
                   }
               }

            } else {
                mostrarMascotas(listaMascotas,TMASC, listaColor,TC,listaTipo,TT);
                printf("Primero debe ingresar una mascota.(opcion 1)\n");
            }

            break;


        case 4:
            if(hayMascotas)
            {
               ordenarMascotasPorTipoYNombre(listaMascotas,TMASC, proximoIdMascota,listaColor,TC,listaTipo,TT);
            } else {
                printf("Primero debe ingresar una mascota.(opcion 1)\n");
            }
            break;

        case 5:
            system("cls");
            mostrarTipos(listaTipo, TT);
            break;
        case 6:
            system("cls");
            mostrarColores(listaColor, TC);
            break;

        case 7:
            system("cls");
            mostrarServicios(listaServicio,TS);
            break;
        case 8:
            if(hayMascotas)
            {
                if (altaTrabajo(listaTrabajos,TTRAB,proximoIdTrabajo, listaServicio,TS,listaMascotas,TMASC, listaColor,TC,listaTipo,TT)==0)
                {
                    proximoIdTrabajo++;
                    flagAltaTrab=1;
                    printf("Alta con exito!\n");
                } else{
                    printf("No se pudo realizar el alta\n");
                }
            } else {
                printf("Primero debe ingresar una mascota para dar alta trabajos.(opcion 1)\n");
            }

            break;

        case 9:
            if(flagAltaTrab)
            {
                mostrarTrabajos(listaTrabajos,TTRAB,listaServicio,TS,listaMascotas,TMASC);
            } else {
                printf("Primero ingresar trabajos. opcion 8\n");
            }
            break;
        case 10:
            if(flagAltaTrab && hayMascotas)
            {
                informesDeMascotas(listaMascotas,TMASC,listaColor,TC,listaTipo,TT,
                                   listaTrabajos,TTRAB,proximoIdTrabajo,listaServicio,TS);
            } else {
                printf("Primero ingresar trabajos. opcion 8\n");
            }
            break;

        case 11:
            confirma= getCharacter("Confirma salida? (s/n):", "Error. Reingrese (s/n):",'a','z');
            if(confirma=='s')
            {
                seguir='n';
            }
            break;


        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }while(seguir=='s');


    return 0;
}
