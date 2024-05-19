#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE("Verifica tabuleiros que não são válido", "[tabuleiros]") {
    Rainhas tabuleiro("tabuleiros/teste1.txt"); 
    REQUIRE(tabuleiro.verifica() == -1);
}

// TEST_CASE("Verifica tabuleiros que são uma solução para o problema", "[tabuleiros]") {
//     Rainhas tabuleiro(""); 
//     REQUIRE(tabuleiro.verifica() == 1);
// }

// TEST_CASE("Verifica tabuleiro que não são uma solução para o problema", "[tabuleiros]") {
//     Rainhas tabuleiro("teste_8_rainhas.txt"); 
//     REQUIRE(tabuleiro.verifica() == 0);
// }