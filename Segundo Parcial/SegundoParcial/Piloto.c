#include <stdlib.h>
#include "Piloto.h"
#include <string.h>

ePiloto* piloto_new()
{
	ePiloto* auxPiloto;

	auxPiloto = (ePiloto*)malloc(sizeof(ePiloto));

	return auxPiloto;
}


ePiloto* piloto_newParametros(char* nombre, char* idPiloto)
{
	ePiloto* auxPiloto;

	auxPiloto = piloto_new();

	if(auxPiloto != NULL)
	{
		piloto_setNombrePiloto(auxPiloto, nombre);
		piloto_setIdPiloto(auxPiloto, atoi(idPiloto));
	}

	return auxPiloto;
}


int piloto_setIdPiloto(ePiloto* this,int idPiloto)
{
	int returnValue = 0;

	if(this != NULL)
	{
		this->idPiloto = idPiloto;
		returnValue = 1;
	}

	return returnValue;
}
int piloto_getIdPiloto(ePiloto* this,int* idPiloto)
{
	int returnValue = 0;

	if(this != NULL)
	{
		*idPiloto = this->idPiloto;
		returnValue = 1;
	}

	return returnValue;
}


int piloto_setNombrePiloto(ePiloto* this,char* nombre)
{
	int returnValue = 0;
	int i;

	if(this != NULL)
	{
		//strlwr(nombre);
		for(i=0; i<strlen(nombre); i++)
		{
			if(i==0 || i-1 == ' ')
			{
				toupper(nombre[i]);
			}
		}

		strcpy(this->nombre, nombre);
		returnValue = 1;
	}

	return returnValue;
}
int piloto_getNombrePiloto(ePiloto* this,char* nombre)
{
	int returnValue = 0;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		returnValue = 1;
	}

	return returnValue;
}


int piloto_filtroNombre(void* element, char* criterio)
{
    int returnValue = 0;
    ePiloto* auxPiloto;
    char auxNombre[128];

    if (element != NULL)
    {
        auxPiloto = (ePiloto*) element;
        piloto_getNombrePiloto(auxPiloto, auxNombre);

        if(strcmp(auxNombre, criterio) == 0)
        {
            returnValue = 1;
        }
    }

    return returnValue;
}

