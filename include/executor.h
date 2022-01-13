#ifndef _EXECUTOR_H_
#define _EXECUTOR_H_

#include <fstream>  // std::ifstream
#include <istream>  // std::istringstream
#include <ostream>  // st::cout, std::cin, std::endl
#include <sstream>  // std::stringstream
#include <string>   // std::string

#include "./binarySearchTree.h"

/**
 * @brief A class to execute tests for a binary search tree.
 *
 * @tparam DataType Type of data the container will store in binary search tree.
 * @tparam KeyType Type of key the container will store in binary search tree.
 */
template <typename DataType, typename KeyType>
class Executor {
    //=== Private members.
   private:
    bst::BinarySearchTree<DataType, KeyType>* tree;
    bool leave = false;

    //=== Private methods.
   private:
    std::string processLine(std::string line);
    void openAndValideFile(std::ifstream& file, bool mustValidateNumbers = false);
    void processMutipleInserts(std::ifstream& file);

    //=== Public methods.
   public:
    Executor(bst::BinarySearchTree<DataType, KeyType>& tree);
    void start(std::string inserionFileName, std::string commandFileName);
};

#endif  // _EXECUTOR_H_