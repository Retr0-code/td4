#include "IOperator.hpp"

namespace td4 {

    IOperatorUnary::IOperatorUnary(const Mnemonic& mnemonic, const OperandPtr &operand)
    : AbstractSyntaxTreeNode(mnemonic), _operand(operand) {  }

    const Mnemonic &IOperatorUnary::GetMnemonic(void) const {
        return this->_mnemonic + this->_operand->GetMnemonic();
    }

    IOperatorBinary::IOperatorBinary(
            const Mnemonic& mnemonic,
            const OperandPtr& operandLeft,
            const OperandPtr& operandRight
        )
    : AbstractSyntaxTreeNode(mnemonic),
    _operandLeft(operandLeft),
    _operandRight(operandRight) {  }

    const Mnemonic &IOperatorBinary::GetMnemonic(void) const {
        return this->_mnemonic + this->_operandLeft->GetMnemonic() + this->_operandRight->GetMnemonic();
    }

}
