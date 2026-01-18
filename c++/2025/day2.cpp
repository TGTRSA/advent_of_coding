
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

struct Separators{
    std::string id_separator=",";
    std::string range_separator="-";
};

struct Boundaries {
    int upper;
    int lower;
};

std::string string_chunk = "11-22,95-115,998-1012,1188511880-1188511890,222220-222224, 1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124";

Boundaries get_boundary_conditions(std::vector<std::string> ID_array, std::string id_char, std::string range_separator){
    Boundaries  conditions;
    std::string boundary;
    int boundary_count = 0;
    for(int j=0; j<ID_array.size() ;j++){
        std::string id_range = ID_array[j];
        int iterator = id_range.length();
        for(int inner_indx=0; inner_indx<iterator; inner_indx++){
            id_char = id_range[inner_indx];
            boundary+= id_range[inner_indx];
            //std::cout << "Individual id parts: " << id_char <<" and is of type " <<typeid(id_char).name() << std::endl;
            
           if (id_char==range_separator){
            if(boundary_count==true){
                conditions.lower = std::stoi(boundary);
            }else{
                conditions.upper = std::stoi(boundary);
            }
           }
            id_char="";
        }
    } 
    return conditions;
}

int main() {
    int lenght_of_chunk = string_chunk.size();
    std::vector<std::string> ID_array;
    std::string id;
    std::string current_char;
    std::string sep = ",";
    std::string  range_separator = "-";
    std::string id_char;

    int id_array_indx=0;

    for(int indx =0; indx<lenght_of_chunk; indx++){
        id += string_chunk[indx];
        current_char = string_chunk[indx];
        
        if(current_char==sep){
            ID_array.push_back(id);
            id="";
        }
    }
    Boundaries boundary_conidtions = get_boundary_conditions(ID_array, id_char, range_separator);
    std::cout << "Lower bound: " << boundary_conidtions.lower << std::endl << "Upper bound: " << boundary_conidtions.upper << std::endl;

    
    return 0;
}