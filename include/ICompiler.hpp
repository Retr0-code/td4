#include <unordered_map>
#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {

    class OpcodeGenerator {

    };

    class ICompiler {
    public:
        virtual ICompiler& Register(const Mnemonic& mnemonic) = 0;

    protected:
        std::unordered_map<Mnemonic, OpcodeGenerator> _mnemonicTable;
    };

}
