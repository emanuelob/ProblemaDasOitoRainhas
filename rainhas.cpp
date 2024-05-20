/**
 * @file rainhas.cpp
 * Implementação da classe Rainhas para resolver o problema das 8 rainhas.
 */
#include "rainhas.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

/**
 * Construtor da classe Rainhas.
 * @param filename Caminho para o arquivo contendo a disposição inicial das rainhas.
 */
Rainhas::Rainhas(const char* filename) {
    this->filename = filename;
}

/**
 * Verifica se a disposição das rainhas no tabuleiro é válida.
 * Uma disposição/solução é considerada válida se nenhuma rainha puder atacar outra.
 * @return 1 se a disposição for válida, 0 caso contrário.
 * @return -1 se a disposição for inválida, como tabuleiro que não seja 8x8,
 * tabuleiro com caracteres não binários, tabuleiro com mais de 8 rainhas
 * e tabuleiro com rainhas localizadas na mesma linha.
 */
int Rainhas::verifica() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1;  // falha ao abrir o arquivo
    }

    int count = 0;
    int row = 0;
    std::string line;
    std::vector<int> queens(8, -1);  // vetor que armazena a posição das rainhas em cada linha

    /**
     * Lê o arquivo linha por linha e verifica se há mais de uma rainha na mesma linha,
     * se o tabuleiro é 8x8 e se todos os caracteres são válidos ('0' ou '1').
     * Essas condições apontam tabuleiros inválidos, retornando -1.	
     */
    while (getline(file, line)) {
        if (row >= 8 || line.size()!= 8) {
            return -1;  // tabuleiro não é 8x8
        }

        int queensInRow = 0;
        for (int col = 0; col < 8; ++col) {
            if (line[col] == '1') {
                if (queensInRow > 0) {
                    return -1;  // mais de uma rainha na mesma linha
                }
                queens[row] = col;
                queensInRow++;
                count++;  // quantidade de rainhas
            } else if (line[col]!= '0') {
                return -1;  // caracter inválido
            }
        }

        row++;
    }

    if (count!= 8) {
        return -1;  // não tem 8 rainhas
    }

    std::ofstream attacksFile("ataques.txt");  // arquivo para salvar os ataques
    bool validSolution = true;

    /**
     * Por meio de dois for loops, verifica se as rainhas estão na mesma coluna 
     * ou se elas se atacam na diagonal. Para tanto, compara a posição das rainhas em cada linha, 
     * verificando se elas estão na mesma coluna ou se a diferença entre as colunas é 
     * igual à diferença entre as linhas. 
     * Caso encontre alguma condição de ataque, marca a solução como falsa 
     * e registra os ataques no arquivo ataques.txt.
     */
    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 8; ++j) {
            if (queens[i] == queens[j] || abs(queens[i] - queens[j]) == abs(i - j)) {
                validSolution = false;
                attacksFile << i + 1 << "," << queens[i] + 1 << " " << j + 1 << "," << queens[j] + 1 << "\n";
            }
        }
    }
    attacksFile.close();

    return validSolution? 1 : 0;  // ternário: solução válida ou não válida
}
