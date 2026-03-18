#include <cstddef>
#include <vector>
#include <iostream>
#include "useful_funcs.h"
// cases: * + * +

std::vector<std::string> h_list = {
    "123", "328","51","64",
    "45","64",  "387"," 23",
    "6","98",  "215", "314",
    "*",  "+",   "*",   "+"
};


int main() {
    std::cout << "Starting program\n";
    int counter = 0;
    size_t len_list = h_list.size();
    std::vector<std::vector<int>> matrix;
    for(size_t i=0;i<len_list;i++){
        std::string c = h_list[i];
        std::cout << c << ",";
        if(c=="+"){

        }else if (c=="*") {
        
        }else {
            int val = std::stoi(c);
            matrix[counter].push_back(val);
            counter++;
            if (counter==3){counter=0;}
        }
    }
    // testing values to see if theyre correctly added to list 
    size_t len_matrix = matrix.size();
    for(size_t i=0;i<len_matrix;i++){
        
    }




}