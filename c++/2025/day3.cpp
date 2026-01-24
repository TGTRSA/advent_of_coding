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
std::vector<int> combined_values_array;

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

LargestInfo get_largest(const std::vector<int>& bank, int bank_size) {
    int largest=0;
    int largest_position;
    LargestInfo largestinfo;
    //std::cout << "Iterating through bank for largest";
    //print_nl();
    
    for(int battery_indx=0;battery_indx<bank_size-1;battery_indx++){        
        int  outer_loop_val = bank[battery_indx];
        for(int j=1;j<bank_size-1;j++){
            int inner_loop_value = bank[j];
            if(outer_loop_val>=inner_loop_value ){
                if(outer_loop_val>=largest){
                    largest=outer_loop_val;
                    largest_position = battery_indx;
                }
            }else if (inner_loop_value>=largest){
                largest=inner_loop_value;
                largest_position = j;
            }
            break;
        }
    }
    largestinfo.value = largest;
    largestinfo.position = largest_position; 
    //std::cout << "Largest value before map: " << largest<< std::endl;
    //largest_map.insert({"largest", {largest, largest_position}});
    return largestinfo;
    //return largest_map;
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
    int batter_cells_len = battery_cells.size();
    LargestInfo largestinfo;
    std::string string_value = "";
    LargestVals battery_vals;
    battery_vals.second_largest = 0;
   

    int while_loop_int =0;
    int tmp=0;
        
    
    for(int i=0;i<batter_cells_len;i++){
        std::vector<int> bank_line = battery_cells[i];
        int bank_line_len  = bank_line.size();
         std::cout << "Array: ";
        for(int u=0;u<bank_line_len;u++){std::cout<<bank_line[u]<<" ";}
        print_nl();
        
        largestinfo = get_largest(bank_line, bank_line_len);
        //std::cout << "Largest value: " << largestinfo.value << "\nLargest value pos: " << largestinfo.position << std::endl;
        for(int k=largestinfo.position+1;k<bank_line_len;k++){
            //std::cout << "Starting from: " << k <<"=> Current value at k " << bank_line[k] <<std::endl;
            if(bank_line[k]>tmp){
                tmp=bank_line[k];
            } 
        }

        battery_vals.largest = largestinfo.value;
        battery_vals.second_largest = tmp;
        std::cout << "Largest value: " << battery_vals.largest<< "\nSecond largest: " << battery_vals.second_largest << std::endl;
        string_value = std::to_string(battery_vals.largest) + std::to_string( battery_vals.second_largest);
        int combined_int = std::stoi(string_value);
        combined_values_array.push_back(combined_int);
        tmp=0;
    }
    return combined_values_array;

}

int main() {
    std::cout << "Hello day3" << std::endl;
    std::vector<int> combined__values = find_largest();
    
    check_values(combined__values);
    int rs = add_values(combined__values);
    std::cout << "Final result: " << rs<< std::endl;
    return 0;
}