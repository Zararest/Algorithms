#include <cassert>
#include <stdio.h>
#include <algorithm>
#include <cstring>

#define MAXLEN 10001
#define BUFFER_SIZE 16

struct Buffer{

    char* data[BUFFER_SIZE];
    int cur_size;
};

struct Line{

    FILE* file;
    int cur_arr_position;
    int cur_file_position;
    char cur_elem[MAXLEN];

    void set_zero(){
        
        cur_arr_position = 0;
    }

    void go_to_beggining(){

        fseek(file, SEEK_SET, 0);
        cur_arr_position = 0;
        cur_file_position = 0;
    }

    void add_elem(const char* new_str){

        fprintf(file, "%s\n", new_str);
        cur_file_position++;
        cur_arr_position++;
    }

    const char* get_elem(int position){

        if (position == cur_arr_position){

            return cur_elem;
        }

        if (position > cur_arr_position){

            fseek(file, SEEK_CUR, position - cur_arr_position - 1);
            cur_file_position += position - cur_arr_position - 1;
            cur_arr_position += position - cur_arr_position - 1;

            fscanf(file, "%s", cur_elem);
            cur_file_position++;
            cur_arr_position++;
        }

        printf("attempt to go back\n");
        return nullptr;
    } 
};




int compare_string(const void* fir_str, const void* sec_str){

    return strcmp(*(const char**)fir_str, *(const char**)sec_str);
}

void put_buffer_to(Buffer& buf, FILE* file){

   qsort(buf.data, buf.cur_size, sizeof(char*), compare_string);

   for (int i = 0; i < buf.cur_size; i++){

       fprintf(file, "%s\n", buf.data[i]);
       printf("buf |%s|\n",  buf.data[i]);
   }
   printf("-----\n\n");
}

int buffer_sort(FILE* input_file, FILE* first_line, FILE* second_line){

    int itter = 0, cur_line = 1, number_of_str = 0;
    bool end_of_file = false;
    Buffer buffer;
    buffer.cur_size = 0;

    for (int i = 0; i < BUFFER_SIZE; i++){

        buffer.data[i] = new char[MAXLEN];
    }

    while (!end_of_file){

        if (fscanf(input_file, "%s", buffer.data[itter]) != EOF){//

            number_of_str++;
            buffer.cur_size++;

            if (itter < BUFFER_SIZE - 1){
                
                itter++;
            } else{

                itter = 0;

                if (cur_line == 1){

                    put_buffer_to(buffer, first_line);
                    cur_line = 2;
                } else{

                    put_buffer_to(buffer, second_line);
                    cur_line = 1;
                }
                
                buffer.cur_size = 0;
            }
        } else{

            end_of_file = true;

            if (cur_line == 1){

                put_buffer_to(buffer, first_line);
                cur_line = 2;
            } else{

                put_buffer_to(buffer, second_line);
                cur_line = 1;
            }
        }
    }

    return number_of_str;
}

void merge(FILE* first_line, FILE* second_line, FILE* output, int first_line_len, int second_line_len){

    int fir_itter = 1, sec_itter = 1;
    int number_of_overflow = 0;
    char fir_line_str[MAXLEN], sec_line_str[MAXLEN];
    
    if (first_line_len > 0){
        fscanf(first_line, "%s", fir_line_str);
    }
    
    if (second_line_len > 0){
        fscanf(second_line , "%s", sec_line_str);
    }
    
    while ((fir_itter < first_line_len) && (sec_itter < second_line_len)){
        
        if (strcmp(fir_line_str, sec_line_str) < 0){
            
            fprintf(output, "%s\n", fir_line_str);
            if (fscanf(first_line, "%s", fir_line_str) == EOF) number_of_overflow++;
            fir_itter++;
        } else{

            fprintf(output, "%s\n", sec_line_str);
            if (fscanf(second_line, "%s", sec_line_str) == EOF) number_of_overflow++;//кажись на одну итерацию обосрался 
            sec_itter++;
        }
    }

    if (fir_itter != first_line_len){

        while (fir_itter < first_line_len){
            
            fprintf(output, "%s\n", fir_line_str);
            fir_itter++;
            if (fscanf(first_line, "%s", fir_line_str) == EOF) number_of_overflow++;
        }
    } else{

        while (sec_itter < second_line_len){

            fprintf(output, "%s\n", sec_line_str);
            sec_itter++;
            if (fscanf(second_line, "%s", sec_line_str) == EOF) number_of_overflow++;
        }
    }   

    printf("overflow number  %i\n", number_of_overflow);
}

