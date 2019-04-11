/**
  * @file Cola_max_vd.h
  * @brief Fichero cabecera del TDA Cola_max_vd
  *
  */

#ifndef __COLA_MAX_VD__
#define __COLA_MAX_VD__

#include "Vector_Dinamico.h"



/**
  *  @brief TDA Cola a partir de vector dinámico
  *
  * Una instancia @e p del tipo de datos abstracto Cola_Max implementa una cola (con máximo) basándose en un vector
  *dinámico.
  *
  * @author  Alejandro Bonet Medina
  * @date    Noviembre 2018
  */
 template <class T>
 class Cola_max{


  private:
  /**
  *  @brief Struct contiene dos int, número y máximo
  */
 
 struct elemento{
 T num;
 T max;
 };

  Vector_Dinamico <elemento> cola; /**< Vector dinamico de dato estructurado elemento */

  public:
     /**
    * @brief Constructor por defecto de la clase. Crea una ColaMax
    * con un el vector de elementos vacío.
    */

  Cola_max();
/**
  * @brief Constructor de copia de la clase
  * @param c.cola Vector dinamico de dato estructurado elemento del ColaMAx a construir
  */
 Cola_max(const Cola_max& cm);
/**
  * @brief Operador de asignación.
  * @param cm ColaMax a asignar al objeto implícito.
  * @return Objeto implícito.
  */
 
Cola_max<T>& operator=(const Cola_max<T> & cm);
/**
  *@brief Obtener numero de elementos de la cola
  *@return Numero de elementos de la cola
  */
int num_elementos() const;
/**
  *@brief Obtener elemento máximo de la cola
  *@return Máximo de la cola
  */
T maximo() const;
/**
  *@brief Saber si una cola está vacia
  *@return true si está vacia, false si hay algún elemento
  */
bool vacia();
/**
  *@brief Añadir un elemento a la cola
  *@param elem elemento que se añade a la cola
  */
void poner(T elem);
/**
  *@brief eliminar un elemento de la cola
  */
void quitar();
/**
  *@brief Mostrar el elemento del frente de la cola
  *@return Elemento frente
  */
T frente() const;

};
#include "Cola_max_vd.tpp"
#endif


