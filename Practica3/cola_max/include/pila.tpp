#include <cassert>
#include <iostream>
#include <pila.h>
using namespace std;

template <class T>
Pila<T>::Pila(){
primera=0;
num_elementos=0;
}

template <class T>
Pila<T>::Pila(const Pila<T> & p)
{
  if (p.primera!=0) {
    Celda *orig=p.primera;
    Celda *nueva;
    primera=nueva= new Celda(orig->elemento,0);
    orig=orig->siguiente;
    while (orig!=0) {
      nueva->siguiente=new Celda(orig->elemento,0);
      nueva=nueva->siguiente;
      orig=orig->siguiente;
    }
  }
  else primera=0;
  num_elementos=p.num_elementos;
}

template <class T>
int Pila<T>::size() const{
 return num_elementos;
}

template <class T>
Pila<T>::~Pila()
{
  Celda *aux;
  while (primera!=0) {
    aux= primera;
    primera=primera->siguiente;
    delete aux;
  }
}

template <class T>
bool Pila<T>:: vacia() const{
return num_elementos==0;
}

template <class T>
T Pila<T>:: top() const{
assert(primera!=0);
return primera->elemento;
}

template <class T>
Pila<T>& Pila<T>::operator=(const Pila<T> & p)
{
  if (this!=&p) {
    Celda *aux;
    while (primera!=0) {
      aux= primera;
      primera=primera->siguiente;
      delete aux;
    }
    if (p.primera!=0) {
      Celda *orig=p.primera;
      Celda *nueva;
      primera=nueva= new Celda(orig->elemento,0);
      orig=orig->siguiente;
      while (orig!=0) {
        nueva->siguiente=new Celda(orig->elemento,0);
        nueva=nueva->siguiente;
        orig=orig->siguiente;
      }
    }
    num_elementos=p.num_elementos;
  }
  return *this;
}



template <class T>
void Pila<T>::push(const T & elem)
{
  primera = new Celda(elem,primera);
  num_elementos++;
}



template <class T>
void Pila<T>::pop()
{
  assert(primera!=0);
  Celda *aux=primera;
  primera = primera->siguiente;
  delete aux;
  num_elementos--;
}
