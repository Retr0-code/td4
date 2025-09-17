#pragma once
#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {
    
    class ASTNodeFabric {
    public:
        virtual AbstractSyntaxTreeNode *operator()(const std::string &token) const = 0;
    };

}
