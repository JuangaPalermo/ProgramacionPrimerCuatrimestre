#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Aerolinea.h"
#include "parser.h"
#include "UserInteractions.h"


int controller_loadFromText(char* path , LinkedList* pArrayListVuelos)
{
	int returnValue = 0;

	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	if(pArrayListVuelos != NULL && pArchivo != NULL)
	{
		parser_VueloFromText(pArchivo, pArrayListVuelos);
		fclose(pArchivo);
		returnValue = 1;
	}

	return returnValue;
}

int hardcodearPilotos (LinkedList* pArrayListPilotos)
{
	int retorno = 0;
	char idPiloto[5][5]={"1","2","3","4","5"};
	char nombre[5][128]={"Alex Lifeson", "Richard Bach", "John Kerry", "Erwin Rommel", "Stephen Coonts"};
	int i;
	ePiloto* auxPiloto;
	if(pArrayListPilotos != NULL)
	{
		for(i=0; i<5; i++)
		{
			auxPiloto = piloto_newParametros(nombre[i], idPiloto[i]);
			ll_add(pArrayListPilotos, auxPiloto);
		}
		retorno = 1;
	}
	return retorno;
}

int controller_listVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
    int returnValue = 0;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[15];
    char destino[30];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    char nombre[128];
    int idPiloto2;

    int i;
    int j;
    int lenVuelos;
    int lenPilotos;
    eVuelo* auxVuelo;
    ePiloto* auxPiloto;

    if(pArrayListVuelos != NULL && pArrayListPilotos != NULL)
    {
        lenVuelos = ll_len(pArrayListVuelos);
        lenPilotos = ll_len(pArrayListPilotos);

        printf("| %5s | %5s | %60s | %15s | %30s | %5s | %5s | %5s |\n", "IDvue", "IDavi", "Nombre Piloto", "Fecha", "Destino", "Pasaj", "Hdesp", "Hlleg");
        for(i = 0; i<lenVuelos; i++)
        {
            auxVuelo = ll_get(pArrayListVuelos, i);

            if(auxVuelo !=NULL)
            {
                vuelo_getIdVuelo(auxVuelo, &idVuelo);
                vuelo_getIdAvion(auxVuelo, &idAvion);
                vuelo_getIdPiloto(auxVuelo, &idPiloto);
                vuelo_getFecha(auxVuelo, fecha);
                vuelo_getDestino(auxVuelo, destino);
                vuelo_getCantPasajeros(auxVuelo, &cantPasajeros);
                vuelo_getHoraDespegue(auxVuelo, &horaDespegue);
                vuelo_getHoraLlegada(auxVuelo, &horaLlegada);
                for(j = 0; j<lenPilotos; j++)
                {
                    auxPiloto = ll_get(pArrayListPilotos, j);
                    if(auxPiloto != NULL)
                    {
                        piloto_getIdPiloto(auxPiloto, &idPiloto2);
                        piloto_getNombrePiloto(auxPiloto, nombre);
                        if(idPiloto == idPiloto2)
                        {
                            printf("| %5d | %5d | %60s | %15s | %30s | %5d | %5d | %5d |\n", idVuelo, idAvion, nombre, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
                            break;
                        }
                    }
                }
            }
        }

        returnValue = 1;
    }

    return returnValue;
}


int controller_pasajerosTotales (LinkedList* pArrayListVuelos)
{
    int returnValue = 0;

    if(pArrayListVuelos != NULL)
    {
        returnValue = ll_count(pArrayListVuelos, vuelo_obtainCantPasajeros);
    }

    return returnValue;
}

int controller_pasajerosIrlanda(LinkedList* pArrayListVuelos)
{
    int returnValue = 0;
    LinkedList* clonedList;

    if(pArrayListVuelos != NULL)
    {
        clonedList = ll_newLinkedList();

        if(clonedList != NULL)
        {
            clonedList = ll_filter(pArrayListVuelos, vuelo_destinoIrlanda);
            returnValue = ll_count(clonedList, vuelo_obtainCantPasajeros);
        }
    }

    return returnValue;
}

