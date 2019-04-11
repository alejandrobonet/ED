multiset<int> multi_interseccion (const multiset<int> & m1, const multiset<int> & m2){
  multiset<int>::iterator it1,it2;
  multiset<int> aux;
  it1=m1.begin();
  it2=m2.begin();

  while(it1!=m1.end() && it2!=m2.end()){
    if((*it1)<(*it2))
     ++it1;
    else if((*it2)<(*it1))
    ++it2;
    else{
      aux.insert(*it1);
      ++it1;
      ++it2;
    }

  }
  return aux;
}
