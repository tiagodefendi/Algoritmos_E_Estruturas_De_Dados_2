/*
4. Dado um vetor de inteiros arr, retorne true se arr contém algum elemento repetido,
e false caso contrário.
*/

#include <unordered_set>
#include <vector>
#include <iostream>

bool temDuplicatas(std::vector<int>& arr) {
    std::unordered_set<int> repetidos;

    for (int num : arr) {
        if (repetidos.count(num)) {
            return true;
        }
        repetidos.insert(num);
    }

    return false;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 7};

    if (temDuplicatas(arr)) {
        std::cout << "O vetor contem elementos repetidos." << std::endl;
    } else {
        std::cout << "Nao ha elementos repetidos no vetor." << std::endl;
    }

    return 0;
}
