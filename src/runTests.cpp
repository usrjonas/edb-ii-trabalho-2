#include <iostream>  // cout, cin, endl, cerr

#include "../include/binarySearchTree.h"
#include "../include/executor.h"

int main(int argc, char *argv[]) {
    // Validação inicial dos argumentos
    if (argv[1] == nullptr || argv[2] == nullptr) {
        std::cerr << "ERRO :: Argumentos com o caminho para os arquivos não foi especificado." << std::endl;
        exit(1);
    }

    // Declara a árvore binária e o executor de testes
    bst::BinarySearchTree<int, int> tree;
    Executor<int, int> executor(tree);

    // Inicia a execução
    std::string insertionFileName(argv[1]);
    std::string commandFileName(argv[2]);
    executor.start(insertionFileName, commandFileName);

    return 0;
}