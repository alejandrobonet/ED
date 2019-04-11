#include <iostream>
#include <list>
using namespace std;

struct enfret
{
    unsigned char eq1,eq2; //codigos de los equipos enfrentados
    unsigned int canastas_eq1,canastas_eq2; //canastas por cada equipo
};
class Liga{
 private:
list <enfret> res;

public:
  int Ganados(unsigned char equipo){
    int cantidad=0;
       list <enfret>::iterator it;
       for(it=res.begin();it!=res.end();it++){
       if((it->eq1==equipo && (it->canastas_eq1>it->canastas_eq2)) || (it->eq2==equipo && (it->canastas_eq2>it->canastas_eq1)) )
       cantidad++;
  }
  return cantidad;
}

class iterator{
  friend class Liga;
private:
  list<enfret>::iterator it,fin;
  iterator(){}

  enfret& operator *(){
    return *it;
  }
  bool operator!=(const iterator &otro) const {
    return it!=otro.it;
  }
  bool operator==(const iterator &otro) const{
    return it==otro.it;
  }

  iterator & operator++(){
    bool salir=false;
    ++it;
    while(it!=fin && !salir){
      if(it->canastas_eq1==it->canastas_eq2)
        salir=true;
      else
        ++it;

    }
    return *this;
  }
};

iterator begin(){
 iterator i;
 i.it=res.begin();
 i.fin=res.end();

 if((i.it)->canastas_eq1 != (i.it)->canastas_eq2)
    ++i;

  return i;
}
iterator end(){
  iterator i;
  i.fin=res.end();
 i.it=res.end();
 return i;
}
};
