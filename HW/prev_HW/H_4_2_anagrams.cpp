#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#define ALFAB_SIZE 26

class StrSet{

    int leters[ALFAB_SIZE] = {};//
    int sum = 0;

public:

    void get_string(std::string& string){

        for (auto it : string){

            leters[it - 'A']++;
        }

        sum = string.size();
    }

    void set_zero(){

        for (int i = 0; i < ALFAB_SIZE; i++){

            leters[i] = 0;
        }
    }

    void print() const{

        for (int i = 0; i < ALFAB_SIZE; i++){

            std::cout << leters[i];
        }

        std::cout << std::endl;
    }

    bool operator <(const StrSet& rhs) const{//

        int pos = 0;
        
        while (pos < ALFAB_SIZE && leters[pos] == rhs.leters[pos]){

            pos++;
        }

        return leters[pos] < rhs.leters[pos];
    }
};

int main(){

    int N = 0;
    std::cin >> N;

    std::set<StrSet> sets;
    StrSet cur_set;
    std::string cur_string;
    std::ios::sync_with_stdio(false);

    for (int i = 0; i < N; i++){

        cur_set.set_zero();
        std::cin >> cur_string;
        
        cur_set.get_string(cur_string);
        sets.insert(cur_set);
    }

    std::cout << sets.size() << std::endl;
}