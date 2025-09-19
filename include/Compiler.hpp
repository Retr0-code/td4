#pragma once
#include <functional>
#include <unordered_map>
#include "AbstractSyntaxTree.hpp"
#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {

    class Compiler {
    public:
        using Bytes = std::vector<uint8_t>;
        using OpcodeGenerator = std::function<Bytes (const ASTNodePtr&)>;

        Compiler(void) = default;

        Compiler(const Compiler& copy);

        virtual ~Compiler() = default;
    
        virtual Compiler& Register(const ASTNodePtr& astNode, const OpcodeGenerator& generator);

        virtual Bytes operator()(const AbstractSyntaxTree& ast) const;

    protected:
        std::unordered_map<Mnemonic, OpcodeGenerator> _generator;
    };

}
