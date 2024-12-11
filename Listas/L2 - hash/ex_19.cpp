/*
19. Dado um vetor de strings, crie um programa que conta a frequência de cada string. Além disto, a
função recebe um dicionário (hash) contendo as palavras que não devem ser contadas (stopwords).
Por exemplo, se arr = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"} e
stopwords = {"the", "is"}, então a saída deve ser {{"day", 1}, {"sunny", 2}}.
*/

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <utility>

std::unordered_map<std::string, int> contarFrequencia(std::vector<std::string>& arr, std::unordered_set<std::string>& stopwords) {
    std::unordered_map<std::string, int> h;

    for (std::string str: arr) {
        if (!stopwords.count(str)) {
            h[str]++;
        }
    }

    return h;
}
