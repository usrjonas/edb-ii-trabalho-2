#include <iostream>
#include "../include/binarySearchTree.h"
#include <random>
#include <time.h>

template <typename DataType>
binarySearchTree<DataType> Fill(binarySearchTree tree, int times){
    srand(time(NULL));
    for(int i = 0; i < times; i++){
        int randomValue = rand()%100
        tree.insert(randomValue);
    }
    return tree;
}

using namespace std;
int main(void){
    binarySearchTree tree = new binarySearchTree();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}