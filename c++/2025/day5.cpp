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
    for(int i=0;i<len_input;i++){
        std::string arr_val = input_arr[i];
        int string_length = arr_val.size();
        std::cout << "Array val is: " << arr_val << std::endl;
        if(arr_val==" "){
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


int main() {
    std::cout << "Hello day 5";
    print_nl();

    BoundaryInfo bounds_info = id_boundaries();
    std::cout << bounds_info.boundary_map.at("upper")[0];
    print_nl();

    return 0;
}