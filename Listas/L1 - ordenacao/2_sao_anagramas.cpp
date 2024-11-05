#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "utils.h"

using namespace std;

#define DEBUG 1

// retorna true se s e t são anagramas. Caso contrário, retorna false.
// s e t são strings terminadas em 0.
bool sao_anagramas(string& s, string& t){
    if (s.size() != t.size()) {
        return false;
    }

    if (s == t) {
        return true;
    }

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    if (s != t) {
        return false;
    }

    // for (int i; i<s.size(); i++) {
    //     if (s[i] != t[i]) {
    //         return false;
    //     }
    // }

    return true;
}

int main(int argc, char** argv){

    string s1(argv[1]);
    string s2(argv[2]);

    #if DEBUG
    cout << sao_anagramas(s1, s2) << "\n";
    #endif

    return EXIT_SUCCESS;
}
