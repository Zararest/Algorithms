#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <vector>
#include <cassert>
#include <functional>
#include <cmath>
#include <queue>

int main(){

    int n, sub_dmg, main_dmg, new_elem;
    std::cin >> n >> main_dmg >> sub_dmg;
    std::vector<int> HP(n);
    std::priority_queue<int, std::vector<int>> HP_queue(HP.begin(), HP.end());
    int extra_dmg = main_dmg - sub_dmg, other_dmg = 0, num_of_hits = 0, tmp = 0;

    for (int i = 0; i < n; i++){

        scanf("%i", &new_elem);
        HP_queue.push(new_elem);
    }

    while (HP_queue.top() > other_dmg){

        tmp = HP_queue.top() - extra_dmg;
        HP_queue.pop();
        HP_queue.push(tmp);
        other_dmg += sub_dmg;
        num_of_hits++;
    }

    std::cout << num_of_hits << std::endl;
}