/*
11. Dado um par de vetores arr1 e arr2, retorne um vetor contendo os elementos que estão em arr1 ou em
arr2. Em outras palavras, sua função deve implementar a operação de união de conjuntos.
*/

#include <unordered_set>
#include <vector>

std::vector<int> uniao(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::unordered_set<int> h;
    std::vector<int> result;

    for(int el: arr1) {
        if(!h.count(el)) {
            h.insert(el);
            result.push_back(el);
        }
    }
    for(int el: arr2) {
        if(!h.count(el)) {
            h.insert(el);
            result.push_back(el);
        }
    }

    return result;
}
