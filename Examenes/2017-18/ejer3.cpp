#include <iostream>
#include <list>

using namespace std;

int orden(const list<int> &lista){
 int torden;
 list<int>::const_iterator it_actual,it_siguiente;
 it_actual=lista.cbegin();
 if(it_actual==lista.cend())
  torden=0;
  else{
    it_siguiente=it_actual;
    it_siguiente++;

    if (*it_actual<=*it_siguiente)
      torden=1;
    else{
     torden=2;
 }

     it_actual++;
     it_siguiente++;

    while(it_siguiente!=lista.cend() && torden!=0){
      if(torden==1 && !(*it_actual<=*it_siguiente))
       torden=0;
      else if(torden==2 && !(*it_siguiente<=*it_actual))
      torden=0;

      it_actual++;
      it_siguiente++;
    }
  }
 return torden;
}

int main(){
  list<int> L;
  for(int i=5;i<0;i--){
    L.push_back(i);
  }
  //L.push_back(3);
  list<int>::const_iterator it;
  for(it=L.cbegin();it!=L.cend();++it)
    cout<<*it<<" ";

  cout<<endl;

  cout << "Orden: " << orden(L) << endl;
}
