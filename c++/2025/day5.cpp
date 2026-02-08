#include <cstdio>
#include <vector>
#include "useful_funcs.h"
#include <map>
#include <iostream>
#include <string>

struct BoundaryInfo {
    std::map<std::string, std::vector<int>> boundary_map;
    int sep_pos;
};

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


BoundaryInfo id_boundaries() {
   BoundaryInfo boundary_map;
    int len_input = input_arr.size();
    const char range_sep = '-';
    int k=0;
    std::string lower_val_string;
    std::string upper_val_string;
    int map_indx=0;
    bool sep_found = false;
    for(int i=0;i<len_input;i++){
        std::string arr_val = input_arr[i];
        int string_length = arr_val.size();
        std::cout << "Array val is: " << arr_val << std::endl;
        if(arr_val==" "){
            std::cout << "Sep pos is: " << i;
            print_nl();
            boundary_map.sep_pos = i;
            return boundary_map;
        }
        while (k<string_length)
        {
            char c = arr_val[k];
            if (arr_val[k]!=range_sep && sep_found==false) {
                lower_val_string+=c;
            }else{
                sep_found=true;
                
                upper_val_string+= c;
            }
            // std::string u_str(1, arr_val[j+1]);
                    // std::string l_str(1, arr_val[j-1]);
                    // int upper_val = std::stoi(u_str);
                    // int lower_val = std::stoi(l_str);
            k+=1;    
        }
        int lower_val = std::stoi(lower_val_string);
        int upper_val = std::stoi(upper_val_string);
        boundary_map.boundary_map.at("upper")[map_indx] = upper_val;
        boundary_map.boundary_map.at("lower")[map_indx] = lower_val;
        lower_val_string = "";
        upper_val_string = "";
        map_indx+=1;
    }
    return boundary_map;
}

void valid_values(BoundaryInfo bounds_info) {
    std::cout<< "Values outside the ranges: "<<std::endl;
    int arr_len = input_arr.size();
    int boundary_map_len = bounds_info.boundary_map.at("upper").size();
    print_nl();
    // int map_index = 0;
    for(int i=bounds_info.sep_pos+1;i<arr_len;i++){
        std::cout << "i is: " << i;
        print_nl();
        std::cout << input_arr[i] << std::endl;

        for(int k=0;k<boundary_map_len;k++){
            printf("Upper value at %d is %d", k, bounds_info.boundary_map.at("upper")[k]);
            // std::cout << "Upper value at "<< k << " " << bounds_info.boundary_map.at("upper")[k];
            print_nl();
            printf("Lower value at %d is %d", k,bounds_info.boundary_map.at("upper")[k]);
            // std::cout << "Lower value at "<< k << " " << bounds_info.boundary_map.at("lower")[k];
            print_nl();
        }
    }
}

int main() {
    std::cout << "Hello day 5";
    print_nl();

    BoundaryInfo bounds_info = id_boundaries();
    printf("Map at 3 %d", bounds_info.boundary_map.at("upper")[3]);
    // std::cout << bounds_info.boundary_map.at("upper")[3];
    print_nl();
    valid_values(bounds_info);
    print_nl();

    return 0;
}