#include <iostream>
#include <cstring>
#include <vector>
#include <list>

#define MAXLEN 100

typedef struct store_struct{

    int start_time;
    int end_time;
} Store;

void sort(std::vector<Store>& arr){

    Store tmp;

    for (int i = 0; i < arr.size(); i++){

        for (int j = 1; j < arr.size() - i; j++){

            if (arr[j - 1].start_time > arr[j].start_time){

                tmp = arr[j -1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void get_arr(std::vector<Store>& arr, int num_count){

    int elem = -1;
    char str[MAXLEN] = {'!'};
    char delim[4] = {" :\n"};

    for (int i = 0; i < num_count; i++){

        Store tmp;

        //std::cin >> str;
        scanf("%s", str);
        tmp.start_time = atoi(strtok(str, " :\n")) * 60 + atoi(strtok(nullptr, " :\n"));
        //std::cin >> str;
        scanf("%s", str);
        tmp.end_time = atoi(strtok(str, " :\n")) * 60 + atoi(strtok(nullptr, " :\n"));

        arr.push_back(tmp);
    }

    sort(arr);
}

int size_of_use(std::list<Store>& in_use, Store new_elem){

    int cur_time = new_elem.start_time;
    auto list_itter = in_use.begin(), tmp = in_use.begin();

    while (list_itter != in_use.end()){

        if (list_itter->end_time < cur_time){
            
            tmp = list_itter;
            ++list_itter;
            in_use.erase(tmp);
        } else{

            ++list_itter;
        }
    }

    in_use.push_back(new_elem);

    return in_use.size();
}


int main(){

    std::vector<Store> store_room;
    std::list<Store> in_use;
    int number_of_stores = 0, cur_size = 0, max_in_use_size = 0;

    //std::cin >> number_of_stores;
    scanf("%i", &number_of_stores);

    get_arr(store_room, number_of_stores);

    for (int i = 0; i < store_room.size(); i++){

        if ((cur_size = size_of_use(in_use, store_room[i])) > max_in_use_size){

            max_in_use_size = cur_size;
        }
    }

    printf("%i", max_in_use_size);
    //std::cout << max_in_use_size;
}