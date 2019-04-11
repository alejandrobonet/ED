#include "ConjuntoLetras.h"


using namespace std;

ConjuntoLetras::ConjuntoLetras(){

}

int ConjuntoLetras::size() const {
  return letras.size();
}
int ConjuntoLetras::puntuacion(string pal){
  int puntos=0;
  for(unsigned int i=0;i<pal.size();i++){
    bool salir=false;
    for(set<Letra>::iterator it = letras.begin();it!=letras.end() && !salir;it++){
      if(tolower(pal[i])==tolower(it->getLetra()) ){
        puntos+=it->getPuntos();
        salir=true;
      }
    }
  }
  return puntos;


}
const Letra & ConjuntoLetras:: operator[](int n)const {
    set<Letra>::iterator it = letras.begin();
  		advance(it, n);
  return *it;
}
ostream & operator<<(ostream & os, const ConjuntoLetras &cl){
  set<Letra>::iterator it;
  for(it=cl.letras.begin();it!=cl.letras.end();it++)
    os<<*it<<endl;

  return os;
}

istream & operator>>(istream & is, ConjuntoLetras &cl){
  string linea;
  getline(is,linea);

  while(is){
    char c;
    int n,p;
    is >> c >> n >> p;

    Letra l(c,n,p);
    cl.letras.insert(l);

  }
  return is;
}
