//Apartado A
void insertar(int k, int d){
  int hash=fhash(k);
  info nuevo(k,d);
  data[hash].push_back(nuevo);

  if(recolocar()){
    int tam = next_primo(2*data.size());
    vector<list<info>> d (tam);
    for(i=0;i<data.size();i++){
      list<info>::iterator it;

      for(it=data[i].begin();it!=data[i].end();++it){
        int p = (it->key)%tam;
        data[p].push_back(*it);
      }
    }
    data=d;
  }
}

class iterator(){
  vector<list<info>>::iterator it,fin;
  list<info>::iterator list;

  iterator(){}

  iterator operator++(){
   if(list!=end())
     ++list
  else if(it!=fin){
      ++it;
      list = (*it).begin();
    } else
      it=fin=list;

    return *this;
  }
  info operator*(){
    return(*list);
  }

}

iterator begin(){
  iterator i;
  i.it=data.begin();
  i.fin=data.end();
  list=(*i.it).begin();
  if(list==(*i.it).end())
   ++list;
   return it;
}
iterator end(){
  iterator i;
  i.it=data.end();
  i.fin=data.end();
  list=(*i.it).end();
}
