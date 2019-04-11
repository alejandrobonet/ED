#ifndef __ConjuntoLetras_h__
#define __ConjuntoLetras_h__

#include <iostream>
#include <string>
#include <set>
#include "letra.h"
using namespace std;
/**
 * @brief TDA ConjuntoLetras
 * @details se llena desde un fichero
 *
 */
 class ConjuntoLetras{
 private:
   /**
* @brief Representación del conjunto de letras (un set)
*/
  set<Letra,Letra::cmp> letras;

public:
  /**
    @brief Construye un conjunto de letras vacío.
  **/
  ConjuntoLetras();

  /**
 * @brief Devuelve Tamaño del conjunto de letras (letras)
 * @return Tamaño del conjunto de letras
 */
 int size() const;
  /**
 * @brief Obtiene la puntuación de una palabra
 * @param palabra le pasamos la palabra como string
 * @return Un entero con la suma de las puntuaciones de las letras de la palabra
 */
 int puntuacion(string pal);

 /**
  * @brief Obtiene una letra en base a su posicion
  *
  * @param n posicion de la letra
  */
  const Letra & operator[](int n) const;
 /**
 	 * @brief Pinta un conjunto de letras en un ostream
 	 * @param os la referencia al ostream donde escribir
 	 * @param cl Conjunto de Letras desde el que leer
 	 */
  friend ostream & operator<<(ostream & os, const ConjuntoLetras &cl);
   /**
  * @brief Llena un conjunto de letras desde un istream
  * @param is la referencia al istream desde el que leer
  * @param cl Conjunto de Letras en el que escribir
  */
	friend istream & operator>>(istream & is, ConjuntoLetras &cl);
 };
#endif
