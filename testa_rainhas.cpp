#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE("Verifica tabuleiro que não é válido", "[tabuleiro]") {
    Rainhas tabuleiro(""); 
    REQUIRE(tabuleiro.verifica() == -1);
}

TEST_CASE("Verifica tabuleiro que é uma solução para o problema", "[tabuleiro]") {
    Rainhas tabuleiro(""); 
    REQUIRE(tabuleiro.verifica() == 1);
}

TEST_CASE("Verifica tabuleiro que não é uma solução para o problema", "[tabuleiro]") {
    Rainhas tabuleiro("teste_8_rainhas.txt"); 
    REQUIRE(tabuleiro.verifica() == 0);
}