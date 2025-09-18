#pragma once
#include <memory>
#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {

    class IOperand : public AbstractSyntaxTreeNode {
    public:
        IOperand(const Mnemonic& mnemonic);

        void SetValue(uint8_t value) noexcept;
        
        uint8_t GetValue(void) const noexcept;

    protected:
        uint8_t _value;
    };

    using OperandPtr = std::shared_ptr<IOperand>;

}
