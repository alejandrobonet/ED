void agrupar_elemento(list<int> & entrada, int k){
  list<int>::iterator inicio,elemento;
  elemento=entrada.end();
  int contador=0;


  for(inicio=entrada.begin();entrada.end();++inicio){
    if((*inicio)==k && elemento==entrada.end())
      elemento=inicio;
    else if((*incio==k)){
      contador++;
      inicio=entrada.erase(inicio);
      --inicio;
    }
    }
    entrada.insert(elemento,contador,k);
  }
