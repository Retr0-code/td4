#include "Compiler.hpp"
#include "Exceptions.hpp"
#include "AbstractSyntaxTree.hpp"

namespace td4 {

    Compiler& Compiler::Register(const ASTNodePtr& astNode, const OpcodeGenerator& generator) {
        this->_generator.emplace(astNode->GetMnemonic(), generator);
        return *this;
    }

    std::vector<uint8_t> Compiler::operator()(const AbstractSyntaxTree& ast) const {
        std::vector<uint8_t> payload;
        for (const auto& node : ast) {
            try {
                payload.emplace_back(this->_generator.at(node->GetMnemonic())(node));
            } catch (std::out_of_range &err) {
                throw UnknownInstruction(node->GetMnemonic().c_str());
            }
        }
    }

}
