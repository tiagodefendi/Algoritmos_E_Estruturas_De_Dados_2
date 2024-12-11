/*
17. Dado um vetor de inteiros, retorne o elemento majoritário do vetor. O elemento majoritário do vetor é
aquele que ocorre mais do que n/2 vezes, onde n é o tamanho do vetor. Se o vetor não contém um elemento
majoritário, retorne -1.
*/

#include <unordered_map>
#include <vector>

int elementoMajoritario(std::vector<int>& arr) {
    std::unordered_map<int, int> h;
    int n = arr.size();

    for(int el: arr) {
        h[el]++;
    }

    int maior_tamanho = -1;
    int maior = -1;

    for (std::pair<int, int> el: h) {
        if (el.second > n/2 && el.second > maior_tamanho) {
            maior_tamanho = el.second;
            maior = el.first;
        }
    }

    return maior;
}
