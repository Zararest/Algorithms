#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main(){

    int len_A = 0, len_B = 0, itter_A = 0, itter_B = 0;

    std::cin >> len_A >> len_B;
    int* arr_A = (int*)calloc(len_A, sizeof(int));
    int* arr_B = (int*)calloc(len_B, sizeof(int));

    for (int i = 0; i < len_A; i++){

        std::cin >> arr_A[i];
    }

    for (int i = 0; i < len_B; i++){

        std::cin >> arr_B[i];
    }

    while ((itter_A < len_A) && (itter_B < len_B)){

        if (arr_A[itter_A] == arr_B[itter_B]){

            std::cout << arr_A[itter_A] << ' ';
            itter_A++;
            itter_B++;
        } else{
            
            if (arr_B[itter_B] < arr_A[itter_A]){
                while (arr_B[itter_B] < arr_A[itter_A]){

                    itter_B++;
                }
            } else{

                while (arr_A[itter_A] < arr_B[itter_B]){

                    itter_A++;
                }
            }
        }
    }
}