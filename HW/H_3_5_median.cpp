#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <vector>
#include <cassert>
#include <functional>
#include <cmath>
#include <queue>

int main(){

    int num_of_requests = 0, cur_median = 0, code = 0, new_elem = 0;
    scanf("%i", &num_of_requests);

    std::vector<int> left_arr;
    std::vector<int> right_arr;

    std::priority_queue<int, std::vector<int>, std::greater<int>> right_queue(right_arr.begin(), right_arr.end());
    std::priority_queue<int, std::vector<int>> left_queue(left_arr.begin(), left_arr.end());

    for (int i = 0; i < num_of_requests; i++){
        
        scanf("%i", &code);

        if (code == 0){

            scanf("%i", &new_elem);
            
            if (new_elem <= cur_median){

                left_queue.push(new_elem);
            } else{

                right_queue.push(new_elem);
            }

            while (right_queue.size() < left_queue.size()){

                right_queue.push(left_queue.top());
                left_queue.pop();
            }
            while (left_queue.size() < right_queue.size()){

                left_queue.push(right_queue.top());
                right_queue.pop();
            }

            cur_median = left_queue.top();
        } else{

            printf("%i\n", cur_median);
        }
    }
}