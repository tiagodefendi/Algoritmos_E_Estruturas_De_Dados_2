#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Pais{
    Pais(const string& nome, int o, int p, int b)
        : nome(move(nome)), ouro(o), prata(p), bronze(b){}

    void print(){
        cout << nome << " " << ouro << " " << prata << " " << bronze << "\n";
    }

    string nome;
    int ouro;
    int prata;
    int bronze;

    bool operator<(const Pais& outro) {
        if (this->ouro != outro.ouro) {
            return this->ouro < outro.ouro;
        }
        else if (this->prata != outro.prata) {
            return this->prata < outro.prata;
        }
        else if (this->bronze != outro.bronze) {
            return this->bronze < outro.bronze;
        }
        else {
            return this->nome < outro.nome;
        }
    }
};


void ordenar_quadro_medalhas(vector<Pais> &paises){
    std::sort(paises.begin(), paises.end());
}

int main(int argc, char** argv){
    int N;

    string nome;
    int o, p, b;

    cin >> N;

    vector<Pais> quadro;
    quadro.reserve(500);

    while(N--){
        cin >> nome >> o >> p >> b;
        quadro.emplace_back(nome, o, p, b);
    }

    ordenar_quadro_medalhas(quadro);

    for(auto& p : quadro){
        p.print();
    }

    return 0;
}
