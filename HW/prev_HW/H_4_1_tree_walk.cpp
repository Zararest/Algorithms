#include <vector>
#include <iostream>

enum Node{

    B = 1,
    W = 2,
    G = 3
};

class Tree{

    int num_of_whites = 0; //количество белых которые после черных
    int num_of_blacks = 0;
    int result = 0;

    std::vector<int> path;
    
public:
    
    void parse_char(char elem);
};

void Tree::parse_char(char elem){

    if (elem == '(' || elem == ',') return;

    if (elem == 'g'){

        path.push_back(G);
        return;
    }

    if (elem == 'b'){

        num_of_blacks++;
        path.push_back(B);
        return;
    }

    if (elem == 'w'){

        if (num_of_blacks != 0){

            num_of_whites++;
        } 

        path.push_back(W);
        return;
    }

    if (elem == ')'){

        result += num_of_whites;
        num_of_whites = 0;

        int path_back = path.back();

        if (path_back == B){
            
            num_of_blacks--;
        }

        path.pop_back();

        if (path.empty()){

            std::cout << result << std::endl;
            exit(0);
        }
    }
}

int main(){

    Tree tree;

    while (true){

        tree.parse_char(getchar());
    }
}