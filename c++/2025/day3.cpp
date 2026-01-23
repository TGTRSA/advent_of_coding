#include <map>
#include <vector>
#include <iostream>
#include <string>
struct LargestVals {
    int largest;
    int second_largest;

};

struct LargestInfo {
    int value;
    int position;
};

std::map<std::string, int> largest; 
std::vector<int> largest_vals_check= {98,89,78,92};
std::vector<int> values_array;

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

int add_values(std::vector<int> values){
    int result=0;
    for(int i=0;i<values.size();i++){
        result+=values[i];
    }
    return result;
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

std::map<std::string,std::pair<int,int>> get_largest(std::vector<int> bank, int bank_size) {
    int largest=0;
    int largest_position;
    //std::cout << "Iterating through bank for largest";
    //print_nl();
    
    for(int battery_indx=0;battery_indx<bank_size-1;battery_indx++){        
        int  outer_loop_val = bank[battery_indx];
        for(int j=1;j<bank_size-1;j++){
            int inner_loop_value = bank[j];
            if(outer_loop_val>=inner_loop_value ){
                if(outer_loop_val>=largest){
                    largest=outer_loop_val;
                    largest_position = j;
                }
            }else if (inner_loop_value>=largest){
                largest=inner_loop_value;
                largest_position = j;
            }
            break;
        }
    }
    std::cout << "Largest value before map: " << largest<< std::endl;
    largest_map.insert({"largest", {largest, largest_position}});
    return largest_map;
}

void check_values(std::vector<int> combined_values){
    for(int i=0;i<largest_vals_check.size();i++){
        if(combined_values[i]==largest_vals_check[i]){
            std::cout << combined_values[i] << " is correct" << std::endl;
        }
    }
}

std::vector<int> find_largest() {
    
    std::vector<int> bank;
    std::string string_value = "";
    LargestVals battery_vals;
    battery_vals.second_largest = 0;
    std::cout << "Array: ";
    int while_loop_int =0;
    
    for(int i=0;i<battery_cells.size();i++){
        std::vector<int> bank_line = battery_cells[i];
        int bank_line_len  = bank_line.size();
        for(int j=0;j<bank_line_len;j++){
            
        }
    }

}

int main() {
    std::cout << "Hello day3" << std::endl;
    std::vector<int> combined__values = find_largest();
    
    check_values(combined__values);
    int rs = add_values(combined__values);
    std::cout << "Final result: " << rs<< std::endl;
    return 0;
}