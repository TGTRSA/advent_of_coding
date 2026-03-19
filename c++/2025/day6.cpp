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
std::vector<int> answers={33210,490, 424355,401};


std::map<int, std::vector<int>> equations;

int main() {
    std::cout << "Starting program\n";

    std::vector<std::string> operations;
    int counter = 1;
    size_t len_list = h_list.size();
    // appending values to map
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
    int count = 0;
    // matching values test
    for(size_t i=1;i<len_map+1;i++){
        // size_t n=i+1;
        std::vector<int>& inner_map = equations[i];
        size_t len_inner = inner_map.size();
        std::cout << "Len inner map: " << len_inner;
        print_nl();
        for(size_t j=0;j<len_inner;j++){
            // std::cout << "j is " << j << "\n";
            // std::cout << inner_map[j] << ", ";
            if (inner_map[j]==std::stoi(h_list[count])) {
                std::cout << "Comparing: " << inner_map[j] << " and " << h_list[count] << "\n"; 
                std::cout << "Values match";
                count+=4;
                break;
            }else {
                std::cout << "VALUE DOES NOT MATCH\nEXITING..." << "\n";
                exit(0);
            }
            
        }
        print_nl();
    }
    // grouping into equation
    int type=0;
    std::string plus = "+";
    std::string multiply = "*";
    std::vector<int> results;
    int result;
    for(size_t i=1;i<len_map+2;i++){
        std::string operation = operations[i-1];
        
        for(size_t j=0;j<len_map+1;j++){
            int value = equations[i][j];
            if(i==1){
                result = value;
            }else{
                if (operation==plus) {
                    result+=value;
                }else if (operation==multiply) {
                    result = result * value;
                }
            }
        }
        results.push_back(result);
        result=0;
    }
    // comparing results with the answers
    


}