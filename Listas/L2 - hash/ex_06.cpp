/*
6. Dado um vetor de strings palavras, retorne um vetor de vetores, onde cada vetor interno contém todas
as palavras que são anagramas entre si. Por exemplo, se palavras = {"ate", "eat", "tea", "bat",
"tab"}, então a saída deve ser {{"ate", "eat", "tea"}, {"bat", "tab"}}.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <iostream>

std::vector<std::vector<std::string>> agruparAnagramas(std::vector<std::string>& palavras) {
    std::unordered_map<std::string, std::vector<std::string>> anagramas; // hash pra guardar os anagramas

    for (const std::string& palavra : palavras) { // passa por todas as palavras
        std::string chave = palavra;
        std::sort(chave.begin(), chave.end());

        anagramas[chave].push_back(palavra); // guarda a palavra no seu grupo de anagrama
    }

    // transforma a hash em um vetor de vetores
    std::vector<std::vector<std::string>> resultado;
    for (const auto& par : anagramas) {
        resultado.push_back(par.second);
    }

    return resultado;
}

int main() {
    std::vector<std::string> palavras = {"ate", "eat", "tea", "bat", "tab"};
    std::vector<std::vector<std::string>> resultado = agruparAnagramas(palavras);

    // Exibe os grupos de anagramas
    for (const auto& grupo : resultado) {
        std::cout << "{ ";
        for (const std::string& palavra : grupo) {
            std::cout << palavra << " ";
        }
        std::cout << "}\n";
    }

    return 0;
}
