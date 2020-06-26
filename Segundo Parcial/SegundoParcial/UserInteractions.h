#ifndef USERINTERACTIONS_H_INCLUDED
#define USERINTERACTIONS_H_INCLUDED

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*/brief imprime un menu ingresado por el usuario y devuelve la opcion seleccionada
 * 		 si el usuario ingresa un numero que supera la cantidad de opciones, pide nuevamente
 * 		 que ingrese una opcion correcta
 *
 * param char opciones[]: lista de opciones
 * param int cantidadOpciones: cantidad de opciones dentro del menu.
 *
 * return Retorna opcion seleccionada o -1 si error
 * */
int printMenu (char opciones [], int cantidadOpciones);


/*brief: pide al usuario que ingrese un entero, lo valida entre dos valores, y lo devuelve
 *
 *param char mensaje[]: Mensaje al usuario pidiendole el int
 *param char error[]: Mensaje de error si el int no cumple los criterios de max/min
 *param int min: Valor minimo permitido a ingresar
 *
 *return: int ingresado por el usuario y validado por la funcion
 */
int getInt (char mensaje[], char error[], int min);


/*brief: recibe dos numeros y devuelve el promedio entre ambos
 *
 *param int primervalor: primer numero a sumar para calcular el promedio
 *param int segundovalor: segundo numero a sumar para calcular el promedio
 *
 *return: float obtenido de dividir la suma de los dos numeros
 */
float getPromedio(int primerValor, int segundoValor);


/*brief: pide un string y lo carga en la direccion indicada
 *
 *param char mensaje[]: Mensaje al usuario pidiendole el string
 *param char texto[]: Direccion donde se carga el string ingresado por el usuario
 *param int largo: Largo maximo permitido por el string
 *
 */
void getString (char mensaje[], char texto[], int largo);


/*brief: le pide al usuario que ingrese un float y lo devuelve
 *
 *param char mensaje[]: mensaje al usuario pidiendole el float
 *param char error[]: mensaje de error al usuario
 *param float min: valor minimo permitido
 *
 *return Retorna el numero ingresado por el usuario.
 * */
float getFloat(char mensaje[], char error[], float min);


/*brief: le pide al usuario que ingrese un char, y lo valida entre los dos char pasados como
 * 	 	 parametro en la funcion. Si hay un error, se lo pide nuevamente hasta que ingrese un
 * 	 	 caracter valido.
 *
 *param char mensaje[]: Mensaje al usuario pidiendole el char
 *param char error[]: mensaje de error en caso de que ingrese un caracter no valido
 *param char letraUno: primer letra para validar
 *param char letraDos: segunda letra para validar
 *
 *return retorna el char validado
 * */
char getChar (char mensaje[], char error[], char letraUno, char letraDos);


/*brief: le pide al usuario que ingrese un int y lo retorna
 *
 * return Retorna el int ingresado por el usuario
 * */
int askForInt (char texto []);

/*Generador de IDs empezando desde 1 y aumentando en 1 cada vez que se llama*/
int generateId (void);

/*Pide un entero y lo valida entre el maximo y el minimo ingresados (incluyendolos)*/
int intBetweenTwo(char texto[], char error[], int min, int max);

/*Cuando el usuario apreta Enter, limpia la pantalla*/
void enterToCleanScreen(void);

#endif // USERINTERACTIONS_H_INCLUDED
