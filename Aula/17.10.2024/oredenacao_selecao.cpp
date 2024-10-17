/*
Ordenação por seleção
selecionar o maior/menor valor e colocar na ultima/primeira posição relativa a interação

v = [3, 0, 4, 6, 1, 5, 2]

descobrir onde tá o maior elemento do vetor
v = [3, 0, 4, (6), 1, 5, 2]

colcar na ultima posição
v = [3, 0, 4, (2), 1, 5,(6)]

descobrir o maior até onde eu ja ordenei
v = [3, 0, 4, 2, 1, (5),6]

colocar na nova ultima posição
v = [3, 0, 4, 2, 1, (5),6]

repetir
v = [3, 0, (4), 2, 1, 5,6] -> v = [3, 0, (1), 2, (4), 5,6]
v = [(3), 0, 1, 2, 4, 5,6] -> v = [(2), 0, 1, (3), 4, 5,6]
v = [(2), 0, 1, 3, 4, 5,6] -> v = [(1), 0, (2), 3, 4, 5,6]
v = [(1), 0, 2, 3, 4, 5,6] -> v = [(0), (1), 2, 3, 4, 5,6]

pronto está ordenado
v = [0, 1, 2, 3, 4, 5,6]
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int* vetor_aleatorio(int n, int max, int seed=99){
    int* v = new int[n];
    srand(seed);
    for(int i=0; i<n-1; i++){
        v[i] = rand() % max;
    }

    return v;
}

int pos_maior(int* v, int ini, int fim){
    int maior = ini;
    for(int i=ini+1; i<=fim; i++){
        if (v[maior] < v[i]){
            maior = i;
        }
    }
    return maior;
}

void SelectionSort(int* v, int n){
    for(int i=n-1; i>0; i--){
        int p = pos_maior(v, 0, i);
        swap(v[p], v[i]);
    }
}

int main(){
    int n = 100;
    int *v = vetor_aleatorio(n, n*100);

    printf("v[%d] = ", n);
    for(int i=0; i<n; i++) printf("%d, ", v[i]);
    printf("\b\b \n");

    SelectionSort(v, n);

    printf("v[%d] = ", n);
    for(int i=0; i<n; i++) printf("%d, ", v[i]);
    printf("\b\b \n");

    return 0;
}

//github.com/tiagodefendi
