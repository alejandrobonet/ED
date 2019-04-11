/**
  * @file pila.h
  * @brief Fichero cabecera del TDA Pila
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo
  *
  */

#ifndef __Pila_H__
#define __Pila_H__

#include <cassert>

/**
 *  @brief T.D.A. Pila
 *
 *
 * Una instancia @e v del tipo de datos abstracto @c Pila sobre el
 * tipo @c T es una lista de elementos del mismo con un funcionamiento
 * @e LIFO (Last Input, First Output). En una pila, las operaciones
 * de inserción y borrado de elementos tienen lugar en uno de los extremos
 * denominado @e Tope. Una pila de longitud @e n la denotamos
 *
 * - [a1,a2,a3,..,an>
 *
 * donde @e ai es el elemento de la posición i-ésima.
 *
 * En esta pila, tendremos acceso únicamente al elemento del @e Tope, es
 * decir, a @e an. El borrado o consulta de un elemento será sobre  @e an, y la
 * inserción de un nuevo elemento se hará sobre éste. Quedando el elemento
 * insertado como @e Tope de la pila.
 *
 * Si @e n=0 diremos que la pila está vacía.
  * @author  Alejandro Bonet Medina
  * @date  Noviembre 2018
  */
template <class T>
class Pila
{
  private:
    struct Celda
    {
      T elemento; 
      Celda * siguiente;

      Celda() : siguiente(0) {};
      Celda(const T & elem, Celda * sig) : elemento(elem), siguiente(sig) {};
    };

    Celda * primera;
    int num_elementos;
  public:
/**
  *@brief Constructor por defecto de la clase
  */  
    Pila();
    /**
      * @brief Constructor de copia
      * @param p Pila que se quiere copiar
      */
    Pila(const Pila<T> & p);
    /**
      * @brief Destructor de PILA
      */
    ~Pila();
     /**
      * @brief Sobrecarga del operador =
      * @param P Objeto que se va a copiar
      */
    Pila& operator= (const Pila<T>& p);
/**
  *@brief Comprueba si la pila está vacia
  *@return true si esta vacia, false si hay algún elemento
  */
    bool vacia() const ;
/**
  *@brief Elemento tope de la pila
  *@return Tope de la pila
  *@pre la pila no debe estar vacia
  */
    T top () const;
/**
  *@breif Añadir un elemento en la pila
  *@param elem Elemento a añadir
  */

    void push(const T & elem);
/**
  *@brief Quitar un elemento de la pila
  *@post Elimina un elemento de la pila (LIFO)
  */
    void pop();
/**
  *@brief Muestra el tamaño de la pila
  *@return Tamaño pila
  */
    int size() const;

};


#include <pila.tpp>

#endif 
