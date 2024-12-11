/*
13. Dado um par de vetores arr1 e arr2, retorne um vetor contendo os elementos que estão em arr1 mas
não estão em arr2. Em outras palavras, sua função deve implementar a operação de diferença de conjuntos.
*/

#include <unordered_set>
#include <vector>

std::vector<int> intersecao(std::vector<int>& arr1, std::vector<int>& arr2){
    std::unordered_set<int> h1;
    std::unordered_set<int> h2;
    std::vector<int> result;

    for(int el: arr1) {
        h1.insert(el);
    }
    for(int el: arr2) {
        h2.insert(el);
    }

    for(int el: h1) {
        if (!h2.count(el)) {
            result.push_back(el);
        }
    }

    return result;
}
