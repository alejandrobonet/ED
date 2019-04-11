template <typename T>
class contenedor{
  private:
  unordered_map<T, ArbolBinario<int> > datos;
public:

  class iterator{
    friend class contenedor;
  private:
    typename unordered_map<T, ArbolBinario<int>>::iterator it,final;
  public:
    iterator(){}
    bool operator==(const iterator &i) const{
      return it==i.it;
    }
    bool operator!=(const iterator &i)const{
      return i.it!=it;
    }
    pair<T, ArbolBinario<int>> & operator*(){
      return *it;
    }
    iterator & operator++(){
      bool salir=false;
      ++it;
      while(it!=final && !salir){
        if(suma(it->second)%2==0)
         salir=true;
        else
        ++it;
      }
    }
  };
  iterator begin(){
  iterator i;
  i.it=datos.begin();
  i.final=datos.end();
  if(suma(it->second)%2!=0)
  ++it;
  return i;
  }
  iterator end(){
    iterator i;
    i.it=datos.end();
    i.final=datos.end();
    return i;
  }
};


int suma(const ArbolBinario<int> & arbol){

int total=0;
Nodo n=arbol.raiz();
queue<Nodo> cola;
Nodo aux;
cola.push(n);
while(!cola.empty()){
  n=arbol.front();
  total+=arbol.etiqueta(n);
  arbol.pop();


  if((aux=arbol.derecha(n)!=0)
   cola.push(aux);


  if((aux=arbol.izquierda(n)!=0))
  cola.push(aux);
}
return total;
