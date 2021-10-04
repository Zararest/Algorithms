#include <stdio.h>


char get_letter(int n_str, int symb_num){

    if (symb_num != 0){

        return get_letter(n_str - 1, symb_num - 1);
    } else{

        return ('a' + symb_num);
    }
}


int main(){

    printf("|%c|\n", get_letter(4, 3));
    return 0;
}