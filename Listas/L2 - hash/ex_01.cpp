/*
1. Dado um vetor de inteiros arr, conte a frequência de cada inteiro
*/

#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<int, int> contarFrequencia(std::vector<int>& arr) {
    std::unordered_map<int, int> frequencia;
    for (int num : arr) {
        frequencia[num]++;
    }
    return frequencia;
}

int main() {
    std::vector<int> numeros = {1, 1000000, -500, 1, 5, 5, 140, 134, 1000000, 1};
    std::unordered_map<int, int> resultado = contarFrequencia(numeros);

    for (const auto& par : resultado) {
        std::cout << "Numero: " << par.first << ", Frequencia: " << par.second << std::endl;
    }

    std::cout << "Tamanho da tabela hash: " << resultado.bucket_count() << std::endl;

    return 0;
}
