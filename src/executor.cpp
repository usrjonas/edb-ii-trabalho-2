#include "executor.h"

#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <sstream>

void verifyIfStringContainsOnlyNumbers(const std::string& str) {
    if (str.find_first_not_of("0123456789 ") != std::string::npos) {
        std::cerr << "ERRO :: String possui caracteres inválidos." << std::endl;
        exit(1);
    }
}

template <typename DataType, typename KeyType>
Executor<DataType, KeyType>::Executor(bst::BinarySearchTree<DataType, KeyType>& tree) : tree{&tree}, leave{false} {}

template <typename DataType, typename KeyType>
void Executor<DataType, KeyType>::start(std::string inserionFileName, std::string commandFileName) {
    std::ifstream inserionFile, commandFile;
    openAndValideFile(inserionFile, true);
    openAndValideFile(commandFile);

    processMutipleInserts(inserionFile);

    std::string line;
    while (!leave && std::getline(file, line)) {
        std::cout << processLine(line) << std::endl << std::endl;
    }
}

template <typename DataType, typename KeyType>
void Executor<DataType, KeyType>::openAndValideFile(std::ifstream& file, bool mustValidateNumbers = false) {
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

template <typename DataType, typename KeyType>
void Executor<DataType, KeyType>::processMutipleInserts(std::ifstream& file) {
    std::string str;
    while (std::getline(file, str, ' ')) {
        int value = std::stoi(str);
        tree->insert(value);
    }
}

template <typename DataType, typename KeyType>
std::string Executor<DataType, KeyType>::processLine(std::string line) {
    std::istringstream buf(line);
    std::string commandName;
    buf >> commandName;

    // Variáveis para auxiliar
    std::stringstream ss;
    std::string str;

    if (commandName.empty()) {
        return "LOG :: Comando Inválido <vazio>.";
    }

    if (commandName == "QUIT") {
        this->leave = true;
        return "LOG :: Execução dos testes finalizou.";
    }

    else if (commandName == "ENESIMO") {
        str.clear();
        buf >> str;

        ss.str(std::string);
        ss << "LOG :: ENESIMO :: Elemento que ocupa a " << str << " possição é "
           << tree->elementInPosition(std::stoi(str)) << ".";

        return ss.str();
    }

    else if (commandName == "POSICAO") {
        str.clear();
        buf >> str;

        ss.str(std::string);
        ss << "LOG :: POSICAO :: Elemento " << str << " encontra-se na posição "
           << tree->elementInPosition(std::stoi(str)) << ".";

        return ss.str();
    }

    else if (commandName == "MEDIANA") {
        ss.str(std::string);
        ss << "LOG :: MEDIANA :: A mediana é " << tree->median(std::stoi(str)) << ".";

        return ss.str();
    }

    else if (commandName == "CHEIA") {
        ss.str(std::string);
        ss << "LOG :: CHEIA :: A ávore " << tree->isFull(std::stoi(str)) ? "não" : std::string() << " é cheia." << ;

        return ss.str();
    }

    else if (commandName == "COMPLETA") {
        ss.str(std::string);
        ss << "LOG :: CHEIA :: A ávore " << tree->isComplete(std::stoi(str)) ? "não"
                                                                             : std::string() << " é completa." << ;

        return ss.str();
    }

    else if (commandName == "IMPRIMA") {
        ss.str(std::string);
        ss << "LOG :: IMPRIMA :: Impressão da árvore: " << tree->toString(std::stoi(str)) << std::endl
           << "------------------------------------";

        return ss.str();
    }

    else if (commandName == "REMOVA") {
        str.clear();
        buf >> str;

        tree->remove(std::stoi(str));

        ss.str(std::string);
        ss << "LOG :: REMOVA :: Elemento " << str << " removido.";

        return ss.str();
    }

    else if (commandName == "INSIRA") {
        str.clear();
        buf >> str;

        tree->insert(std::stoi(str));

        ss.str(std::string);
        ss << "LOG :: INSIRA :: Elemento " << str << " inserido.";

        return ss.str();
    }

    else {
        return "LOG :: Comando '" + commandName + "' não reconhecido.";
    }
}