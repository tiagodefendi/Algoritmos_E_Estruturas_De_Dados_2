#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Aluno {
public:
    Aluno(string nome, int ra)
        : nome(nome), ra(ra) {}
    // A Fazer:
    // Para que a função sort possa ordenar um vetor de alunos, é necessário
    // sobrecarregar o operador <. Implemente a sobrecarga do operador < para
    // que a função sort possa ordenar um vetor de alunos pelo campo ra.

    bool operator<(const Aluno& other){
        return this->ra < other.ra;
    }


    void imprimir(){
        cout << "Nome: " << nome << ", RA: " << ra << endl;
    }

    string getNome() const {
        return nome;
    }

private:
    string nome;
    int ra;
};

bool compararAlunosNome(const Aluno& a, const Aluno& b) {
    return a.getNome() < b.getNome();
}


int main(int argc, char** argv){

    vector<Aluno> alunos = {
        Aluno("João", 2032548),
        Aluno("Maria", 2038894),
        Aluno("José", 1898856),
        Aluno("Pedro", 1922659),
        Aluno("João", 1900136),
        Aluno("Vanessa", 1788965),
        Aluno("Ana", 2199432),
    };

    //Ordenar o vetor de alunos.
    std::sort(alunos.begin(), alunos.end());
    std::sort(alunos.begin(), alunos.end(), compararAlunosNome); // ordena usando função de comparação por nome


    for(auto& aluno : alunos){
        aluno.imprimir();
    }

    return 0;
}
