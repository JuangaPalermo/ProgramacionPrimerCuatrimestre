#include "UserInteractions.h"

int printMenu (char opciones [], int cantidadOpciones)
{
	int returnValue;

	printf("%s\n", opciones);
	printf("Ingrese la opcion que desee: ");
	scanf("%d", &returnValue);

	while (returnValue > cantidadOpciones || returnValue < 1)
	{
		printf("Error, opcion invalida. Por favor, reingrese la opcion que desea: ");
		scanf("%d", &returnValue);
	}

	return returnValue;
}

int getInt (char mensaje[], char error[], int min)
{
    int valor;

    printf ("%s", mensaje);
    scanf ("%d", &valor);

    while (valor < min)
    {
        printf ("%s", error);
        scanf ("%d", &valor);
    }

  return valor;
}

int intBetweenTwo(char texto[], char error[], int min, int max)
{
    int valor;

    printf ("%s", texto);
    scanf ("%d", &valor);

    while (valor < min || valor > max)
    {
        printf ("%s", error);
        scanf ("%d", &valor);
    }

  return valor;
}

float getPromedio(int primerValor, int segundoValor)
{
    return ((float) primerValor + segundoValor) / 2;
}


void getString (char mensaje[], char texto[], int largo)
{
    printf("%s", mensaje);
    __fpurge(stdin);
    fgets(texto, largo, stdin);
    texto[strlen(texto)-1]='\0';
}

float getFloat(char mensaje[], char error[], float min)
{
	float valor;

	printf ("%s", mensaje);
	scanf ("%f", &valor);

	while (valor < min)
	{
		printf ("%s", error);
		scanf ("%f", &valor);
	}

	return valor;
}

char getChar (char mensaje[], char error[], char letraUno, char letraDos)
{
    char opcionSeleccionada;
    int returnValue;

    printf("%s", mensaje);
    __fpurge(stdin);
    scanf("%c", &opcionSeleccionada);
    returnValue = tolower(opcionSeleccionada);

    while(returnValue != letraUno && returnValue != letraDos)
    {
        printf("%s", error);
        __fpurge(stdin);
        scanf("%c", &opcionSeleccionada);
        returnValue = tolower(opcionSeleccionada);
    }

    return returnValue;
}

int askForInt (char texto [])
{
	int returnValue;

	printf("%s", texto);
	scanf("%d", &returnValue);

	return returnValue;
}

int generateId (void)
{
	static int id = 0;

	id++;

	return id;
}

void enterToCleanScreen(void)
{
    printf("Presione ENTER para continuar...");
    __fpurge(stdin);
    getchar();
    system("clear");
}
