#include <string.h>
#include <iostream>
#include <vector>
#include <typeinfo>

std::vector rotations = {"L68","L30","R48" ,"L5" , "R60", "L55", "L1", "L99", "R14","L82"};


int main() {
const char* experimental = "Some string";

  int starting_point = 50;
int i = 0;
int j=0;
//int length_of_rotations_list = sizeof...()
for (i; i<rotations.size(); i++)
{
  
  std::cout<< rotations[i] << ": " ;
  std::cout << typeid(rotations[i]).name() << std::endl;
  //for (j; j<rotations[i];j++) {
    //std::cout << "Inner values of array:" << &rotations[i][j] << std::endl;
  //:w
  //}
}

for(i; i<sizeof(experimental); i++ ){
  std::cout << "array";
  std::cout << experimental[i];
}

return 0;
}
