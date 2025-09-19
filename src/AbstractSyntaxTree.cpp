#include <array>
#include <regex>
#include <string>
#include <iostream>

#include "Exceptions.hpp"
#include "AbstractSyntaxTree.hpp"

#include "Operators.hpp"
#include "Operands.hpp"

namespace td4 {

    AbstractSyntaxTree::AbstractSyntaxTree(const ASTNodeFactoryPtr &nodeFactory)
        : _nodeFactory(nodeFactory) {  }

    AbstractSyntaxTree::AbstractSyntaxTree(const ASTNodeFactoryPtr& nodeFactory, std::istream& program)
        : _nodeFactory(nodeFactory) {
        this->Parse(program);
    }

    AbstractSyntaxTree& AbstractSyntaxTree::Parse(std::istream& program) {
        for (std::string line; std::getline(program, line);) {
            this->_tree.emplace_back(std::move(this->ParseLine(line)));
        }

        return *this;
    }
    
    ASTNodePtr AbstractSyntaxTree::ParseLine(const std::string &line) const {
        std::vector<std::string> tokens{this->Tokenize(line)};
        OperatorPtr operatorNode{nullptr};

        auto currentToken = tokens.begin();
        try {
            operatorNode = std::shared_ptr<IOperator>(
                reinterpret_cast<IOperator*>((*this->_nodeFactory)(*currentToken)));

            std::transform(++currentToken, tokens.end(), operatorNode->begin(),
                [this](const std::string& token) {
                    return std::shared_ptr<IOperand>(
                        reinterpret_cast<IOperand*>((*this->_nodeFactory)(token)));
                }
            );
        } catch (exception::InvalidToken &err) {
            std::cerr << err.what() << '\n';
            throw exception::InvalidSyntax(line.c_str());
        }

        return operatorNode;
    }

    AbstractSyntaxTree::Iterator AbstractSyntaxTree::begin(void) {
        return this->_tree.begin();
    }

    AbstractSyntaxTree::Iterator AbstractSyntaxTree::end(void) {
        return this->_tree.end();
    }

    AbstractSyntaxTree::ConstIterator AbstractSyntaxTree::begin(void) const {
        return this->_tree.begin();
    }
        
    AbstractSyntaxTree::ConstIterator AbstractSyntaxTree::end(void) const {
        return this->_tree.end();
    }

    std::vector<std::string> AbstractSyntaxTree::Tokenize(const std::string &line) const {
        std::vector<std::string> tokens;
        std::regex pattern(R"(\s*([a-zA-Z]+)\s*([a-fA-F0-9]+[hbo]*)(?:\s*,\s*([a-fA-F0-9]+[hbo]*))?)");
        std::smatch regexTokens;

        std::regex_match(line, regexTokens, pattern);

        if (regexTokens.empty())
            throw exception::InvalidSyntax{line.c_str()};

        for (auto token = regexTokens.begin() + 1; token != regexTokens.end(); ++token)
            if (token->length() > 0)
                tokens.emplace_back(std::move(AbstractSyntaxTree::TokenToLower(*token)));

        return tokens;
    }

    std::string AbstractSyntaxTree::TokenToLower(std::string token) {
        std::transform(token.begin(), token.end(), token.begin(),
            [](uint8_t c){ return std::tolower(c); }
        );
        return token;
    }

    AbstractSyntaxTree::TreeRaw &AbstractSyntaxTree::GetTree(void) {
        return this->_tree;
    }

}
