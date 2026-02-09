#include <cstdio>
#include <map>
#include <vector>
#include "useful_funcs.h"
#include <iostream>
#include <string>
#include <format>
#include <string>
struct Boundary {
    int upper;
    int lower;
};

std::map<std::string,std::vector<int>> ids_map;

using ids_info = std::map<std::string,std::vector<int>>;
using BoundaryArray = std::vector<Boundary>;

std::vector<std::string> input_arr = {
    "3-5",
    "10-14",
    "16-20",
    "12-18",
    " ",
    "1",
    "5",
    "8",
    "11",
    "17",
    "32",
};


std::vector<Boundary> id_boundaries() {
    std::vector<Boundary> boundaries;
    
    int len_input = input_arr.size();
    const char range_sep = '-';
    int k=0;
    std::string lower_val_string;
    std::string upper_val_string;

    bool sep_found = false;
    for(int i=0;i<len_input;i++){
        Boundary boundary;
        std::string arr_val = input_arr[i];
        int string_length = arr_val.size();
        std::cout << "Array val is: " << arr_val << std::endl;
        
        if(arr_val==" "){
            return boundaries;
        }
        printf("Size of string: %d\n", string_length);
        while (k<string_length)
        {
            char c = arr_val[k];
            // printf("k value is : %d\n" , k);
            // printf("Current char: %c\n", c);
            if(sep_found){
                upper_val_string=upper_val_string+ c;
            }
            if (!(c==range_sep) && sep_found==false) {                
                lower_val_string= lower_val_string + c;
            }else if (c==range_sep) {
                sep_found=true;                
            }
             
            k+=1;    
        }
         printf("Lower string: %s\nUpper string: %s\n", lower_val_string.c_str(), upper_val_string.c_str());
        // std::cout << "Type of lower_stirng_val:  " << typeid(lower_val_string).name();
        
        int lower_val = std::stoi(lower_val_string);
        int upper_val = std::stoi(upper_val_string);
        boundary.lower = lower_val;
        boundary.upper = upper_val;
        boundaries.push_back(boundary);
        lower_val_string = "";
        upper_val_string = "";
        sep_found=false;
        k=0;
    }
    return boundaries;
}

bool check_valid(int id_int, int j){
    bool is_valid=false;
    if(id_int==j){
        is_valid=true;
    }else{
        ;
    }
    return is_valid;
}

ids_info valid_values(BoundaryArray boundaries_arr) {   
    int len_boundary_arr = boundaries_arr.size();
    int empty_range_pos;
    int id_int;
    int k = 0;
    bool is_valid = false;
    int input_arr_size = input_arr.size();
    while(k<input_arr_size){
        std::string val = input_arr[k];
        if(val==" "){   
            // making the position ahead of the empty range
            printf("Sep found at: %d", k);
            empty_range_pos = k+1;
            break;
        }
        k+=1;
    }


    for(int i=0;i<len_boundary_arr;i++){
        int lower_bound = boundaries_arr[i].lower;
        int upper_bound = boundaries_arr[i].upper;
        for(int j=lower_bound;j<upper_bound;j++){
            std::string id = input_arr[empty_range_pos];      
            id_int =  std::stoi(id);
            is_valid = check_valid(id_int, j); 
        }
        if(is_valid){
            ids_map["valid"].push_back(id_int);
        }else{
            ids_map["invalid"].push_back(id_int);
        }
        empty_range_pos+=1;
    }
    return ids_map;
}

int main() {
    std::cout << "Hello day 5";
    print_nl();
    // int used_len;
    std::vector<Boundary> bounds_info = id_boundaries();
    printf("Map at 3 lower: %d and upper:  %d\n", bounds_info[3].lower, bounds_info[3].upper);
    // std::cout << bounds_info.boundary_map.at("upper")[3];
    print_nl();
    ids_info ids_map =  valid_values(bounds_info);
    int valid_len = ids_map["valid"].size();
    int invalid_len =ids_map["invalid"].size();

    for(int i=0;i<valid_len;i++){
          printf("ids_map.at(\"valid\")[%d]: %d\n", i, ids_map["valid"][i]);

    }
    for(int i=0;i<invalid_len;i++){
          printf("ids_map.at(\"invalid\")[%d]: %d\n", i, ids_map["invalid"][i]);
    }
    
    // printf("const char *__restrict format, ...")
    //print_nl();

    return 0;
}