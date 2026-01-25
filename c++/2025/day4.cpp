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
           if(line[j]=='@'){
            map+="@";
           }else if(line[j]=='.'){
            map+=".";
           }
        }
        new_array.push_back(map);
    return new_array;
}

void recognise_symbols() {
    Counter counter;
    std::string map;
    char above;
    char below;
    char left;
    char right;
    //std::cout << "Counter value: " <<  counter.val <<std::endl;

   // Convert to vector
    for(int i=0;i< toilet_paper_array.size();i++){
        std::string line = toilet_paper_array[i];
        int line_len = toilet_paper_array[i].size();
        std::vector<std::string> char_array =  convert_to_vector(line_len, line);
        
        for(int j=0;j<char_array.size();j++){
            std::cout << "j is currently: " << j<<std::endl;
            std::cout << char_array[j] << "\n";
            // Check up above i=0
            if(i!=0){
                above = toilet_paper_array[i-1][j];
                std::string s = std::format("Checking above: toilet_paper_array[{0}][{1}]\n",i-1,j );
                std::cout << s;
                if(toilet_paper_array[i][j]=='@'){
                    // write to map
                }
            }            
            // check below
            if(i!=line_len-1){
                below = toilet_paper_array[i+1][j];
                std::string s = std::format("Checking below: toilet_paper_array[{0}][{1}]\n",i+1 , j);
                std::cout << s;
            }
            // check right
            if(j!=char_array.size()){
                right = toilet_paper_array[i][j+1];
                std::string s = std::format("Checking below: toilet_paper_array[{0}][{1}]\n",i , j+1);
                std::cout << s;
            }
            // check left
            if(j!=0){
                left = toilet_paper_array[i][j-1];
                std::string s = std::format("Checking below: toilet_paper_array[{0}][{1}]\n",i , j-1);
                std::cout << s;
            }
        }
    }

}

int main() {
    std::cout << "Hello day 4" << std::endl;
    recognise_symbols();

    return 0;
}