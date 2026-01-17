#include <cstring>
#include <iostream>
#include <string>
#include <vector>


std::string string_chunk = "11-22,95-115,998-1012,1188511880-1188511890,222220-222224, 1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124";


int main() {

    int lenght_of_chunk = string_chunk.size();
    std::vector<std::string> ID_array;
    std::string id;
    std::string current_char;
    std::string sep = ",";
    int id_array_indx=0;

    for(int indx =0; indx<lenght_of_chunk; indx++){
        id += string_chunk[indx];
        current_char = string_chunk[indx];
        
        if(current_char==sep){
            ID_array.push_back(id);
            id="";
        }
    }
    for(int j=0; j<ID_array.size() ;j++){
        std::cout << ID_array[j] << std::endl;
    }
    
    return 0;
}