/**
  * @file diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */

#ifndef __DICCIONARIO
#define __DICCIONARIO

#include <iostream>
#include <vector>
#include "termino.h"

using namespace std;
/**
  *  @brief T.D.A. Diccionario
  *
  * Una instancia @e c del tipo de datos abstracto @c Diccionario es una colección de términos ordenados alfabéticamente.
  *
  * palabra1: <definicion1>, <definicion2>,..
  * palabra2: <definicion1>, <definicion2>,..
  * palabra3: <definicion1>, <definicion2>,..
  *
  * Un ejemplo de su uso:
  * @include pruebadiccionario.cpp
  *
  * @author Alejandro Bonet Medina
  * @date Octubre 2018
  */
class Diccionario{
 private:
 
/**
  * @page rep Conjunto Rep del diccionario
  * vector<Termino>
  *
  * @section inv Conjunto Invariante de la representación
  * Los Terminos deben estar definidos corretamente según las restricciones
  * propias de la clase Termino
  *
  * @section fa Conjunto Función de abstracción
  * Un vector de objetos de la clase Termino
  *
  * Un objeto válido @e rep del Traductor representa al valor
  * (vector de Terminos)
  *
  */

  /**
   * @brief Coleccion (lista) de instancias de la clase palabra
   */
 vector<Termino> palabras ;/**< Colección de palabras */
 void ordena(); /**< Ordena el vector alfabéticamente*/
 int buscarPalabra(string p); /**<Busca la posición de una palabra en una definición*/
 public:

/**
  * @brief Constructor por defecto de la clase.
  */ 
 Diccionario();

/**
  * @brief Constructor de la clase
  * @param pal conjunto de términos
  * @return crea un Diccionario
  */
  Diccionario(const vector<Termino> pal);
/**
  * @brief Constructor de copias de la clase
  * @param c.term terminos del Diccionario a construir
  * @param c.n_terms numero de terminos del Diccionario a construir
  */
 Diccionario(const Diccionario& c);

/**
  * @brief Definición de un término
  * @pre Debe contener al menos una definicion;
  * @param i Indice de la palabra que se quieren obtener sus términos
  * @return Devuelve las definiciones asociadas a un término
  */
 Termino definicion(string palabra);

/**
  * @brief Obtener todos los términos
  * @return devuelve todos los términos del diccionario
  */

vector<Termino> terminos();

/**
  * @brief Obtener el número de terminos del diccionario
  * @return Número de terminos del diccionario
  */
 int numTerminos() ;

/**
  * @brief Añadir un nuevo término al diccionario. Si ya existia ese termino hacer unión
  * @param term Término que se añade
  */
 void anadir(Termino & term);

/**
  *@brief Eliminar un término del diccionario
  *@param Palabra de la definicion a eliminar
  *@return true si se ha eliminado, false si no se ha encontrado
  */
 bool eliminar(const string pal);

/**
  * @brief Salida de un Diccionario a ostream
  * @param os stream de salida
  * @param d Diccionario a escribir
  * @post  Se obtiene la salida del diccionario
  */
  friend ostream& operator<< (ostream& os, Diccionario& d);

/**
  * @brief Entrada de un Diccionario desde istream
  * @param is stream de entrada
  * @param d Diccionario que recibe el valor
  * @retval El Diccionario leído en d
  * @pre La entrada debe de tener el formato palabra;definicion
  */
  friend istream& operator>> (istream& is, Diccionario& d);

/**
  *@brief Obtener un subconjunto de este diccionario que incluya únicamente los términos cuya palabra asociada esté en el intervalo especificado
  * @param caracter_inicio Inicio del intervalo
  *@param caracter_fin Fin del intervalo
  *@return Devuelve el subconjunto del diccionario
  */
 Diccionario filtrado(string i, string f);

/**
  *@brief obtener un subconjunto de este diccionario que incluya únicamente las palabras en cuya definición aparezca la palabra clave
  *@param clave Palabra clave 
  *@pre Si una palabra tiene varias definiciones, solo se devolverían como resultado del filtrado por palabra clave aquellas definiciones relacionadas
  *con la palabra clave
  *@return Subconjuto de términos palabra clave
  */
 Diccionario clave(string clave);

/**
  *@brief Obtener el número total de definiciones, el máximo de definiciones asociadas a una única palabra y el promedio de definiciones por palabra.
  *@param max Maximo de definiciones asociadas a una palabra
  *@param total Número total de definiciones
  *@param media Promedio de definiciones por palabra
  */
void recuento(int& max, int& total, double& med);
/**
  * @brief Operador de asignación.
  * @param d Diccionario a asignar al objeto implícito.
  * @return Objeto implícito.
  */
Diccionario & operator= (const Diccionario & d);
/**
 * @brief Operador suma. Realiza la unión de dos Diccionarios
 * @param d Diccionario a unir.
 * @return Nuevo diccionario con la unión
 */
Diccionario operator+(const Diccionario & d);
};
#endif
