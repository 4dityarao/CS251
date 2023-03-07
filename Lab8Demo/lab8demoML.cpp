#include <iostream>
#include "class.h"
using namespace std;

int main() {
  int a,b;
  Vehicle *v[5];
  v[0] = new Vehicle("Truck","HonkHonk!",18,100);
  v[1] = new Airplane("Cesna","Rotorrrrrr!",3,100,20000,200);
  v[2] = new Airplane("Airbus A380","6EnginesBaby!",15,150,40000,500);
  v[3] = new Vehicle("Tesla Model X", "______", 4,200);
  int c = 0;
  for(int i= 0; i<5; i++){
    cout<<"I am a "<<v[i]->get_name()<<" and I say "<< v[i]->get_sound()<<"\n";
    c++;
    a+=v[i]->get_max_speed();
    
  }
  b = a/c;
cout << "Avg Max Speed: "<< b;
  return 0;
}