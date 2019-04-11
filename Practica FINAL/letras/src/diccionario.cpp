#include <iostream>
#include <algorithm>
#include "diccionario.h"

using namespace std;



Diccionario::Diccionario(){

}

int Diccionario::size() const {
  return datos.size();
}
bool Diccionario::Esta(string palabra){
  bool encontrado = false;

  for (iterator it = begin() ;it != end() && !encontrado; ++it){
  if((*it).compare(palabra)==0)
    encontrado=true;
    }
    return encontrado;
  }

vector<string> Diccionario::PalabrasLongitud(unsigned int longitud){
  vector<string> subdiccionario;

  for (iterator it =begin(); it != end() ; ++it){

    if ((*it).size() == longitud)
    subdiccionario.push_back(*it);


}

 return subdiccionario;

}


Diccionario::iterator::iterator(){

}

string Diccionario::iterator::operator *(){
  return *it;
}
Diccionario::iterator & Diccionario::iterator::operator ++(){
  ++it;
  return *this;
}
bool Diccionario::iterator::operator ==(const iterator &i){
  return i.it==it;
}
bool Diccionario::iterator:: operator !=(const iterator &i){
  return i.it!=it;
}
Diccionario::iterator Diccionario::begin(){
  iterator i;
  i.it=datos.begin();
  return i;
}

Diccionario::iterator Diccionario::end(){
  iterator i;
  i.it=datos.end();
  return i;
}
istream& operator>> (istream & is,Diccionario &D){
string pal;

while(is>>pal){
  D.datos.insert(pal);

}

 return is;
}

ostream & operator<<(ostream & os,const Diccionario &D){
 set<string>::iterator it;

 for (it = D.datos.begin(); it != D.datos.end(); ++it)
   os << (*it) << endl;

return os;

}
