#pragma once
#include <memory>
#include <unordered_map>

#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {
    
    class AbstractSyntaxTree {
    public:
        using TreeNodePtr = std::shared_ptr<AbstractSyntaxTreeNode>;
        using TreeRaw = std::vector<TreeNodePtr>;

        AbstractSyntaxTree(std::istream& program);

        AbstractSyntaxTree& Parse(std::istream& program);
        
        TreeNodePtr ParseLine(const std::string& line) const;

        TreeRaw& GetTree(void);

    private:
        std::vector<std::string> Tokenize(const std::string& line) const;

        // Mnemonic GetMnemonic(const AbstractSyntaxTreeNode& node) const;

    private:
        TreeRaw _tree;
        static std::unordered_map<std::string, TreeNodePtr> _registry;
    };

}
