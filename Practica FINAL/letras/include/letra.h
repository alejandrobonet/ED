#ifndef __Letra_h__
#define __Letra_h__

#include <iostream>
#include<string>

using namespace std;
/**
 * @brief TDA Letra
 * @details almacena un caracter, la cantidad de veces que aparece en la bolsa y su puntuación
 *
 */
class Letra{
private:
  /**
     * La representación interna de la clase Letra son tres variables
     * c que es el caracter de la letra (tipo char)
     * n que es el numero de veces que debe aparecer en la bolsa (tipo int)
     * p que es el la puntuación asociada a esa letra (tipo int)
     *
     */
	char c;	// El caracter de la propia letra
	int n; 	// La cantidad de veces que puede aparecer.
  int p; // La puntuacion de una letra.

public:
  /**
    @brief Construye una letra vacía.
  **/
  Letra();
  /**
  * @brief Constructor que inicializa una letra con su puntuación
  *
  * @param caracter char que contiene un caracter
  * @param num enter con el numero de apariciones de la letra en la bolsa
  * @param puntos puntuación de la letra
  */
  Letra(char caracter,int num,int puntos);
  /**
  *@brief Devuelve la cantidad de la Letra
  *@return cantidad de apariciones de una Letra
  */
  int getCantidad() const;
  /**
  *@brief Devuelve la puntuacion de la Letra
  *@return cantidad de puntuacion de una Letra
  */
  int getPuntos() const;
  /**
  *@brief Devuelve la Letra
  *@return cantidad la Letra
  */
  char getLetra() const;
	/**
		*@brief Obtiene el numero de veces que aparece una letra en una palabra
		*@param palabra que se quiere obtener el numero de apariciones
		*@return numero de apariciones de una letra en una palabra
		*/
		int apariciones(string palabra);
  /**
   @brief Escribe en un flujo de salida un diccionario
   @param os:flujo de salida
   @param D: el objeto diccionario que se escribe
   @return el flujo de salida
 **/
 friend ostream & operator<<(ostream & os, const Letra &L);

 struct cmp
    {
        bool operator()(const Letra &L1 , const Letra &L2)
        {
            return (L1.c < L2.c) ? true : false;
        }
};
};
#endif
