#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED

typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto; //FK

    char fecha[15];
    char destino[30];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

}eVuelo;

typedef struct
{
	char nombre[128];
	int idPiloto; //PK
}ePiloto;


/*Crea en memoria dinamica espacio para una variable de tipo eVuelo
 *return: la direccion de memoria dinamica
 */
eVuelo* vuelo_new();

/*Crea en memoria dinamica espacio para una variable de tipo ePiloto
 *return: la direccion de memoria dinamica
 */
ePiloto* piloto_new();

/*Constructor por parametros para eVuelo (recibe todos los parametros en formato tipo char*, despues convierte)
 *param idVuelo: ID vuelo
 *param idAvion: ID avion
 *param idPiloto: ID piloto
 *param fecha: fecha asignada al elemento
 *param destino: destino asignado al elemento
 *param cantPasajeros: pasajeros totales del elemento
 *param horaDespegue: horario de comienzo del elemento
 *param horaLlegada: horario de finalizacion del elemento
 *return: eVuelo*
 */
eVuelo* vuelo_newParametros(char* idVuelo,char* idAvion,char* idPiloto,char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada);

/*Constructor por parametros para ePiloto (recibe todos los parametros en formato tipo char*, despues convierte)
 *param nombre: nombre del piloto
 *param idPiloto: ID asignado al elemento
 *return ePiloto*
 */
ePiloto* piloto_newParametros(char* nombre, char* idPiloto);


/*Setter ID vuelo
 *param this: puntero del vuelo
 *param idVuelo: ID vuelo a asignar
 *return: (0) error o (1) OK.*/
int vuelo_setIdVuelo(eVuelo* this,int idVuelo);
/*Getter ID vuelo
 *param this: puntero del vuelo
 *param idVuelo: puntero del ID vuelo
 *return: (0) error o (1) OK.*/
int vuelo_getIdVuelo(eVuelo* this,int* idVuelo);

/*Setter ID avion
 *param this: puntero del vuelo
 *param idAvion: ID avion a asignar
 *return: (0) error o (1) OK.*/
int vuelo_setIdAvion(eVuelo* this,int idAvion);
/*Getter ID avion
 *param this: puntero del vuelo
 *param idAvion: puntero del ID avion
 *return: (0) error o (1) OK.*/
int vuelo_getIdAvion(eVuelo* this,int* idAvion);

/*Setter ID piloto
 *param this: puntero del vuelo
 *param idPiloto: ID piloto a asignar
 *return: (0) error o (1) OK.*/
int vuelo_setIdPiloto(eVuelo* this,int idPiloto);
/*Getter ID piloto
 *param this: puntero del vuelo
 *param idPiloto: puntero del ID piloto
 *return: (0) error o (1) OK.*/
int vuelo_getIdPiloto(eVuelo* this,int* idPiloto);


/*Setter fecha
 *param this: puntero del vuelo
 *param fecha: fecha a asignar
 *return: (0) error o (1) OK.*/
int vuelo_setFecha (eVuelo* this,char* fecha);
/*Getter fecha
 *param this: puntero del vuelo
 *param fecha: puntero de la fecha
 *return: (0) error o (1) OK.*/
int vuelo_getFecha (eVuelo* this,char* fecha);

/*Setter destino
 *param this: puntero del vuelo
 *param destino: destino a asignar
 *return: (0) error o (1) OK.*/
int vuelo_setDestino(eVuelo* this,char* destino);
/*Getter destino
 *param this: puntero del vuelo
 *param destino: puntero del destino
 *return: (0) error o (1) OK.*/
int vuelo_getDestino(eVuelo* this,char* destino);

/*Setter cantPasajeros
 *param this: puntero del vuelo
 *param cantPasajeros: cantPasajeros a asignar
 *return: (0) error o (1) OK.*/
int vuelo_setCantPasajeros(eVuelo* this,int cantPasajeros);
/*Getter cantPasajeros
 *param this: puntero del vuelo
 *param cantPasajeros: puntero del cantPasajeros
 *return: (0) error o (1) OK.*/
int vuelo_getCantPasajeros(eVuelo* this,int* cantPasajeros);

/*Setter horaDespegue
 *param this: puntero del vuelo
 *param horaDespegue: horaDespegue a asignar
 *return: (0) error o (1) OK.*/
int vuelo_setHoraDespegue(eVuelo* this,int horaDespegue);
/*Getter cantPasajeros
 *param this: puntero del vuelo
 *param horaDespegue: puntero del horaDespegue
 *return: (0) error o (1) OK.*/
int vuelo_getHoraDespegue(eVuelo* this,int* horaDespegue);

/*Setter horaLlegada
 *param this: puntero del vuelo
 *param horaLlegada: horaLlegada a asignar
 *return: (0) error oCantPasajeros (1) OK.*/
int vuelo_setHoraLlegada(eVuelo* this,int horaLlegada);
/*Getter horaLlegada
 *param this: puntero del vuelo
 *param horaLlegada: puntero del horaLlegada
 *return: (0) error o (1) OK.*/
int vuelo_getHoraLlegada(eVuelo* this,int* horaLlegada);



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


/** \brief Recibe una posicion de la lista y retorna el numero de dicha posicion
 * \param element void* elemento del LL
 * \return int asignado a cantPasajeros de ese elemento
 */
int vuelo_obtainCantPasajeros(void* element);


/** \brief Recibe una posicion de la lista y retorna 1 si el destino es Irlanda
 * \param element void* elemento del LL
 * \return int (1) si destino == Irlanda o (0) si destino != Irlanda
 */
int vuelo_destinoIrlanda(void* element);

int vuelo_menosDe3Horas(void* element);

int vuelo_destinoPortugal(void* element);

int vuelo_sacarAlexLifeson(void* element);

int vuelo_soloAlexLifeson(void* element);

int vuelo_soloRichardBach(void* element);

int vuelo_soloJohnKerry(void* element);

int vuelo_soloErwinRommel(void* element);

int vuelo_soloStephenCoonts(void* element);
/******************************************************************************************/

/*
 * Esta firma es igual a la de LL sort. Aca tengo que agregar los criterios de ordenamiento*/
/*
 * int employee_CompareByName(void* e1, void* e2);
   int employee_CompareById(void* e1, void* e2);
   int employee_CompareByHoras(void* e1, void* e2);
   int employee_CompareBySueldo(void* e1, void* e2);
 */



/*Elimina el empleado que le paso como parametro
 *esta funcion se encontraba vacia, se le cambian los parametros para su utilizacion.
void employee_delete(Employee* this);*/


#endif // AEROLINEA_H_INCLUDED
