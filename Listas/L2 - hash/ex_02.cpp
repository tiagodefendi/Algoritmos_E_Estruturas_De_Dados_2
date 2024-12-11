/*
2. Dado um vetor de inteiros arr, retorne a posição do primeiro elemento do vetor que não tem duplicata.
Se todos os elementos ocorrerrem pelo menos duas vezes, retorne -1
*/

#include <unordered_map>
#include <vector>
#include <iostream>

int primeiroUnico(std::vector<int>& arr) {
    std::unordered_map<int, int> frequencia;

    for (int num : arr) {
        frequencia[num]++;
    }

    for (size_t i = 0; i < arr.size(); ++i) {
        if (frequencia[arr[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    std::vector<int> arr = {4, 5, 6, 5, 4, 7};
    int posicao = primeiroUnico(arr);

    if (posicao != -1) {
        printf("A posicao do primeiro elemento unico e: %d\n", posicao);
    } else {
        printf("Nao ha elementos unicos no vetor.\n");
    }

    return 0;
}
