#include "../include/binarySearchTree.h"

namespace bst {

// TODO: Fazer documentação doxygen
template <typename DataType>
binarySearchTree<DataType>::binarySearchTree(void) : raw_pointer{nullptr} {}

// TODO: Fazer documentação doxygen
template <typename DataType>
binarySearchTree<DataType>::binarySearchTree(ConstReference _data) : binarySearchTree() {
    raw_pointer = new node(_data);
}

// TODO: Fazer documentação doxygen
template <typename DataType>
binarySearchTree<DataType>::~binarySearchTree(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType>
binarySearchTree<DataType>::Node* binarySearchTree<DataType>::insert(ConstReference _data) {}

// TODO: Fazer documentação doxygen
template <typename DataType>
binarySearchTree<DataType>::Node* binarySearchTree<DataType>::remove(ConstReference _data) {}

// TODO: Fazer documentação doxygen
template <typename DataType>
binarySearchTree<DataType>::Node* binarySearchTree<DataType>::clear(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType>
DataType binarySearchTree<DataType>::median(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType>
int binarySearchTree<DataType>::findPositionOfElement(ConstReference _data) {
    int temp = simetric(tree, _data, 0);
    if(temp == 0){
        cout << "Element not found!" << endl;
    }else{
        cout << "Element in position : " << temp << endl;
    }
}

// TODO: Fazer documentação doxygen
template <typename DataType>
DataType binarySearchTree<DataType>::elementInPosition(int position) {}

// TODO: Fazer documentação doxygen
template <typename DataType>
bool binarySearchTree<DataType>::isComplete(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType>
bool binarySearchTree<DataType>::isFull(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType>
std::string binarySearchTree<DataType>::toString(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType>
int binarySearchTree<DataType>::simetric(Node *source, DataType key, int iteration) {
    if(source != NULL){
        cout << "Value:" << source->data << endl;
        if(source->data == key){
            return iteration;
        }
        iteration++
        this->simetric(source->left, key, iteration);
        this->simetric(source->right, key, iteration);
    }
    return 0;
}

}  // namespace bst