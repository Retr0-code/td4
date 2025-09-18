#pragma once
#include <memory>
#include <unordered_map>

#include "AbstractSyntaxTreeNode.hpp"
#include "ASTNodeFactory.hpp"

namespace td4 {
    
    class AbstractSyntaxTree {
    public:
        using TreeRaw = std::vector<ASTNodePtr>;

        AbstractSyntaxTree(const ASTNodeFactoryPtr& astFactory, std::istream& program);

        AbstractSyntaxTree& Parse(std::istream& program);
        
        ASTNodePtr ParseLine(const std::string& line) const;

        TreeRaw& GetTree(void);

    private:
        std::vector<std::string> Tokenize(const std::string& line) const;

        static std::string TokenToLower(std::string token);

        // Mnemonic GetMnemonic(const AbstractSyntaxTreeNode& node) const;

    private:
        ASTNodeFactoryPtr _nodeFactory;
        TreeRaw _tree;
        static std::unordered_map<std::string, ASTNodePtr> _registry;
    };

}
