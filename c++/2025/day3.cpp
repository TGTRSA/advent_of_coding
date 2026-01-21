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

// std::map<std::string, std::map<int,int>> largest_map; =>  wrong
std::map<std::string, std::pair<int, int>> largest_map;

void print_nl(){
    std::cout << std::endl;
}

std::map<std::string, std::pair<int,int>> map_largest(std::vector<int> bank){
    int line_length = bank.size();
    int largest;
    int largest_position;
    for(int battery_indx=0;battery_indx<line_length; battery_indx++){
        if(battery_indx!=line_length){
            largest_position = battery_indx;
            largest=bank[battery_indx];
        }
    }
    largest_map.insert({"largest",{largest_position,largest}});
    return largest_map;
}

void find_largest() {
    std::vector<int> bank;
    int bank_size;
    LargestVals battery_vals;
    for(int line_indx=0;line_indx<battery_cells.size();line_indx++){
        bank = battery_cells[line_indx];
        bank_size = battery_cells[line_indx].size();
        std::map battery_map = map_largest(bank);
        int largest_position = battery_map.at("largest").first;
        int largest_value = battery_map.at("largest").second;

        for(int u=0;u<bank_size;u++){
            int bank_val = bank[u];
            for(int inner_indx=1; inner_indx<bank_size;inner_indx++)
                if(bank_val<bank[inner_indx]) {
                    battery_vals.second_largest=bank_val;
                }else if(u<largest_position && bank_val > largest_value){
                    battery_vals.second_largest = bank_val;    
                }
            break;
        }
        std::cout << "Largest: " << largest_value << std::endl;
        std::cout << "Second largest: " << battery_vals.second_largest;
        print_nl();
    }
}

int main() {
    std::cout << "Hello day3" << std::endl;
    find_largest();
    return 0;
}