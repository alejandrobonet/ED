
a)
template <class T>
void dividir_lista(List<T> & entrada, T k){
  List<T>::iterator inicio,fin;
  int aux;
  inicio=entrada.begin();
  fin=entrada.end()
  bool salir=false;
  while(inicio!=fin && !salir){

    if(*inicio>=k){
      while(*fin>=k && !salir){
        if(fin==inicio)
        salir=true;

        --fin;
      }
      if(!salir){
        aux=*inicio;
        *inicio=*fin;
        *fin=aux;
      }
    }
    ++inicio;
  }
}

b)
template <class T>
int getNivel(const ArbolBinario<T> &a ,const Nodo &n){
  int nivel=0;
  Nodo aux=n;
  while(aux!=a.getRaiz()){
    aux=aux.padre();
    nivel++;
  }
 return nivel;
}

template <class T>
Nodo buscarPadreComun(const Nodo &v, const &w){
  if(v.padre()==w.padre())
   return v.padre();
  else
    return buscarPadreComun(v.padre(),w.padre());
}

template <class T>
Nodo getAMC(const ArbolBinario<T> &arbol, const Nodo &v,const Nodo &w){
  int nivel_v=getNivel(arbol,v);
  int nivel_w=(getNivel(arbol,w);

  if(nivel_v==nivel_w)
    return buscarPadreComun(v,w);
  else if(nivel_v>nivel_w)
    return getAMC(arbol,v.padre(),w)
  else if(nivel_w>nivel_v)
      return getAMC(arbol,v,w.padre();)
}
