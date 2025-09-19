#include <string>
#include <optional>
#include "ASTNodeFactory.hpp"
#include "Operators.hpp"
#include "Operands.hpp"
#include "Exceptions.hpp"

namespace td4 {

    ASTNodeFactory::ASTNodeFactory(void) {
        this->_registry.emplace("mov", [](){ return new OperatorMov(); });
        this->_registry.emplace("add", [](){ return new OperatorAdd(); });
        this->_registry.emplace("jmp", [](){ return new OperatorJmp(); });
        this->_registry.emplace("jnc", [](){ return new OperatorJnc(); });
        this->_registry.emplace("out", [](){ return new OperatorOut(); });
        this->_registry.emplace("in", [](){ return new OperatorIn(); });
        this->_registry.emplace("a", [](){ return new RegisterA(); });
        this->_registry.emplace("b", [](){ return new RegisterB(); });
        this->_registry.emplace("im", [](){ return new Immediate(); });
    }

    AbstractSyntaxTreeNode *ASTNodeFactory::operator()(const std::string &token) const {
        AbstractSyntaxTreeNode *astNode{nullptr};

        try {
            astNode = this->_registry.at(token)();
        } catch (std::out_of_range &err) {
            std::optional<uint8_t> immediate{TryParseImmediate(token)};
            if (!immediate)
                throw InvalidToken(token.c_str());

            astNode = this->_registry.at("im")();
            reinterpret_cast<IOperand*>(astNode)->SetValue(*immediate);
        }

        return astNode;
    }

    std::optional<uint8_t> ASTNodeFactory::TryParseImmediate(const std::string &token) const {
        uint8_t immediate{0};
        int base{10};

        if (token.length() > 1) {
            char marker{token.back()};

            switch (marker) {
            case NumericalSystemBin:
                base = 2;
                break;

            case NumericalSystemOct:
                base = 8;
                break;

            case NumericalSystemHex:
                base = 16;
                break;
            }
        }

        try {
            immediate = std::stoi(token, nullptr, base);
        } catch (std::exception &err) {
            throw InvalidToken(token.c_str());
        }

        return immediate;
    }

}
