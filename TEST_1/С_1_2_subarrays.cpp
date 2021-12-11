#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <vector>
#include <cassert>
#include <functional>
#include <cmath>
#include <queue>
#include <cassert>

bool find(std::vector<int>& data, int new_segment){

    int cur_segment_beg = 0, cur_sum = 0, cur_segment_end = 0;

    while ((cur_sum < new_segment) && (cur_segment_end < data.size())){

        cur_sum += data[cur_segment_end];
        cur_segment_end++;

        while (cur_sum > new_segment){

            cur_sum -= data[cur_segment_beg];
            cur_segment_beg++;
        }
    }
    
    if (cur_sum == new_segment){

        printf("%i %i\n", cur_segment_beg + 1, cur_segment_end + 1);
        return true;
    } else{

        printf("Not found\n");
        return false;
    }
}

int main(){

    int n, m, new_elem;
    std::cin >> n >> m;
    std::vector<int> data(n);

    for (int i = 0; i < n; i++) {

        std::cin >> data[i];
    }

    for (int i = 0; i < m; i++) {

        std::cin >> new_elem;
        find(data, new_elem);
    }
}