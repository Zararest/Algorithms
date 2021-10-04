#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

class Set{ //храним числа в дапазоне 1..N как бит в нужном месте 

private: 

    using T = unsigned;

    enum {SIZE_T = 32}; //размер unsigned

    T* data;

    size_t N;

public: 

    Set(size_t N);

    ~Set();

    bool insert(size_t k);

    bool erase(size_t k);

    bool in(size_t k);
};

Set::Set(size_t N): N(N){

    data = new T[(N + SIZE_T - 1) / SIZE_T];
    memset(data, 0, N * sizeof(T));
}

Set::~Set(){

    delete [] data;
}

bool Set::insert(size_t k){

    if (k > N){

        return false;
    }

    data[k / SIZE_T] |= 1 << k % SIZE_T; //установка единицы в нужный бит

    return true;
}

bool Set::erase(size_t k){

    if (k > N){

        return false;
    }

    data[k / SIZE_T] = ~((T) 1 << k % SIZE_T);

    return true;
}

bool Set::in(size_t k){

    return (data[k / SIZE_T] >> k % SIZE_T) & 1;
}
