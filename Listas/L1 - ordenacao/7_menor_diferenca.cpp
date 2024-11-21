#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Dado um vetor de inteiros não-negativos v, retorne um par de inteiros
//cuja diferença é a menor possível dentre todas as diferenças possíveis
//entre dois elementos do vetor.
//Exemplo: v = {10, 14, 4, 7}
//menor_diferenca(v) = {4, 7}
//O vetor de entrada não deve ser modificado.
pair<int,int> menor_diferenca(vector<int> &v){
    if (v.size() < 2){
        return {-1, -1};
    }

    int menor_dif = s[1]-s[0];
    int menor_pos = 0;

    for (int i=1; i<n-1; i++) {
        int dif = s[i+1] - s[i];
        if (menor_dif > dif){
            menor_pos = i;
        }
    }

    vector<int> s = v;
    sort(s.begin(), s.end());
    return {s[menor], s[menor+1]};
}

int main(){
    vector<int> v = {10, 14, 4, 7};

    pair<int,int> res = menor_diferenca(v);

    cout << res.first << " " << res.second << "\n";

    return EXIT_SUCCESS;
}
