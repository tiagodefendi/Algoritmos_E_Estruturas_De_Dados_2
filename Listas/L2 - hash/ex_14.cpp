/*
14. Dado um par de vetores arr1 e arr2, retorne true se arr1 é um subconjunto de arr2, ou false caso
contrário. Considere que os vetores não contém elementos duplicados. Por definição arr1 é subconjunto de
arr2 se todos os elementos de arr1 estão em arr2.
*/
#include <unordered_set>
#include <vector>

bool ehSubconjunto(std::vector<int>& arr1, std::vector<int>& arr2) {
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
