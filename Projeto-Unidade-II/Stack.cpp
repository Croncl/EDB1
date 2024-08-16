// Stack.cpp
#include "Stack.hpp"
#include <stdexcept>

// Construtor: inicializa o topo da pilha como nullptr
Stack::Stack() : top(nullptr) {}

// Destrutor: limpa a memória alocada para a pilha
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

// Método para empilhar um caractere
void Stack::push(char ch) {
    Node* newNode = new Node(); // Cria um novo nó
    newNode->data = ch;         // Define o dado do nó
    newNode->next = top;        // Aponta para o nó atual do topo
    top = newNode;              // Atualiza o topo para o novo nó
}

// Método para desempilhar um caractere
void Stack::pop() {
    if (isEmpty()) return;      // Se a pilha estiver vazia, não faz nada
    Node* temp = top;           // Armazena o nó do topo
    top = top->next;            // Atualiza o topo para o próximo nó
    delete temp;                // Libera a memória do nó removido
}

// Método para obter o caractere do topo sem removê-lo
char Stack::peek() {
    if (isEmpty()) throw std::runtime_error("Stack is empty"); // Lança exceção se a pilha estiver vazia
    return top->data; // Retorna o dado do nó do topo
}

// Método para verificar se a pilha está vazia
bool Stack::isEmpty() {
    return top == nullptr; // Retorna true se o topo for nullptr
}

// Função para verificar se os caracteres de abertura e fechamento formam um par correspondente
bool isMatchingPair(char abre, char fecha) {
    return (abre == '(' && fecha == ')') || 
           (abre == '[' && fecha == ']') || 
           (abre == '{' && fecha == '}');
}

// Função para verificar se a expressão está balanceada
bool isBalanced(const std::string& expressao) {
    Stack s; // Cria uma pilha personalizada

    for (char ch : expressao) { // Percorre cada caractere da expressão
        if (ch == '(' || ch == '[' || ch == '{') { // Se for um delimitador de abertura
            s.push(ch); // Empilha o delimitador
        } else if (ch == ')' || ch == ']' || ch == '}') { // Se for um delimitador de fechamento
            if (s.isEmpty() || !isMatchingPair(s.peek(), ch)) { // Verifica se a pilha está vazia ou se o topo não corresponde
                return false; // Expressão não está balanceada
            }
            s.pop(); // Remove o delimitador de abertura correspondente da pilha
        }
    }

    return s.isEmpty(); // Retorna true se a pilha estiver vazia (expressão balanceada)
}