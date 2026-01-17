//#include <string.h>
#include <cstring>
#include <iostream>
#include <ostream>
#include <vector>
#include <typeinfo>

std::vector rotations = {"L68","L30","R48" ,"L5" , "R60", "L55", "L1", "L99", "R14","L82"};


void print_direction(std::string direction) {
  std::cout << direction ;
}

int main() {

  const char* rotation;
  int starting_point = 50;
  int natural_indx;
  int inner_indx;
  char left = 'L';
  char right = 'R';
  //int length_of_rotations_list = sizeof...()
  for (natural_indx=0; natural_indx<rotations.size(); natural_indx++)
  {
    rotation = rotations[natural_indx];
    std::cout << rotation << ": ";
    char direction = rotation[0];
      if(direction == left){
        print_direction("Left ");
      }else {
        print_direction("Right ");
      }
    for(inner_indx=1; inner_indx<strlen(rotation); inner_indx++){
      std::cout << rotation[inner_indx];
      if(inner_indx==strlen(rotation)-1){
        std::cout << std::endl;
      }
    }
  }

  return 0;
}
