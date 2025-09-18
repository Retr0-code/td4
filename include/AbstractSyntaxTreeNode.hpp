#pragma once
#include <string>
#include <vector>
#include <memory>
#include <cstdint>

namespace td4 {

    using Mnemonic = std::string;

    class IOpcodeGenerator {
    public:
        using Bytes = std::vector<uint8_t>;

        virtual Bytes operator()(void) = 0;
    };

    class AbstractSyntaxTreeNode {
    public:
        AbstractSyntaxTreeNode(const Mnemonic& mnemonic);

        virtual Mnemonic GetMnemonic(void) const;
    
    protected:
        Mnemonic _mnemonic;
    };

    using ASTNodePtr = std::shared_ptr<AbstractSyntaxTreeNode>;

}
