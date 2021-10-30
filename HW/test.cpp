#include <cassert>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>

#define MAXLEN 100


void merge(FILE* first_line, FILE* second_line, FILE* output, int first_line_len, int second_line_len){

    int fir_itter = 0, sec_itter = 0;
    char fir_line_str[MAXLEN], sec_line_str[MAXLEN];

    fscanf(first_line, "%s", fir_line_str);
    fscanf(second_line , "%s", sec_line_str);

    while ((fir_itter < first_line_len) && (sec_itter < second_line_len)){
        
        if (strcmp(fir_line_str, sec_line_str) < 0){
            
            fprintf(output, "%s\n", fir_line_str);
            fscanf(first_line, "%s", fir_line_str);
            fir_itter++;
        } else{

            fprintf(output, "%s\n", sec_line_str);
            fscanf(second_line, "%s", sec_line_str);
            sec_itter++;
        }
    }

    if (fir_itter != first_line_len){

        while (fir_itter < first_line_len){
            
            fprintf(output, "%s\n", fir_line_str);
            fir_itter++;
            fscanf(first_line, "%s", fir_line_str);
        }
    } else{

        while (sec_itter < second_line_len){

            fprintf(output, "%s\n", sec_line_str);
            sec_itter++;
            fscanf(second_line, "%s", sec_line_str);
        }
    }   
}

int main(){

    int a = 4, b = 3;

    printf("%lf\n", ceil(1.1));
    //FILE* first_line = fopen("./bin/test_line_1.txt", "r");
    //FILE* second_line = fopen("./bin/test_line_2.txt", "r");
    //FILE* output = fopen("./bin/test.txt", "w+");

    //merge(first_line, second_line, output, 10, 5);
}