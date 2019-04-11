#include <iostream>
#include <cassert>
#include "Cola_max_pila.h"
using namespace std;

template <class T>
Cola_max<T>::Cola_max(){

}

template <class T>
Cola_max<T>::Cola_max(const Cola_max& cm){
 cola=cm.cola;
 }

template <class T>
Cola_max<T>& Cola_max<T>::operator=(const Cola_max<T> &cm){
 cola=cm.cola;
 
 return *this;
}

template <class T>
int Cola_max<T>::num_elementos() const{
 return cola.size();
}

template <class T>
T Cola_max<T>:: maximo() const{
 return cola.top().max;
}
template <class T>
bool Cola_max<T>::vacia(){
 return cola.vacia();
}
template <class T>
void Cola_max<T>:: poner(T elem){
  elemento aux;
  aux.num = elem;

  if(vacia()) {
    aux.max = elem;
  } else {
    if(cola.top().max > elem)
     elem = cola.top().max;
    aux.max = elem;
  }

  cola.push(aux);

}
template <class T>
void Cola_max<T>::quitar(){
 assert(!vacia());

  Pila<elemento> aux;
  while(!cola.vacia())
  {
    aux.push(cola.top());
    cola.pop();
  }

  aux.pop();  // borrar elemento en cuestión

  while(!aux.vacia())
  {
    poner(aux.top().num);
    aux.pop();
 }
}
template <class T>
T Cola_max<T>::frente() const{
 assert(!cola.vacia());
 Pila<elemento> aux;
 Pila<elemento>aux2;
 aux2=cola;

 
 while(!aux2.vacia()){
  aux.push(aux2.top());
  aux2.pop();
 } 
 return aux.top().num;
}
