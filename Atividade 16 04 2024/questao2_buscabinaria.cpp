#include <iostream>

using namespace std;

int busca_binaria_recursiva(int *vetor, int inicio, int fim, int valor) {
    if (inicio > fim) {
        return -1; // Valor não encontrado
    }

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == valor) {
        return meio; // Elemento encontrado, retorna o índice
    } else if (vetor[meio] < valor) {
        return busca_binaria_recursiva(vetor, meio + 1, fim, valor); // Busca na metade direita
    } else {
        return busca_binaria_recursiva(vetor, inicio, meio - 1, valor); // Busca na metade esquerda
    }
}

int busca_binaria_iterativa(int *vetor, int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == valor) {
            return meio; // Elemento encontrado, retorna o índice
        } else if (vetor[meio] < valor) {
            inicio = meio + 1; // Descarta a metade esquerda
        } else {
            fim = meio - 1; // Descarta a metade direita
        }
    }

    return -1; // Valor não encontrado
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    cout << "Vetor: ";
    for (int i = 0; i < tamanho; ++i) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Testes
    int valor_existente = 7;
    int indice_existente_recursiva = busca_binaria_recursiva(vetor, 0, tamanho - 1, valor_existente);
    int indice_existente_iterativa = busca_binaria_iterativa(vetor, tamanho, valor_existente);
    cout << "Busca por " << valor_existente << ": Recursiva - " << indice_existente_recursiva << ", Iterativa - " << indice_existente_iterativa << endl;

    int valor_inexistente = 8;
    int indice_inexistente_recursiva = busca_binaria_recursiva(vetor, 0, tamanho - 1, valor_inexistente);
    int indice_inexistente_iterativa = busca_binaria_iterativa(vetor, tamanho, valor_inexistente);
    cout << "Busca por " << valor_inexistente << ": Recursiva - " << indice_inexistente_recursiva << ", Iterativa - " << indice_inexistente_iterativa << endl;

    return 0;
}
