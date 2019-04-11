//vector
void Baraja(vector<Carta> &v){
  for(int i=0;i<v.size();i++){
    Carta aux = v[i];
    v[i] = v[(i+2) % v.size()-1];
    v[(i+2) % v.size()-1] = aux;
  }
}
