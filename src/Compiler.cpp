#include <iostream>
#include <iomanip>
#include "Compiler.hpp"
#include "Exceptions.hpp"
#include "AbstractSyntaxTree.hpp"

namespace td4 {

    Compiler::Compiler(const Compiler& copy)
        : _generator(copy._generator) {  }

    Compiler& Compiler::Register(const ASTNodePtr& astNode, const OpcodeGenerator& generator) {
        this->_generator.emplace(astNode->GetMnemonic(), generator);
        return *this;
    }

    std::vector<uint8_t> Compiler::operator()(const AbstractSyntaxTree& ast) const {
        std::vector<uint8_t> payload;
        for (const auto& node : ast) {
            try {
                for (uint8_t byte : this->_generator.at(node->GetMnemonic())(node)) {
                    std::cout << std::hex << (int)byte << std::endl;
                    payload.emplace_back(byte);
                }
            } catch (std::out_of_range &err) {
                throw exception::UnknownInstruction(node->GetMnemonic().c_str());
            }
        }

        return payload;
    }

}
