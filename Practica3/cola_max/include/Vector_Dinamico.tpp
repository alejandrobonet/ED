#include <iostream>
#include <Vector_Dinamico.h>
using namespace std;

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(){
reservados=0;
utilizados=0;
 vect = 0;

}

template <class T>
  bool Vector_Dinamico<T>::posvalida(int pos) const{
    return (pos >= 0 && pos < utilizados);
  }

template <class T>
void Vector_Dinamico<T>::destruir() {
  delete [] vect;
  vect = 0;
  reservados = 0;
  utilizados = 0;
 }

 template <class T>
Vector_Dinamico<T>::~Vector_Dinamico() {
  destruir();
}



 template <class T>
   void Vector_Dinamico<T>::resize(int n){
      if(n>reservados){
        T *aux = new T[n];
        for (int i=0; i<utilizados; i++)
           aux[i] = vect[i];
        delete[] vect;
        vect = aux;
        reservados = n;
      }
   }

template <class T>
   bool Vector_Dinamico<T>::espacio_libre() const {
     return utilizados < reservados;
   }

template <class T>
  int Vector_Dinamico<T>::getUtilizados() const {
    return utilizados;
  }

template <class T>
  int Vector_Dinamico<T>::getReservados() const {
    return reservados;
  }

  //Si no es válida la posición, devuelve un T vacío


  template <class T>
  T& Vector_Dinamico<T>::operator[](int i) {
    return vect[i];
  }

  template <class T>
  const T& Vector_Dinamico<T>::operator[](int i) const{
    return vect[i];
  }


 //Añade elemento al vector
  template <class T>
   void Vector_Dinamico<T>::push(const T & elem){
      if(!espacio_libre()) {
        if(reservados == 0)
          resize(1);
        else
          resize(reservados*2);
      }
      vect[utilizados++]=elem;
      
   }

   template <class T>
    void Vector_Dinamico<T>::pop(int pos) {
        if(posvalida(pos)) {
        for(int i = pos; i < utilizados - 1; i++)
          vect[i] = vect[i+1];
        utilizados--;
      }
    }

    template <class T>
    Vector_Dinamico<T>::Vector_Dinamico(const Vector_Dinamico& v) {
      if(this != &v) {
        utilizados = v.getUtilizados();
        reservados = v.getReservados();
        vect = new T[reservados];
        for(int i = 0; i < utilizados; i++)
          vect[i] = v.getItem(i);
        }
      }
template <class T>
bool Vector_Dinamico<T>::vacia() const{
 return utilizados==0;
 }


template <class T>
Vector_Dinamico<T>& Vector_Dinamico<T>::operator=(const Vector_Dinamico<T>& nuevo) {
  if(&nuevo != this) {
    destruir();
    reservados = nuevo.getReservados();
    utilizados = nuevo.getUtilizados();
    vect = new T[reservados];
    for(int i = 0; i < utilizados; i++)
      vect[i] = nuevo.getItem(i);
  }
  return *this;
}
template <class T>

  T Vector_Dinamico<T>::getItem(int pos) const {
    if(!posvalida(pos)) {
      T t1;
      return t1;
    }
    return vect[pos];
}
