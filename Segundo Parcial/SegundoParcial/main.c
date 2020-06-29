/*
 PARCIAL N2	DE PROGRAMACION - UTN
 Juan Gabriel Palermo - 1 'F'.
 */

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "Aerolinea.h"
#include "Piloto.h"
#include "UserInteractions.h"

int main()
{
    LinkedList* listVuelos;
	LinkedList* listPilotos;

	int opcionSeleccionada;
	int retornoFuncion;
	char archivo[50];

	listVuelos = ll_newLinkedList();
	listPilotos = ll_newLinkedList();

	hardcodearPilotos(listPilotos);

	do
	{
		opcionSeleccionada = printMenu("1.Cargar archivo\n2.Imprimir vuelos\n3.Cantidad de pasajeros\n4.Cantidad de pasajeros a Irlanda\n5.Filtrar vuelos cortos\n6.Listar vuelos a Portugal\n7.Filtrar a Alex Lifeson\n8.Generar archivo piloto especifico\n9.Salir", 9);

		switch(opcionSeleccionada)
		{
		case 1:
		    getString("Inserte el nombre del archivo: ", archivo, 50);
			retornoFuncion = controller_loadFromText(archivo, listVuelos);
			if(retornoFuncion == 1)
			{
				printf("Archivo cargado con exito.\n");
			}
			else
			{
				printf("Error al cargar archivo.\n");
			}
			break;
		case 2:
		    retornoFuncion = controller_listVuelos(listVuelos, listPilotos);
		    if(retornoFuncion == 1)
            {
                printf("Lista Impresa.\n");
            }
            else
            {
                printf("Error.\n");
            }
			break;
		case 3:
		    retornoFuncion = controller_pasajerosTotales(listVuelos);
		    if(retornoFuncion != 0)
            {
                printf("Cantidad total de pasajeros: %d\n", retornoFuncion);
            }
            else
            {
                printf("Error.\n");
            }
			break;
		case 4:
		    retornoFuncion = controller_pasajerosIrlanda(listVuelos);
		    if(retornoFuncion!=0)
            {
                printf("Cantidad de pasajeros a Irlanda: %d\n", retornoFuncion);
            }
            else
            {
                printf("Error.\n");
            }
			break;
		case 5:
		    retornoFuncion = controller_saveAsText("VuelosCortos.csv", ll_filter(listVuelos, vuelo_menosDe3Horas)); //preguntar si esto es mejor que un controller especifico
		    if(retornoFuncion == 1)
            {
                printf("Archivo creado con exito\n");
            }
            else
            {
                printf("Error.\n");
            }
			break;
		case 6:
		    retornoFuncion = controller_listVuelos(ll_filter(listVuelos, vuelo_destinoPortugal), listPilotos);
		    if(retornoFuncion == 1)
            {
                printf("Lista impresa.\n");
            }
            else
            {
                printf("Error.\n");
            }
			break;
		case 7:
		    retornoFuncion = controller_listVuelos(ll_filter(listVuelos, vuelo_sacarAlexLifeson), listPilotos);
		    if(retornoFuncion == 1)
            {
                printf("Lista impresa.\n");
            }
            else
            {
                printf("Error.\n");
            }
			break;
		case 8:
		    retornoFuncion = controller_saveAsTextPilotoEspecifico(listVuelos, listPilotos);
		    if(retornoFuncion == 1)
            {
                printf("Archivo creado con exito.\n");
            }
            else
            {
                printf("Error.\n");
            }
			break;
		case 9:
		    printf("\n\nGracias por utilizar el programa!\n\n\n");
			break;
		}

        enterToCleanScreen();

	}while(opcionSeleccionada != 9);

    return 0;
}
