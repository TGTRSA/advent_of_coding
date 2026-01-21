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

void print_array(std::vector<int>  array){
    int len_arr = array.size();
    std::cout << "Array: ";
    for(int i=0;i<len_arr;i++){
        std::cout << array[i] << ", ";
    }
    print_nl();
}

int get_second_largest(std::vector<int> bank ,LargestVals& largest_vals){
    int bank_size = bank.size();
    largest_vals.second_largest = 0;
    for(int indx=0;indx<bank_size;indx++){
        int battery = bank[indx]; 
        if(battery>largest_vals.second_largest && battery<largest_vals.largest){
            largest_vals.second_largest = battery;
        }
    }
    return largest_vals.second_largest;
}

int get_largest(std::vector<int> bank, int battery1, int bank_size) {
    int largest;
    for(int battery_indx=0;battery_indx<bank_size-1;battery_indx++){
        int battery2 = bank[battery_indx];
        if(battery1>battery2){
            largest = battery1;
        }else if(battery2 >= battery1) {
            largest = battery2;
        }
    }
    return largest;
}


void find_largest() {
    std::vector<int> bank;
    
    LargestVals battery_vals;
    std::cout << "Array: ";
    for(int i=0; i<battery_cells.size();i++) {
        bank = battery_cells[i]; 
        int bank_size= bank.size();
        std::cout << bank[i] << ", ";
        print_nl();
        for(int j=0;j<bank_size;j++){
            int battery1 = bank[j];
            
            battery_vals.largest = get_largest(bank,battery1,bank_size);
            battery_vals.second_largest = get_second_largest(bank,battery_vals);

            if(bank[bank_size-1] > battery_vals.largest ){
                battery_vals.second_largest = bank[bank_size-1];
            }
        }
        std::cout << "Largest val: " << std::endl << "Second largest: ";
        print_nl();
    }

}

int main() {
    std::cout << "Hello day3" << std::endl;
    find_largest();
    return 0;
}