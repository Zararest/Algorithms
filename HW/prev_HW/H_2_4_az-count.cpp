#include <iostream>
#include <vector>

typedef struct Letters_mass_struct{

    int count;
    char letter;
}Letter;

void sort(std::vector<Letter>& arr){

    Letter tmp;

    for (int i = 0; i < arr.size(); i++){

        for (int j = 1; j < arr.size() - i; j++){

            if (arr[j - 1].count < arr[j].count){

                tmp = arr[j -1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(){

    char letter = '!';
    std::vector<Letter> arr;

    for(int i = 0; i < 27; i++){
        
        arr.push_back(Letter{0, (char)('A' + i)});
    }

    letter = fgetc(stdin);

    while (letter != '\n'){

        arr[letter - 'A'].count++;
        letter = fgetc(stdin);
    }
    
    sort(arr);

    int i = 0;
    while (arr[i].count != 0){

        std::cout << arr[i].letter << ' ' << arr[i].count << '\n';
        i++;
    }
}