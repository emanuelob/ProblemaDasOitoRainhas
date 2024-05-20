#include "rainhas.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

Rainhas::Rainhas(const char* filename) {
    this->filename = filename;
}

int Rainhas::verifica() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1; // falha ao abrir o arquivo
    }

    int count = 0;
    int row = 0;
    std::string line;
    std::vector<int> queens(8, -1); // vetor para armazenar a posição das rainhas em cada linha

    while (getline(file, line)) {
        if (row >= 8 || line.size()!= 8) {
            return -1; // tabuleiro não é 8x8
        }

        for (int col = 0; col < 8; ++col) {
            if (line[col] == '1') {
                queens[row] = col; // permite múltiplas rainhas na mesma linha, por enquanto
                count++; // quantidade de rainhas
            } else if (line[col]!= '0') {
                return -1; // caracter inválido
            }
        }

        row++;
    }

    if (count!= 8) {
        return -1; // não tem 8 rainhas
    }

    // aplica restrição de ataque: dois loops para comparar todas as rainhas do tabuleiro
    std::ofstream attacksFile("ataques.txt"); // arquivo para salvar os ataques
    bool validSolution = true;

    // as rainhas estão na mesma linha ou coluna?
    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 8; ++j) {
            if (queens[i] == queens[j]) { // rainhas na mesma coluna
                validSolution = false;
                attacksFile << i + 1 << "," << queens[i] + 1 << " ";
            }
        }
    }

    // agpra, verificação de ataques em diagonais
    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 8; ++j) {
            if (abs(queens[i] - queens[j]) == abs(i - j)) { // mesma diagonal
                validSolution = false;
                attacksFile << i + 1 << "," << queens[i] + 1 << " ";
            }
        }
    }
    attacksFile.close(); 

    return validSolution? 1 : 0; // ternário: solução válida ou não válida
}
