#pragma once
#include <memory>
#include <unordered_map>

#include "AbstractSyntaxTreeNode.hpp"
#include "ASTNodeFactory.hpp"

namespace td4 {
    
    class AbstractSyntaxTree {
    public:
        using TreeRaw = std::vector<ASTNodePtr>;
        using Iterator = TreeRaw::iterator;
        using ConstIterator = TreeRaw::const_iterator;

        AbstractSyntaxTree(const ASTNodeFactoryPtr& astFactory, std::istream& program);

        AbstractSyntaxTree& Parse(std::istream& program);
        
        ASTNodePtr ParseLine(const std::string& line) const;

        TreeRaw& GetTree(void);

        Iterator begin(void);
        
        Iterator end(void);

        ConstIterator begin(void) const;
        
        ConstIterator end(void) const;

    private:
        std::vector<std::string> Tokenize(const std::string& line) const;

        static std::string TokenToLower(std::string token);

    private:
        TreeRaw _tree;
        ASTNodeFactoryPtr _nodeFactory;
    };

}
