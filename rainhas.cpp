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

        int col_count = 0;
        for (int col = 0; col < 8; ++col) {
            if (line[col] == '1') {
                if (queens[row]!= -1) {
                    return -1; // mais de uma rainha na mesma linha
                }
                queens[row] = col;
                col_count++;
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
    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 8; ++j) {
            if (queens[i] == queens[j] || // rainhas na mesma coluna
                queens[i] == queens[j] + (j - i) || // mesma diagonal ascendente
                queens[i] == queens[j] - (j - i)) { // mesma diagonal descendente
                validSolution = false; // solução inválida
                attacksFile << i + 1 << "," << queens[i] + 1 << " " << j + 1 << "," << queens[j] + 1 << std::endl; // salva os ataques
            }
        }
    }
    attacksFile.close(); 

    return validSolution? 1 : 0; // solução válida ou não
}
