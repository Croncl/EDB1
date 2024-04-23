#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

bool verifica_ordenacao(const vector<int>& vetor) {
    for (size_t i = 0; i < vetor.size() - 1; ++i) {
        if (vetor[i] > vetor[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(nullptr)); // Inicializa a semente do gerador de números aleatórios

    int tamanho;
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    // Vetor em ordem crescente
    vector<int> vetorCrescente(tamanho);
    for (int i = 0; i < tamanho; ++i) {
        vetorCrescente[i] = i + 1;
    }

    // Vetor em ordem decrescente
    vector<int> vetorDecrescente(tamanho);
    for (int i = 0; i < tamanho; ++i) {
        vetorDecrescente[i] = tamanho - i;
    }

    // Vetor com números aleatórios
    vector<int> vetorAleatorio(tamanho);
    for (int i = 0; i < tamanho; ++i) {
        vetorAleatorio[i] = rand() % (tamanho + 1); // Gera números aleatórios entre 0 e tamanho
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

    // Verifica ordenação
    cout << "Verificando a ordenacao dos vetores:" << endl;
    cout << "Vetor crescente: " << (verifica_ordenacao(vetorCrescente) ? "Ordenado" : "Nao ordenado") << endl;
    cout << "Vetor decrescente: " << (verifica_ordenacao(vetorDecrescente) ? "Ordenado" : "Nao ordenado") << endl;
    cout << "Vetor aleatorio: " << (verifica_ordenacao(vetorAleatorio) ? "Ordenado" : "Nao ordenado") << endl;

    return 0;
}
