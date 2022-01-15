#include "binarySearchTree.hpp"

namespace bst {

template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::BinarySearchTree(void) : raw_pointer{nullptr} {}

template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::BinarySearchTree(DataConstReference _data, KeyConstReference _key)
    : BinarySearchTree() {
    raw_pointer = new Node(_data, _key);
}

template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::~BinarySearchTree(void) {}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::insert(DataConstReference _data, KeyConstReference _key) {
    Node* pointerFather = raw_pointer;
    int controlVariable = -1;

    search(_key, pointerFather, controlVariable);

    if (controlVariable != 1 && controlVariable != -1) {
        Node* pointerSon = new Node(_data, _key);
        if (!controlVariable)
            raw_pointer = pointerSon;
        else {
            if (controlVariable == 2) {
                pointerFather->left = pointerSon;

            } else {
                pointerFather->right = pointerSon;
            }
        }
    }
}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::remove(KeyConstReference _key) {
    Node* pointerFather = nullptr;
    Node* pointerSon = raw_pointer;

    int controlVariable = -1;
    bool isSonLeft = false;
    int position;

    search(_key, pointerFather, pointerSon, position, controlVariable, isSonLeft);

    if (controlVariable == 1 && pointerSon != nullptr) {
        const bool sonHasEmptyLeftSubTree = pointerSon->left == nullptr;
        const bool sonHasEmptyRightSubTree = pointerSon->right == nullptr;

        const bool isSonLeft = pointerFather->left == pointerSon;

        if (sonHasEmptyLeftSubTree && sonHasEmptyRightSubTree) {
            if (pointerFather == nullptr) {
                raw_pointer = nullptr;
            } else if (isSonLeft) {
                pointerFather->left = nullptr;
            } else {
                pointerFather->right = nullptr;
            }
        } else if (sonHasEmptyLeftSubTree) {
            if (pointerFather == nullptr) {
                raw_pointer = pointerSon->right;
            } else if (isSonLeft) {
                pointerFather->left = pointerSon->right;
            } else {
                pointerFather->right = pointerSon->right;
            }
        } else if (sonHasEmptyRightSubTree) {
            if (pointerFather == nullptr) {
                raw_pointer = pointerSon->left;
            } else if (isSonLeft) {
                pointerFather->left = pointerSon->left;
            } else {
                pointerFather->right = pointerSon->left;
            }
        } else {
            Node* pointerGreatestLeftElement = findGreatestElement(pointerSon->left);

            pointerSon->key = pointerGreatestLeftElement->key;
            pointerSon->data = pointerGreatestLeftElement->data;

            pointerSon = pointerGreatestLeftElement;
        }

        delete pointerSon;
    }
}

template <typename DataType, typename KeyType>
typename BinarySearchTree<DataType, KeyType>::Node* BinarySearchTree<DataType, KeyType>::findGreatestElement(
    Node* pointer) {
    if (pointer == nullptr)
        return nullptr;
    else if (pointer->right == nullptr)
        return pointer;
    else
        return findGreatestElement(pointer->right);
}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::search(KeyConstReference _key, Node* pointerSon, int& controlVariable) {
    Node* pointerFather = nullptr;
    int position = 0;
    bool isSonLeft = true;

    search(_key, pointerFather, pointerSon, position, controlVariable, isSonLeft);
}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::search(KeyConstReference _key, Node* pointerFather, Node* pointerSon,
                                                 int& position, int& controlVariable, bool& isSonLeft) {
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
                    isSonLeft = true;
                    position++;
                }
            } else {
                if (pointerSon->right == nullptr) {
                    controlVariable = 3;
                } else {
                    pointerFather = pointerSon;
                    pointerSon = pointerSon->right;
                    isSonLeft = false;
                    position++;
                }
            }
            if (controlVariable < 1) {
                search(_key, pointerFather, pointerSon, position, controlVariable, isSonLeft);
            }
        }
    }
}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::clear(void) {}

template <typename DataType, typename KeyType>
DataType BinarySearchTree<DataType, KeyType>::median(void) {
    vector<int> elements;
    int control, median;
    if (raw_pointer != nullptr) {
        this->Pre_order(raw_pointer->left);
        elements.push_back(raw_pointer);
        this->Pre_order(raw_pointer->right);
    }
    int vector_Size = elements.size();
    int j, k;
    for (int i = 2; i <= vector_Size; i++) {
        k = elements[i];
        j = i - 1;
        elements[0] = k;
        while (k < elements[j]) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = k;
    }
    if (vector_Size % 2 == 0) {
        median = vector_Size / 2;
        return elements[median - 1];
    } else {
        median = (vector_Size + 1) / 2;
        return elements[median];
    }
}

template <typename DataType, typename KeyType>
int BinarySearchTree<DataType, KeyType>::findPositionOfElement(KeyConstReference _key) {
    //  int temp = simetric(tree, _data, 0);
    //  if (temp == 0) {
    //      std::cout << "Element not found!" << endl;
    //  } else {
    //      std::cout << "Element in position : " << temp << endl;
    //  }
}

template <typename DataType, typename KeyType>
DataType BinarySearchTree<DataType, KeyType>::elementInPosition(int position) {}

template <typename DataType, typename KeyType>
bool BinarySearchTree<DataType, KeyType>::isComplete(void) {}

template <typename DataType, typename KeyType>
bool BinarySearchTree<DataType, KeyType>::isFull(void) {}

template <typename DataType, typename KeyType>
std::string BinarySearchTree<DataType, KeyType>::toString(void) {
    queue<DataType> MyQueue;
    Node* node = raw_pointer;
    string print_tree;
    MyQueue.push(node);
    if (!MyQueue.Empty) {
        while (!MyQueue.Empty) {
            node = MyQueue.pop();  // try 'front'
            print_tree += toString(node->data) + " ";
            if (node->left != nullptr) {
                MyQueue.push(node->left);
            }
            if (node->right != nullptr) {
                MyQueue.push(node->right);
            }
            return print_tree;
        }
    } else {
        return "Empty tree"
    }
}

/* template <typename DataType, typename KeyType>
int BinarySearchTree<DataType, KeyType>::simetric(Node* source, KeyConstReference key, int iteration) {
    if (source != NULL) {
        cout << "Value:" << source->data << endl;
        if (source->data == key) {
            return iteration;
        }
        iteration++;
        this->simetric(source->left, key, iteration);
        this->simetric(source->right, key, iteration);
    }
    return 0;
} */

}  // namespace bst