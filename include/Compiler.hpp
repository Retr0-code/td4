#pragma once
#include <unordered_map>
#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {

    class Compiler {
    public:
        Compiler(std::string architecture);

        Compiler& Register(const Mnemonic& mnemonic, const IOpcodeGenerator& generator);

    protected:
        std::unordered_map<Mnemonic, const IOpcodeGenerator&> _mnemonicTable;
    };

}
