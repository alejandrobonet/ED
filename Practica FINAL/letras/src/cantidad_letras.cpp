#include <fstream>
#include "diccionario.h"
#include "ConjuntoLetras.h"
#include <iostream>


int main(int argc, char *argv[]) {

if(argc!=4){
  cout<<"Sintaxis: prompt% cantidad_letras spanish letras.txt salida.txt"<<endl;
  return 1;
}
ifstream dic(argv[1]);
if(!dic){
  cout<<"No puedo abrir el diccionario"<<endl;
  return 0;
}
ifstream letras(argv[2]);
if(!letras){
  cout<<"No puedo abrir el fichero letras"<<endl;
  return 0;
}
ofstream salida(argv[3]);
  if(!salida){
    cout<<"No puedo crear el fichero"<<endl;
    return 0;
  }
  salida<<"#Letra\tFAbs.\tFrel."<<endl;

 Diccionario diccionario;
 dic>>diccionario;

 ConjuntoLetras conjunto;
 letras>>conjunto;

Diccionario::iterator it;

  float Fabs[conjunto.size()],total;
  float Frel[conjunto.size()];
  total=0;
  for(int i=0;i<conjunto.size();i++){
    Fabs[i]=0;
    Letra L = conjunto[i];

    for (it = diccionario.begin();it!=diccionario.end();++it){
    Fabs[i]+=L.apariciones(*it);

  }
  total+=Fabs[i];
}
for(int i=0;i<conjunto.size();i++){
Frel[i]=(100*Fabs[i])/total;
Letra L = conjunto[i];
salida<<L.getLetra()<<'\t'<<Fabs[i]<<'\t'<<Frel[i]<<endl;
}
    salida.close();




  return 0;
}
