#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Aerolinea.h"
#include "Piloto.h"

int parser_VueloFromText(FILE* pFile , LinkedList* pArrayListVuelos)
{
	int returnValue = 0;

	char idVuelo[20];
	char idAvion[20];
	char idPiloto[20];
	char fecha[15];
	char destino[30];
	char cantPasajeros[20];
	char horaDespegue[20];
	char horaLlegada[20];

	int auxScan;
	eVuelo* auxVuelo;

	if(pFile != NULL && pArrayListVuelos != NULL)
	{
		auxScan = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);

		do
		{
			auxScan = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);

			if(auxScan == 8)
			{
				auxVuelo = vuelo_newParametros(idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
				ll_add(pArrayListVuelos, auxVuelo);
			}

		}while(!feof(pFile));

		returnValue = 1;
	}

	return returnValue;
}

int parser_PilotoFromText(FILE* pFile, LinkedList* pArrayListPilotos)
{
    int returnValue = 0;

	char idPiloto[20];
	char nombrePiloto[128];

	int auxScan;
	ePiloto* auxPiloto;

	if(pFile != NULL && pArrayListPilotos != NULL)
	{
		auxScan = fscanf(pFile, "%[^,],%[^\n]\n",  idPiloto, nombrePiloto);

		do
		{
			auxScan = fscanf(pFile, "%[^,],%[^\n]\n",  idPiloto, nombrePiloto);

			if(auxScan == 2)
			{
				auxPiloto = piloto_newParametros(nombrePiloto, idPiloto);
				ll_add(pArrayListPilotos, auxPiloto);
			}

		}while(!feof(pFile));

		returnValue = 1;
	}

	return returnValue;

}
