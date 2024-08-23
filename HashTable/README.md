# Sistema de Contagem de Palavras

Este projeto é um sistema para contar e gerenciar palavras em um texto usando uma tabela hash com listas ligadas para lidar com colisões. O programa permite adicionar texto/palavras, contar ocorrências de cada palavra, atualizar contagens, remover palavras, verificar a presença de palavras.

## Funcionalidades

- **Adicionar Texto**: Adiciona uma palavra à tabela hash e inicializa ou incrementa sua contagem.
- **Contar Palavra**: Conta o número de ocorrências de uma palavra específica na tabela.
- **Atualizar Contagem**: Atualiza a contagem de uma palavra existente.
- **Remover Palavra**: Remove uma palavra da tabela hash.
- **Verificar Palavra**: Verifica se uma palavra está presente na tabela.
- **Imprimir Tabela**: Imprime o conteúdo da tabela hash.


## Compilação e Execução

1. **Compilação**

   Para compilar o código, use um compilador C++ que suporte o padrão C++11 ou superior. O seguinte comando usa o `g++` para compilar:

   ```sh
   g++ -std=c++11 -o sistema_contagem_palavras main.cpp
   ```

2. **Execução**

   Para executar o programa compilado, use o comando:

   ```sh
   ./sistema_contagem_palavras
   ```

   O programa exibirá um menu com várias opções para interagir com a tabela hash.

## Uso

Ao iniciar o programa, você verá um menu com as seguintes opções:

1. **Adicionar Texto**: Insira a palavra a ser adicionada à tabela.
2. **Contar Palavra**: Insira a palavra para contar suas ocorrências.
3. **Atualizar Contagem**: Insira a palavra e a nova contagem para atualizar.
4. **Remover Palavra**: Insira a palavra a ser removida da tabela.
5. **Verificar Palavra**: Insira a palavra para verificar se está presente na tabela.
6. **Imprimir Tabela**: Exibe o conteúdo atual da tabela hash.
0. **Sair**: Encerra o programa.


teste:
apple orange banana grape cherry peach mango apricot plum date