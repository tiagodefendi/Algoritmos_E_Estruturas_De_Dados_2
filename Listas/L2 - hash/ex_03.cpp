/*
3. Dado um vetor de inteiros arr, retorne um par de inteiros que somados resultam em um valor k dado.
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_set>
#include <random>
#include <algorithm>
using namespace std;

pair<int, int> twosum(vector<int>& v, int k) {
    unordered_set<int> h;
    for (int el: v) {
        h.insert(el);
    }

    for (int el: v) {
        int x = k - el;
        if (h.count(x)==1) {
            return make_pair(el, x);
        }
    }

    return make_pair(-1, -1);
}

int main(int argc, char** argv){
    int n;
    int k;

    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }
    shuffle(v.begin(), v.end(), default_random_engine(99));

    pair<int, int> p = twosum(v, k);
    if (p.first + p.second != k) {
        printf("Não existem elementos que se somem\n");
    }
    else {
        printf("%d + %d = %d\n", p.first, p.second, k);
    }

    return 0;
}

//github.com/tiagodefendi
