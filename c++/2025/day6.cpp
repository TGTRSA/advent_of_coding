#include <cstddef>
#include <map>
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


std::map<int, std::vector<int>> equations;

int main() {
    std::cout << "Starting program\n";

    std::vector<std::string> operations;
    int counter = 1;
    size_t len_list = h_list.size();
    for(size_t i=0;i<len_list;i++){
        std::string c = h_list[i];
        std::cout << c << ",";
        if(c=="+" or c=="*"){
            operations.push_back(c);
        }else {
            int val = std::stoi(c);
            switch (counter) {
                case 1:
                {
                    equations[1].push_back(val);
                    std::cout << "Appending at "<< counter << "\n";
                    break;
                }
                case 2:
                {
                    equations[2].push_back(val);
                    std::cout << "Appending at "<< counter << "\n";

                    break;
                
                }
                case 3:
                {
                    equations[3].push_back(val);
                    std::cout << "Appending at "<< counter << "\n";
                    break;
                }
                case 4:
                {
                    equations[4].push_back(val);
                    std::cout << "Appending at "<< counter << "\n";
                    counter=0;
                    break;
                }
            }
            counter++;
        }
    }
    print_nl();
    size_t len_map = equations.size();
    for(size_t i=0;i<len_map;i++){
        size_t n=i+1;
        size_t len_inner = equations.at(n).size();
        std::cout << "Len inner map: " << len_inner;
        for(size_t j=0;j<len_inner;j++){
            std::cout << equations[i][j];
            if (equations[i][j]==std::stoi(h_list[j])) {
                std::cout << "Values match";
            }
        }
    }



}