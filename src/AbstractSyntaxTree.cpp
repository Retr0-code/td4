#include <array>
#include <regex>
#include <string>
#include <iostream>

#include "Exceptions.hpp"
#include "AbstractSyntaxTree.hpp"

namespace td4 {

    AbstractSyntaxTree::AbstractSyntaxTree(std::istream& program) {
        this->Parse(program);
    }

    AbstractSyntaxTree& AbstractSyntaxTree::Parse(std::istream& program) {
        for (std::string line; std::getline(program, line);) {
            this->ParseLine(line);
        }

        return *this;
    }
    
    AbstractSyntaxTreeNode AbstractSyntaxTree::ParseLine(const std::string &line) {
        AbstractSyntaxTreeNode astNode;
        for (std::string token : this->Tokenize(line)) {
            std::cout << token << '\n';
        }

        return astNode;
    }

    std::vector<std::string> AbstractSyntaxTree::Tokenize(const std::string &line)
    {
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

}
