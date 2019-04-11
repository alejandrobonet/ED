#include "letra.h"

using namespace std;

Letra::Letra(){
  c=0;
  n=0;
  p=0;
}

Letra::Letra(char caracter,int num,int puntos){
  c=caracter;
  n=num;
  p=puntos;
}
int Letra::getCantidad() const{
  return n;
}
int Letra::getPuntos() const{
  return p;
}
char Letra::getLetra() const{
  return c;
}
int Letra::apariciones(string palabra){
  int num=0;
  for(unsigned int i=0;i<palabra.size();i++){
    if(toupper(palabra[i])==c)
      num++;

  }
  return num;
}
ostream & operator<<(ostream & os,const Letra &L){
  os<<L.c<<" cantidad:"<<L.n<<" Pnts:"<<L.p;
  return os;
}
