int NumeroCaminosNodo(ArbolBinario<int>::preorden_iterator n,int k){

}


int NumeroCaminos(const ArbolBinario<int> &a, int k){
  Nodo n=a.raiz();
  ArbolBinario<int> derecha,izquierda;
  int contador=0;
  int caminos=0;
  contador=A.etiqueta(n);
  else if(a.izquierda(n)!=NULL){
    A.podar_izquierda(izquierda);
    contador += longitud(izquierda,k);
    if(contador==k)
     caminos++;
  }else if(a.derecha(n)!=NULL){
    A.podar_derecha(derecha);
    contador+=numeroCaminos(derecha,k);
    if(contador==k);
    caminos++;
  }


  return caminos;
}
