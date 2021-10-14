#include <iostream>
#include <vector>
#include <algorithm>

typedef struct Data_and_poition_s{

    long elem;
    int position;

} Data_and_poition;

typedef struct First_line_s{

    long* line;
    int* old_positions;

} First_line;

typedef struct First_column_s{

    long* column;
    int* old_positions;

} First_column;


void sort_line(First_line& line, int size){

    int tmp_pos = 0;
    long tmp_val = 0;

    for (int i = 0; i < size; i++){

        for (int j = 1; j < size - i; j++){

            if (line.line[j - 1] > line.line[j]){
                
                tmp_val = line.line[j - 1];
                tmp_pos = line.old_positions[j - 1];

                line.line[j - 1] = line.line[j];
                line.old_positions[j - 1] = line.old_positions[j];
                
                line.line[j] = tmp_val;
                line.old_positions[j] = tmp_pos;
            }
        }
    }
}

void sort_column(First_column& column, int size){

    int tmp_pos = 0;
    long tmp_val = 0;

    for (int i = 0; i < size; i++){

        for (int j = 1; j < size - i; j++){

            if (column.column[j - 1] > column.column[j]){
                
                tmp_val = column.column[j - 1];
                tmp_pos = column.old_positions[j - 1];

                column.column[j - 1] = column.column[j];
                column.old_positions[j - 1] = column.old_positions[j];
                
                column.column[j] = tmp_val;
                column.old_positions[j] = tmp_pos;
            }
        }
    }
}

int main(){

    long* tmp = nullptr;
    int m, n, line_with_min_elem = 0;
    long elem, min_elem = 2147483647;
    First_column column_first;
    First_line line_first;

    std::cin >> n >> m;

    long** data = new long*[n];

    column_first.column = new long[n];
    column_first.old_positions = new int[n];

    line_first.line = new long[m];
    line_first.old_positions = new int[m];

    for (int y = 0; y < n; y++){

        long* line = new long[m];

        for (int x = 0; x < m; x++){

            std::cin >> elem;

            if (elem < min_elem){
                
                min_elem = elem;
                line_with_min_elem = y;
            }

            line[x] = elem;
        }
        data[y] = line;
    }

    tmp = data[0];
    data[0] = data[line_with_min_elem];
    data[line_with_min_elem] = tmp;

    for (int x = 0; x < m; x++){

        line_first.line[x] = data[0][x];
        line_first.old_positions[x] = x;
    }

    sort_line(line_first, m);

    for (int y = 0; y < n; y++){

        column_first.column[y] = data[y][line_first.old_positions[0]];
        column_first.old_positions[y] = y;
    }

    sort_column(column_first, n);

    for (int y = 0; y < n; y++){

        int cur_line = column_first.old_positions[y];

        for (int x = 0; x < m; x++){

            int cur_elem_number = line_first.old_positions[x];

            std::cout << data[cur_line][cur_elem_number] << ' ';
        }

        std::cout << '\n';
    }
}