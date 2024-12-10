/*
5. Dado um vetor de inteiros arr, retorne um vetor com os elementos de arr, mas sem elementos repetidos.
Os elementos no vetor de saída precisam estar na mesma ordem que os elementos do vetor de entrada.
*/

#include <unordered_set>
#include <vector>
#include <iostream>

std::vector<int> semDuplicatas(std::vector<int>& arr) {
    std::unordered_set<int> vistos; // guarda os numeros ja visitados
    std::vector<int> resultado;    // vetor sem duplicatas

    for (int num : arr) {
        if (vistos.find(num) == vistos.end()) { // verifica se ainda não foi visto, vendo se o iterador é igual a end()
            // marca o numero como visto
            vistos.insert(num);
            // adiciona ao resultado
            resultado.push_back(num);
        }
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
