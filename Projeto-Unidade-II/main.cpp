// main.cpp
#include <iostream>
#include <string>
#include "Stack.hpp"

int main() {
    std::string expressao;

    // Solicita ao usuário que digite uma expressão
    std::cout << "Digite a expressão para verificar o balanceamento: \n";
    std::getline(std::cin, expressao); // Lê a expressão digitada

    // Verifica se a expressão está balanceada e imprime o resultado
    if (isBalanced(expressao)) {
        std::cout << "A expressão está balanceada" << std::endl;
    } else {
        std::cout << "A expressão não está balanceada" << std::endl;
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}