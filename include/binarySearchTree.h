#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <iostream> // st::cout, std::cin, std::endl
#include <string>  // std::string

namespace bst {  // binary search tree

/**
 * @brief A class representing a binary search tree.
 *
 * @tparam DataType Type of data the container will store.
 * @tparam KeyType Type of key the container will store.
 */
template <typename DataType, typename KeyType>
class BinarySearchTree {
   private:
    //=== The data node.
    struct Node {
        DataType data;  //!< Information to be stored in the container.
        KeyType key;    //!< Key to my Nome.
        Node* left;     //!< Pointer to left Node.
        Node* right;    //!< Pointer to right Node.

        Node(const DataType& _data = DataType{}, const KeyType& _key = KeyType{}, Node* l = nullptr, Node* r = nullptr)
            : data{_data}, key{_key}, left{l}, right{r} {}
    };

   public:
    //=== Some aliases to help writing a clearer code.
    using DataReference = DataType&;             //!< reference to the data value.
    using DataConstReference = const DataType&;  //!< const reference to the data value.
    using KeyReference = KeyType&;               //!< reference to the key value.
    using KeyConstReference = const KeyType&;    //!< const reference to the key value.

   //=== Private members.
   private:
    Node* raw_pointer;

    /**
     * @brief 
     * 
     * @param _key 
     * @param pointerFather 
     * @param controlVariable 
     */
    void search(KeyConstReference _key, Node* pointerSon, int& controlVariable) {
        Node* pointerFather = nullptr;
        int position = 0;

        search(_key, pointerFather, pointerSon, position, controlVariable);
    }

    /**
     * @brief 
     * 
     * @param pointer 
     * @return Node* 
     */
    Node* findGreatestElement(Node* pointer) {
        if (pointer == nullptr) {
            return nullptr;
        }
        else if (pointer->right == nullptr) {
            return pointer;
        }
        else {
            return findGreatestElement(pointer->right);
        }
    }

   //=== Public interface
   public:

    //=== Constructors and Destructors
    BinarySearchTree(void) : raw_pointer{nullptr} {}
    BinarySearchTree(DataConstReference _data, KeyConstReference _key)
        : BinarySearchTree() { raw_pointer = new Node(_data, _key); }
    ~BinarySearchTree(void) {}

    //=== Methods Modifiers

    /**
     * @brief 
     * 
     * @param _key 
     * @param pointerFather 
     * @param pointerSon 
     * @param position 
     * @param controlVariable 
     * @param isSonLeft 
     */
    void search(KeyConstReference _key, Node* pointerFather, Node* pointerSon,
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
                    search(_key, pointerFather, pointerSon, position, controlVariable);
                }
            }
        }
    }

    /**
     * @brief 
     * 
     * @param _data 
     * @param _key 
     */
    void insert(DataConstReference _data, KeyConstReference _key) {
        Node* pointerFather = raw_pointer;
        int controlVariable = -1;

        search(_key, pointerFather, controlVariable);

        if (controlVariable != 1 || controlVariable != -1) {
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

    /**
     * @brief 
     * 
     * @param _data 
     * @param _key 
     */
    void remove(DataConstReference _data, KeyConstReference _key) {
        Node* pointerFather = nullptr;
        Node* pointerSon = raw_pointer;

        int controlVariable = -1;
        bool isSonLeft = false;
        int position;

        search(_key, pointerFather, pointerSon, position, controlVariable, isSonLeft);

        if (controlVariable == 1 && pointerSon != nullptr) {
            const bool sonHasEmptyLeftSubTree = pointerSon->left == nullptr;
            const bool sonHasEmptyRightSubTree = pointerSon->right == nullptr;

            const bool sonIsLeft = pointerFather->left == pointerSon;

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

    /**
     * @brief 
     */
    void clear(void) {}

    //=== Methods Acess

    /**
     * @brief 
     * 
     * @return DataType 
     */
    DataType median(void) {}

    /**
     * @brief 
     * 
     * @param _key 
     * @return int 
     */
    int findPositionOfElement(KeyConstReference _key) {
        // int temp = simetric(tree, _data, 0);
        // if (temp == 0) {
        //     std::cout << "Element not found!" << endl;
        // } else {
        //     std::cout << "Element in position : " << temp << endl;
        // }
    }
    
    /**
     * @brief 
     * 
     * @param position 
     * @return DataType 
     */
    DataType elementInPosition(int position) {}
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool isComplete(void) {}
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool isFull(void) {}
    
    /**
     * @brief 
     * 
     * @return std::string 
     */
    std::string toString(void) {}
    
    /**
     * @brief 
     * 
     * @param source 
     * @param key 
     * @param iteration 
     * @return int 
     */
    int simetric(Node* source, KeyConstReference key, int iteration) {
        // if (source != NULL) {
        //     cout << "Value:" << source->data << endl;
        //     if (source->data == key) {
        //         return iteration;
        //     }
        //     iteration++;
        //     this->simetric(source->left, key, iteration);
        //     this->simetric(source->right, key, iteration);
        // }
        // return 0;
    }
};

}  // namespace bst

#endif  // _BINARY_SEARCH_TREE_H_