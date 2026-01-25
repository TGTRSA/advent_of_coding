#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <format>

struct Counter {
    int val = 0;
    void reset () {
        val=0;
    }
    void print() {
        std::cout << "Current counter value: " << val << std::endl;
    }

    void add(int x) {
        val+=x;
    }
};

std::vector<std::string> toilet_paper_array = {
    "..@@.@@@@.",
    "@@@.@.@.@@",
    "@@@@@.@.@@",
    "@.@@@@..@.",
    "@@.@@@@.@@",
    ".@@@@@@@.@",
    ".@.@.@.@@@",
    "@.@@@.@@@@",
    ".@@@@@@@@.",
    "@.@.@@@.@."
};


void compose_map(Counter counter){
    int number_of_rolls = 10;
}

std::vector<std::string> convert_to_vector(int line_len, std::string line){
    std::vector<std::string> new_array;
    std::string map;
        for(int j=0;j<line_len;j++){
            std::string  l = std::to_string(line[j]);
            new_array.push_back(l);
        }
    return new_array;
}

std::vector<std::vector<char>> recognise_symbols() {
    Counter counter;
    std::string map;
    char above;
    char below;
    char left;
    char right;
    //std::cout << "Counter value: " <<  counter.val <<std::endl;
    std::vector<std::vector<char>> cross_map;
    std::vector<char> inner_map;
    char at_symbol = '@';
    std::string string_at = "@";
    char x = 'X';
    std::string dot = ".";
   // Convert to vector
    for(int i=0;i< toilet_paper_array.size();i++){
        std::string line = toilet_paper_array[i];
        int line_len = toilet_paper_array[i].size();
        std::vector<std::string> char_array =  convert_to_vector(line_len, line);
        std::cout << "Array size " << char_array.size(); 
        for(int j=0;j<char_array.size();j++){
            std::cout << "j is currently: " << j <<std::endl;
            //std::cout << char_array[j] << "\n";
            // Check up above i=0
            if(char_array[j]==string_at){
                if(i!=0){
                above = toilet_paper_array[i-1][j];
                std::string s = std::format("Checking above: toilet_paper_array[{0}][{1}]\n",i-1,j );
                std::cout << s;
                if(above==at_symbol){
                    // write to map
                    inner_map.push_back(x);
                }
            }            
                // check below
                if(i!=line_len-1){
                    below = toilet_paper_array[i+1][j];
                    std::string s = std::format("Checking below: toilet_paper_array[{0}][{1}]\n",i+1 , j);
                    std::cout << s;
                    if(below==at_symbol){
                        inner_map.push_back(x);
                    }
                }
                // check right
                if(j!=char_array.size()){
                    right = toilet_paper_array[i][j+1];
                    std::string s = std::format("Checking right: toilet_paper_array[{0}][{1}]\n",i , j+1);
                    std::cout << s;
                    if(below==at_symbol){
                        inner_map.push_back(x);
                    }
                }
                // check left
                if(j!=0){
                    left = toilet_paper_array[i][j-1];
                    std::string s = std::format("Checking left: toilet_paper_array[{0}][{1}]\n",i , j-1);
                    std::cout << s;
                    if(left==at_symbol){
                        inner_map.push_back(x);
                    }
                }
            }else if (char_array[j]==dot) {
                inner_map.push_back('.');
            }
            
            cross_map.push_back(inner_map);
        }
    }
    return cross_map;
}

int main() {
    std::cout << "Hello day 4" << std::endl;
    std::vector<std::vector<char>> cross_map = recognise_symbols();
    for(int i=0;i<cross_map.size();i++) {
        std::vector<char> line = cross_map[i]; 
        for(int j=0; j<line.size();j++){
            std::cout << line[j] ;
        }
        //std::cout << std::endl;
        
    }
    return 0;
}