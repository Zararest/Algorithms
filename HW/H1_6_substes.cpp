#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

//   вывести все комбинации(структура с элементами, слово, начало слова)
//      печатаем слово
//
//      пока есть элементы с двойными встречами (вроде можно не только с двойными)
//          запускаем "вывести все комбинации(тут нету текущей буквы, слово содержит нужное количество текущей буквы, начало слова)"
//      запускаем "вывести все комбинации" без двойных
//  

void print_all_comb(int* number_of_elems_in_str, char* str, char* word, int cur_word_len){

    if (number_of_elems_in_str[0] != 0){

        print_all_comb(number_of_elems_in_str + 1, str + 1, word, cur_word_len);
    } else{

        word[cur_word_len] = '\0';
        std::cout << word << '\n';
    }

    for (int i = 0; i < number_of_elems_in_str[0]; i++){

        word[cur_word_len + i] = str[0];

        print_all_comb(number_of_elems_in_str + 1, str + 1, word, cur_word_len + i + 1);
    }
}

int main(){
//тут битовая маска
    /*char c = '!';
    bool in_str = false;
    int str_len = 0;
    char str[24];
    int number_of_elems_in_str[24];

    for(int i = 0; i < 24; i++){

        str[i] = '\0';
        number_of_elems_in_str[i] = 0;
    }

    while ((c = fgetc(stdin)) != '\n'){

        in_str = false;

        for (int i = 0; i < str_len; i++){

            if (str[i] == c){

                in_str = true;
                number_of_elems_in_str[i]++;
                str_len--;
            }
        }

        if (!in_str){

            number_of_elems_in_str[str_len]++;
            str[str_len] = c;
        }

        str_len++;
    }

    str[str_len] = '\0';

    //std::cout << str << '\n';
    /*for (int i = 0; i < str_len; i++){

        std::cout << number_of_elems_in_str[i];
    }
    

    unsigned int get_bit = 1;
    int cur_bit_number = 0;

    for (unsigned int bit_mask = (1 << str_len) - 1; bit_mask > 0; bit_mask--){

        //std::cout << '\n' << bit_mask << '\n';

        cur_bit_number = 0;
        get_bit = 1;

        while (cur_bit_number < str_len){
           
            //std::cout << ((bit_mask & get_bit) >> cur_bit_number);

            if (((bit_mask & get_bit) >> cur_bit_number) == 1){

                std::cout << str[cur_bit_number];
            }

            cur_bit_number++;
            get_bit = get_bit << 1;
        }

        std::cout << '\n';
    }*/

    int str_len = 0, i = 0;
    char c = '\0';
    bool in_str = false;
    char str[24], word[24];
    int number_of_elems_in_str[24];

    for(int i = 0; i < 24; i++){

        str[i] = '\0';
        word[i] = '\0';
        number_of_elems_in_str[i] = 0;
    }

    while ((c = fgetc(stdin)) != '\n'){

        in_str = false;

        for (i = 0; i < str_len; i++){

            if (str[i] == c){

                in_str = true;
                number_of_elems_in_str[i]++;
                str_len--;
            }
        }

        if (!in_str){

            number_of_elems_in_str[str_len]++;
            str[str_len] = c;
        }

        str_len++;
    }
    
    i = 0;

    print_all_comb(number_of_elems_in_str + 1, str + 1, word, 0);
    while (number_of_elems_in_str[0] != 0){

        word[i] = str[0];
        i++;
        print_all_comb(number_of_elems_in_str + 1, str + 1, word, i);
        number_of_elems_in_str[0]--;
    }
}
