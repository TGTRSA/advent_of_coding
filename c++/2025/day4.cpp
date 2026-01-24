#include <iostream>
#include <string>
#include <vector>
#include <map>

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


int main() {
    std::cout << "Hello day 4" << std::endl;
    int counter;

    for (int i=0; i<toilet_paper_array.size();i++){
        std::string line = toilet_paper_array[i];
        std::cout << toilet_paper_array[i]<< std::endl;
        for(int j=0;j<line.size();j++){
            if(line[j]=='@'){
                std::cout << "@ found"<< std::endl;
            }
        }
    }

    return 0;
}