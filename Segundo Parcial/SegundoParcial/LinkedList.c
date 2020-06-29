#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode;
    int i;

    if(this == NULL || nodeIndex < 0 || nodeIndex >= ll_len(this))
    {
    	pNode = NULL;
    }
    else
    {
    	pNode = this->pFirstNode;

    	for(i=0; i != nodeIndex; i++)
    	{
    		pNode = pNode->pNextNode;

    	}
    }

	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prevNode;
    Node* postNode;
    Node* newNode;

    if(this != NULL && nodeIndex > -1 && nodeIndex <= ll_len(this))
	{
    	newNode = (Node*) malloc (sizeof(Node));

    	if(newNode != NULL)
    	{
    		if(nodeIndex == 0)
    		{
    			newNode->pNextNode = getNode(this, nodeIndex);
    			// (es valido //) newNode->pNextNode = this->pFirstNode;
    			newNode->pElement = pElement;
    			this->pFirstNode = newNode;
    			this->size++;
    			returnAux = 0;
    		}
    		else if (nodeIndex == ll_len(this))
    		{
    			newNode->pNextNode = NULL;
    			newNode->pElement = pElement;
    			prevNode = getNode(this, (nodeIndex-1));
    			prevNode->pNextNode = newNode;
    			this->size++;
    			returnAux = 0;
    		}
    		else
    		{
    			prevNode = getNode(this, nodeIndex-1);
    			postNode = getNode(this, nodeIndex);
    			newNode->pNextNode = postNode;
    			newNode->pElement = pElement;
    			prevNode->pNextNode = newNode;
    			//postNode->pNextNode = getNode(this, nodeIndex+1);
    			this->size++;
    			returnAux = 0;
    		}
    	}
	}

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	addNode(this, ll_len(this), pElement);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Trae un elemento de la lista ubicado en el inidice indicado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this != NULL && index > -1 && index < ll_len(this))
	{
    	auxNode = getNode(this, index);
    	returnAux = auxNode->pElement;
	}

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode;

    if(this != NULL && index > -1 && index < ll_len(this))
	{
    	auxNode = getNode(this, index);
    	auxNode->pElement = pElement;
    	returnAux = 0;
	}

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* selectedNode;
    Node* prevNode;
    Node* nextNode;

    if(this != NULL && index > -1 && index < ll_len(this))
	{
    	if(index == 0)
		{
			selectedNode = getNode(this, index);
			free(selectedNode);
    		this->pFirstNode = getNode(this, index+1);
			this->size--;
			returnAux = 0;

		}
		else if (index == ll_len(this))
		{
			selectedNode = getNode(this, index);
			free(selectedNode);
			this->size--;
			returnAux = 0;
		}
		else
		{
			selectedNode = getNode(this, index);
			prevNode = getNode(this, index-1);
			nextNode = getNode(this, index+1);
			free(selectedNode);
			prevNode->pNextNode = nextNode;
			this->size--;
			returnAux = 0;
		}
	}

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	for(i=len; i>0; i--) //preguntar si la condicion es > a -1 o > a 0
    	{
    		ll_remove(this, i);
    	}

    	this->pFirstNode = NULL;
    	this->size = 0;
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this); //se agrega el clear
    	//free(this); //el free es innecesario, ya que el clear ya lo aplica
    	this = NULL; //se agrega el NULL
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* auxNode;
    int i;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	for(i=0; i<len; i++) //preguntar si es < o <=
    	{
    		auxNode = getNode(this, i);

    		if(pElement == auxNode->pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_len(this) > 0)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >-1 && index <= ll_len(this))
    {
    	addNode(this, index, pElement);
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this != NULL && index > -1 && index <ll_len(this))
    {
    	auxNode = getNode(this, index);
    	returnAux = auxNode -> pElement;
    	ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* auxNode;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	for(i=0; i<len; i++)
    	{
    		auxNode = getNode(this, i);

    		if(pElement==auxNode->pElement)
    		{
    			returnAux = 1;
    			break;
    		}
    	}

    	if(i==ll_len(this))
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int len2;
    Node* auxNode2;
    int auxElement;

    if(this != NULL && this2 != NULL)
    {
    	len2 = ll_len(this2);

    	for(i=0; i<len2; i++)
    	{
    		auxNode2 = getNode(this2, i);
    		auxElement = ll_contains(this, auxNode2->pElement);

    		if(auxElement == 0)
    		{
    			returnAux = 0;
    			break;
    		}

    	}

    	if(len2 == i)
    	{
    		returnAux = 1;
    	}

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param this LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to) //revisar
{
    LinkedList* cloneArray = NULL;
    void* auxElement;
    int i;

    if(this != NULL && from >-1 && from<=ll_len(this) && to >= from && to<=ll_len(this))
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(i=from; i<=to; i++)
    		{
    			auxElement = ll_get(this, i);
    			ll_add(cloneArray, auxElement);
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this) //revisar
{
    LinkedList* cloneArray = NULL;
    int i;
    int len;
    void* auxElement;

    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	len = ll_len(this);

    	if(cloneArray != NULL)
    	{
    		for(i=0; i<len; i++)
    		{
    			auxElement = ll_get(this, i);
    			ll_add(cloneArray, auxElement);
    		}
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    int len;
    void* auxElement;

    if((order == 0 || order == 1) && this != NULL && pFunc != NULL)
    {
    	len = ll_len(this);

    	for(i=0; i<len-1; i++)
    	{
    		for(j=i+1; j<len; j++)
    		{
    			if(order == 0)
    			{
    				if(ll_get(this,i) != NULL && ll_get(this,j) != NULL && pFunc(ll_get(this,i), ll_get(this,j)) < 0)
    				{
    					auxElement = ll_get(this,i);
						ll_set(this,i,ll_get(this,j));
						ll_set(this,j,auxElement);
    				}

    			}
    			else
    			{
    				if(ll_get(this,i) != NULL && ll_get(this,j) != NULL && pFunc(ll_get(this,i), ll_get(this,j)) > 0)
					{
						auxElement = ll_get(this,i);
						ll_set(this,i,ll_get(this,j));
						ll_set(this,j,auxElement);
					}
    			}
    		}
    	}

    	returnAux = 0;
    }

    return returnAux;

}


/** \brief
 *
 * \param this LinkedList* Puntero a LinkedList
 * \param pFuncion (*pFuncion) - puntero a la funcion contador
 * \return int (suma de retornos del puntero a funcion) si OK, o (0) si error;
 *
 */
int ll_count(LinkedList* this, int(*pFuncion)(void* element))
{
    int retornoFuncion = 0;
    int acumulador = 0;

    void* pElement;
    int i;
    int len;

    if(this!=NULL && pFuncion!=NULL)
    {
        len = ll_len(this);

        for(i=0; i<len; i++)
        {
            pElement = ll_get(this, i);
            if(pElement != NULL)
            {
                retornoFuncion = pFuncion(pElement);
                acumulador+= retornoFuncion;
            }
        }
    }

    return acumulador;
}

/** \brief Filtra la lista pasada como parametro segun el criterio del puntero a funcion
 *
 * \param this LinkedList* - lista a filtrar
 * \param pFuncion (*pFuncion) - puntero a funcion criterio de filtrado
 * \return LinkedList* (clonedList = NULL) si error o (clonedList) si OK.
 *
 */
LinkedList* ll_filter(LinkedList* this, int(*pFuncion)(void* element))
{
    int auxMatch;
    void* pElement;
    LinkedList* clonedList;
    int i;
    int len;

    pElement = NULL;
    clonedList = NULL;

    if(this != NULL && pFuncion != NULL)
    {
        clonedList = ll_newLinkedList();

        if(clonedList != NULL)
        {
            len = ll_len(this);

            for(i=0; i<len; i++)
            {

                pElement = ll_get(this,i);

                if(pElement != NULL)
                {
                    auxMatch = pFuncion(pElement);

                    if(auxMatch == 1)
                    {
                        ll_add(clonedList, pElement);
                    }
                }

            }
        }
    }

    return clonedList;
}

LinkedList* ll_filter_parametro(LinkedList* this, int(*pFuncion)(void* element, char* filtro), char* parametro)
{
    int auxMatch;
    void* pElement;
    LinkedList* clonedList;
    int i;
    int len;

    pElement = NULL;
    clonedList = NULL;

    if(this != NULL && pFuncion != NULL)
    {
        clonedList = ll_newLinkedList();

        if(clonedList != NULL)
        {
            len = ll_len(this);

            for(i=0; i<len; i++)
            {

                pElement = ll_get(this,i);

                if(pElement != NULL)
                {
                    auxMatch = pFuncion(pElement, parametro);

                    if(auxMatch == 1)
                    {
                        ll_add(clonedList, pElement);
                    }
                }

            }
        }
    }

    return clonedList;
}
