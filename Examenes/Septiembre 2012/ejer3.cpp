

class sistema {
private:
  enum prods {producto1, producto2, producto3, producto4};
  map<string, list<prods> > usuarios;
  map<prods, unsigned> productos;
}

void comprar(const string &user, const string &prod){
  usuarios[user].second.push_back(prod);
  productos[prod].second--;
}

string superventas(){
 map<prods,unsigned> aux=productos;
 map<prod,unsigned>::iterator i;

 for(i=aux.begin();i!=aux.end();++i)
   (*i).second()=0;

 map<string> ,list<prods>::iterator it;
 list<prods>::iterator it;

 for(it=usuarios.begin();it.usuarios.end();++it)
  for(ite=(*it).second.begin();it!=(*ite).second.end();++ite)
    aux[(*ite)]++;

i=aux.begin();
string mayor = (*i).firts;
int n = (*it).second;

for(i;i!=aux.end();++i){
  if((*i).second > n){
    mascomprado=(*i).firts;
    n=(*i).second
  }
}
 return mascomprado;
}
