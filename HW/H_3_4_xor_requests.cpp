#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <vector>
#include <cassert>
#include <functional>
#include <queue>

#define NEUTRAL_ELEM 0 //надо дерево отрезков переписать на плюсы и загрузить в полезные программы

void propagate(std::vector<int>& bin_heap, unsigned int pos, unsigned int c){

    if (pos % 2 == 0){
        
        bin_heap[(c >> 1) + (pos >> 1)] = bin_heap[c + pos] xor bin_heap[c + pos + 1];
        
    } else{
        
        bin_heap[(c >> 1) + (pos >> 1)] = bin_heap[c + pos] xor bin_heap[c + pos - 1];
    }

    if (c > 1){

        propagate(bin_heap, pos >> 1, c >> 1);
    }
}

void insert(std::vector<int>& bin_heap, int new_elem, unsigned int pos, unsigned int c){

    bin_heap[c + pos] = new_elem;
    propagate(bin_heap, pos, c);
}

int find(std::vector<int>& bin_heap, unsigned int from, unsigned int to){

    int result = NEUTRAL_ELEM;
    if (from % 2 == 1) result = result xor bin_heap[from++];
    if (to % 2 == 0) result = result xor bin_heap[to--];
    
    if (to > from) result = result xor find(bin_heap, from >> 1, to >> 1);

    return result;
}

int main(){

    unsigned int n = 0, num_of_commands = 0, size = 1, code = 0;
    int fir_arg = 0, sec_arg = 0;
    scanf("%i %i", &n, &num_of_commands);

    while(size < n) size = size << 1;
    
    std::vector<int> bin_heap(size << 1);

    for (int i = 0; i < n; i++){

        scanf("%i", &fir_arg);
        insert(bin_heap, fir_arg, i, size);
    }

    for (int i = 0; i < num_of_commands; i++){

        scanf("%i %i %i", &code, &fir_arg, &sec_arg);

        if (code == 1){

            printf("%i\n", find(bin_heap, size + fir_arg, size + sec_arg));
        } else{

            insert(bin_heap, sec_arg, fir_arg, size);
        }
    }
}