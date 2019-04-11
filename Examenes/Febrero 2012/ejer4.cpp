#include <set>
#include <iostream>

using namespace std;

bool masparesqueimpares (const set<int> & c, set<int> & cpar, set<int> & cimpar){
  set<int>::const_iterator it;
  for(it=c.begin();it!=c.begin();++it)
   if((*it)%2==0)
    cpar.insert(*it);
  else
     cimpar.insert(*it);

  return cpar.size() > cimpar.size();
}
