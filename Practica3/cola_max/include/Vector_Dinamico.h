/**
  * @file Vector_Dinamico.h
  * @brief Fichero cabecera del TDA Vector_Dinamico
  *
  */

#include <iostream>

#ifndef __VECTOR_DINAMICO_
#define __VECTOR_DINAMICO_

using namespace std;
/**
  *  @brief T.D.A. VectorDinamico
  *
  * Una instancia @e c del tipo de datos abstracto @c Vector_Dinanmico es un objeto
  * con 3 campo, un vector dinámico de un objeto template T, y dos int, uno para
  * el número de objetos utiles en el vector y otro con el numero de posiciones
  * reservadas
  
  *
  * @author  Alejandro Bonet Medina
  * @date  Noviembre 2018
  */



template <class T>
class Vector_Dinamico{
  private:
    int utilizados;                      /**<Int con el número de utilizados */
    int reservados;                      /**<Int con el número de posiciones reservadas */
    T *vect;                             /**<Vector dinámico de objetos T */
    void resize(int n);                  /**<Función bool que redimensiona el vector */
    bool espacio_libre() const;          /**<Función bool que nos dice si hay espacio libre */
    bool posvalida(int pos) const;       /**<Funcion bool que nos dice si es una posicion valida*/

  public:

    /**
      * @brief Constructor por defecto
      */
    Vector_Dinamico();


    /**
      * @brief Destructor de Vector_Dinamico
      */
    ~Vector_Dinamico();

    /**
      * @brief Destruye el objeto
      */
    void destruir();

    /**
      * @brief Añade un nuevo objeto T al final del vector
      * @param nuevo Objeto T que se quiere añadir
      */
    void push(const T & elem);

    /**
      * @brief Elimina el objeto T de la posicion pos
      * @param pos Posicion donde se encuentra el objeto a borrar
      */
    void pop(int pos);

      /**
        * @brief Sobrecarga constante del operador []
        * @param i Posicion del objeto que se quiere devolver
        */
    T& operator[](int i);

    /**
      * @brief Sobrecarga del operador []
      * @param i Posicion del objeto que se quiere devolver
      */
    const T& operator[](int i) const;

    /**
      * @brief Constructor de copia
      * @param v Vector que se quiere copiar
      */
    Vector_Dinamico(const Vector_Dinamico& v);

    /**
      * @brief Devuelve utilizados
      * return Devuelve utilizados
      */
    int getUtilizados() const;

    /**
      * @brief Devuelve reservados
      * @return Devuelve reservados
      */
    int getReservados() const;
    /**
      * @brief Devuelve el objeto de la posicion pos
      * @param pos Posicion del objeto
      * @return Devuelve objeto de la posicion pos
      */
T getItem(int pos) const;
/**
  *@brief Comprueba si la pila está vacia
  *@return true si esta vacia, false si hay algún elemento
  */
 bool vacia() const;

    /**
      * @brief Sobrecarga del operador =
      * @param nuevo Objeto que se va a copiar
      */
    Vector_Dinamico<T>& operator=(const Vector_Dinamico<T>& nuevo);

};

#include "Vector_Dinamico.tpp"

#endif
