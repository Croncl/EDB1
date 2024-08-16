// Stack.hpp
#ifndef STACK_HPP
#define STACK_HPP

#include <string>

// Estrutura de nó para a pilha
struct Node {
    char data;  // Armazena o caractere
    Node* next; // Ponteiro para o próximo nó
};

// Classe que representa a pilha
class Stack {
private:
    Node* top; // Ponteiro para o topo da pilha

public:
    // Construtor: inicializa o topo como nullptr
    Stack();

    // Destrutor: limpa a memória alocada para a pilha
    ~Stack();

    // Método para empilhar um caractere
    void push(char ch);

    // Método para desempilhar um caractere
    void pop();

    // Método para obter o caractere do topo sem removê-lo
    char peek();

    // Método para verificar se a pilha está vazia
    bool isEmpty();
};

// Função para verificar se os caracteres de abertura e fechamento formam um par correspondente
bool isMatchingPair(char abre, char fecha);

// Função para verificar se a expressão está balanceada
bool isBalanced(const std::string& expressao);

#endif // STACK_HPP