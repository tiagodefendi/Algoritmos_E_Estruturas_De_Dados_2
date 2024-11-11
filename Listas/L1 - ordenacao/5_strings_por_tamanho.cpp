#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compararStringTamanho(const string& a, const string& b) {
    return a.size() <= b.size();
}

//esta função recebe um vetor de strings de diferentes tamanhos
//e retorna um vetor com as mesmas strings, mas ordenadas por tamanho
//O vetor de entrada não deve ser modificado.
vector<string> ordenar_por_tamanho(vector<string> &v){
    vector<string> s = v;
    sort(s.begin(), s.end(), compararStringTamanho);

    return s;
}

int main(){
    vector<string> v = {"gato", "macaco", "galinha", "porco", "cachorro", "pato", "vaca", "cavalo", "ovelha"};

    vector<string> res = ordenar_por_tamanho(v);

    for(auto s : res){
        cout << s << "\n";
    }

    return EXIT_SUCCESS;
}

