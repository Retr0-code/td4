#pragma once
#include <string>
#include <vector>
#include <memory>
#include <cstdint>

namespace td4 {

    using Mnemonic = std::string;

    class AbstractSyntaxTreeNode {
    public:
        AbstractSyntaxTreeNode(const Mnemonic& mnemonic);

        virtual ~AbstractSyntaxTreeNode() = default;

        virtual Mnemonic GetMnemonic(void) const;
    
    protected:
        Mnemonic _mnemonic;
    };

    using ASTNodePtr = std::shared_ptr<AbstractSyntaxTreeNode>;

}
