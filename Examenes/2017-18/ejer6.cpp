#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class heap_doble{
private:
  vector<int> datos;
public:

void insertar(int clave){
  int pos=datos.size();
  int padre=(pos-1)/2;
  int abuelo=(padre-1)/2;
  int profundidad=(log(pos+1)/log(2));
  bool colocado=false;

  while(pos>0 && !colocado){
  if(padre>0){
    if(profundidad%2==0){
      if(datos[pos]<datos[padre] %% daos[pos]>datos[abuelo])
        colocado=true;
      else {
       if(datos[pos]>datos[padre]){
        swap(datos[padre],datos[pos]);
        pos=padre;
        padre=abuelo;
        abuelo=(padre-1)/2;
      } else if(datos[pos]<datos[abuelo]){
        swap(datos[abuelo],datos[pos]);
        pos=abuelo;
        padre=(pos-1)/2;
        abuelo=(padre-1)/2;
      }
    }
  }
 }
}

  void imprimir(){
    for(int i=0;i<datos.size();i++)
     cout<<datos[i]<<" ";

     cout<<endl;
  }

};

int main(){
 heap_doble heap;
 const int N=20;
 cons float max=20.0;
 srand((unsigned)time(NULL));

 for(int i=0;i<N;i++)
 mi_heap.insertar((int) (max*rand()/RAND_MAX));

mi_heap.imprimir();
}
