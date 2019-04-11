#ifndef __Bolsa_Letras_h__
#define __Bolsa_Letras_h__

#include <iostream>
#include <string>
#include <set>
#include "letra.h"
#include "ConjuntoLetras.h"

using namespace std;
/**
 * @brief TDA ConjuntoLetras
 * @details Almacena las letras repetidas tantas veces como indica su vaor en repeticiones
 */
 class BolsaLetras{
 private:

 	/**
 	 * @brief Representación de la bolsa de letras (un multiset)
 	 * le pasamos un functor de comparación definido en letra
 	 */
 multiset<Letra, Letra::cmp> bolsa;

public:
  /**
    @brief Construye una bolsa de letras vacia.
  **/
 BolsaLetras();
 /*
 * @brief Devuelve Tamaño de la bolsa de letras
 *
 * @return Tamaño de la bolsa de letras
 */
 int size() const;
 /**
	 * @brief Obtiene una letra en base a su posicion
	 *
	 * @param n posicion de la letra
	 */
  const Letra & operator[](int n) const;
  /**
 * @brief Pinta una bolsa de letras en un ostream
 *
 * @param os la referencia al ostream donde escribir
 * @param bl Bolsa de Letras desde el que leer
 */
friend ostream & operator<<(ostream & os, const BolsaLetras &bl);
/**
 * @brief Llena una bolsa de letras desde un istream
 *
 * @param cl la referencia al ConjuntoLetras desde el que leer
 * @param bl Bolsa de Letras en el que escribir
 */
friend ConjuntoLetras & operator>>(ConjuntoLetras &cl, BolsaLetras &bl);

 };
 #endif
