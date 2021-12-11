#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

#define MAXLEN 100

typedef struct store_struct{

    int start_time;
    int end_time;
} Store;

bool compar_start(Store first, Store second){

    return first.start_time < second.start_time;
}

bool compar_end(Store first, Store second){

    return first.end_time < second.end_time;
}

void get_arr(std::vector<Store>& arr_1, std::vector<Store>&  arr_2){

    int elem_1 = -1, elem_2 = -1, num_count = 0;

    scanf("%i", &num_count);

    for (int i = 0; i < num_count; i++){

        Store tmp;

        scanf("%d:%d", &elem_1, &elem_2);
        tmp.start_time = elem_1 * 60 + elem_2;
        
        scanf("%d:%d", &elem_1, &elem_2);
        tmp.end_time = elem_1 * 60 + elem_2;

        arr_1.push_back(tmp);
        arr_2.push_back(tmp);
    }

    sort(arr_1.begin(), arr_1.end(), compar_start);
    sort(arr_2.begin(), arr_2.end(), compar_end);
}

int number_of_closed(std::vector<Store>& arr, std::vector<Store>& closed_arr, int cur_itter, int cur_itter_closed){

    int cur_time = arr[cur_itter].start_time, prev_itter_time = arr[cur_itter - 1].start_time;
    int just_closed = 0;

    while (closed_arr[cur_itter_closed + just_closed].end_time < cur_time){

        just_closed++;

        if (cur_itter_closed + just_closed >= closed_arr.size()){

            return just_closed;
        }
    }
    
    return just_closed;
}

int main(){

    std::vector<Store> store_room, locked_stores; //два массива(второй сортированный по закрытым файлам)
    int max_in_use_size = 0, cur_in_use = 1, itter_in_closed_arr = 0, just_closed = 0;

    get_arr(store_room, locked_stores);

    for (int i = 1; i < store_room.size(); i++){

        cur_in_use++;
        just_closed = number_of_closed(store_room, locked_stores, i, itter_in_closed_arr);
        cur_in_use -= just_closed;
        itter_in_closed_arr += just_closed;

        if (cur_in_use > max_in_use_size){

            max_in_use_size = cur_in_use;
        }
    }

    printf("%i", max_in_use_size);
}