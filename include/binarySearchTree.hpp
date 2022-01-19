#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <iostream>  // st::cout, std::cin, std::endl
#include <queue>     // std::queue
#include <sstream>   // std::stringstream
#include <string>    // std::string
#include <vector>    // std::vector

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

    //=== Some aliases to help writing a clearer code.
   public:
    using DataReference = DataType&;             //!< reference to the data value.
    using DataConstReference = const DataType&;  //!< const reference to the data value.
    using KeyReference = KeyType&;               //!< reference to the key value.
    using KeyConstReference = const KeyType&;    //!< const reference to the key value.

    //=== Private members.
   private:
    Node* raw_pointer;

    //=== Auxiliaries Methods
    Node* freeNode(Node* node);
    Node* insert(Node* pointer, DataConstReference _data, KeyConstReference _key);
    Node* findGreatestElement(Node* pointer);
    void search(KeyConstReference _key, Node* pointerFather, Node* pointerSon, int& position, int& controlVariable,
                bool& isSonLeft);
    int simetric(Node* source, KeyConstReference key, int iteration);
    void simetricToMedian(Node* node, std::vector<Node*>& dados);
    void toStringPerLevel(Node* pointer, std::stringstream& ss);
    void toStringSorted(Node* pointer, std::stringstream& ss);

   public:
    //=== Public interface

    //=== Constructors and Destructors
    BinarySearchTree(void);
    BinarySearchTree(DataConstReference _data, KeyConstReference _key);
    ~BinarySearchTree(void);

    //=== Modifiers Methods
    void insert(DataConstReference _data, KeyConstReference _key);
    void remove(KeyConstReference _key);
    void search(KeyConstReference _key, Node* pointerFather, int& controlVariable);
    void clear(void);

    //=== Access Methods
    DataType elementInPosition(int position);
    int findPositionOfElement(KeyConstReference _key);
    DataType median(void);
    bool isComplete(void);
    bool isFull(void);
    std::string toString(std::string type);
    int simetric(Node* source, KeyConstReference key, int& iteration, int& var_controle);
};

}  // namespace bst

#include "binarySearchTree.inl"
#endif  // _BINARY_SEARCH_TREE_H_