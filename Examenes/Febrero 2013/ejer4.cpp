typedef pair<int,int> intervalo;

bool Extraer(list<intervalo> &l1, intervalo x,list<intervalo> &l2){
  list<intervalo>::iterator i;
  bool continuar1=true;
  for(i=l1.begin();i!=l1.end() && continuar;++i){
    if(x.firts < (*i).second){
      int aux=(*i).second;
      (*i).second = x.firts-1;
      if(aux > x.second){
        Intervalo nuevo((x.second+1),aux);
      }
      continuar=false;
    }
  }

  list<intervalo>::iterator it;
  bool continuar=true;
  for(it=l2.begin();it!=l2.end() && continuar ;++it){
    if(x.second<=(*it).firts){
      (*it).firts=x.firts;
      /*
      i=it;
      --i:
      if((*it).firts < (*i.firts))
       l2.erase(i);
     */
      continuar=false;
    }

  }
  return !(continuar1 && continuar);
}
