#ifndef RAINHAS_HPP_
#define RAINHAS_HPP_

/**
 * @file rainhas.hpp
 * Declaração da classe Rainhas para resolver o problema das 8 rainhas.
 */

/**
 * Classe Rainhas.
 *
 * Esta classe encapsula a lógica para resolver o problema das 8 rainhas em um tabuleiro 8x8.
 * Ela lê a disposição inicial das rainhas de um arquivo e verifica se a disposição é válida,
 * ou seja, se nenhuma rainha pode atacar outra.
 */
class Rainhas {
 public:
   /**
     * Construtor da classe Rainhas: @param filename Caminho para o arquivo contendo a disposição inicial das rainhas.
     */
    Rainhas(const char* filename);
   /**
     * @return sempre será um inteiro.
     */
    int verifica();
 private:
   /**
    * Nome do arquivo que contém a disposição inicial das rainhas.
    */
    const char* filename;
};

#endif  // RAINHAS_HPP_
