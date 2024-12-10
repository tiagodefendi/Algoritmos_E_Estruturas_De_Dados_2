#include <unordered_map>
#include <vector>
#include <iostream>

int primeiroUnico(std::vector<int>& arr) {
    // Mapeia cada elemento ao seu numero de ocorrencias
    std::unordered_map<int, int> frequencia;
    
    // Primeiro loop: conta as ocorrencias de cada elemento
    for (int num : arr) {
        frequencia[num]++;
    }
    
    // Segundo loop: encontra o primeiro elemento com frequencia 1
    for (size_t i = 0; i < arr.size(); ++i) {
        if (frequencia[arr[i]] == 1) {
            return i; // Retorna a posicao do primeiro elemento unico
        }
    }
    
    return -1; // Retorna -1 se nao houver elementos unicos
}

int main() {
    std::vector<int> arr = {4, 5, 6, 5, 4, 7};
    int posicao = primeiroUnico(arr);
    
    if (posicao != -1) {
        printf("A posicao do primeiro elemento unico e: %d\n", posicao);
    } else {
        printf("Nao ha elementos unicos no vetor.\n");
    }

    return 0;
}
