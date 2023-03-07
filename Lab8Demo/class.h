#include <iostream>
using namespace std;
class Vehicle {
   private:
    string name;
    string sound;
    int num_wheels;
    int max_speed;

  public:

    Vehicle(){
      this->name = "Car";
      this->sound = "Vroom Vroom!";
      this->num_wheels = 4;
      this->max_speed = 150;      
    }
    Vehicle(string name, string sound, int num_wheels, int max_speed){
      this->name = name;
      this->sound =sound;
      this->num_wheels =  num_wheels;
      this->max_speed = max_speed;      
    }
    void set_name(string name){
      this->name = name;
    }
    void set_sound(string sound){
      this->sound = sound;
    }

    void set_num_wheels(int num_wheels){
      this->num_wheels = num_wheels;
    }
    void set_max_speed(int max_speed){
      this->max_speed = max_speed;
    }
    string get_name(){
      return name;
    }
    string get_sound(){
      return sound;
    }
    int get_num_wheels(){
      return num_wheels;
    }
    int get_max_speed(){
      return max_speed;
    }

};

class Airplane :public Vehicle{
    private:
      int max_altitude;
      int max_air_speed;
    public:
    Airplane():Vehicle(){      
    max_air_speed  = 500;
    max_altitude = 40000;
    set_name("Airplane");
    set_sound("Whooooosh!");
    set_num_wheels(13);
  }
  Airplane(string name, string sound, int num_wheels, 
          int max_speed, int max_altitude, int max_air_speed):
          Vehicle(name, sound, num_wheels, max_speed){ 
    this->max_air_speed  = max_air_speed;
    this->max_altitude = max_altitude;
      }
      
  };
