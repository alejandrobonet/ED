
void ImprimeProfundidad(){
  queue<Nodo> cola;
  Nodo n = arbol.raiz();
  Nodo hijo;
  cola.push(n);
  stack<Nodo> pila;
  while(!cola.empty()){
    n=arbol.front();
    arbol.pop();
    pila.push(n);

    if((aux=arbol.derecha(n)!=0)
     cola.push(aux);

    if((aux=arbol.izquierda(n)!=0))
    cola.push(aux);
  }

  while(!pila.empty()){
    n=pila.top();
    cout<<arbol.etiqueta(n)<<" ";
    pila.pop();
  }
}
