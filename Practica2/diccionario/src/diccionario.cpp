#include <iostream>
#include <algorithm>  
#include "diccionario.h"

using namespace std;

void Diccionario::ordena(){
  sort( palabras.begin(), palabras.end() );
}

int Diccionario::buscarPalabra(string p){
 vector<Termino>::const_iterator it;

 int pos = -1;
 bool encontrado = false;

 for (it = palabras.begin(); it != palabras.end() && !encontrado; it++){
		
  if ((*it).pal() == p){
   encontrado = true;
   pos = it - palabras.begin();
   }
 }
   	
return pos;
}

Diccionario::Diccionario(){
}

Diccionario::Diccionario(const vector<Termino> pal){
 palabras=pal;
 ordena();
}

Diccionario::Diccionario(const Diccionario& c){
 palabras=c.palabras;
}

Termino Diccionario::definicion(string palabra){
 Termino t;
 int pos = buscarPalabra(palabra);
 
  if(pos!=-1)
   t = palabras[pos];

return t;
}

vector<Termino> Diccionario::terminos(){
 return palabras;
}

int Diccionario::numTerminos(){
 return palabras.size();
}



void Diccionario::anadir(Termino & term){
 int pos = buscarPalabra(term.pal());
 
 if(pos == -1){
  palabras.push_back(term);
  ordena();
 }else{
  palabras[pos] = term+palabras[pos];
 }

}

bool Diccionario::eliminar(const string pal){
 int pos = buscarPalabra(pal);
 bool eliminado=false;

 if(pos!=-1){
  palabras.erase(palabras.begin()+pos);
  eliminado=true;
 }
 return eliminado;

}

Diccionario Diccionario::filtrado(string i, string f){
Diccionario aux;

 vector<Termino>::const_iterator it;

 for (it = palabras.begin(); it != palabras.end(); it++){
   if ((*it).pal().compare(i)>0 && (*it).pal().compare(f))
	aux.palabras.push_back(*it);
 }

	return aux;

}


Diccionario Diccionario::clave(string clave){
 Diccionario d;

 vector<Termino>::const_iterator it;

  for (it = palabras.begin(); it != palabras.end(); it++){
   Termino aux;
   if ((*it).buscarDefinicion(clave,aux))
	d.anadir(aux);
  }

  d.ordena();

return d;
}

void Diccionario::recuento(int& max, int& total, double& med){

 max=0;
 total=0;
 vector<Termino>::const_iterator it;
 for(it = palabras.begin(); it != palabras.end(); it++){
   if(max<it->numero())
     max=it->numero();
  
   total+=it->numero();
   
    
 }
 med=total/(double)palabras.size();
}

Diccionario Diccionario::operator+(const Diccionario & d){
 Diccionario menor;
 Diccionario mayor;

  if (d.palabras.size() < palabras.size()){
	menor = d;
	mayor = palabras;
   }else{
      menor = palabras;
      mayor = d;
    }

 Diccionario nuevo = menor;
 vector<Termino>::iterator it;

	
 for (it = mayor.palabras.begin(); it != mayor.palabras.end(); it++){
   int pos = menor.buscarPalabra((*it).pal());

   bool encontrado = pos != -1;
		
   if (!encontrado){
    nuevo.anadir(*it);
   }else{
    Termino f = (*it)+menor.palabras[pos];
    nuevo.anadir(f);
   }
 }

 nuevo.ordena();
 return nuevo;
}

Diccionario & Diccionario::operator= (const Diccionario & d){
 palabras = d.palabras;

 return *this;

}

istream& operator>> (istream& is, Diccionario& d){
 Termino t;
 Termino t2;
 bool salir = false;
 while(is>>t){
  while(!salir){

  is>>t2;

   if(t==t2){
    t.anadir(t2.definicion()[0]);
    }else{
     d.anadir(t2);
     salir=true;
    }
  }
 d.anadir(t);

}

 return is;
}

ostream& operator<< (ostream& os, Diccionario& d){
 vector<Termino>::iterator it;

 for (it = d.palabras.begin(); it != d.palabras.end(); it++)
   os << *it << endl;
	
return os;  
   
}
