#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>

void sort(std::vector<int>& arr){

    int tmp = 0;

    for (int i = 0; i < arr.size(); i++){

        for (int j = 1; j < arr.size() - i; j++){

            if (arr[j - 1] > arr[j]){

                tmp = arr[j -1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void get_arr(std::vector<int>& arr){

    int elem = -1;
    std::cin >> elem;

    while (elem != 0){

        arr.push_back(elem);
        std::cin >> elem;
    }

    sort(arr);
}

int main(){

    std::vector<int> arr_A;
    std::vector<int> arr_B;

    get_arr(arr_A);
    get_arr(arr_B);

    int itter_A = 0, itter_B = 0;
    while ((itter_A < arr_A.size()) && (itter_B < arr_B.size())){
        
        if (arr_A[itter_A] != arr_B[itter_B]){
            
            if (arr_A[itter_A] < arr_B[itter_B]){

                while ((arr_A[itter_A] < arr_B[itter_B]) && (itter_A < arr_A.size())){

                    std::cout << arr_A[itter_A] << ' ';
                    itter_A++;
                }
            } else{
                
                while ((arr_B[itter_B] < arr_A[itter_A]) && (itter_B < arr_B.size())){

                    std::cout << arr_B[itter_B] << ' ';
                    itter_B++;
                } 
            }
        } else{

            if (itter_A < arr_A.size()){

                itter_A++;
            }

            if (itter_B < arr_B.size()){

                itter_B++;
            }
        }
    }

    while (itter_A < arr_A.size()){

        std::cout << arr_A[itter_A] << ' ';
        itter_A++;
    }

    while (itter_B < arr_B.size()){

        std::cout << arr_B[itter_B] << ' ';
        itter_B++;
    }
}