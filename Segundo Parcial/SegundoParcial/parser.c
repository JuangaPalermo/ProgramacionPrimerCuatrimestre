#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Aerolinea.h"

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
