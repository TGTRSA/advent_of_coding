//#include <string.h>
#include <cstring>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <typeinfo>
extern "C" {
  #include <cstring>
}
// of type stringc
std::vector rotations = {"L68","L30","R48" ,"L5" , "R60", "L55", "L1", "L99", "R14","L82"};

struct Boundaries {
  int boundary1=100;
  int boundary2=0;
};

void print_direction(std::string direction) {
  std::cout << direction ;
}
// if left - else + at 100 or 0 reset?? 

int main() {
  Boundaries boundary_vals;
  const char* rotation;
  int starting_point = 50;
  int natural_indx;
  int inner_indx;
  std::string value;
  int value_integer;

  std::cout << "Type of vlue for value var: "  << typeid(value).name() <<std::endl;
  char left = 'L';
  char right = 'R';
  //int length_of_rotations_list = sizeof...()


  for (natural_indx=0; natural_indx<rotations.size(); natural_indx++)
  {
    rotation = rotations[natural_indx];
    std::cout << rotation << ": ";
    char direction = rotation[0];
  //  std::cout << "Lenght of rotation string: " << strlen(rotation)<< std::endl;
    for(inner_indx=1; inner_indx<strlen(rotation); inner_indx++){
//      std::cout << "Inner index: " << inner_indx  << "\nChar at index: " << rotation[inner_indx] << std::endl;
      //std::string character = std::string cpp_str(rotation[inner_indx]);
      value+=rotation[inner_indx];

      std::cout << "Value to adjust: " << value << std::endl;
      value_integer = std::stoi(value);

      if(direction == left){
        print_direction("Left ");
        
        starting_point = starting_point-value_integer;
      }else {
        print_direction("Right ");
        starting_point = starting_point+value_integer;        
      }
      if (starting_point > boundary_vals.boundary1){
        starting_point-=100;
      }

      if(inner_indx==strlen(rotation)-1){      
        std::cout << std::endl;
        value = "";
      }

    }
  }

  return 0;
}
