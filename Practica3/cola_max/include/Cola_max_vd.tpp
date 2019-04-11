#include <iostream>
#include <cassert>
#include "Cola_max_vd.h"

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
 return cola.getUtilizados();
}

template <class T>
T Cola_max<T>::maximo() const{
 return cola[cola.getUtilizados()-1].max;
}
 template <class T>
bool Cola_max<T>::vacia(){
 return cola.getUtilizados()==0;
}
 template <class T>
void Cola_max<T>::poner(T elem){
  elemento aux;
  aux.num = elem;

  if(vacia()) {
    aux.max = elem;
  } else {
   int id = cola.getUtilizados()-1;
    if(cola[id].max > elem)
     elem = cola[id].max;

    aux.max = elem;
  }

  cola.push(aux);
}

 template <class T>
void Cola_max<T>::quitar(){
 assert(!cola.vacia());
 Vector_Dinamico <elemento> aux;
 aux=cola;
 while(!cola.vacia()){
 cola.pop(0);
 }
 aux.pop(0);
 while(!aux.vacia()){
 poner(aux[0].num);
 aux.pop(0);
}
}
 template <class T>
T Cola_max<T>::frente() const{
 assert(!cola.vacia());
 return cola.getItem(0).num;
}
