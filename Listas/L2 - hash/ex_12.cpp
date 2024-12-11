/*
12. Dado um par de vetores arr1 e arr2, retorne um vetor contendo os elementos que estão em arr1 e em
arr2. Em outras palavras, sua função deve implementar a operação de interseção de conjuntos.
*/

#include <unordered_set>
#include <vector>

std::vector<int> intersecao(std::vector<int>& arr1, std::vector<int>& arr2){
    std::unordered_set<int> h1;
    std::vector<int> result;

    for(int el: arr1) {
        h1.insert(el);
    }

    for(int el: arr2) {
        if (h1.count(el)) {
            result.push_back(el);
        }
    }

    return result;
}
