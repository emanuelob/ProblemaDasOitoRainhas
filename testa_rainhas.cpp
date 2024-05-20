#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainhas.hpp"

/**
 * @file testa_rainhas.cpp
 * Testes unitários para a classe Rainhas.
 */

/**
 * Test case para verificar tabuleiros que não são válidos.
 *
 * Este teste verifica se a função verifica() retorna -1 para tabuleiros que não são válidos,
 * ou seja, tabuleiros que violam o formato e as regras do problema das 8 rainhas (disposição das entradas).
 */
TEST_CASE("Verifica tabuleiros que não são válidos", "[tabuleiros]") {
    Rainhas tabuleiro("tabuleiros/teste1.txt");
    REQUIRE(tabuleiro.verifica() == -1);
    Rainhas tabuleiro2("tabuleiros/teste2.txt");
    REQUIRE(tabuleiro2.verifica() == -1);
    Rainhas tabuleiro3("tabuleiros/teste3.txt");
    REQUIRE(tabuleiro3.verifica() == -1);
    Rainhas tabuleiro4("tabuleiros/teste4.txt");
    REQUIRE(tabuleiro4.verifica() == -1);
    Rainhas tabuleiro21("tabuleiros/teste21.txt");
    REQUIRE(tabuleiro21.verifica() == -1);
    Rainhas tabuleiro23("tabuleiros/teste23.txt");
    REQUIRE(tabuleiro23.verifica() == -1);
    Rainhas tabuleiro24("tabuleiros/teste24.txt");
    REQUIRE(tabuleiro24.verifica() == -1);
    Rainhas tabuleiro26("tabuleiros/teste26.txt");
    REQUIRE(tabuleiro26.verifica() == -1);
    Rainhas tabuleiro30("tabuleiros/teste30.txt");
    REQUIRE(tabuleiro30.verifica() == -1);
}

/**
 * Test case para verificar tabuleiros que são uma solução para o problema.
 *
 * Este teste confere se a função verifica() retorna 1 para tabuleiros que são válidos,
 * ou seja, tabuleiros cujas soluções satisfazem o problema das 8 rainhas. 
 * Nessa, a disposição do tabuleiro é válida e nenhuma rainha pode atacar outra.
 */
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
    Rainhas tabuleiro25("tabuleiros/teste25.txt");
    REQUIRE(tabuleiro25.verifica() == 1);
    Rainhas tabuleiro27("tabuleiros/teste27.txt");
    REQUIRE(tabuleiro27.verifica() == 1);
    Rainhas tabuleiro28("tabuleiros/teste28.txt");
    REQUIRE(tabuleiro28.verifica() == 1);
    Rainhas tabuleiro29("tabuleiros/teste29.txt");
    REQUIRE(tabuleiro29.verifica() == 1);
}

/**
 * Test case para verificar tabuleiros que não são uma solução para o problema das 8 rainhas.
 *
 * Este teste confere se a função verifica() retorna 0 para tabuleiros que não possuem soluções válidos,
 * ou seja, tabuleiros que possuem formatação correta mas não satisfazem 
 * as regras do problema das 8 rainhas (em algum momento as rainhas se atacam).
 * Além disso, gera o arquivo ataques.txt correspondente aos ataques.
 */
TEST_CASE("Verifica tabuleiros que não são uma solução para o problema", "[tabuleiros]") {
    Rainhas tabuleiro11("tabuleiros/teste11.txt");
    REQUIRE(tabuleiro11.verifica() == 0);
    Rainhas tabuleiro12("tabuleiros/teste12.txt");
    REQUIRE(tabuleiro12.verifica() == 0);
    Rainhas tabuleiro13("tabuleiros/teste13.txt");
    REQUIRE(tabuleiro13.verifica() == 0);
    Rainhas tabuleiro14("tabuleiros/teste14.txt");
    REQUIRE(tabuleiro14.verifica() == 0);
    Rainhas tabuleiro15("tabuleiros/teste15.txt");
    REQUIRE(tabuleiro15.verifica() == 0);
    Rainhas tabuleiro16("tabuleiros/teste16.txt");
    REQUIRE(tabuleiro16.verifica() == 0);
    Rainhas tabuleiro17("tabuleiros/teste17.txt");
    REQUIRE(tabuleiro17.verifica() == 0);
    Rainhas tabuleiro18("tabuleiros/teste18.txt");
    REQUIRE(tabuleiro18.verifica() == 0);
    Rainhas tabuleiro19("tabuleiros/teste19.txt");
    REQUIRE(tabuleiro19.verifica() == 0);
    Rainhas tabuleiro20("tabuleiros/teste20.txt");
    REQUIRE(tabuleiro20.verifica() == 0);
    Rainhas tabuleiro22("tabuleiros/teste22.txt");  // teste_8_rainhas.txt
    REQUIRE(tabuleiro22.verifica() == 0);
}
