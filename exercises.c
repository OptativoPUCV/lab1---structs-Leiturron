#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) 
{ 
  int max = arr[0];
  for(int i = 1; i < size; i++)
    {
      if(arr[i] > max)
      {
        max = arr[i];
      }
    }
  
  return max; 
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) 
{
  int temp;
  for(int i = 0; i < size / 2; i++)
    {
      temp = arr[i];
      arr[i] = arr[size - i - 1];
      arr[size - i - 1] = temp;
    }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
newsize apunta a una dirección válida que no ha sido inicializada con nigún valor específico. 
*newsize debe almacenar el tamaño del nuevo arreglo que se retorna.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) 
{
  /* CON REALLOC NO FUNCIONA
  int *arrPar = NULL;
  int talla = 0;
  for(int i = 0; i < size; i++)
    {
      if(arr[i] % 2 == 0 && arr[i] != 0)
      {
        arrPar = (int *) realloc(arrPar, sizeof(int) * (talla + 1));
        arrPar[talla] = arr[i];
        talla++;
      }
    }
  (*newSize) = talla;
  //printf("%d", *newSize);
  for(int i = 0; i < *newSize; i++)
  {
    printf(" %d", arrPar[i]);
  }
  */ // CON REALLOC NO FUNCIONA
  int *arrPar = NULL;
  int talla = 0;
  for(int i = 0; i < size; i++)
  {
    if(arr[i] % 2 == 0 && arr[i] != 0)
    {
      talla++;
    }
  }
  arrPar = (int *) malloc(sizeof(int) * talla);
  (*newSize) = talla;
  for(int i = 0, k = 0; i < size; i++)
  {
    if(arr[i] % 2 == 0 && arr[i] != 0)
    {
      arrPar[k] = arr[i];
      k++;
    }
  }
  
  
  return arrPar; 
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados de menor a mayor y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado de menor a mayor.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[])
{
  for(int i = 0, j = 0, k = 0; i < size1 + size2; i++)
    {
      while(j < size1 || k < size2)
        {
          if((arr1[j] < arr2[k] && j < size1) || k >= size2)
          {
            result[i] = arr1[j];
            j++;
            break;
          }
          else
          {
            result[i] = arr2[k];
            k++;
            break;
          }
        }
    }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) 
{
  int temp = arr[0];
  int record = 0;
  for(int i = 1; i < size; i++)
    {
      if(temp < arr[i])
      {
        if(record == 0) record = 1;
        if(record != 1) return 0;
      }
      else if(temp > arr[i])
      {
        if(record == 0) record = -1;
        if(record != -1) return 0;
      }
      temp = arr[i];
    }
  return record;
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion)
{
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
Puedes guiarte con lo que vimos en las clases (diapos).
  */

typedef struct Nodo {
  int numero;
  struct Nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size)
{
  Nodo *cabeza = NULL, *temp = NULL, *actual = NULL;
  for(int i = 0; i < size; i++)
    {
      temp = (Nodo *) malloc(sizeof(Nodo));
      temp->numero = arr[i];
      temp->siguiente = NULL;

      if(cabeza == NULL) cabeza = temp;
      else actual->siguiente = temp;
      actual = temp;
      
    }
  
  return cabeza; 
}
