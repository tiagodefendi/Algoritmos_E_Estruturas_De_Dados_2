/*
16. Dado um par de vetores arr1 e arr2, retorne um vetor contendo os elementos que estão em arr1 ou
em arr2, mas não em ambos. Em outras palavras, sua função deve implementar a operação de diferença
simétrica de conjuntos.
*/

#include <unordered_set>
#include <vector>

std::vector<int> diferencaSimetrica(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::unordered_set<int> h1;
    std::unordered_set<int> h2;

    std::unordered_set<int> h3;
    std::vector<int> result;

    for(int el: arr1) {
        h1.insert(el);
        h3.insert(el);
    }
    for(int el: arr2) {
        h2.insert(el);
        h3.insert(el);
    }

    for(int el: h3) {
        if (!(h1.count(el) && h2.count(el))) {
            result.push_back(el);
        }
    }

    return result;
}