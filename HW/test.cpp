#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAXLEN 100

typedef struct store_struct{

    int start_time;
    int end_time;
} Store;

bool compar(Store first, Store second){

    return first.start_time < second.start_time;
}

void get_arr(std::vector<Store>& arr, int num_count){

    int elem = -1;
    char str[MAXLEN] = {'!'};
    char delim[4] = {" :\n"};

    for (int i = 0; i < num_count; i++){

        Store tmp;

        scanf("%s", str);
        tmp.start_time = atoi(strtok(str, " :\n")) * 60 + atoi(strtok(nullptr, " :\n"));
        
        scanf("%s", str);
        tmp.end_time = atoi(strtok(str, " :\n")) * 60 + atoi(strtok(nullptr, " :\n"));

        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end(), compar);
}

int size_of_use(std::vector<Store>& in_use, Store new_elem){

    int cur_time = new_elem.start_time;

    for (int i = 0; i < in_use.size(); i++){

        if (in_use[i].end_time < cur_time){

            in_use.erase(in_use.begin() + i);
        }
    }

    in_use.push_back(new_elem);

    return in_use.size();
}


int main(){

    std::vector<Store> in_use, store_room;
    int number_of_stores = 0, cur_size = 0, max_in_use_size = 0;

    scanf("%i", &number_of_stores);

    get_arr(store_room, number_of_stores);

    for (int i = 0; i < store_room.size(); i++){

        if ((cur_size = size_of_use(in_use, store_room[i])) > max_in_use_size){

            max_in_use_size = cur_size;
        }
    }

    printf("%i", max_in_use_size);
}