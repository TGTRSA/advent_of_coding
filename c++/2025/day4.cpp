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
        std::cout << toilet_paper_array[i];
    }

    return 0;
}