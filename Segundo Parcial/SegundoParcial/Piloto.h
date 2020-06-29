#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED

typedef struct
{
	char nombre[128];
	int idPiloto; //PK
}ePiloto;


/*Crea en memoria dinamica espacio para una variable de tipo ePiloto
 *return: la direccion de memoria dinamica
 */
ePiloto* piloto_new();


/*Constructor por parametros para ePiloto (recibe todos los parametros en formato tipo char*, despues convierte)
 *param nombre: nombre del piloto
 *param idPiloto: ID asignado al elemento
 *return ePiloto*
 */
ePiloto* piloto_newParametros(char* nombre, char* idPiloto);


/*Setter ID piloto
 *param this: puntero del piloto
 *param idPiloto: ID piloto a asignar
 *return: (0) error o (1) OK.*/
int piloto_setIdPiloto(ePiloto* this,int idPiloto);
/*Getter ID piloto
 *param this: puntero del piloto
 *param idPiloto: puntero del ID piloto
 *return: (0) error o (1) OK.*/
int piloto_getIdPiloto(ePiloto* this,int* idPiloto);

/*Setter nombre piloto
 *param this: puntero del piloto
 *param nombre: NombrePiloto a asignar
 *return: (0) error o (1) OK.*/
int piloto_setNombrePiloto(ePiloto* this,char* nombre);
/*Getter ID piloto
 *param this: puntero del piloto
 *param nombre: puntero del NombrePiloto
 *return: (0) error o (1) OK.*/
int piloto_getNombrePiloto(ePiloto* this,char* nombre);

#endif // PILOTO_H_INCLUDED
