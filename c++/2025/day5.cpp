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
    const char sep = '-';
    std::string lower_val_string;
    std::string upper_val_string;
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
        for(int j=0;j<string_length;j++){
            const char c = arr_val[j];
            std::cout << "Current char " << c <<" is it -? " <<std::endl;
            if(c==sep){
                std::string u_str(1, arr_val[j+1]);
                std::string l_str(1, arr_val[j-1]);
                int upper_val = std::stoi(u_str);
                int lower_val = std::stoi(l_str);
                std::cout << "The chars for this range are " << arr_val[j-1] << " and " << arr_val[j+1];
                print_nl();
                std::cout << "The int reps are " << lower_val;
                std::cout <<  " and " << upper_val;
                print_nl();
                boundary_map.boundary_map["upper"].push_back(upper_val);
                boundary_map.boundary_map["lower"].push_back(lower_val);
                break;
            }
        }
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