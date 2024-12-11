/*
5. Dado um vetor de inteiros arr, retorne um vetor com os elementos de arr, mas sem elementos repetidos.
Os elementos no vetor de saída precisam estar na mesma ordem que os elementos do vetor de entrada.
*/

#include <unordered_set>
#include <vector>
#include <iostream>

std::vector<int> semDuplicatas(std::vector<int>& arr) {
    std::unordered_set<int> vistos;
    std::vector<int> resultado;

    for (int num : arr) {
        if (!vistos.count(num)) {
            resultado.push_back(num);
        }
        vistos.insert(num);
    }

    return resultado;
}

int main() {
    std::vector<int> arr = {4, 5, 6, 5, 4, 7};

    std::vector<int> resultado = semDuplicatas(arr);

    std::cout << "Vetor sem duplicatas: ";
    for (int num : resultado) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
