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

        try {
            auto currentToken{tokens.begin()};
            
            operatorNode = std::shared_ptr<IOperator>(
                reinterpret_cast<IOperator*>((*this->_nodeFactory)(*currentToken))
            );
            
            auto operandIter{operatorNode->begin()};
            bool firstToken{true};

            for (; currentToken != tokens.end(); ++operandIter) {
                if (operandIter == operatorNode->end())
                    throw exception::InvalidToken(currentToken->c_str());

                if (currentToken + 1 == tokens.end())
                    throw exception::ExpectedToken(currentToken->c_str());

                if (*currentToken == "," || firstToken) {
                    *operandIter = std::shared_ptr<IOperand>(
                        reinterpret_cast<IOperand*>((*this->_nodeFactory)(*(++currentToken)))
                    );

                    ++currentToken;
                    firstToken = false;
                }
                
                if (*currentToken == "+") {
                    std::optional<uint8_t> value{_nodeFactory->TryParseImmediate(*(++currentToken))};
                    if (!value || *operandIter == nullptr)
                        throw exception::InvalidToken(currentToken->c_str());

                    (*operandIter)->SetValue(*value);
                    ++currentToken;
                }
            }

            if (operandIter != operatorNode->end())
                throw exception::ExpectedToken((currentToken - 1)->c_str());

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
        std::regex tokenizer(R"((\w+|[\+\-,]))");
        std::sregex_token_iterator token{line.begin(), line.end(), tokenizer};
        std::sregex_token_iterator tokensEnd;

        for (; token != tokensEnd; ++token)
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
