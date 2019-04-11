bool condicion(stack<int> &P,queue<int> &Q){
  stack<int> aux;

  while(!Q.empty()){
    aux.push_back(Q.front());
    Q.pop();
  }

  bool cond=false;
  bool continuar=true;
unsigned  tam = aux.size();
  while(!aux.empty() && continuar && P.empty()){
    if(aux.front()==P.front()){
      cond=true;
      aux.pop();
    }else{
      cond=false;
      if(tam>aux.size())
       continuar=false;
    }
   P.pop();
  }

  return esta;
}
