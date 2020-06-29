#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

/*Sirve para cargar datos a partir de un archivo en formato texto
 *param path: nombre del archivo
 *param pArrayListVuelos: lista de vuelos
 *return: (0) error o (1) OK
 */
int controller_Palermo_loadFromText(char* path , LinkedList* pArrayListVuelos);

int controller_Palermo_loadPilotosFromText(char* path , LinkedList* pArrayListPilotos);

/** \brief Hardcodea la lista de pilotos
 * \param pArrayList lista a hardcodear
 * \return (0) error o (1) OK
 */
int hardcodearPilotos(LinkedList* pArrayListPilotos);


/** \brief Sirve para imprimir un listado con los datos de los vuelos, y el nombre del piloto (en lugar del ID)
 * \param pArrayListVuelos: Array que almacena los datos de los vuelos
 * \param pArrayListPilotos: Array que almadena los datos de los pilotos
 * \return: (0) error o (1) OK
 */
int controller_Palermo_listVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos);


/** \brief Calcula los pasajeros totales de la lista que le paso como parametro
 * \param  pArrayListVuelos LinkedList* - Array para calcular el dato
 * \return int suma de pasajeros totales
 */
int controller_Palermo_pasajerosTotales (LinkedList* pArrayListVuelos);


/** \brief  Calcula los pasajeros totales que tienen como destino Irlanda
 * \param pArrayListVuelos LinkedList* - Array con todos los vuelos (sin filtrar)
 * \return int suma de pasajeros a Irlanda
 */
int controller_Palermo_pasajerosIrlanda(LinkedList* pArrayListVuelos);


/** \brief Guarda (o si no existe, crea) un archivo con el listado que se le pasa como parametro.
 * \param path char* - nombre del archivo.
 * \param pArrayListVuelos LinkedList* - LinkedList a guardar.
 * \return int (0) si error o (1) si OK.
 */
int controller_Palermo_saveAsText(char* path, LinkedList* pArrayListVuelos);

int controller_Palermo_listPilotos(LinkedList* pArrayListPilotos);

int controller_Palermo_saveAsTextPilotoEspecifico(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos);


#endif // CONTROLLER_H_INCLUDED
