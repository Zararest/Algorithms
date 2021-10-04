#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>


int main(){

    int num_of_itter = 0, min_sum = 0, cur_elem = 0, cur_sum = 0;

    std::cin >> num_of_itter;

    for (int i = 0; i < num_of_itter; i++){

        std::cin >> cur_elem;

        if (cur_elem == 100){

            cur_sum -= 19;
        }

        if (cur_elem == 50){

            cur_sum -= 9;
        }

        if (cur_elem == 10){

            cur_sum -= 1;
        }

        if (cur_elem == 5){

            cur_sum += 1;
        }

        if (cur_sum < min_sum){

            min_sum = cur_sum;
        }
    }

    std::cout << ((-1) * min_sum) << '\n';
}