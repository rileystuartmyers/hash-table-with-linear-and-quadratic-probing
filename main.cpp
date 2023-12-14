#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "hash_table.h"

int main() {

    std::ofstream ofs("output.txt"); // size, type, list
    std::ifstream ifs("input.txt");
    std::string input_string;

    int size;
    std::string probing_type;
    std::vector<int> int_list;


    std::getline(ifs, input_string);
    std::istringstream iss(input_string);
    iss >> size;

    std::getline(ifs, input_string);
    probing_type = input_string;

    std::getline(ifs, input_string);
    std::string int_list_string = input_string;
    
    for (int i = 0; i < int_list_string.size(); ++i) { // removes commas from int list for string stream

        if (int_list_string[i] == ',') {

            int_list_string[i] = ' ';

        }

    }

    std::istringstream ils(int_list_string);
    int temp;

    while (ils >> temp) {

        int_list.push_back(temp);

    }


    hash_map h(size);

    if (probing_type.find("Linear probing") != std::string::npos) { // linear insertion into hash

        for (int i = 0; i < int_list.size(); ++i) {

            h.Linear_Probing(int_list[i]);

        }

    }
    
    if (probing_type.find("Quadratic probing") != std::string::npos) { // quadratic insertion into hash

        for (int i = 0; i < int_list.size(); ++i) {

            h.Quadratic_Probing(int_list[i]);

        }

    }

    h.print(ofs);

    std::vector<int> hash_values;
    h.Contents_To_Vector(hash_values);

    min_heap m(size);

    for (int i = 0; i < hash_values.size(); ++i) { // insertion into heap

        m.push(hash_values[i]);

    }

    m.min_print(ofs);

    return 0;

}