#include "rainhas.hpp"
#include <fstream>

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

    while (getline(file, line)) {
        if (row >= 8 || line.size()!= 8) {
            return -1; // tabuleiro não é 8x8
        }

        for (char c : line) {
            if (c == '1') {
                count++; //quantidade de rainhas
            } else if (c!= '0') {
                return -1; //caracter inválido 
            }
        }

        row++;
    }

    if (count!= 8) {
        return -1; // não tem 8 rainhas
    }

    // return 1; // tabuleiro válido

}