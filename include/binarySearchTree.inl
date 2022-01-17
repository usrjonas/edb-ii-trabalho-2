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
BinarySearchTree<DataType, KeyType>::~BinarySearchTree(void) {
    raw_pointer = freeNode(raw_pointer);
}

template <typename DataType, typename KeyType>
typename BinarySearchTree<DataType, KeyType>::Node* BinarySearchTree<DataType, KeyType>::freeNode(Node* node) {
    if (node == nullptr) return nullptr;

    node->left = freeNode(node->left);
    node->right = freeNode(node->right);
    delete node;

    return nullptr;
}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::insert(DataConstReference _data, KeyConstReference _key) {
    raw_pointer = insert(raw_pointer, _data, _key);
}

template <typename DataType, typename KeyType>
typename BinarySearchTree<DataType, KeyType>::Node* BinarySearchTree<DataType, KeyType>::insert(
    Node* pointer, DataConstReference _data, KeyConstReference _key) {
    if (pointer == nullptr) {
        pointer = new Node(_data, _key);
        // pointer->data = _data;
        // pointer->key = _key;
        pointer->left = pointer->right = nullptr;
    }

    else if (_key < pointer->key)
        pointer->left = insert(pointer->left, _data, _key);

    else if (_key > pointer->key)
        pointer->right = insert(pointer->right, _data, _key);

    return pointer;
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
void BinarySearchTree<DataType, KeyType>::Run_order(Node* node, std::vector<Node*> &dados){
    if(node != nullptr){
        this->Run_order(node->left,dados);
        dados.push_back(node);
        this->Run_order(node->right,dados);
    }
}

template <typename DataType, typename KeyType>
DataType BinarySearchTree<DataType, KeyType>::median(void) {
    std::vector<Node*> elements;
    int median;
    Run_order(raw_pointer,elements);
    int vector_Size = elements.size();
    Node* k;
    for(int i = 0; i < vector_Size-1; i++){
        for(int j = 0;j-i-1; j++){
            if(elements[j] > elements[j+1]){
                Node* temp = elements[j];
                elements[j] = elements[j+1];
                elements[j+1] = temp;
            }
        }
    }
    if(vector_Size % 2 == 0){
        median = vector_Size / 2;
        return elements[median - 2]->data;
    }else{
        median = (vector_Size + 1) / 2;
        return elements[median-2]->data;
    }
}

template <typename DataType, typename KeyType>
int BinarySearchTree<DataType, KeyType>::findPositionOfElement(KeyConstReference _key) {
    int temp = simetric(raw_pointer, _key, 0);
    if (temp == 0) {
        throw(std::string("Element not found!"));
    } else {
        return temp;
    }
}

template <typename DataType, typename KeyType>
DataType BinarySearchTree<DataType, KeyType>::elementInPosition(int position) {}

template <typename DataType, typename KeyType>
bool BinarySearchTree<DataType, KeyType>::isComplete(void) {}

template <typename DataType, typename KeyType>
bool BinarySearchTree<DataType, KeyType>::isFull(void) {}

template <typename DataType, typename KeyType>
std::string BinarySearchTree<DataType, KeyType>::toString(void) {
    std::stringstream ss;
    toString(raw_pointer, ss);

    return ss.str();
}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::toString(Node* pointer, std::stringstream& ss) {
    if (pointer == nullptr) return;
    toString(pointer->left, ss);
    ss << pointer->data << " ";
    toString(pointer->right, ss);

    // std::queue<Node*> MyQueue; // fila ta vazia
    // std::string print_tree;

    // MyQueue.push(pointer); // 1 elemento da fila

    // while (!MyQueue.empty()) {
    //     pointer = MyQueue.front();
    //     MyQueue.pop(); // lista fica vazia

    //     print_tree += toString(pointer) + " ";
    //     if (pointer->left != nullptr) {
    //         MyQueue.push(pointer->left);
    //     }
    //     if (pointer->right != nullptr) {
    //         MyQueue.push(pointer->right);
    //     }
    // }

    // return print_tree.empty() ? "Empty tree" : print_tree;
}

template <typename DataType, typename KeyType>
int BinarySearchTree<DataType, KeyType>::simetric(Node* source, KeyConstReference key, int iteration) {
    if (source != NULL) {
        std::cout << "Value:" << source->data << std::endl;
        if (source->data == key) {
            return iteration;
        }
        iteration++;
        this->simetric(source->left, key, iteration);
        this->simetric(source->right, key, iteration);
    }
    return 0;
}

}  // namespace bst