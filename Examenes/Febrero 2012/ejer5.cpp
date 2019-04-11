//Apartado A
#include "arbolbinario.h"
#include <iostream>
using namespace std;

bool estaSesgado(const ArbolBinario<int> &arbol){
  bool segado=true;
  ArbolBinario<int>::preordern_iterator i;
  for(i=arbol.begin_preorden();i!=arbol.end_preorden() && segado ;++i){
    if(i.derecha()!=NULL && (i->izquierda >= i->derecha))
      segado=false;
  }
  return segado;
}

//Apartado B

void TransformaEnSesgado(const Nodo & n,ArbolBinario<int> arbol){
  ArbolBinario<int> a1,a2;

  if(n.derecha()!=NULL && (n.izquierda()>= n.derecha())){
    a1.podar_izquierda(n);
    a2.podar_derecha(n);
    arbol.insertar_izquierda(n,a2)
    arbol.insertar_derecha(n,a1);
  }
  if(n.derecha()!=0)
   return TransformaEnSesgado(n.derecha(),arbol);

  if(n.izquierda()!=0)
    return TransformaEnSesgado(n.izquierda(),arbol);
}