int put_str_to(FILE* input, FILE* line, int cur_series_len){ //надо переделать без eof

    char cur_str[MAXLEN];
    int i = 0;

    for (i = 0; i < cur_series_len; i++){

        assert(fscanf(input, "%s", cur_str) != EOF);
        fprintf(line, "%s\n", cur_str);
    }

    return i;
}

void split_into_lines(FILE* first_line, FILE* second_line, FILE* output, int cur_series_len, int number_of_str){

    int cur_line = 1;
    int number_of_chunks = 0, small_chunk = 0;

    fseek(first_line, SEEK_SET, 0);
    fseek(second_line, SEEK_SET, 0);
    fseek(output, SEEK_SET, 0);

    number_of_chunks = number_of_str / cur_series_len;
    small_chunk = number_of_str % cur_series_len;

    while (number_of_chunks > 0){//тут надо условие поменять 
            
        if (cur_line == 1){

            put_str_to(output, first_line, cur_series_len);
            cur_line = 2;
        } else{

            put_str_to(output, second_line, cur_series_len);
            cur_line = 1;
        }

        number_of_chunks--;
    }

    if (small_chunk != 0){

        if (cur_line == 1){

            put_str_to(output, first_line, small_chunk);
        } else{

            put_str_to(output, second_line, small_chunk);
        }
    }

    /*while (number_of_splited_strs < number_of_str){

        if (cur_line == 1){

            first_line_len += put_str_to(output, first_line, cur_series_len);
            cur_line = 2;
        } else{

            second_line_len += put_str_to(output, second_line, cur_series_len);
            cur_line = 1;
        }

        number_of_splited_strs += cur_series_len;
    }*/
}

void merge_sort(FILE* first_line, FILE* second_line, FILE* output, int number_of_str){

    int cur_series_len = BUFFER_SIZE;
    int first_line_len, second_line_len, number_of_chunks = 0, small_chunk = 0, elements_in_first = 0, elements_in_second = 0;
    
    while (cur_series_len < number_of_str){

        number_of_chunks = number_of_str / cur_series_len;
        small_chunk = number_of_str % cur_series_len;
        printf("size of chunk = %i number of chunks = %i small = %i\n", cur_series_len, number_of_chunks, small_chunk);

        fseek(first_line, SEEK_SET, 0);
        fseek(second_line, SEEK_SET, 0);
        fseek(output, SEEK_SET, 0);

        while (number_of_chunks >= 0){//тут надо условие поменять 
            
            if (number_of_chunks >= 2){

                merge(first_line, second_line, output, cur_series_len, cur_series_len);
                elements_in_first += cur_series_len;
                elements_in_second += cur_series_len;
                number_of_chunks -= 2;
            } else{
                
                if (number_of_chunks == 1){

                    merge(first_line, second_line, output, cur_series_len, small_chunk);
                    elements_in_first += cur_series_len;
                    elements_in_second += small_chunk; 
                } else{

                    merge(first_line, second_line, output, small_chunk, 0);
                    elements_in_first += small_chunk;
                }

                number_of_chunks--;
            }
        }
        
        cur_series_len *= 2;
        exit(0);
        if (cur_series_len < number_of_str){

            split_into_lines(first_line, second_line, output, cur_series_len, number_of_str);
        }   
    }
}


int main(){

    FILE* input_file = fopen("../bin/input.txt", "r");
    
    FILE* first_line = fopen("../bin/first_line.txt", "w+");
    FILE* second_line = fopen("../bin/second_line.txt", "w+");
    FILE* output_file = fopen("../bin/output.txt", "w+");

    assert(first_line != nullptr);
    assert(second_line != nullptr);
    assert(output_file != nullptr);
    
    int number_of_lines = buffer_sort(input_file, first_line, second_line);        

    if (BUFFER_SIZE <= number_of_lines){

        merge_sort(first_line, second_line, output_file, number_of_lines);
    } else{

        printf("sorted with buffer\n");
    }
    
    fclose(first_line);
    fclose(second_line);
    fclose(output_file);
}

