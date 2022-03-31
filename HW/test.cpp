#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <math.h>
 
#define K_MAX 20000000
 
using namespace std;  
 
int main() {  
 
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL);  
 
    int64_t M, N;  
 
    cin >> M >> N;   
 
    // построим массив от 1 до K_MAX + N 
 
    vector<bool> is_prime(N + K_MAX + 1, true);  
    is_prime[0] = false; 
    is_prime[1] = false; 
 
    for(int64_t i = 2; i <= (int64_t)sqrt(is_prime.size()); i++) {
        if(is_prime[i]) {
            for (int64_t j = i * i; j <= is_prime.size(); j += i) {
                is_prime[j] = false; 
            }
        }
    } 
 
    int64_t i = 2; 
    int64_t count = 0;   
    
    //посчитали количество простых в первом промежутке
 
    for(int64_t j = i; j - i + 1 <= N; j++) {
        if(is_prime[j] == true) {
            count++; 
        }  
 
    } 
 
    if(count == M) {
        cout << i << "\n"; 
        return 0;
    } 
 
    int64_t j = i + N;
 
    while(true) {
        if(i > K_MAX) {
            break;
        }   
// тут посчитали последний элемент на предыдщем шаге 
        if(is_prime[i] == true) {
            count--;
        } 
        i++;   
 
        if(is_prime[j] == true) {
            count++;
        } 
 
        j++;
 
        if(count == M) {
            cout << i << "\n"; 
            return 0;
        } 
    } 
 
    cout << -1 << "\n";
 
    return 0;
}