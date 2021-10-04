#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

void calc_factorial(unsigned long long* arr, int n){

    unsigned long long factor = 1;
    arr[0] = 1;

    for (int i = 1; i <= 20; i++){

        factor *= i;
        arr[i] = factor;
    }
}

int sum(bool* used_numbers, unsigned long long cur_number){

    int i = 1;

    while (cur_number > 0){

        
        if (used_numbers[i] == false){
            
            cur_number -= 1;
        }
        i++;
    }

    return i - 1;
}

int main(){

    unsigned long long arr_factor[22];
    bool used_numbers[22];
    int n = 0, new_number = 0;
    unsigned long long m = 0, tmp = 0;

    for (int i = 0; i < 22; i++){

        used_numbers[i] = false;
    }
    
    std::cin >> n;
    std::cin >> m;

    calc_factorial(arr_factor, n);

    for (int i = 1; i <= n; i++){

        tmp = (m - 1) / arr_factor[n - i];
        m = m - tmp * arr_factor[n - i];
        new_number = sum(used_numbers, tmp + 1);
        used_numbers[new_number] = true;
        
        std::cout << new_number << ' ';
    }

    std::cout << '\n';
}