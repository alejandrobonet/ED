#include <iostream>
#include "termino.h"
#include <sstream>
#include <cassert>


using namespace std;

Termino::Termino(){
 n=0;
}


Termino::Termino(const string & pal,const vector<string> & def){
 palabra=pal;
 definiciones=def;
 n=definiciones.size();
}

Termino::Termino(const Termino& c){
  palabra = c.palabra;
  definiciones = c.definiciones;
  n=c.definiciones.size();
}

const string & Termino::pal()const{
 return palabra;
}

vector<string> Termino::definicion() {
 return definiciones;
}

 const int & Termino::numero() const{
 return n;
}

bool Termino::buscarDefinicion(string s, Termino &nuevo) const{

 bool encontrado = false;
 vector<string>::const_iterator it;

 for(it = definiciones.begin(); it != definiciones.end(); it++){
   if ((*it).find(s) < 1000000){
	nuevo.anadir(*it);
	encontrado = true;
    }
  }
  if (encontrado)
    nuevo.palabra = palabra;

 return encontrado;
}

bool Termino::buscarDefinicion(string s) const{
 bool encontrado = false;
 vector<string>::const_iterator it;

 for(it = definiciones.begin(); it != definiciones.end() && encontrado; it++)
   if ((*it).find(s) < 1000000)
	encontrado = true;

  return encontrado;
}
void Termino::establecer(const string & pal){
 palabra=pal;
}

void Termino::anadir(const string & def){
 
 definiciones.push_back(def);
 n=definiciones.size();
	
}

bool Termino::operator < (const Termino & der){
 if(palabra.compare(der.palabra)<0){
  return true;
 }else{
  return false;
 }
}

bool Termino::operator == (const Termino & der){
 if(palabra.compare(der.palabra)==0){
  return true;
 }else{
  return false;
 }
}

Termino & Termino::operator= (const Termino & t){
 palabra = t.palabra;
 definiciones = t.definiciones;
 n=t.definiciones.size();
return *this;
}

Termino Termino::operator+ (const Termino & t){
 assert(t.palabra == palabra);
 vector<string>::const_iterator it;
 string p  = palabra;
 vector<string> a;

 if (definiciones.size() > t.definiciones.size() ){
   a = definiciones;
   for (it = t.definiciones.begin(); it != t.definiciones.end(); it++)
	if (!buscarDefinicion(*it)) 
         a.push_back(*it); 
   
	}else{
	  a = t.definiciones;

	 for (it = definiciones.begin(); it != definiciones.end(); it++)
	  if (!t.buscarDefinicion(*it)) 
	   a.push_back(*it); 		
	}

	return Termino(p,a);
}


ostream& operator<< (ostream& os, Termino& t){
	vector<string>::const_iterator it;

	os << t.palabra;

	for(it = t.definiciones.begin(); it != t.definiciones.end(); it++)
		os << endl << "\t" << *it;

  return os ;
}

istream& operator>> (istream& is, Termino& t){
 char separador = ';';
 string pal;
 string linea, token;
 vector<string> def;

 getline(is,linea);
 stringstream linestream(linea);
 
 getline(linestream, token, separador);
  if (token != "")
     pal = token;

  getline(linestream, token);
  def.push_back(token);


  t = Termino(pal,def); 

    return is;

}


