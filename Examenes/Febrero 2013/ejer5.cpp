//Apartado A
bool check_rep(const ArbolBinario<float> &A){
  Nodo n = A.raiz();
  ArbolBinario<float> subarbol_derecha;
  ArbolBinario<float> subarbol_izquierda;
  if(A.derecha(n)!=0 A.izquierda(n)!=0){
    if(A.etiqueta(A.derecha(n))+A.etiqueta(A.izquierda(n)) == 1.0){

      A.podar_derecha(n,subarbol_derecha);
     return check_rep(subarbol_derecha);

     A.podar_izquierda(n,subarbol_izquierda);
    return check_rep(subarbol_izquierda);
  }else
    return false;
  }else
    return true; //nodo hoja
}

//Apartado B;

float probable_nodo(const ArbolBinario<float> &a){
  Nodo n = a.raiz();
  ArbolBinario<float> subarbol_derecha;
  ArbolBinario<float> subarbol_izquierda;

  if(a.derecha(n)==NULL && a.izquierda(n)==NULL)
   return a.etiqueta(n);

  else{
    a.podar_derecha(n,subarbol_derecha);
    float d = (subarbol_derecha);
    if((a.etiqueta(n) * d)>0.5)
      return a.etiqueta(n) * d;

      a.podar_izquierda(n,subarbol_izquierda);
      float i = (subarbol_izquierda);
      if((a.etiqueta(n) * i)>0.5)
        return a.etiqueta(n) * i;

  }
}

bool probable(const ArbolBinario<float> &A){
 return probable_nodo(A)>=0.5;
}
