#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Dados dois vetores v1 e v2 de inteiros positivos, retorne um vetor contendo a interseção
//dos elementos de v1 e v2. Em outras palavras, a função deve retornar os elementos
//comuns a ambos os vetores, sem repetições. A ordem dos elementos no vetor retornado
//não é importante. Caso não haja elementos em comum, retorne um vetor vazio.
//V1 e v2 podem conter elementos repetidos. Os vetores de entrada não devem ser modificados,
//mas você pode criar vetores auxiliares.

//Exemplo: v1 = {1, 2, 3, 4, 5}, v2 = {5, 4, 3, 2, 1} deve retornar {1, 2, 3, 4, 5}
//Exemplo: v1 = {1, 2, 3, 4, 5}, v2 = {5, 4, 3, 2, 0} deve retornar {2, 3, 4, 5}
//Exemplo: v1 = {1, 2, 3}, v2 = {4, 5, 6} deve retornar {}
//Exemplo: v1 = {1}, v2 = {1} deve retornar {1}
//Exemplo: v1 = {1, 1, 2}, v2 = {1, 2} deve retornar {1, 2}
//Exemplo: v1 = {1, 1, 2}, v2 = {1, 2, 3} deve retornar {1, 2}

vector<int> intersecao(vector<int> &v1, vector<int> &v2){
    vector<int> s1 = v1;
    vector<int> s2 = v2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    vector<int> res;

    int i, j, k = 0;

    while (i<s1.size() and j<s2.size()){
        if (s1[i] < s2[j]){
            i++;
        }

        else if (s2[i] < s1[j]){
            j++;
        }

        else if (s1[i] == s2[j]){
            if (k == 0) {
                res.push_back(s1[i]);
                k++;
            }
            if (s1[i] != res[k]) {
                res.push_back(s1[i]);
                k++;
            }
            i++;
            j++;
        }
    }

    while (i<s1.size()){
        if (s1[i] == s2[j]){
            if (k == 0) {
                res.push_back(s1[i]);
                k++;
            }
            if (s1[i] != res[k]) {
                res.push_back(s1[i]);
                k++;
            }
        }
        i++;
    }

    while (j<s2.size()){
        if (s1[i] == s2[j]){
            if (k == 0) {
                res.push_back(s1[i]);
                k++;
            }
            if (s1[i] != res[k]) {
                res.push_back(s1[i]);
                k++;
            }
        }
        j++;
    }


    return res;
}

int main () {
    vector<pair<vector<int>, vector<int>>> testes = {
        {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}},
        {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 0}},
        {{1, 2, 3}, {4, 5, 6}},
        {{1}, {1}},
        {{1}, {}},
        {{1, 1, 2}, {1, 2}},
        {{1, 1, 2}, {1, 2, 3}}
    };

    auto imprimir = [](vector<int> &v) {
        for (auto x : v) cout << x << " ";
        cout << endl;
    };

    for (int i = 0; i < testes.size(); i++) {
        auto [v1, v2] = testes[i];
        cout << "Testando caso " << i << endl;
        cout << "Vetor 1: ";
        imprimir(v1);
        cout << "Vetor 2: ";
        imprimir(v2);
        vector<int> res = intersecao(v1, v2);
        cout << "Resultado: ";
        imprimir(res);
        cout << endl;
    }

    return 0;
}
