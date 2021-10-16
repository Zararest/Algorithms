#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node{

    int sum = -1;
    size_t freq = 0;
    node* left = nullptr; 
    node* right = nullptr;
};

struct pq_less{
    bool operator () (node const* l, node const * r){

        return l->freq > r->freq;
    }
};

void walk(node const* root, string const& s){

    if (root->left  != nullptr) walk(root->left, s + "0");
    if (root->right != nullptr) walk(root->right, s + "1");
    if (root->sum >= 0){
        printf("%c %s\n", root->sum, s.c_str());
    } 
}

vector<string> huf(string const& s){

    vector<string> res;
    vector<size_t> freq(256);

    for(auto c: s){

        freq[c & 0xFF]++; //тут маска чтобы сделать элемент положительным
    }

    priority_queue<node*, vector<node *>, pq_less> pq;

    for (int sum = 0; sum < 256; sum++){

        if (freq[sum] > 0){

            node* n = new node();
            n->sum = sum;
            n->freq = freq[sum];
            pq.push(n);
        }
    }

    while (pq.size() > 1){//мы сделали дерево с помощью приоритетной очереди 

        auto el1 = pq.top(); pq.pop();
        auto el2 = pq.top(); pq.pop();
        auto par = new node();
        par->left = el1;
        par->right = el2;
        par->sum = -1;
        par->freq = el1->freq + el2->freq;
        pq.push(par);
    }

    auto root = pq.top(); pq.pop();

    return res;
}

int main(){

    auto res = huf("abracadabra");

    for (size_t i = 0; i < res.size(); i++){

        auto const& c = res[i];

        if (!c.empty()){

            printf("%c: '%s'\n", (char)i, c.c_str());
        } 
    }
}
