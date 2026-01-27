#include <cstddef>
#include <cstring>
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

    int get_val() {
        return val;
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



std::vector<std::string> convert_to_vector(int line_len, std::string line){
    std::vector<std::string> new_array;
    
    std::string l;
        for(int j=0;j<line_len;j++){
            l += line[j];
            new_array.push_back(l);
            l="";
        }
    return new_array;
}

std::vector<std::vector<std::string>> recognise_symbols() {
    Counter counter;
    std::string map;
    char above;
    char below;
    char left;
    char top_left_diagonal;
    char top_right_diagonal;
    char bottom_right_diagonal;
    char bottom_left_diagonal;
    char right;
    //std::cout << "Counter value: " <<  counter.val <<std::endl;
    std::vector<std::vector<std::string>> cross_map;
    std::vector<std::string> inner_map;
    char  at_symbol ='@';

   // Convert to vector
    for(size_t i=0;i< toilet_paper_array.size();i++){
        std::string line = toilet_paper_array[i];
        size_t line_len = toilet_paper_array[i].size();
        std::vector<std::string> char_array =  convert_to_vector(line_len, line);
        std::vector<std::string> map(char_array.size(), ".");

        //std::cout << "Array size " << char_array.size(); 
        for(size_t j=0;j<char_array.size();j++){
            //std::cout << "j is currently: " << j <<std::endl;
            //std::cout <<"Character " << char_array[j] << "\n";

            if(char_array[j]=="@"){

                // check above
                if(i>0){
                    above = toilet_paper_array[i-1][j];
                    std::cout <<" Checking above: ";
                    ////std::string s = std::format("toilet_paper_array[{0}][{1}]\n",i-1,j );
                    ////std::cout << s;
                    if(above==at_symbol){
                        // write to map
                        counter.add(1);
                        counter.print();
                    }
                }          
                // check below
                if(i+1 < toilet_paper_array.size() && j < toilet_paper_array[i+1].size()){
                    below = toilet_paper_array[i+1][j];
                    std::cout << "Checking below:";
                    ////std::string s = std::format(" toilet_paper_array[{0}][{1}]\n",i+1 , j);
                    ////std::cout << s;
                    if(below==at_symbol){
                        counter.add(1);
                        counter.print();
                    }
    
                }
                // bottom left
                if(j>0 && i<toilet_paper_array.size() - 1){
                    std::cout << "Bottom left" << std::endl;
                    bottom_left_diagonal = toilet_paper_array[i+1][j-1];
                    if(bottom_left_diagonal==at_symbol){
                        counter.add(1);
                    }
                }   
                // bottom right
                if(j!=char_array.size()-1 && i<toilet_paper_array.size()-1 ){
                    std::cout << "Bottom right" <<  std::endl;
                    bottom_right_diagonal = toilet_paper_array[i+1][j+1];
                    if(bottom_right_diagonal==at_symbol){
                        counter.add(1);
                        counter.print();
                    }
                }

                // top right
                if(i>0 && j<char_array.size()-1){
                    top_right_diagonal = toilet_paper_array[i-1][j+1];
                    if (top_right_diagonal==at_symbol) {
                        counter.add(1);
                        counter.print();
                    }
                }
                //top left
                if(j>0 && i>0) {
                    top_left_diagonal = toilet_paper_array[i-1][j-1];
                    if(top_left_diagonal==at_symbol){
                        counter.add(1);
                        counter.print();
                    }
                }
                // check right
                if(j!=char_array.size()-1){
                    right = toilet_paper_array[i][j+1];
                    
                    //std::string s = std::format("Checking right: toilet_paper_array[{0}][{1}]\n",i , j+1);
                    //std::cout << s;
                    if(right==at_symbol){
                        counter.add(1);
                        counter.print();
                    }
                                    
                }
                // check left
                if(j>0){
                    left = toilet_paper_array[i][j-1];
                    
                    //std::string s = std::format("Checking left: toilet_paper_array[{0}][{1}]\n",i , j-1);
                    //std::cout << s;
                    if(left==at_symbol){
                        counter.add(1);
                        counter.print();
                    }
                }       
                if(counter.val<4){
                    //map+="X";
                    map[j]=("X");
                }else {
                    //map+="@";
                    map[j]=("@");
                }
                counter.reset();
            }else {
                //map+=".";
                map[j]=(".");
            }
            
            //std::cout << "This is the map:  " << map << std::endl;
            
        }
        //cross_map.push_back(std::vector<std::string>{map});
        cross_map.push_back(map);
    }
    return cross_map;
}

int main() {
    std::cout << "Hello day 4" << std::endl;
    std::vector<std::vector<std::string>> cross_map = recognise_symbols();
    uint cross_map_len = cross_map.size();
    Counter new_counter; 
    for(uint i=0;i< cross_map_len ;i++) {
        std::vector<std::string> line = cross_map[i]; 
        uint line_len = line.size() ;
        for(uint j=0; j<line_len;j++){
            
          
            std::cout << line[j] << "";
            if(line[j]=="X"){
                new_counter.add(1);
            }
        
        }
        std::cout << std::endl;
        
    }
    std::cout << "There are: " << new_counter.get_val() << " X rolls";
    return 0;
}