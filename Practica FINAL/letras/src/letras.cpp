#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include "diccionario.h"
#include "ConjuntoLetras.h"
#include "Bolsa_Letras.h"


using namespace std;

struct Encontradas{
  string palabra;
  int puntos;
};

bool orden_puntos(const Encontradas &E1 , const Encontradas &E2){
  return (E1.puntos>E2.puntos) ? true : false;
}

bool orden_longitud(const Encontradas &E1 , const Encontradas &E2){
  return (E1.palabra.size() > E2.palabra.size()) ? true : false;
}

int main(int argc, char * argv[])
{
	if (argc!=5)
	{
		cout<<"Sintaxis prompt% letras spanish letras.txt 8 L"<<endl;
    cout<<"Los parametros de entrada son los siguientes:"<<endl;
    cout<<"1.El nombre del fichero con el diccionario"<<endl;
    cout<<"2.El nombre del fichero con las letras"<<endl;
    cout<<"3.El numero de letras que se deben generar de forma aleatoria"<<endl;
    cout<<"4.Modalidad de juego:"<<endl;
    cout<<"Longitud: Si el parámetro es L se buscará la palabra más larga."<<endl;
    cout<<"Puntuación: Si el parámetro es P se obtendrá la palabra de mayor puntuación."<<endl;
		return 0;
	}

if(strcmp(argv[4],"P") != 0 && strcmp(argv[4],"L") != 0){
  cout<<"Modo de juego incorrecto, debe ser L o P"<<endl;
  return 0;
}
	ifstream f_dicccionario (argv[1]);
	if (!f_dicccionario)
	{
		cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
		return 0;
	}

	ifstream f_letras (argv[2]);
	if (!f_letras)
	{
		cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
		return 0;
	}



	Diccionario diccionario;
	f_dicccionario >> diccionario;


	ConjuntoLetras conjunto;
	f_letras >> conjunto;

  if(strcmp(argv[4],"P") == 0){
    cout<<"*****PUNTUACIONES LETRAS*****"<<endl;
    cout<<conjunto;
  }

	BolsaLetras bolsa;
	conjunto >> bolsa;


 unsigned int numero_letras = atoi(argv[3]);
  char type;
  do{
    cout<<"Las letras son:\t";
    srand(time(0));
    vector<Letra> letras;

    for(unsigned int i=0;i<numero_letras;i++){
      int random = rand() % bolsa.size();
      Letra l = bolsa[random];
      cout<<l.getLetra()<<"\t";
      letras.push_back(l);
    }
    cout<<endl;
    string palabra;
    for(unsigned int i=0;i<letras.size();i++){
      Letra l = letras[i];
      palabra.push_back(tolower(l.getLetra()));
    }
    bool error=false;
    string solucion;
    do{
      error=false;
      cout<<"Escribe tu solucion: ";
      cin>>solucion;
      if(solucion.size()>numero_letras){
        cout<<"Tu solucion es incorrecta, ya que tiene mas letras que la cantidad proporcionada"<<endl;
        error=true;
      }else{
        for(unsigned int i=0;!error && i<solucion.size();i++){
          char letra = solucion[i];
          if(palabra.find(letra) == string::npos){
            cout<<"Tu solucion es incorrecta, ya que usaste una letra que no se te proporciono"<<endl;
            error=true;
          }
        }
      }

    } while(error);
    if(!diccionario.Esta(solucion))
     cout<<"Tu solucion no existe"<<endl;
     else{
      if(strcmp(argv[4],"L") == 0)
       cout<<solucion<<"\t Puntuacion: "<< solucion.size()<<endl;
       else
       cout<<solucion<<"\t Puntuacion: "<< conjunto.puntuacion(solucion)<<endl;
     }


     vector<Encontradas> encontradas;
     cout<<"Mis soluciones son:"<<endl;
     for(int i=numero_letras;i>0;i--){
       vector<string> longitud = diccionario.PalabrasLongitud(i);

       for(vector<string>::iterator it=longitud.begin();it!=longitud.end();it++){
         string palabra_vector = *it;

         vector<bool> letras_usadas(letras.size(),false);
         unsigned int contador_usadas=0;
         for(unsigned int pos_actual=0;pos_actual<palabra_vector.size();pos_actual++){
           bool salir=false;
           char letra_actual=palabra_vector[pos_actual];
           for(unsigned int origen =0;!salir && origen<palabra.size();origen++){
             if(!letras_usadas[origen] && palabra[origen] == letra_actual){
               letras_usadas[origen]=true;
               contador_usadas++;
               salir=true;
             }
           }
         }
         if(contador_usadas == palabra_vector.size()){
           Encontradas nueva;
           nueva.palabra=palabra_vector;
           nueva.puntos=conjunto.puntuacion(palabra_vector);
         encontradas.push_back(nueva);
       }
       }
     }
     if(encontradas.empty())
     cout<<"No se encontro ninguna palabra con esas letras"<<endl;
     else{
       if(strcmp(argv[4],"L") == 0){
        sort(encontradas.begin(),encontradas.end(),orden_longitud);
        for(unsigned int i=0;i<encontradas.size();i++)
        cout<<encontradas[i].palabra<<"\tPuntuacion: "<<encontradas[i].palabra.size()<<endl;
      }
        else if(strcmp(argv[4],"P") == 0){
        sort(encontradas.begin(),encontradas.end(),orden_puntos);

        for(unsigned int i=0;i<encontradas.size();i++)
          cout<<encontradas[i].palabra<<"\tPuntuacion: "<<encontradas[i].puntos<<endl;

        }
        cout<<"Mejor solucion: "<<encontradas[0].palabra<<endl;
  }

     cout << "¿Quieres seguir jugando[S/N]?";
     cin >> type;
    cout << endl;
  }while(tolower(type)!='n');


return 0;
}
