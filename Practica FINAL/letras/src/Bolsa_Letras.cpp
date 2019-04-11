#include "Bolsa_Letras.h"

using namespace std;

BolsaLetras::BolsaLetras(){

}

int BolsaLetras::size() const{
  return bolsa.size();
}

const Letra & BolsaLetras:: operator[](int n)const{
  multiset<Letra>::iterator it = bolsa.begin();
    advance(it, n);
return *it;
}

ostream & operator<<(ostream & os, const BolsaLetras &bl){
  set<Letra>::iterator it = bl.bolsa.begin();

  		for (; it!=bl.bolsa.end(); ++it )
  os << *it << endl;
   return os;
}

ConjuntoLetras & operator>>(ConjuntoLetras &cl, BolsaLetras &bl){
  for(int i=0;i<cl.size();i++){
    Letra letra = cl[i];

    for(int j=0;j<letra.getCantidad();j++)
    bl.bolsa.insert(letra);
  }
  return cl;
}
