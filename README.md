# Implementação de uma Árvore Binária de Busca (ABB)

Neste projeto foi implementado uma estrutura de dados do tipo **Árvore Binária de Busca (ABB)**.

Além das três operações básicas de inserção, remoção e busca, a árvore deveria possuir mais seis métodos para tornar a estrutura mais completa.

Este projeto foi realizado durante o período 2021.2 do Bacharelado em Tecnologia da Informação (BTI) da Universidade Federal do Rio Grande do Norte (UFRN).

## ⏯️ Compilação e Execução

### ⚒️ Ferramentas

O trabalho foi implementado na linguagem de programação C++. Portanto, para rodar o trabalho, deve-se ter instalado em sua máquina o `GCC (GNU Compiler Collection)` a partir da versão 4.0, pois inclui suporte ao C++ através do `g++`.

Logo, para instalar o compilador em sistemas Unix-like, como o Ubuntu, basta digitar um dos seguintes comandos no terminal (mais recomendado o primeiro):
```console
sudo apt install g++
sudo apt install gcc
```

### Compilação

Para compilar o projeto, entre na pasta do projeto e execute o comando de compilação na pasta raiz do projeto:
```sh
# Entrar na pasta raiz do projeto
cd edb-ii-trabalho-2/

# Compilar o projeto
g++ -std=c++11 src/runTests.cpp -I include/ -o build/runTests
```

### Execução

Para execução do projeto devem ser passados dois arquivos como argumentos:
- O primeiro, chamado de **arquivo de entrada**, deve ser uma sequência de valores inteiros separados por um espaço, de modo que não tenha espaços ou linhas extras no final e no início do arquivo. Esses valores informados vão ser inseridos sequencialmente na árvore.
Por exemplo:
>51 54 68 57 26 34 85 65 25 84

Ademais, montamos um arquivo de inserção localizado em: `data/insertionFiles/insertion.txt`.
- O segundo, chamado de **arquivo de comandos**, contém uma sequência de operações (uma operação por linha) a serem realizadas pelo seu árvore binária de busca.
O arquivo de comando poderá utilizar as operações a seguir:
    ```
    ENESIMO N
    POSICAO N
    MEDIANA
    CHEIA
    COMPLETA
    IMPRIMA
    REMOVA N
    INSIRA N
    QUIT
    ```
Sendo 'N' um número inteiro.
O `QUIT`, é um comando que não foi requerido pela docente, mas achamos válido implementá-lo. Ele marca até qual comando você deseja que seja executado os testes. Por exemplo:

```sh
# Comandos "COMPLETA" e "POSICAO 6" não são executados
IMPRIMA
ENESIMO 4
MEDIANA
QUIT
COMPLETA
POSICAO 6
```
Nesse caso os comandos abaixo do `QUIT` (`COMPLETA` e `POSICAO`) não serão executados.

O arquivo de entrada deve ser colocado na pasta `data/insertionFiles` e o arquivo de comandos em `data/commandFiles`. Após colocado os arquivos, o projeto pode ser executado através do comando:
```
./build/runTests data/insertionFiles/<arquivo_de_entrada> data/commandFiles/<arquivo_de_comandos>
```