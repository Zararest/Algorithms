#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <vector>
#include <ctime>
#include <functional>
#include <queue>
//в четвертом номере нужно сделать дерево отрезков

double merge(std::priority_queue<double, std::vector<double>, std::greater<double>>& companies, int n){

    long tmp_company = 0;
    double sum = 0;

    while (companies.size() > 1){

        tmp_company = companies.top(); 
        companies.pop();
        tmp_company += companies.top();
        companies.pop();

        companies.push(tmp_company);

        sum += tmp_company * 0.01; 
    }

    return sum;
}

int main(){

    int n = 0;
    double new_elem = 0;
    std::cin >> n;

    std::vector<double> data(n);
    
    for (int i = 0; i < n; i++){

        std::cin >> new_elem;
        data[i] = new_elem;
    }
    std::priority_queue<double, std::vector<double>, std::greater<double>> prior_queue(data.begin(), data.end());

    printf("%.2f\n", merge(prior_queue, n));
}