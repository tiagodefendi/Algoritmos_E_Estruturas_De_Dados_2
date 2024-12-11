/*
7. Dado um vetor arr não-ordenado de inteiros, retorne o comprimento da maior sequência de inteiros
consecutivos em arr. Por exemplo, se arr = {1, 9, 3, 10, 4, 20, 2}, então a saída deve ser 4,
pois a maior sequência de inteiros consecutivos é {1, 3, 4, 2}.
Note que os elementos desta sequência não precisam estar um ao lado do outro no vetor arr.
*/

#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

int maiorSequenciaConsecutivos(std::vector<int>& arr) {
    std::unordered_set<int> elementos;
    for (int el: arr){
        elementos.insert(el);
    }

    int maiorComprimento = 0;
    for (int num : arr) {
        if (!elementos.count(num - 1)) {
            int comprimentoAtual = 1;
            int atual = num;

            while (elementos.count(atual + 1)) {
                atual++;
                comprimentoAtual++;
            }

            if (maiorComprimento < comprimentoAtual) {
                maiorComprimento = comprimentoAtual;
            }
        }
    }

    return maiorComprimento;
}

int main() {
    std::vector<int> arr = {1, 9, 3, 10, 4, 20, 2};
    std::cout << "O comprimento da maior sequencia consecutiva e: "
            << maiorSequenciaConsecutivos(arr) << std::endl;
    return 0;
}
