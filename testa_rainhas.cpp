#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE("Verifica tabuleiros que não são válidos", "[tabuleiros]") {
    Rainhas tabuleiro("tabuleiros/teste1.txt"); 
    REQUIRE(tabuleiro.verifica() == -1);
    Rainhas tabuleiro2("tabuleiros/teste2.txt");
    REQUIRE(tabuleiro2.verifica() == -1);
    Rainhas tabuleiro3("tabuleiros/teste3.txt");
    REQUIRE(tabuleiro3.verifica() == -1);
    Rainhas tabuleiro4("tabuleiros/teste4.txt");
    REQUIRE(tabuleiro4.verifica() == -1);
}

TEST_CASE("Verifica tabuleiros que são uma solução para o problema", "[tabuleiros]") {
    Rainhas tabuleiro5("tabuleiros/teste5.txt"); 
    REQUIRE(tabuleiro5.verifica() == 1);
    Rainhas tabuleiro6("tabuleiros/teste6.txt");
    REQUIRE(tabuleiro6.verifica() == 1);
    Rainhas tabuleiro7("tabuleiros/teste7.txt");	
    REQUIRE(tabuleiro7.verifica() == 1);
    Rainhas tabuleiro8("tabuleiros/teste8.txt");
    REQUIRE(tabuleiro8.verifica() == 1);
    Rainhas tabuleiro9("tabuleiros/teste9.txt");
    REQUIRE(tabuleiro9.verifica() == 1);
    Rainhas tabuleiro10("tabuleiros/teste10.txt");
    REQUIRE(tabuleiro10.verifica() == 1);
}

TEST_CASE("Verifica tabuleiros que não são uma solução para o problema", "[tabuleiros]") {
    Rainhas tabuleiroProfessor("teste_8_rainhas.txt"); 
    REQUIRE(tabuleiroProfessor.verifica() == 0);
    Rainhas tabuleiro11("tabuleiros/teste11.txt"); 
    REQUIRE(tabuleiro11.verifica() == 0);
    Rainhas tabuleiro12("tabuleiros/teste12.txt");
    REQUIRE(tabuleiro12.verifica() == 0);
}