#include <stdlib.h>
#include <iostream>

int main(){

    int sum = 0, cur_number = 0, n = 0, min_number = -1;
    
    std::cin >> n;
    
    for (int i = 0; i < n; i++){

        std::cin >> cur_number;

        if (cur_number <= sum + 1){

            sum += cur_number;
        } else{

            min_number = sum + 1;
        }
    }

    if (min_number == -1){

        min_number = sum + 1;
    }

    std::cout << min_number;
}