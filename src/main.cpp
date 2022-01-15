#include <time.h>

#include <iostream>
#include <random>

#include "../include/binarySearchTree.h"
// Função para preencher a árvore aleatoriamente, passando uma árvore, e quantos elementos terão essa árvore.
template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::BinarySearchTree Random_Fill(
    BinarySearchTree<DataType, KeyType>::BinarySearchTree tree, int times) {
    srand(time(NULL));
    for (int i = 0; i < times; i++) {
        int randomValue = rand() % 100 tree.insert(randomValue);
    }
    return tree;
}
// Preenche a árvore baseado em um vetor de valores inteiros.
template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::BinarySearchTree Fill(BinarySearchTree<DataType, KeyType>::BinarySearchTree tree,
                                                           int x, int entry[x]) {
    for (int i = 0; i < x; i++) {
        tree.insert(entry[x]);
    }
}
// Testa se o método inserção está funcionando corretamente. Atente para o tipo de vetor que será utilizado, se será o
// 'values1', '2' ou '3'. Sendo esse o último parâmetro. Obs.: Essa função insere apenas o valor >>30<<, se atente para
// esse valor, em cada vetor de valores ele tem uma posição diferente.
template <typename DataType, typename KeyType>
void Insert_Test(BinarySearchTree<DataType, KeyType>::BinarySearchTree tree, int key, int type) {
    tree.insert(30);
    cout << "Saída do método: ";
    tree.toString();
    cout << endl;
    if (type == 1) {
        cout << "Saída esperada: 50 35 70 25 40 65 90 30 80" << endl;
    } else if (type == 2) {
        cout << "Saída esperada: 35 30 40 25 32 38 45" << endl;
    } else {
        cout << "Saída esperada: 20 15 30 10 18 90 8 11 17 19 80 95" << endl;
    }
}
// Teste de remoção. Note que não há saída esperada. Atente para o que será impresso.
template <typename DataType, typename KeyType>
void Remove_Test(BinarySearchTree<DataType, KeyType>::BinarySearchTree tree, int x) {
    tree.remove(x);
    cout << "Saída do método: ";
    tree.toString();
}
// Atenção, esse método precisa estar funcionando corretamente para que os outros teste funcionem.
// Obs.: Todas as impressões são feitas por nível.
template <typename DataType, typename KeyType>
void toString_test(BinarySearchTree<DataType, KeyType>::BinarySearchTree tree, int type) {
    cout << "Saída do método: ";
    tree.toString();
    if (type == 1) {
        cout << "Saída esperada: 50 35 70 25 40 65 90 80" << endl;
    } else if (type == 2) {
        cout << "Saída esperada: 35 30 40 25 32 38 45" << endl;
    } else {
        cout << "Saída esperada: 20 15 90 10 18 80 95 8 11 17 19" << endl;
    }
}
using namespace std;
int main(void) {
    /*
     Todas os teste utilizam a impressão por nível: toString();
    */
    template <typename DataType, typename KeyType>
    BinarySearchTree<DataType, KeyType>::BinarySearchTree tree = new BinarySearchTree();
    std::cout << "Hello, World!" << std::endl;
    int values1[10] = {25, 35, 40, 50, 65, 70, 80, 90};         // Vetor de teste 1
    int values2[10] = {25, , 32, 35, 38, 40, 45};               // Vetor de teste 2
    int values3[10] = {8, 10, 11, 15, 17, 18, 19, 20, 80, 90};  // Vetor de teste 3
    return 0;
}