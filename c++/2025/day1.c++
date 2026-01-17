//#include <string.h>
#include <cstring>
#include <iostream>
#include <ostream>
#include <vector>
#include <typeinfo>

std::vector rotations = {"L68","L30","R48" ,"L5" , "R60", "L55", "L1", "L99", "R14","L82"};


int main() {
const char* experimental = "Some string";
  const char* result;
  int starting_point = 50;
  int i = 0;
  int j=0;
  //int length_of_rotations_list = sizeof...()
  for (i; i<rotations.size(); i++)
  {
    result = rotations[i];
    std::cout<< rotations[i] << ": " ;
    std::cout << typeid(rotations[i]).name() << std::endl;
  }
  const char* empty = " ";
  std::cout << "Type of empty: " <<typeid(*empty).name() << " whose value is " <<  empty << "whose length is " << strlen(empty) << "\n";
  std::cout << "Type of experimental: " << typeid(experimental).name() << " whose value is " << experimental[2] << "\n";
  std::cout << "What happens when we want the type of an index into of const char* " << typeid(experimental[0]).name() << std::endl;
  
  for(j; j<strlen(experimental); j++ ){
   // std::cout << "array\n"
    if(std::strcmp(experimental, empty)==0){
      std::cout << experimental[j] <<std::endl;
    }else{
      std::cout << experimental[j] << std::endl;
    }
  }

  return 0;
}
