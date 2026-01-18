
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

enum class int_type {
    EVEN,
    ODD,
};

struct Separators{
    char id_separator=',';
    char range_separator='-';
};

struct Boundaries {
    int upper;
    int lower;
};


Separators separator;
std::vector<std::string> valid_ids;
std::string string_chunk = "11-22,95-115,998-1012,1188511880-1188511890,222220-222224, 1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124";

bool is_valid(std::string id_chunk, int id_len, enum int_type){
    
}

void print_nl(){
    std::cout << std::endl;
}

bool is_even(int value){
    if(value%2==0){
        return true;
    }else{
        return false;
    }
}

void is_valid(Boundaries boundaries) {
    int loop_int = 0; 
    for(int i=boundaries.lower;i<boundaries.upper;i++){
        std::string string_int = std::to_string(i);
        int id_length = string_int.length();
        if(is_even(id_length)){
            int loop_upper = id_length/2;
            for(int u=0;u<loop_upper;u++){
                bool validity = is_valid(string_int,id_length, int_type::EVEN);
            }
        }
    }
}

Boundaries get_boundary_conditions(std::string id_range){
    Boundaries  conditions;
    std::string id_char;
    std::string boundary;
    int i=0;
    while(i<id_range.size()-1){
        id_char+=id_range[i];
        if(id_range[i]!=separator.range_separator){
            conditions.lower=std::stoi(id_char);
        }else{
            conditions.upper = std::stoi(id_char);
        }
        i+=1;
    }
    return conditions;
}

void loop_through_ranges(std::vector<std::string> ID_array) {
    std::string range;
    for(int i=0; i<ID_array.size();i++)
    {
        range=ID_array[i];
        for(int j=0;j<range.length();j++){
            std::cout << "Current range " << range;
            print_nl();
            Boundaries boundary_conidtions = get_boundary_conditions(range);
            std::cout << "Lower bound: " << boundary_conidtions.lower << std::endl << "Upper bound: " << boundary_conidtions.upper << std::endl;    
        }
        range = " ";
    }
   
}

int main() {
    int lenght_of_chunk = string_chunk.size();
    std::vector<std::string> ID_array;
    std::string id;
    std::string current_char;
    std::string sep = ",";
    std::string  range_separator = "-";

    for(int indx =0; indx<lenght_of_chunk; indx++){
        current_char = string_chunk[indx];
        
        if(current_char==sep){
            ID_array.push_back(id);
            id="";
        }else{
            id += string_chunk[indx];
        }
    }
    std::cout << "ID array: ";
    for(int i=0; i<ID_array.size();i++)
    {        
        std::cout << ID_array[i];
    }
    
    print_nl();
    loop_through_ranges(ID_array);
    
    return 0;
}