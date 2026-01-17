//#include <string.h>
#include <cstring>
#include <iostream>
#include <ostream>
#include <vector>
#include <typeinfo>
extern "C" {
  #include <cstring>
}
// of type stringc
std::vector rotations = {"L68","L30","R48" ,"L5" , "R60", "L55", "L1", "L99", "R14","L82"};


void print_direction(std::string direction) {
  std::cout << direction ;
}
// if left - else + at 100 or 0 reset?? 

int main() {

  const char* rotation;
  int starting_point = 50;
  int boundary1=100 ;
  int boundary2=0;
  int natural_indx;
  int inner_indx;
  std::string value; // of type c
  std::cout << "Type of vlue for value var: "  << typeid(value).name() <<std::endl;
  char left = 'L';
  char right = 'R';
  //int length_of_rotations_list = sizeof...()


  for (natural_indx=0; natural_indx<rotations.size(); natural_indx++)
  {
    rotation = rotations[natural_indx];
    std::cout << rotation << ": ";
    char direction = rotation[0];
      
    for(inner_indx=1; inner_indx<strlen(rotation); inner_indx++){
      //std::cout << rotation[inner_indx];
      //std::string character = std::string cpp_str(rotation[inner_indx]);
      value+=rotation[inner_indx];

      if(inner_indx==strlen(rotation)-1){
        
        std::cout << std::endl;
        value = "";
      }
      std::cout << "Value to adjust: " << value << std::endl;
      
      
      if(direction == left){
        print_direction("Left ");
      }else {
        print_direction("Right ");
      }
    }
  }

  return 0;
}
