#include <set>
#include <string>
#include <iostream>
#include <vector>

struct Life{

    int X = 0;
    int Y = 0;

    Life(){}

    Life(int new_x, int new_y){

        X = new_x;
        Y = new_y;
    }

    bool operator <(const Life& rhs) const{

        if (X == rhs.X) return Y < rhs.Y;

        return X < rhs.X;
    }
};

class Game{

    int field_size_X = 0;       // x < field_size_X
    int field_size_Y = 0;
    std::set<Life> field;
    std::vector<Life> about_to_die;//тут нужен итератор 
    std::vector<Life> new_life;

    int get_num_of_neighb(int X, int Y);
    void try_to_resurect(int X, int Y);

public:

    Game(int N, int M);
    void fill_field(int num_of_lives);
    void tact();
    void print();
};

int Game::get_num_of_neighb(int X, int Y){

    Life tmp_life(X - 1, Y - 1);
    int result = 0;

    for (int i = 0; i < 9; i++){

        tmp_life.X = X - 1 + i % 3;
        tmp_life.Y = Y - 1 + i / 3;

        result += field.find(tmp_life) != field.end();
    }

    return result;
}

Game::Game(int N, int M){

    field_size_X = N;
    field_size_Y = M;
}

void Game::fill_field(int num_of_lives){

    Life tmp_life;

    for (int i = 0; i < num_of_lives; i++){

        scanf("%i %i", &tmp_life.X, &tmp_life.Y);
        field.insert(tmp_life);
    }
}

void Game::try_to_resurect(int X, int Y){

    if (X >= field_size_X || X < 0 || Y >= field_size_Y || Y < 0) return;

    Life tmp_life(X, Y);
    if (field.find(tmp_life) != field.end()) return;

    int num_of_neighb = get_num_of_neighb(X, Y);
    
    if (get_num_of_neighb(X, Y) == 3){

        new_life.emplace_back(X, Y);
    }
}

void Game::tact(){

    Life tmp_life;
    int cur_num_of_neighb = 0;
    about_to_die.clear();
    new_life.clear();

    for(auto it : field){
        
        int cur_num_of_neighb = get_num_of_neighb(it.X, it.Y) - 1; //тк мы знаем что она живая

        if (cur_num_of_neighb < 2 || cur_num_of_neighb > 3){

            about_to_die.push_back(it);
        }

        for (int i = 2; i < 9; i++){
            
            if (i != 4){

                try_to_resurect(it.X - 1 + i % 3, it.Y - 1 + i / 3);
            }
        }
    }

    for (auto it : new_life){

        field.insert(it);
    } 

    for (auto it : about_to_die){

        field.erase(it);
    }   
}

void Game::print(){

    for (auto it : field){

        printf("%i %i\n", it.X, it.Y);
    }
}

int main(){

    int N, M, L, K;
    std::cin >> N >> M >> L >> K;

    Game game(N, M);
    game.fill_field(L);

    for (int i = 0; i < K; i++){

        game.tact();
    }

    game.print();
}