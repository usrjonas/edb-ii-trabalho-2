#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <string>  // std::string

namespace bst {  // binary search tree

/**
 * @brief A class representing a binary search tree.
 *
 * @tparam DataType Type of data the container will store.
 */
template <typename DataType>
class binarySearchTree {
   private:
    //=== The data node.
    struct Node {
        DataType data;  //!< Type of information to be stored in the container.
        Node* left;     //!< Pointer to left Node.
        Node* rigth;    //!< Pointer to rigth Node.

        Node(const DataType& _data = DataType{}, Node* n = nullptr, Node* p = nullptr) : data{_data} {}
    };

    //=== Some aliases to help writing a clearer code.
   public:
    using Reference = DataType&;             //!< reference to the value.
    using ConstReference = const DataType&;  //!< const reference to the value.

    //=== Private members.
   private:
    Node* raw_pointer;

   public:
    //=== Public interface

    //=== Constructors and Destructors
    binarySearchTree(void);
    binarySearchTree(ConstReference _data) : binarySearchTree();
    ~binarySearchTree(void);

    //=== Methods Modifiers
    Node* insert(ConstReference _data);
    Node* remove(ConstReference _data);
    Node* clear(void);

    //=== Methods Acess
    DataType median(void);
    int findPositionOfElement(ConstReference _data);
    DataType elementInPosition(int position);
    bool isComplete(void);
    bool isFull(void);
    std::string toString(void);
};

}  // namespace bst

#endif  // _BINARY_SEARCH_TREE_H_