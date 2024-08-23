#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

// Define o tamanho padrão da tabela hash
const int TABLE_SIZE = 100;

// Estrutura que representa uma palavra e sua contagem
struct Palavra {
    std::string texto; // Texto da palavra
    int contagem;      // Contagem de ocorrências da palavra

    // Construtor que inicializa o texto e a contagem
    Palavra(const std::string& t, int c);
};

// Função hash que calcula o valor hash para uma string
unsigned long hashFunction(const std::string& palavra);

// Classe que representa a tabela hash
class HashTable {
private:
    std::vector<std::list<Palavra>> tabela; // Vetor de listas para armazenar as palavras
    int capacidade; // Capacidade da tabela hash

public:
    // Construtor que inicializa a tabela com uma capacidade específica
    HashTable(int cap = TABLE_SIZE);

    // Calcula o índice na tabela hash para uma dada palavra
    int getIndex(const std::string& palavra);
    // Adiciona uma palavra à tabela hash com uma contagem específica
    void addWord(const std::string& palavra, int contagem = 1);
    // Conta a ocorrência de uma palavra na tabela hash
    int countWord(const std::string& palavra);
    // Remove uma palavra da tabela hash
    void removeWord(const std::string& palavra);
    // Verifica se uma palavra está presente na tabela hash
    bool containsWord(const std::string& palavra);
    // Imprime o conteúdo da tabela hash
    void printTable() const;
};

#endif // HASHTABLE_H