/**
  * @file termino.h
  * @brief Fichero cabecera del TDA Termino
  *
  */

#ifndef __TERMINO
#define __TERMINO

#include <iostream>
#include <vector>
#include <string>	

using namespace std;

/**
  *  @brief T.D.A. Termino
  *
  * Una instancia @e c del tipo de datos abstracto @c Termino se compone de una palabra y una o más definiciones asociadas a esa palabra.
  *Cada una de las definiciones puede contener más de una palabra.
  *
  * palabra: 
  *          <definicion1>, 
   *         <definicion2>,..
  *
  * Un ejemplo de su uso:
  * @include pruebadiccionario.cpp
  *
  * @author Alejandro Bonet Medina
  * @date Octubre 2018
  */


class Termino{
 private:
/**
  * @page rep Conjunto Rep del TDA Termino
  * string palabra
  * vector<string> definicion
  *
  * @section inv Conjunto Invariante de la representación
  * Las definiciones no contendran acentos, tildes ni el caracter ñ.
  * Las definiciones si existe mas de uno se separan por un espacio.
  *
  * @section fa Conjunto Función de abstracción
  * La palabra origen es un String
  * Las definiciones asociadas se almacenan en un vector de string
  *
  * Un objeto válido @e rep del TDA Termino representa al valor
  * "palabra" 
  *           "definicion1" 
  *           "definicion2"
  *             ....
  *
  */

  string palabra; /**< palabra */
  vector<string> definiciones; /**< Coleccion de definiciones */
  int n; /**<Tamaño vector */


 public:
/**
  * @brief Constructor por defecto de la clase.
  */
  Termino();

/**
  * @brief Constructor de la clase
  * @param pal palabra a definir
  * @param def Definiciones de la palabra origen
  * @return crea el término pal: def

  */
  Termino(const string & pal,const vector<string> & def);

/**
  * @brief Constructor de copias de la clase
  * @param c.pal palabra del término a construir
  * @param c.def definición del término a construir
  * @param c.n numero de definiciones del término a construir
  */
  Termino(const Termino& c); 

/**
  * @brief Palabra
  * @return Devuelve la palabra del término
  */  
  const string & pal() const;

/**
  * @brief Definición
  * @pre Debe contener al menos una definicion;
  * @return Devuelve una definición del término
  */
  vector<string> definicion();

/**
  * @brief Numero
  * @return Devuelve el numero de definiciones de la palabra
  */
 const int & numero() const;
/**
  * @brief busca definiciones dado una palabra clave
  * @param s string con la palabra a buscar
  * @param nuevo Termino donde se van a introducir los resultados
  * @return Devuelve true o false indicando si está o no está
  */
bool buscarDefinicion(string s, Termino &nuevo) const;

  /**
  * @brief busca definiciones dado una palabra clave
  * @param s string con la palabra a buscar
  * @return Devuelve true o false indicando si está o no está
  */
 bool buscarDefinicion(string s) const;
/**
  * @brief Establecer la palabra del término a construir
  * @param pal Definición que se añade
  */

  void establecer(const string & pal);

/**
  * @brief Añadir una nueva definición a la palabra
  * @param def Definicion que se añade
  * @post El número de definiciones incrementa
  */

  void anadir(const string & def);

/**
  * @brief Operador de comparación menor
  * @param der Termino correspondiente a la parte derecha de la expresión  
  * @return true si izq.palabra < der.palabra, false en caso contrario
  */
 bool operator < (const Termino & der);
  /**
  * @brief Operador de igualdad
  * @param der Termino correspondiente a la parte derecha de la expresión  
  * @return true si izq.palabra == der.palabra, false en caso contrario
  */

bool operator == (const Termino & der);

  /**
  * @brief Operador de asignación.
  * @param t Termino asignar al objeto implícito.
  * @return Objeto implícito.
  */
Termino & operator= (const Termino & t);
/**
  * @brief Operador suma. Une definiciones a una palabra.
  * @param t Termino a sumar.
  * @pre t.palabra == (*this).palabra
  * @return Unión de las definiciones
  */
Termino operator+ (const Termino & t);
/**
  * @brief Salida de un Termino desde istream
  * @param is stream de entrada
  * @param t Termino que recibe el valor
  * @retval El Termino escrito en t
  *@post Se obtiene en \a os la cadena palabra \\n\\t definicion1 \\n\\t definicion2... 
  *
  */

  friend ostream& operator<< (ostream& os, Termino& t);

/**
  * @brief Entrada de un Termino desde istream
  * @param is stream de entrada
  * @param t Termino que recibe el valor
  * @retval El Termino leído en t
  * @pre La entrada de una cadena separada por ";" con una palabra origen y al
  * menos una palabra de traduccion
  *
  */
  friend istream& operator>> (istream& is, Termino& t);

};

#endif
