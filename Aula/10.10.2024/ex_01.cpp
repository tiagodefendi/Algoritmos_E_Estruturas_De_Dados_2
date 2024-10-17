#include <iostream>
#include <string>
using namespace std;

template <typename T>
void troca(T&a, T&b){
    T aux;

    aux = a;
    a = b;
    b = aux;
}

int main(){
    int x = 5;
    int y = 10;

    printf("n1: %d - n2: %d\n", x, y);

    troca(x, y);

    printf("n1: %d - n2: %d", x, y);

    return 0;
}

//github.com/tiagodefendi
