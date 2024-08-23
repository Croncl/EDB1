#include "hashTable.hpp"

// Construtor da classe Palavra, inicializa o texto e a contagem
Palavra::Palavra(const std::string& t, int c) : texto(t), contagem(c) {}

// Função hash que calcula o valor hash para uma string
unsigned long hashFunction(const std::string& palavra) {
    unsigned long hash = 5381;
    // Itera sobre cada caractere da palavra e atualiza o valor hash
    for (char c : palavra) {
        hash = ((hash << 5) + hash) + static_cast<unsigned long>(c);
    }
    // Retorna o valor hash modulado pelo tamanho da tabela
    return hash % TABLE_SIZE;
}

// Construtor da classe HashTable, inicializa a capacidade e redimensiona a tabela
HashTable::HashTable(int cap) : capacidade(cap) {
    tabela.resize(capacidade);
}

// Calcula o índice na tabela hash para uma dada palavra
int HashTable::getIndex(const std::string& palavra) {
    return hashFunction(palavra) % capacidade;
}

// Adiciona uma palavra à tabela hash com uma contagem específica
void HashTable::addWord(const std::string& palavra, int contagem) {
    int indice = getIndex(palavra);
    // Verifica se a palavra já existe na lista do índice calculado
    for (auto& p : tabela[indice]) {
        if (p.texto == palavra) {
            // Se a palavra já existe, incrementa a contagem
            p.contagem += contagem;
            return;
        }
    }
    // Se a palavra não existe, adiciona uma nova entrada na lista
    tabela[indice].emplace_back(palavra, contagem);
}

// Conta a ocorrência de uma palavra na tabela hash
int HashTable::countWord(const std::string& palavra) {
    int indice = getIndex(palavra);
    // Procura a palavra na lista do índice calculado
    for (const auto& p : tabela[indice]) {
        if (p.texto == palavra) {
            // Retorna a contagem se a palavra for encontrada
            return p.contagem;
        }
    }
    // Retorna 0 se a palavra não for encontrada
    return 0;
}

// Remove uma palavra da tabela hash
void HashTable::removeWord(const std::string& palavra) {
    int indice = getIndex(palavra);
    // Remove a palavra da lista do índice calculado
    tabela[indice].remove_if([&](const Palavra& p) { return p.texto == palavra; });
}

// Verifica se uma palavra está presente na tabela hash
bool HashTable::containsWord(const std::string& palavra) {
    int indice = getIndex(palavra);
    // Procura a palavra na lista do índice calculado
    for (const auto& p : tabela[indice]) {
        if (p.texto == palavra) {
            // Retorna true se a palavra for encontrada
            return true;
        }
    }
    // Retorna false se a palavra não for encontrada
    return false;
}

// Imprime o conteúdo da tabela hash
void HashTable::printTable() const {
    // Itera sobre cada índice da tabela
    for (int i = 0; i < capacidade; ++i) {
        std::cout << "Índice " << i << ": ";
        if (!tabela[i].empty()) {
            bool first = true;
            // Itera sobre cada palavra na lista do índice
            for (const auto& p : tabela[i]) {
                if (!first) {
                    std::cout << " -> ";
                }
                first = false;
                // Imprime a palavra e sua contagem
                std::cout << "( \"" << p.texto << "\", " << p.contagem << " )";
            }
        }
        // Indica o final da lista
        std::cout << " -> NULL" << std::endl;
    }
}