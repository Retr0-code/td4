#include <array>
#include <regex>
#include <string>
#include <iostream>

#include "Exceptions.hpp"
#include "AbstractSyntaxTree.hpp"

#include "Operators.hpp"
#include "Operands.hpp"

namespace td4 {

    AbstractSyntaxTree::AbstractSyntaxTree(std::istream& program) {
        this->_registry.emplace("mov", std::make_shared<OperatorMov>());
        this->_registry.emplace("add", std::make_shared<OperatorAdd>());
        this->_registry.emplace("jmp", std::make_shared<OperatorJmp>());
        this->_registry.emplace("jnc", std::make_shared<OperatorJnc>());
        this->_registry.emplace("out", std::make_shared<OperatorOut>());
        this->_registry.emplace("in", std::make_shared<OperatorIn>());
        this->_registry.emplace("a", std::make_shared<RegisterA>());
        this->_registry.emplace("b", std::make_shared<RegisterB>());
        this->_registry.emplace("im", std::make_shared<Immediate>());

        this->Parse(program);
    }

    AbstractSyntaxTree& AbstractSyntaxTree::Parse(std::istream& program) {
        for (std::string line; std::getline(program, line);) {
            this->ParseLine(line);
        }

        return *this;
    }
    
    AbstractSyntaxTreeNode AbstractSyntaxTree::ParseLine(const std::string &line) const {
        AbstractSyntaxTreeNode astNode;
        for (std::string token : this->Tokenize(line)) {
            std::cout << token << '\n';
        }

        return astNode;
    }

    std::vector<std::string> AbstractSyntaxTree::Tokenize(const std::string &line) const {
        std::vector<std::string> tokens;
        std::regex pattern(R"(\s*([a-zA-Z]+)\s*([a-fA-F0-9]+[hbo]*)(?:\s*,\s*([a-fA-F0-9]+[hbo]*))?)");
        std::smatch regexTokens;

        std::regex_match(line, regexTokens, pattern);

        if (regexTokens.empty())
            throw InvalidSyntax{line.c_str()};

        for (auto token = regexTokens.begin() + 1; token != regexTokens.end(); ++token)
            if (token->length() > 0)
                tokens.emplace_back(std::move(*token));

        return tokens;
    }

    AbstractSyntaxTree::TreeRaw &AbstractSyntaxTree::GetTree(void) {
        return this->_tree;
    }

}
