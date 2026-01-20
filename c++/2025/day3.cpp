#include <map>
#include <vector>
#include <iostream>

struct LargestVals {
    int largest;
    int second_largest;

    int add() const {
        return largest+second_largest;
    }
};

std::vector<std::vector<int>> battery_cells={
    {9,8,7,6,5,4,3,2,1,1,1,1,1,1,1},
    {8,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
    {2,3,4,2,3,4,2,3,4,2,3,4,2,7,8},
    {8,1,8,1,8,1,9,1,1,1,1,2,1,1,1},
};

std::map<int,int> largest_map;

void print_nl(){
    std::cout << std::endl;
}

std::map<int, int> map_largest(std::vector<int> bank){
    int line_length = bank.size();
    int largest;
    int largest_position;
    for(int battery_indx=0;battery_indx<line_length; battery_indx++){
        if(battery_indx!=line_length){
            largest_position = battery_indx;
            largest=bank[battery_indx];
        }
    }
    largest_map.insert({largest,largest_position});
    return largest_map;
}

void find_largest() {
    std::vector<int> bank;
    int bank_size;
    int largest=0;
    LargestVals battery_vals;
    for(int line_indx=0;line_indx<battery_cells.size();line_indx++){
        bank = battery_cells[line_indx];
        bank_size = battery_cells[line_indx].size();
        std::map battery_map = map_largest(bank);
    }
}

int main() {
    std::cout << "Hello day3" << std::endl;
    find_largest();
    return 0;
}