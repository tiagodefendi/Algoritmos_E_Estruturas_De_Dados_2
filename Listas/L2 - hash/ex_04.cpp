/*
4. Dado um vetor de inteiros arr, retorne true se arr contém algum elemento repetido, 
e false caso contrário.
*/

#include <unordered_set>
#include <vector>
#include <iostream>

bool temDuplicatas(std::vector<int>& arr) {
    std::unordered_set<int> repetidos; // guarda os elementos visitados

    for (int num : arr) {
        if (repetidos.find(num) != repetidos.end()) { // se o elemento existir retorna um iterador diferente de end()
            return true; // elemento ja foi encontrado anteriormente, duplicata detectada
        }
        repetidos.insert(num); // adiciona o numero atual ao conjunto
    }

    return false; // nenhuma duplicata encontrada
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 7};

    if (temDuplicatas(arr)) {
        std::cout << "O vetor contem elementos repetidos." << std::endl;
    } else {
        std::cout << "Nao ha elementos repetidos no vetor." << std::endl;
    }

    return 0;
}
