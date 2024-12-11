/*
15. Dado um par de vetores arr1 e arr2, retorne true se arr1 e arr2 são disjuntos, ou false caso contrário.
Considere que os vetores não contém elementos duplicados. Por definição arr1 e arr2 são disjuntos se não
existe nenhum elemento em comum entre eles.
*/

#include <unordered_set>
#include <vector>

bool saoDisjuntos(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::unordered_set<int> h1;
    std::unordered_set<int> h2;

    for(int el: arr1) {
        h1.insert(el);
    }
    for(int el: arr2) {
        h2.insert(el);
    }

    for(int el: h1) {
        if (h2.count(el)) {
            return false;
        }
    }

    return true;
}
