#include <iostream>
#include <cstdlib>  // Para utilizar a função rand()
#include <ctime>    // Para utilizar a função time()

using namespace std;

int busca_sequencial_recursiva(int *vetor, int tamanho, int valor) {
    if (tamanho == 0) {
        return -1;  // Se o vetor estiver vazio, retorna -1
    }
    if (vetor[tamanho - 1] == valor) {
        return tamanho - 1;  // Retorna o índice se encontrar o valor
    } else {
        return busca_sequencial_recursiva(vetor, tamanho - 1, valor);  // Chama recursivamente com um subvetor
    }
}

int main() {
    srand(time(nullptr)); // Inicializa a semente do gerador de números aleatórios

    int tamanho;
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    // Vetor em ordem crescente
    int vetorCrescente[tamanho];
    for (int i = 0; i < tamanho; ++i) {
        vetorCrescente[i] = i + 1;
    }

    // Vetor em ordem decrescente
    int vetorDecrescente[tamanho];
    for (int i = 0; i < tamanho; ++i) {
        vetorDecrescente[i] = tamanho - i;
    }

    // Vetor com números aleatórios
    int vetorAleatorio[tamanho];
    for (int i = 0; i < tamanho; ++i) {
        vetorAleatorio[i] = rand() % (tamanho+1); // Gera números aleatórios entre 0 e 10 * tamanho
    }

    // Exibe os vetores gerados
    cout << "Vetor em ordem crescente: ";
    for (int i = 0; i < tamanho; ++i) {
        cout << vetorCrescente[i] << " ";
    }
    cout << endl;

    cout << "Vetor em ordem decrescente: ";
    for (int i = 0; i < tamanho; ++i) {
        cout << vetorDecrescente[i] << " ";
    }
    cout << endl;

    cout << "Vetor aleatorio: ";
    for (int i = 0; i < tamanho; ++i) {
        cout << vetorAleatorio[i] << " ";
    }
    cout << endl;

    // Busca por um valor em cada vetor
    int numero_procurado;
    cout << "Digite o numero a ser buscado: ";
    cin >> numero_procurado;

    // Saída
    if (busca_sequencial_recursiva(vetorCrescente, tamanho, numero_procurado) == -1) {
        cout << "Elemento nao encontrado no vetor (crescente)" << endl;
    } else {
        cout << "O numero procurado esta na posicao (crescente): " << busca_sequencial_recursiva(vetorCrescente, tamanho, numero_procurado) << endl;
    }

    if (busca_sequencial_recursiva(vetorDecrescente, tamanho, numero_procurado) == -1) {
        cout << "Elemento nao encontrado no vetor (decrescente)" << endl;
    } else {
        cout << "O numero procurado esta na posicao (decrescente): " << busca_sequencial_recursiva(vetorDecrescente, tamanho, numero_procurado) << endl;
    }

    if (busca_sequencial_recursiva(vetorAleatorio, tamanho, numero_procurado) == -1) {
        cout << "Elemento nao encontrado no vetor (aleatorio)" << endl;
    } else {
        cout << "O numero procurado esta na posicao (aleatorio): " << busca_sequencial_recursiva(vetorAleatorio, tamanho, numero_procurado) << endl;
    }

    return 0;
}
