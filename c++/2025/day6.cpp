#include <cstddef>
#include <vector>
#include <iostream>
#include "useful_funcs.h"
std::vector<std::string> h_list = {
    "123", "328","  51"," 64",
    "45","64",  "387"," 23",
    "6"," 98",  "215", "314",
    "*",  "+",   "*",   "+"
};


int main() {
    std::cout << "Starting program\n";

    size_t len_list = h_list.size();
    for(size_t i=0;i<len_list;i++){
        std::cout << h_list[i] << ",";
    }
    print_nl();

}