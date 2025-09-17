#include "IOperand.hpp"

namespace td4 {

    IOperand::IOperand(const Mnemonic& mnemonic)
    : AbstractSyntaxTreeNode(mnemonic), _value{0} {  }

    void IOperand::SetValue(uint8_t value) noexcept {
        this->_value = value;
    }

    uint8_t IOperand::GetValue(void) const noexcept {
        return this->_value;
    }
}
