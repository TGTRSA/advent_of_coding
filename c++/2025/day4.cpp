#include <iostream>
#include <string>
#include <vector>
#include <map>

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

void recognise_symbols() {
    Counter counter;
    std::string map;
    std::cout << "Counter value: " <<  counter.val <<std::endl;

    for (int i=0; i<toilet_paper_array.size();i++){
        std::string line = toilet_paper_array[i];
        int line_len = line.size() ;
        std::cout << toilet_paper_array[i]<< std::endl;
        
        for(int j=0;j<line_len;j++){
            if(line[j]=='@'){
                std::cout << "@ found"<< std::endl;
                counter.add(1);
                map+="X";
            }else if(line[j]=='.'){
                
                counter.print();
                map+=".";
                std::cout << "Found ." << std::endl;
                counter.reset();
            }
            if(j+1==line_len){
                std::cout << map<<std::endl;
                map="";
            }
        }
    }
}

int main() {
    std::cout << "Hello day 4" << std::endl;
    recognise_symbols();

    return 0;
}