int controller_saveAsText(char* path, LinkedList* pArrayListVuelos)
{
    int returnValue = 0;
    FILE* pArchivo;
    eVuelo* auxVuelo;
    int i;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[15];
    char destino[30];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;


    pArchivo = fopen(path, "w");

    if(pArrayListVuelos!=NULL && pArchivo!=NULL)
    {
        fprintf(pArchivo, "IdVuelo,IdAvion,IdPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");

        for(i=0; i<ll_len(pArrayListVuelos); i++)
        {
            auxVuelo = ll_get(pArrayListVuelos, i);

            if(auxVuelo != NULL)
            {
                vuelo_getIdVuelo(auxVuelo, &idVuelo);
                vuelo_getIdAvion(auxVuelo, &idAvion);
                vuelo_getIdPiloto(auxVuelo, &idPiloto);
                vuelo_getFecha(auxVuelo, fecha);
                vuelo_getDestino(auxVuelo, destino);
                vuelo_getCantPasajeros(auxVuelo, &cantPasajeros);
                vuelo_getHoraDespegue(auxVuelo, &horaDespegue);
                vuelo_getHoraLlegada(auxVuelo, &horaLlegada);

                fprintf(pArchivo, "%d,%d,%d,%s,%s,%d,%d,%d\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            }

        }
        fclose(pArchivo);
        returnValue = 1;
    }

    return returnValue;
}

int controller_listPilotos(LinkedList* pArrayListPilotos)
{
    int returnValue = 0;
    int idPiloto;
    char nombre[128];
    ePiloto* auxPiloto;

    int i;
    int len;

    if(pArrayListPilotos != NULL)
    {
        len = ll_len(pArrayListPilotos);

        printf("| %5s | %60s |\n", "ID", "Nombre completo");

        for(i=0; i<len; i++)
        {
            auxPiloto = ll_get(pArrayListPilotos, i);
            if(auxPiloto != NULL)
            {
                piloto_getIdPiloto(auxPiloto, &idPiloto);
                piloto_getNombrePiloto(auxPiloto, nombre);

                printf("| %5d | %60s |\n", idPiloto, nombre);
            }

        }

        returnValue = 1;
    }

    return returnValue;
}

int controller_selectPiloto(LinkedList* pArrayListPilotos)
{
    int returnValue = 0;
    int i;
    int len;
    ePiloto* auxPiloto;
    int idSeleccionado;
    int auxId;

    if(pArrayListPilotos != NULL)
    {
        len = ll_len(pArrayListPilotos);

        do
        {
            printf("Ingrese el ID que desea seleccionar: ");
            scanf("%d", &idSeleccionado);

            for(i=0; i<len; i++)
            {
                auxPiloto = ll_get(pArrayListPilotos, i);

                if(auxPiloto != NULL)
                {
                    piloto_getIdPiloto(auxPiloto, &auxId);

                    if(auxId == idSeleccionado)
                    {
                        returnValue = idSeleccionado;
                        break;
                    }
                }

            }

            if(returnValue == 0)
            {
                printf("Error, ese ID no existe en el listado. ");
            }

        }while(returnValue == 0);
    }

    return returnValue;
}


int controller_saveAsTextPilotoEspecifico(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
    int returnValue = 0;
    int pilotoSeleccionado;

    controller_listPilotos(pArrayListPilotos); //imprime la lista de pilotos
    pilotoSeleccionado = controller_selectPiloto(pArrayListPilotos); //Le pide al usuario el ID del piloto
    //lo de arriba podria haberse hecho con un prinMenu, pero no habria sido dinamico.

    switch(pilotoSeleccionado)
    {
    case 1:
        controller_saveAsText("VuelosLifeson.csv", ll_filter(pArrayListVuelos, vuelo_soloAlexLifeson));
        break;
    case 2:
        controller_saveAsText("VuelosBach.csv", ll_filter(pArrayListVuelos, vuelo_soloRichardBach));
        break;
    case 3:
        controller_saveAsText("VuelosKerry.csv", ll_filter(pArrayListVuelos, vuelo_soloJohnKerry));
        break;
    case 4:
        controller_saveAsText("VuelosRommel.csv", ll_filter(pArrayListVuelos, vuelo_soloErwinRommel));
        break;
    case 5:
        controller_saveAsText("VuelosCoonts.csv", ll_filter(pArrayListVuelos, vuelo_soloStephenCoonts));
        break;
    }

    returnValue = 1;
}

