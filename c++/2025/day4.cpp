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


void recognise_symbols() {
    Counter counter;
    std::cout << "Counter value: " <<  counter.val <<std::endl;

    for (int i=0; i<toilet_paper_array.size();i++){
        std::string line = toilet_paper_array[i];
        std::cout << toilet_paper_array[i]<< std::endl;
        for(int j=0;j<line.size();j++){
            if(line[j]=='@'){
                std::cout << "@ found"<< std::endl;
                counter.val +=1;
            }else if(line[j]=='.'){
                counter.print();

                std::cout << "Found ." << std::endl;
                counter.reset();
            }
        }
    }
}

int main() {
    std::cout << "Hello day 4" << std::endl;
    recognise_symbols();

    return 0;
}