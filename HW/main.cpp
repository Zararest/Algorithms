#include <iostream>
#include <vector>
#include <cassert>

#define MAXLEN 20000000

void calc_primal(std::vector<int>& arr, int n){
    
    int cur_number = 0;

    for (int i = 0; i < MAXLEN + n; i++){

        for (int j = 2; (j <= i) && ((cur_number = j * i) < MAXLEN + n); j++){

            arr[cur_number] = -1;
        }
    }
}

int main(){

    int n = 0, m = 0;

    std::cin >> m >> n;

    std::vector<int> primal_numbers(MAXLEN + n);
    int num_of_primals = 0;
    
    calc_primal(primal_numbers, n);

    int begin = 1, end = n;

    for (int i = 1; i <= n; i++){

        num_of_primals += 1 + primal_numbers[i];
    }

    while (num_of_primals != m){

        if (begin >= MAXLEN){

            std::cout << -1 << std::endl;
            return 0;
        }

        num_of_primals += primal_numbers[begin] * primal_numbers[begin] - 1;
        num_of_primals += primal_numbers[end + 1] + 1;
        begin++;
        end++;
    }

    std::cout << begin << std::endl;
}