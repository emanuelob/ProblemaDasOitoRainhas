# Problema das Oitos Rainhas

## Sobre o Projeto

Este projeto implementa um verificador de solução para o clássico problema das 8 rainhas, utilizando C++. O objetivo é posicionar 8 rainhas em um tabuleiro de xadrez 8x8 de forma que nenhuma delas possa atacar outra. A solução é baseada na leitura de um arquivo de entrada que define a disposição inicial (tabuleiro) das rainhas.

## Pré-requisitos

- C++
- Compiler compatível com C++ (GDB)
- Makefile para automação de compilação e execução de testes

## Instalação

1. Clone o repositório do projeto.
2. Certifique-se de ter o C++ instalado e configurado corretamente no seu ambiente.
3. Execute `make compile` para compilar o projeto.

## Execução

### Compilação

Execute o comando `make compile` para compilar os arquivos do projeto. Isso irá gerar o executável `testa_rainhas`.

### Execução dos Testes

Use o comando `make test` para executar os testes unitários. Isso irá rodar o executável `testa_rainhas` e mostrar os resultados dos testes.

### Verificação de Estilo

Utilize o comando `make cpplint` para verificar o estilo do código. Isso irá executar o cpplint nos arquivos especificados e reportar quaisquer problemas de estilo.

### Cobertura de Código

Use o comando `make gcov` ou `make gcovr` para gerar a cobertura de código. Isso irá compilar os arquivos com as flags necessárias para cobertura e executar o teste, gerando arquivos `.gcov` que mostram a cobertura de cada linha de código.

### Verificação Estática

Execute o comando `make cppcheck` para executar o cppcheck nos arquivos especificados. Isso irá reportar quaisquer problemas estáticos encontrados no código.

### Verificação Dinâmica

Use o comando `make valgrind` para executar o Valgrind no executável `testa_rainhas`. Isso irá verificar se há problemas dinâmicos.

### Limpeza

Execute o comando `make clean` para remover os arquivos gerados durante a compilação e execução dos testes.

## Resultados Esperados

Os testes cobertos devem retornar:
- 1 caso seja uma solução para o problema
- 0 caso não seja uma solução para o problema
- -1 caso a entrada não seja válida (exemplo: não é um tabuleiro 8x8, não tem 8 rainhas, não possui entrada binária, rainhas na mesma linha).

No caso de não ser uma solução para o problema, o programa salva um arquivo “ataques.txt” com as posições das rainhas que se atacam. Um ataque por linha, por exemplo: `1,3 4,3` (significa rainha na posição 1,3 (linha, coluna) ataca rainha na posição 4,3 (e vice-versa)).
Para este trabalho, foi gerado cada teste individualmente e colocado o arquivo ataques.txt correspondente na pasta "ataques".
