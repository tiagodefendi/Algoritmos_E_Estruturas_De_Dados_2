using namespace std;

// UTILITY ================================================================================================

// troca dois elementos do vetor de posição
void troca (int* v, int pos1, int pos2) {
    int temp = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp;
}

// descobre qual maior elemento do vetor
int max (int* v, int n) {
    int max = 0;
    for (int i = 1; i < n; i ++){
        if (v[i] > v[max]) {
            max = i;
        }
    }

    return max;
}



// SELECTION SORT ======================================================================================

void selection_sort (int* v, int n) {
    for (int i = n-1; i > 0; i--) {
        troca(v, n, max(v, i)); // coloca o maior valor na ultima posição
    }
}



// MERGE SORT ===========================================================================================

// mistura dois vetores ja ordenados em ordem crescente
void merge (int* v, int p, int q, int r) {
    // tamanho dos vetores temporarios
    int n1 = q - p + 1;
    int n2 = r - q; // r - (q + 1) + 1 = r (-q -1) + 1 = r - q + (1 - 1)

    // cria os vetores
    int *e = new int[n1];
    int *d = new int[n2];

    // preenche os vetores
    for (int i = 0; i < n1; i++) {
        e[i] = v[p+i];
    }
    for (int i = 0; i < n1; i++) {
        d[i] = v[(q+1)+i];
    }

    // cira as variaveis temporarias para cada posição
    int i= 0, j = 0, k = p;

    // insere em ordem o menor elemento entre os dois vetores
    while (i<n1 && j<n2) {
        if (e[i] <= d[j]) {
            v[k] = e[i];
            i++;
        }
        else {
            v[k] = d[j];
            j++;
        }
        k++;
    }
    // preenche com o resto do vetor a esquerda
    while (i<n1) {
        v[k] = e[i];
        i++;
        k++;
    }
    // preenche com o resto do vetor a direita
    while (j<n2) {
        v[k] = d[j];
        j++;
        k++;
    }

    // deleta os vetores temporarios
    delete e;
    delete d;
}

void merge_sort (int* v, int e, int d) {
    int m;
    if (e < d) {  // verifica se já não é um vetor unitario (sempre estará ordenado)
        m = (e+d)/2; // pega a posição da metade do vetor
        merge_sort(v, e, m); // chama a função para metade esqueda
        merge_sort(v, m+1, d); // chama a função para metade esqueda
        merge(v, e, m, d); // ordena o subvetor ja ordenado
    }
}




// QUICK SORT ================================================================================================

/*
Exemplo de Partition:

1 4 6 2 10 3 8
x = 8

| | 1 4 9 2 10 3 [8]
1 | | 4 9 2 10 3 [8] 
1 4 | | 9 2 10 3 [8] 
1 4 | 9 | 2 10 3 [8] 
1 4 2 | 9 | 10 3 [8] 
1 4 2 | 9 10 | 3 [8] 
1 4 2 3 | 10 9 | [8] 
1 4 2 3 [8] 9 10
*/

// coloca o ultimo elemento do vetor na sua posição correta
int partition (int* v, int p, int r) {
    int x = v[r]; // pega o ultimo elemento
    int i = p-1; // coloca a primeira barra antes do vetor começar

    for (int j = p; j < r; j++) {
        // quando o elemento for menor que x avança a primeira barra e 
        // troca o elemento autal com o primeiro maior
        if (v[j] < x) {
            i++;
            troca(v, i, j);
        }
    }

    troca(v, i+1, r); // coloca o elemento x na sua posição
    return i+1; // retorna a posição do elemento x
}

void quick_sort (int* v, int p, int r) {
    int q;
    if (p < r) { // verifica se já não é um vetor unitario (sempre estará ordenado)
        q = partition(v, p, r); // particiona o sub vetor e pega a posição do elemento ordenado
        quick_sort(v, p, q-1); // chama a função para particionar o subvetor da esqueda
        quick_sort(v, q+1, r); // chama a função para particionar o subvetor da direita
    }
}



// HEAP SORT ==================================================================================================

// define a posição do filho esquerdo
int esq (int i) {
    return 2*i + 1;
}

// define a posição do filho direito
int dir (int i) {
    return 2*i + 2; // esq(i) + 1
}

// verifica se um pai é maior q os dois filhos
// caso contrario não corrige até atender as condições da max heap a partir do pai original
void max_heapfy (int* v, int i, int th) {
    // descobre a posição dos filhos
    int e = esq(i);
    int d = dir(i);

    // descobre o maior elemento
    int maior = i;
    if ((e<th) && v[e] > v[i]) {
        maior = e;
    }
    if ((d<th) && v[d] > v[maior]) {
        maior = d;
    }
    
    // se um dos filhos for o maior troca de posição e verifica se as condições da max heap continua
    if (maior != i) {
        troca(v, i, maior);
        max_heapfy(v, maior, th);
    }
}

// transforma um vetor em uma maxheap chamando a max heapfy a partir dos ultimos pais
// ja que seus filhos, já são os maiores, pois estes não possuem filhos
// estes estão localizados na metade inferior do vetor
void build_max_heap (int* v, int n) {
    for (int i = n/2; i >= 0; i--) {
        max_heapfy(v, i, n); // verifica se é um pai maior que os filhos
    }
}

void heap_sort (int* v, int n) {
    build_max_heap(v, n); // garante q o vetor será uma max heap
    // a max heap garante q o primeiro pai é o maior elemento da arvore

    // i representa a posição inicial dos elementos ordenados
    for (int i = n-1; i > 0; i--) {
        troca(v, 0, i); // coloca o primeiro pai no inicio da lista
        max_heapfy(v, 0, i); // verifica e garante após a troca a condição da max heap até a posição i
    }
}
