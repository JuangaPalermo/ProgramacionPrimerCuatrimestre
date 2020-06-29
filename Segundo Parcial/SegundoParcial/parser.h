#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/*parseo de un archivo de texto
 *param pFile: puntero al archivo
 *param pArrayListVuelos: lista de vuelos
 *return: (0) error o (1) OK.
 */
int parser_VueloFromText(FILE* pFile , LinkedList* pArrayListVuelos);

int parser_PilotoFromText(FILE* pFile, LinkedList* pArrayListPilotos);

#endif // PARSER_H_INCLUDED
