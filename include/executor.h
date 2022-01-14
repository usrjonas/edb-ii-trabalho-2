#ifndef _EXECUTOR_H_
#define _EXECUTOR_H_

#include <iostream> // st::cout, std::cin, std::endl
#include <fstream>  // std::ifstream
#include <istream>  // std::istringstream
#include <ostream>  // std::ostringstream
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
    void verifyIfStringContainsOnlyNumbers(const std::string& str) {
        if (str.find_first_not_of("0123456789 ") != std::string::npos) {
            std::cerr << "ERRO :: String possui caracteres inválidos." << std::endl;
            exit(1);
        }
    }

    std::string processLine(std::string line) {
        std::istringstream buf(line);
        std::string commandName;
        buf >> commandName;

        // Variáveis para auxiliar
        std::stringstream ss;
        std::string str;

        if (commandName.empty()) {
            return "LOG :: Comando Inválido <vazio>.";
        }

        else if (commandName == "QUIT") {
            this->leave = true;
            return "LOG :: Execução dos testes finalizou.";
        }

        else if (commandName == "ENESIMO") {
            buf >> str;
            verifyIfStringContainsOnlyNumbers(str);

            ss << "LOG :: ENESIMO :: Elemento que ocupa a " << str << " possição é "
            << tree->elementInPosition(std::stoi(str)) << ".";

            return ss.str();
        }

        else if (commandName == "POSICAO") {
            buf >> str;
            verifyIfStringContainsOnlyNumbers(str);

            ss << "LOG :: POSICAO :: Elemento " << str << " encontra-se na posição "
            << tree->elementInPosition(std::stoi(str)) << ".";

            return ss.str();
        }

        else if (commandName == "MEDIANA") {
            ss << "LOG :: MEDIANA :: A mediana é " << tree->median(std::stoi(str)) << ".";

            return ss.str();
        }

        else if (commandName == "CHEIA") {
            str = tree->isFull(std::stoi(str)) ? "não" : "";
            ss << "LOG :: CHEIA :: A ávore " << str << " é cheia.";

            return ss.str();
        }

        else if (commandName == "COMPLETA") {
            str = tree->isComplete(std::stoi(str)) ? "não" : "";
            ss << "LOG :: CHEIA :: A ávore " << str << " é completa.";

            return ss.str();
        }

        else if (commandName == "IMPRIMA") {
            ss << "LOG :: IMPRIMA :: Impressão da árvore: " << tree->toString(std::stoi(str)) << std::endl
            << "------------------------------------";

            return ss.str();
        }

        else if (commandName == "REMOVA") {
            buf >> str;
            verifyIfStringContainsOnlyNumbers(str);

            tree->remove(std::stoi(str));

            ss << "LOG :: REMOVA :: Elemento " << str << " removido.";

            return ss.str();
        }

        else if (commandName == "INSIRA") {
            buf >> str;
            verifyIfStringContainsOnlyNumbers(str);

            tree->insert(std::stoi(str));

            ss << "LOG :: INSIRA :: Elemento " << str << " inserido.";

            return ss.str();
        }

        else {
            return "LOG :: Comando '" + commandName + "' não reconhecido.";
        }
    }

    void openAndValideFile(std::ifstream& file, std::string fileName, bool mustValidateNumbers = false) {
        file.open(fileName.c_str());

        if (!file.is_open()) {
            std::cerr << "ERRO :: Arquivo " << fileName << " informado é inválido." << std::endl;
            exit(1);
        }

        if (mustValidateNumbers) {
            int numberOfLines = 0;
            std::string line;

            while (!file.eof()) {
                std::getline(file, line);
                numberOfLines++;

                if (line.find_first_of("0123456789") == std::string::npos) {
                    std::cerr << "ERRO :: Linha " << numberOfLines << " não possui números." << std::endl;
                    exit(1);
                }

                if (line.find_first_not_of("0123456789 ") != std::string::npos) {
                    std::cerr << "ERRO :: Arquivo possui caracteres inválidos." << std::endl;
                    exit(1);
                }
            }

            file.seekg(0, std::ios::beg);
        }
    }
    
    void processMutipleInserts(std::ifstream& file) {
        std::string str;
        while (std::getline(file, str, ' ')) {
            int value = std::stoi(str);
            tree->insert(value);
        }
    }

   //=== Public methods.
   public:
    //=== Constructor
    Executor(bst::BinarySearchTree<DataType, KeyType>& _tree) : tree{&_tree}, leave{false} {}
    
    /**
     * @brief 
     * 
     * @param insertionFileName 
     * @param commandFileName 
     */
    void start(std::string insertionFileName, std::string commandFileName) {
        std::ifstream insertionFile, commandFile;
        openAndValideFile(insertionFile, insertionFileName, true);
        openAndValideFile(commandFile, commandFileName);

        processMutipleInserts(insertionFile);

        std::string line;
        while (not leave && std::getline(commandFile, line)) {
            std::cout << processLine(line) << std::endl << std::endl;
        }
    }
};

#endif  // _EXECUTOR_H_