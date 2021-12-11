#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <vector>
#include <cassert>
#include <functional>
#include <cmath>

int count_books(std::vector<int>& data, int cur_len){

    int min = cur_len, cur_book = 1, cur_book_len = 0;

    for (int i = 0; i < data.size(); i++){

        cur_book_len += data[i];

        if (cur_book_len > cur_len){

            if (cur_book_len - cur_len < min){

                min = cur_book_len - cur_len;
            }

            cur_book_len = data[i];
            cur_book++;
        }
    }

    return cur_book;
}

int main(){

    int num_of_chap = 0, num_of_books = 0, sum = 0, new_elem = 0, cur_len = 0, max = 0;
    scanf("%i %i", &num_of_books, &num_of_chap);

    std::vector<int> data(num_of_chap);

    for (int i = 0; i < num_of_chap; i++){

        scanf("%i", &new_elem);
        data[i] = new_elem;
        sum += new_elem;

        if (data[i] > max){

            max = data[i];
        }
    }

    unsigned int min_len, max_len;
    min_len = std::max(sum / num_of_chap, max);
    max_len = sum;
    cur_len = min_len + ((max_len - min_len) >> 1);

    while (min_len != max_len){

        if (count_books(data, cur_len) <= num_of_books){

            max_len = cur_len;
            cur_len = max_len - ((max_len - min_len) >> 1);
        } else{

            min_len = cur_len;
            cur_len = max_len - ((max_len - min_len) >> 1);
        }

        if (min_len + 1 == max_len){
            
            if (count_books(data, min_len) <= num_of_books){

                cur_len = min_len;
                min_len = max_len;
            } else{

                cur_len = max_len;
                min_len = max_len;
            }
        }
    }   

    printf("%i\n", cur_len);
}