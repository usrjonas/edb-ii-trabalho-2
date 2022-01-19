#include "binarySearchTree.hpp"

namespace bst {

/*****************************************************************************
 * Constructors and Destructors
 ****************************************************************************/

template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::BinarySearchTree(void) : raw_pointer{nullptr}, height{0} {}

template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::BinarySearchTree(DataConstReference _data, KeyConstReference _key)
    : BinarySearchTree() {
    raw_pointer = new Node(_data, _key);
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
BinarySearchTree<DataType, KeyType>::~BinarySearchTree(void) {
    raw_pointer = freeNode(raw_pointer);
    height = 0;
}

/*****************************************************************************
 * Modifiers Methods (insert, remove, search and clear)
 ****************************************************************************/

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::insert(DataConstReference _data, KeyConstReference _key) {
    raw_pointer = insert(raw_pointer, _data, _key);
    height = get_height(raw_pointer);
}

template <typename DataType, typename KeyType>
typename BinarySearchTree<DataType, KeyType>::Node* BinarySearchTree<DataType, KeyType>::insert(
    Node* pointer, DataConstReference _data, KeyConstReference _key) {
    if (pointer == nullptr) {
        pointer = new Node(_data, _key);
        pointer->left = pointer->right = nullptr;
    } else if (_key < pointer->key) {
        pointer->left = insert(pointer->left, _data, _key);
    } else if (_key > pointer->key) {
        pointer->right = insert(pointer->right, _data, _key);
    }
    return pointer;
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

    height = get_height(raw_pointer);
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

/*****************************************************************************
 * Access Methods
 ****************************************************************************/

template <typename DataType, typename KeyType>
DataType BinarySearchTree<DataType, KeyType>::elementInPosition(int position) {}

template <typename DataType, typename KeyType>
int BinarySearchTree<DataType, KeyType>::simetric(Node* source, KeyConstReference key, int& iteration,
                                                  int& var_controle) {
    if (source == nullptr) {
        return 0;
    }
    if (source->data == key) {
        var_controle++;
        return iteration;
    }
    if (source->left != nullptr) {
        this->simetric(source->left, key, iteration, var_controle);
    }
    if (var_controle == 0) {
        iteration++;
    }
    if (source->right != nullptr) {
        this->simetric(source->right, key, iteration, var_controle);
    }
    return 0;
}

template <typename DataType, typename KeyType>
int BinarySearchTree<DataType, KeyType>::findPositionOfElement(KeyConstReference _key) {
    int position = 1, var_controle = 0;
    simetric(raw_pointer, _key, position, var_controle);
    if (var_controle == 0) {
        std::cout << "Elemento nao encontrado" << std::endl;
        throw(std::string("Element not found!"));
    } else {
        return position;
    }
}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::simetricToMedian(Node* node, std::vector<Node*>& dados) {
    if (node != nullptr) {
        this->simetricToMedian(node->left, dados);
        dados.push_back(node);
        this->simetricToMedian(node->right, dados);
    }
}

template <typename DataType, typename KeyType>
DataType BinarySearchTree<DataType, KeyType>::median(void) {
    // Retrieve all ABB elements by pre-order
    std::vector<Node*> elements;
    simetricToMedian(raw_pointer, elements);
    int vector_size = elements.size();

    /* Median calculation depends on whether
    ABB has an odd or even number of elements */
    int median_ind;
    if (vector_size % 2 == 0) {
        median_ind = (vector_size / 2) - 1;
        return elements[median_ind]->data;
    } else {
        median_ind = vector_size / 2;
        return elements[median_ind]->data;
    }
}

template <typename DataType, typename KeyType>
int BinarySearchTree<DataType, KeyType>::nodesOnLevel(Node* _pt, int current_level, int level) {
    if (current_level == level) {
        return (_pt == nullptr) ? 0 : 1;
    }
    else if (level > 0) {
        int nodes_left = nodesOnLevel(_pt->left, current_level + 1, level);
        int node_right = nodesOnLevel(_pt->right, current_level + 1, level);
        return nodes_left + node_right;
    }
}

template <typename DataType, typename KeyType>
bool BinarySearchTree<DataType, KeyType>::isComplete(void) {
    // std::cout << "ALTURA: " << height << std::endl << std::endl;

    for (int level = 0; level < height-1; level++) {
        // std::cout << "Nível: " << level+1 << std::endl;
        // std::cout << "Número de nós = " << nodesOnLevel(raw_pointer, 0, level) << std::endl;
        // std::cout << "2^{" << level+1 << "-1} = " << std::pow(2, level) << std::endl << std::endl;
        if (nodesOnLevel(raw_pointer, 0, level) != std::pow(2, level)) {
            return false;
        }
    }

    return true;
}

template <typename DataType, typename KeyType>
int BinarySearchTree<DataType, KeyType>::get_height(Node* _pt) {
    if (_pt == nullptr) {
        return 0;
    }
    else {
        // Calculates the height of each subtree
        int left_height = get_height(_pt->left);
        int right_height = get_height(_pt->right);

        // Returns the highest height between the subtrees
        if (left_height > right_height) {
            return (left_height + 1);
        }
        else {
            return (right_height + 1);
        }
    }
}

template <typename DataType, typename KeyType>
bool BinarySearchTree<DataType, KeyType>::isFull(void) {}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::toStringHierarchical(const Node* node, bool isLeft,
                                std::stringstream& ss, const std::string& prefix) {
    if (node != nullptr) {
        ss << prefix;
        ss << (isLeft ? "├──" : "└──" );

        // print the value of the node
        ss << node->data << std::endl;

        // enter the next tree level - left and right branch
        toStringHierarchical(node->left, true, ss, prefix + (isLeft ? "│   " : "    "));
        toStringHierarchical(node->right, false, ss, prefix + (isLeft ? "│   " : "    "));
    }
}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::toStringHierarchical(Node* pointer, std::stringstream& ss) {
    ss << std::endl << std::endl;
    toStringHierarchical(pointer, false, ss, "");
}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::toStringSorted(Node* pointer, std::stringstream& ss) {
    if (pointer == nullptr) return;
    toStringSorted(pointer->left, ss);
    ss << pointer->data << " ";
    toStringSorted(pointer->right, ss);
}

template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::toStringPerLevel(Node* pointer, std::stringstream& ss) {
    std::queue<Node*> elements_per_level;  // queue is empty

    // Base Case
    if (pointer == nullptr) {
        return;
    } else {
        elements_per_level.push(pointer);  // add root node to queue
    }

    while (!elements_per_level.empty()) {
        // Add the front of queue to ss and remove it from queue
        Node* current_node = elements_per_level.front();
        ss << current_node->data << " ";
        elements_per_level.pop();

        // Put the children in queue
        if (current_node->left != nullptr) {
            elements_per_level.push(current_node->left);
        }
        if (current_node->right != nullptr) {
            elements_per_level.push(current_node->right);
        }
    }
}

template <typename DataType, typename KeyType>
std::string BinarySearchTree<DataType, KeyType>::toString(std::string type) {
    std::stringstream ss;
    if (type == "EM NIVEL") {
        toStringPerLevel(raw_pointer, ss);
    } else if (type == "SIMETRICA") {
        toStringSorted(raw_pointer, ss);
    } else if (type == "HIERARQUICA") {
        toStringHierarchical(raw_pointer, ss);
    }

    // If the tree has no elements
    if (ss.str().empty()) {
        return "Árvore vazia";
    } else {
        return ss.str();
    }
}

}  // namespace bst