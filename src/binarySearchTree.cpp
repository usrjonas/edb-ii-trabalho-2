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
int binarySearchTree<DataType>::findPositionOfElement(ConstReference _data) {}

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

}  // namespace bst