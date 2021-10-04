#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

unsigned long long strs_lengths[31];

int get_number_len(int num){

    int counter = 0;

    if (num == 0){

        return 1;
    }
    
    while(num != 0){

        num = num / 10;
        counter++;
    }

    return counter;
}

char get_symbol_in_num(int num, int position){

    for (int i = 0; i < get_number_len(num) - position; i++){

        num = num / 10;
    }

    return '0' + (num % 10);
}

unsigned long long str_len(int number_of_str){

    assert(number_of_str > 0);
    assert(number_of_str <= 30);

    return strs_lengths[number_of_str];
}

char get_symbol(int number_of_str, int number_in_str){

    int len_of_number = get_number_len(number_of_str);

    if (number_of_str <= 1){

        assert(number_of_str == 1);
        assert(number_in_str == 1);

        return '1';
    }

    if (number_in_str <= len_of_number){

        return get_symbol_in_num(number_of_str, number_in_str);
    }

    if (number_in_str <= ((str_len(number_of_str) - len_of_number) / 2 + len_of_number)){

        return get_symbol(number_of_str - 1, number_in_str - len_of_number);
    } else{

        return get_symbol(number_of_str - 1, str_len(number_of_str) - number_in_str + 1);
    }
}

int main(){

    int m = 0, n_of_str = 0, new_number_in_str = 0;

    strs_lengths[0] = 0;
    for (int i = 1; i < 31; i++){

        strs_lengths[i] = strs_lengths[i - 1] * 2 + get_number_len(i);
    }
    
    std::cin >> n_of_str;
    std::cin >> m;



    for (int i = 0; i < m; i++){

        std::cin >> new_number_in_str;

        std::cout << get_symbol(n_of_str, new_number_in_str);
    }
}