#include "../include/binarySearchTree.h"

namespace bst {

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::binarySearchTree(void) : raw_pointer{nullptr} {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::binarySearchTree(DataConstReference _data, KeyConstReference _key)
    : binarySearchTree() {
    raw_pointer = new node(_data, _key);
}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::~binarySearchTree(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::Node* binarySearchTree<DataType, KeyType>::insert(DataConstReference _data,
                                                                                       KeyConstReference _key) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::Node* binarySearchTree<DataType, KeyType>::remove(DataConstReference _data,
                                                                                       KeyConstReference _key) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::Node* binarySearchTree<DataType, KeyType>::clear(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
DataType binarySearchTree<DataType, KeyType>::median(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
int binarySearchTree<DataType, KeyType>::findPositionOfElement(KeyConstReference _key) {
    int temp = simetric(tree, _data, 0);
    if (temp == 0) {
        cout << "Element not found!" << endl;
    } else {
        cout << "Element in position : " << temp << endl;
    }
}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
DataType binarySearchTree<DataType, KeyType>::elementInPosition(int position) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
bool binarySearchTree<DataType, KeyType>::isComplete(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
bool binarySearchTree<DataType, KeyType>::isFull(void) {
    return isStrictlyBinaryTree(raw_pointer) && isComplete();
}

template <typename DataType, typename KeyType>
bool binarySearchTree<DataType, KeyType>::isStrictlyBinaryTree(Node* _pt) {
    if (_pt == nullptr) {
        return true;
    }
    else if (_pt->left == nullptr && _pt->right == nullptr) {
        return true;
    }
    else if (_pt->left != nullptr && _pt->right != nullptr) {
        return isStrictlyBinaryTree(_pt->left) && isStrictlyBinaryTree(_pt->right);
    }
    else {
        return false;
    }
}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
std::string binarySearchTree<DataType, KeyType>::toString(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
int binarySearchTree<DataType, KeyType>::simetric(Node* source, KeyConstReference key, int iteration) {
    if (source != NULL) {
        cout << "Value:" << source->data << endl;
        if (source->data == key) {
            return iteration;
        }
        iteration++ this->simetric(source->left, key, iteration);
        this->simetric(source->right, key, iteration);
    }
    return 0;
}

}  // namespace bst