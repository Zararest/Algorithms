#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>

#define MAXLEN 20000001

void calc_primal(int* arr, int n){
    
    int cur_number = 0;

    for (int i = 0; i < MAXLEN + n; i++){

        for (int j = 2; (j <= i) && ((cur_number = j * i) < MAXLEN + n); j++){

            arr[cur_number] = 1;
        }
    }
}

int main(){

    int n = 0, m = 0;

    std::cin >> m >> n;

    int* primal_numbers = new int[MAXLEN + n];
    bool number_have_found = false;
    int cur_number = 2, num_of_primals = 0;
    int begin_itter = 0, end_itter = 0;
    
    long start_time = clock();
    calc_primal(primal_numbers, n);
    long end_time = clock();

    for (int i = 0; num_of_primals < m; i++){

        if (primal_numbers[i] != 1){

            num_of_primals++;
        }
    }
}
