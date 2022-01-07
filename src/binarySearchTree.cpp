#include "../include/binarySearchTree.h"

namespace bst {

template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::binarySearchTree(void) : raw_pointer{nullptr} {}

template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::binarySearchTree(DataConstReference _data, KeyConstReference _key)
    : binarySearchTree() {
    raw_pointer = new node(_data, _key);
}

template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::~binarySearchTree(void) {}

template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::Node* binarySearchTree<DataType, KeyType>::insert(DataConstReference _data,
                                                                                       KeyConstReference _key) {}

template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::Node* binarySearchTree<DataType, KeyType>::remove(DataConstReference _data,
                                                                                       KeyConstReference _key) {}

template <typename DataType, typename KeyType>
void binarySearchTree<DataType, KeyType>::search(KeyConstReference _key, Node* pointerSon, int& controlVariable) {
    Node* pointerFather = nullptr;
    int position = 0;

    search(_key, pointerFather, pointerSon, position, controlVariable);
}

template <typename DataType, typename KeyType>
void binarySearchTree<DataType, KeyType>::search(KeyConstReference _key, Node* pointerFather, Node* pointerSon,
                                                 int& position, int& controlVariable) {
    if (pointerSon != nullptr) {
        if (pointerSon->key == _key) {
            controlVariable = 1;
        } else {
            if (_key < pointerSon->key) {
                if (pointerSon->left == nullptr) {
                    controlVariable = 2;
                } else {
                    pointerFather = pointerSon;
                    pointerSon = pointerSon->left;
                    position++;
                }
            } else {
                if (pointerSon->right == nullptr) {
                    controlVariable = 3;
                } else {
                    pointerFather = pointerSon;
                    pointerSon = pointerSon->right;
                    position++;
                }
            }
            if (controlVariable < 1) {
                search(_key, pointerFather, pointerSon, position, controlVariable);
            }
        }
    }
}

template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::Node* binarySearchTree<DataType, KeyType>::clear(void) {}

template <typename DataType, typename KeyType>
DataType binarySearchTree<DataType, KeyType>::median(void) {}

template <typename DataType, typename KeyType>
int binarySearchTree<DataType, KeyType>::findPositionOfElement(KeyConstReference _key) {
    int temp = simetric(tree, _data, 0);
    if (temp == 0) {
        cout << "Element not found!" << endl;
    } else {
        cout << "Element in position : " << temp << endl;
    }
}

template <typename DataType, typename KeyType>
DataType binarySearchTree<DataType, KeyType>::elementInPosition(int position) {}

template <typename DataType, typename KeyType>
bool binarySearchTree<DataType, KeyType>::isComplete(void) {}

template <typename DataType, typename KeyType>
bool binarySearchTree<DataType, KeyType>::isFull(void) {}

template <typename DataType, typename KeyType>
std::string binarySearchTree<DataType, KeyType>::toString(void) {}

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