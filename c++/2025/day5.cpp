#include <vector>
#include "useful_funcs.h"
#include <map>



struct BoundaryInfo {
    std::map<std::string, std::vector<int>> boundary_map;
    int sep_pos;
};

std::vector<std::string> input_arr = {
    "3-5",
    "10-14",
    "16-20",
    "12-18",
    "",
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
        if(arr_val==" "){
            break;
        }
        for(int j=0;j<arr_val.length();j++){
            const char c = arr_val[j];
            if(c==sep){
                boundary_map.boundary_map["upper"].push_back(arr_val[j+1]);
                break;
            }else{
                boundary_map.boundary_map["lower"].push_back(arr_val[j]); 
            }
        }
    }
    return boundary_map;
}


int main() {
    std::cout << "Hello day 5";
    print_nl();

    BoundaryInfo bounds_info = id_boundaries();

    

    return 0;
}