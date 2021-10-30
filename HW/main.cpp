#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <vector>
#include <cassert>
#include <functional>
#include <cmath>

struct End_of_book{

    int nex_chapter = -1;
    int need_more_pages = -1;
};

int main(){

    int num_of_chap = 0, num_of_books = 0, sum = 0, new_elem = 0, cur_len = 0, max = 0;
    scanf("%i %i", &num_of_books, &num_of_chap);

    std::vector<int> data(num_of_chap);
    std::vector<End_of_book> arr_of_books_ends(num_of_books);

    for (int i = 0; i < num_of_chap; i++){

        scanf("%i", &new_elem);
        data[i] = new_elem;
        sum += new_elem;

        if (data[i] > max){

            max = data[i];
        }
    }

    cur_len = std::max(sum / num_of_books, max);

    int min = sum;
    for (int i = 0, cur_book = 0, cur_book_size = 0; i < num_of_chap; i++){

        cur_book_size += data[i];

        if (cur_book_size > cur_len){

            arr_of_books_ends[cur_book].nex_chapter = i;
            arr_of_books_ends[cur_book].need_more_pages = cur_book_size - cur_len;

            if (arr_of_books_ends[cur_book].need_more_pages < min){

                min = arr_of_books_ends[cur_book].need_more_pages;
            }
            cur_book_size = data[i];
            cur_book++;
        }
    }

    int num_of_added_pages = min, pages_prev_book_got = 0, j = 0;
    while ((arr_of_books_ends.back().nex_chapter < num_of_chap) && (arr_of_books_ends.back().nex_chapter != -1)){

        cur_len += num_of_added_pages;
        pages_prev_book_got = 0;
        min = sum;

        for (int cur_book = 0; cur_book < num_of_books; cur_book++){

            if (arr_of_books_ends[cur_book].need_more_pages - pages_prev_book_got - num_of_added_pages <= 0){

                arr_of_books_ends[cur_book].need_more_pages -= pages_prev_book_got + num_of_added_pages;

                for (j = 1; arr_of_books_ends[cur_book].need_more_pages <= 0; j++){
                    
                    if (arr_of_books_ends[cur_book].nex_chapter + j < num_of_chap){

                        arr_of_books_ends[cur_book].need_more_pages += data[arr_of_books_ends[cur_book].nex_chapter + j];
                        pages_prev_book_got += data[arr_of_books_ends[cur_book].nex_chapter + j];
                    } else{
                        
                        arr_of_books_ends.back().nex_chapter = num_of_chap;
                        arr_of_books_ends[cur_book].need_more_pages = 1;
                    }   
                }
                pages_prev_book_got -= data[arr_of_books_ends[cur_book].nex_chapter + j];
                arr_of_books_ends[cur_book].nex_chapter += j;
            } else{

                pages_prev_book_got = 0;
                arr_of_books_ends[cur_book].need_more_pages -= num_of_added_pages;
            }

            if (arr_of_books_ends[cur_book].need_more_pages < min){

                min = arr_of_books_ends[cur_book].need_more_pages;
            }
        }
        num_of_added_pages = min;
    }
    printf("%i\n", cur_len);
}