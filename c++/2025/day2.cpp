
#include <cstdint>

#include <iostream>
#include <string>
#include <vector>

enum class Boundary{
    UPPER,
    LOWER,
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

bool compare_sets(std::string set1, std::string set2){
    if(set1==set2){
        return false;
    }else {
        return true;
    }
}

bool check_first_two(std::string id_chunk){

    if(id_chunk[0]==id_chunk[1]){return false;} 
    else{return true;}
        
}

bool is_valid(std::string id_chunk, int id_len){
    std::string set1;
    std::string set2;
    int32_t set = 0;
    bool duplicate;
    if(id_len==2){
        duplicate = check_first_two(id_chunk);
        return duplicate;
    }else{
        if (id_len%2==0) 
        {           
            int half = id_len/2;
            for(int i=0;i<half;i++){
                if(set==0){
                    set1+=id_chunk[i];
                    if(i==half){
                        i=half;
                        half=half*2;
                        set=1;
                    }
                }else{
                    set2+=id_chunk[i];
                }
            }
            duplicate = compare_sets(set1, set2);
            
        }
        return duplicate;
    }
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

void valid_id(Boundaries boundaries) {
    int loop_int = 0; 
    for(int i=boundaries.lower;i<boundaries.upper;i++){
        std::string string_int = std::to_string(i);
        int id_length = string_int.length();
        if(is_even(id_length)){
            bool duplicate = is_valid(string_int,id_length);
            if(duplicate==false){
                std::cout << string_int << " is valid";
                print_nl();
            }
        }
    }
   
}


Boundaries get_boundary_conditions(std::string id_range){
    Boundaries  boundaries;
    std::string id_char;
    std::string boundary;
    int i=0;
    int choice = 0;

    std::cout << "Getting boundary for range";
    print_nl();
    int range_len = id_range.size();

    while (i < range_len) {
        if (id_range[i] == separator.range_separator) {
            boundaries.lower = std::stoi(id_char);
            id_char = "";
        } else {
            id_char += id_range[i];
        }
        i++;
    }

    // Trigger the upper boundary after the loop
    boundaries.upper = std::stoi(id_char);

    return boundaries;
}

void loop_through_ranges(std::vector<std::string> ID_array) {
    std::string range;
    for(int i=0; i<ID_array.size();i++)
    {
        range=ID_array[i];
        
        std::cout << "Current range " << range;
        print_nl();
        
        Boundaries boundary_conidtions = get_boundary_conditions(range);
        std::cout << "Lower bound: " << boundary_conidtions.lower << std::endl << "Upper bound: " << boundary_conidtions.upper << std::endl;    
        valid_id(boundary_conidtions);
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
        std::cout << ID_array[i]<< ",";
    }
    
    print_nl();
    loop_through_ranges(ID_array);
    
    return 0;
}