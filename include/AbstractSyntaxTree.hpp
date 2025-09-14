#pragma once
#include <memory>
#include <unordered_map>

#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {
    
    class AbstractSyntaxTree {
    public:
        using TreeRaw = std::vector<std::shared_ptr<AbstractSyntaxTreeNode>>;

        AbstractSyntaxTree(std::istream& program);

        AbstractSyntaxTree& Parse(std::istream& program);
        
        AbstractSyntaxTreeNode ParseLine(const std::string& line);

        // TreeRaw& GetTree(void);

    private:
        std::vector<std::string> Tokenize(const std::string& line);

        // Mnemonic GetMnemonic(const AbstractSyntaxTreeNode& node);

    private:
        TreeRaw _tree;
        // std::unordered_map<std::string, >
    };

}
