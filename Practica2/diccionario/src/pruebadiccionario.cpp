#include "diccionario.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Diccionario mi_diccionario;
   f>>mi_diccionario; //Cargamos en memoria el diccionario
   bool salir=false;
   string opcion;
   string newter,defi,inicio,fin;
   Termino t;
   int max,total;
   double med;
   Diccionario d;	
   do{
    int a;
    	
    cout<<"------------Menu del diccionario-------"<<endl<<endl;
    cout<<"1-Imprimir diccionario asi como sus datos"<<endl;
    cout<<"2-Obtener definiciones de una palara"<<endl;
    cout<<"3-Eliminar termino"<<endl;
    cout<<"4-Añadir termino"<<endl;
    cout<<"5-Obtener subdiccionario con palabra clave asi como sus datos."<<endl;
    cout<<"6-Obtener subdiccionario intervalo asi como sus datos."<<endl;
    cout<<"7-Salir menu diccionario."<<endl;
    cout<<endl<<"Seleccione una opcion: "<<endl;
    cin>>a; 
 

   switch(a){
	case 1:
   	cout << endl << endl << "Imprimiendo Diccionario: " << endl << endl << mi_diccionario << endl;
	mi_diccionario.recuento(max,total,med);
    cout<<"-------------------------DATOS DICCIONARIO---------------------"<<endl<<endl;
   cout<<"El diccionario tiene "<<mi_diccionario.numTerminos()<<" terminos."<<endl;
   cout<<"EL número maximo de definiciones por palabra es de "<<max<<" definiciones."<<endl;
   cout<<"El numero total de definiciones es: "<<total<<"."<<endl;
   cout<<"El numero medio de definiciones por palabra es: "<<med<<"."<<endl;
   break;
  	case 2:

  cout << endl << "Introduce una palabra para obtener sus definiciones: ";
  cin>>opcion;
  
  
  t= mi_diccionario.definicion(opcion);
  cout << endl << "Resultado: " << endl << endl << t << endl << endl;
 //eliminar termino
  break;
	case 3:
 	cout<<"Introduce una palabra para eliminarla del diccionario"<<endl;
	 cin>>opcion;
	
	 if(!mi_diccionario.eliminar(opcion))
	  cout<<"La palabra "<<opcion<<" no se encuentra en mi diccionario"<<endl;
 break;
	case 4:

//añadir termino
	

	 cout<<endl<<endl;
	 cout<<"Introduce un nuevo termino al diccionario:"<<endl;
	 cin>> newter;
	 t.establecer(newter);
	 cout<<"Introduce su definicion: "<<endl;
	 getline(cin,defi);
	 
	 t.anadir(defi);
	 mi_diccionario.anadir(t);
 break;
 	case 5:

//palabra clave

  	cout << endl << "Introduce una palabra para obtener el subdiccionario asociado: ";

	  cin >> opcion;
	  d = mi_diccionario.clave(opcion);
	  if(d.numTerminos()==0){
	   cout<<"No hay diccionario asociado a la palabra clave "<<opcion<<"."<<endl;
	  }else{
	cout << endl << endl << "Imprimiendo Diccionario asociado: " << endl << endl << d << endl;
	  d.recuento(max,total,med);
	   cout<<"-------------------------DATOS DICCIONARIO---------------------"<<endl<<endl;
	   cout<<"El diccionario tiene "<<d.numTerminos()<<" terminos."<<endl;
	   cout<<"EL número maximo de definiciones por palabra es de "<<max<<" definiciones."<<endl;
	   cout<<"El numero total de definiciones es: "<<total<<"."<<endl;
	  cout<<"El numero medio de definiciones por palabra es: "<<med<<"."<<endl;
 	}
break;
	case 6:

//intervalo
	  cout << endl << "Introduce un intervalo el subdiccionario asociado (ejemplo subdiccionario a-c): "<<endl;
	  cout<<"Inicio intervalo:"<<endl;
	  cin >> inicio;
	  cout<<"Fin intervalo: "<<endl;
	  cin >> fin;
	  d = mi_diccionario.filtrado(inicio,fin);
	cout << endl << endl << "Imprimiendo Diccionario intervalo: " << endl << endl << d << endl;
	  d.recuento(max,total,med);
	   cout<<"-------------------------DATOS DICCIONARIO---------------------"<<endl<<endl;
	   cout<<"El diccionario tiene "<<d.numTerminos()<<" terminos."<<endl;
	   cout<<"EL número maximo de definiciones por palabra es de "<<max<<" definiciones."<<endl;
	   cout<<"El numero total de definiciones es: "<<total<<"."<<endl;
	   cout<<"El numero medio de definiciones por palabra es: "<<med<<"."<<endl;
break;

	case 7:
	 salir=true;
break;

	default:
	cout<<"Opcion del menú incorrecta"<<endl;
break;
 }  
 }while(!salir);
   /* Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino  
    Algunas sugerencias: 
    - Obtener las definiciones asociadas a una palabra   
    - Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
    - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"   
    - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
    - Cualquier otra funcionalidad que considereis de interes 
   */

}
