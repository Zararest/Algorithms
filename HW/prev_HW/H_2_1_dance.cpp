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

void get_arr(std::vector<int>& arr, int num_count){

    int elem = -1;

    for (int i = 0; i < num_count; i++){

        std::cin >> elem;
        arr.push_back(elem);
    }

    sort(arr);
}

int main(){

    std::vector<int> arr;
    int segment_len = 0, number_of_points = 0, begin_of_cur_base_segment = 0, number_of_base_segments = 0;
    bool have_intersec = true;
    std::vector<int>::iterator cur_base_point;

    std::cin >> segment_len >>number_of_points;

    get_arr(arr, number_of_points);

    begin_of_cur_base_segment = arr[0];
    number_of_base_segments = 1;

    for (int i = 1; i < arr.size(); i++){

        if (arr[i] > begin_of_cur_base_segment + 2 * segment_len){

            number_of_base_segments++;
            begin_of_cur_base_segment = arr[i];
        }
    }

    std::cout << number_of_base_segments;
}