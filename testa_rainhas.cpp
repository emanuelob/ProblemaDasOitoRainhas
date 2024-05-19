#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE("Verifica tabuleiro válido", "[tabuleiro]") {
    Rainhas tabuleiro("teste_8_rainhas.txt"); 
    REQUIRE(tabuleiro.verifica() == 1);
}