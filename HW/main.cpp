#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <vector>
#include <cassert>
#include <functional>
#include <cmath>
#include <queue>
#include <unistd.h>

#define P_CONST 259

void find_sub_string(const std::vector<char>& main_string, int new_zero_point, int size, std::vector<unsigned int> htab, std::vector<unsigned int> p_table){

    unsigned hs1 = (htab[new_zero_point] - htab[new_zero_point - size]) * p_table[size];

    for (unsigned i = new_zero_point; i < main_string.size() - size; i++){

        unsigned hs2 = htab[i + size] - htab[i];

        if (hs2 == hs1){
            
            bool ok = true;

            for (unsigned j = 0; j < size; j++){
                assert(new_zero_point - size + j < main_string.size());
                assert(i + j < main_string.size());
                if (main_string[new_zero_point - size + j] != main_string[i + j]){

                    ok = false;
                }
            }

            if (ok){
                assert(i + size < main_string.size());
                write(STDOUT_FILENO, &main_string[i], size);
                putc('\n', stdout);
                exit(0);
            }
        }
        hs1 *= P_CONST;
    }
}

void find_max_substring(std::vector<char>& string, std::vector<unsigned int>& table_of_hash, std::vector<unsigned int>& p_table){

    int size = 4;

    for (int cur_size = string.size() / 2; cur_size > 0; cur_size--){

        for (int new_string_beg = cur_size; new_string_beg < string.size() - cur_size; new_string_beg++){

            find_sub_string(string, new_string_beg, cur_size, table_of_hash, p_table);
        }
    }
}

int main(){

    std::vector<char> string;
    char symbol = '\0';

    do{
        symbol = getc(stdin);
        string.push_back(symbol);

    } while(symbol != '\n');

    std::vector<unsigned int> table_of_hash;
    std::vector<unsigned int> p_table;
    unsigned int cur_p = 1, cur_sum = 0;

    for (unsigned int i = 0; i < string.size(); i++){

        p_table.push_back(cur_p);
        table_of_hash.push_back(cur_sum);
        cur_p *= P_CONST;
        cur_sum += string[i] * cur_p;
    }

    find_max_substring(string, table_of_hash, p_table);
}