#include "IOperator.hpp"

namespace td4 {

    IOperator::IOperator(const Mnemonic& mnemonic, size_t operandsAmount)
        : AbstractSyntaxTreeNode(mnemonic), _operands(operandsAmount) {  }

    IOperator::Iterator IOperator::begin(void) {
        return _operands.begin();
    }

    IOperator::Iterator IOperator::end(void) {
        return _operands.end();
    }

    IOperatorUnary::IOperatorUnary(const Mnemonic &mnemonic)
        : IOperator(mnemonic, 1) {
        this->_operands[0] = nullptr;
    }

    IOperatorUnary::IOperatorUnary(const Mnemonic& mnemonic, const OperandPtr &operand)
    : IOperator(mnemonic, 1) {
        this->_operands[0] = operand;
    }

    Mnemonic IOperatorUnary::GetMnemonic(void) const {
        return this->_mnemonic + this->_operands[0]->GetMnemonic();
    }

    IOperatorBinary::IOperatorBinary(const Mnemonic &mnemonic)
        : IOperator(mnemonic, 2) {
        this->_operands[0] = nullptr;
        this->_operands[1] = nullptr;
    }

    IOperatorBinary::IOperatorBinary(
            const Mnemonic& mnemonic,
            const OperandPtr& operandLeft,
            const OperandPtr& operandRight
        )
    : IOperator(mnemonic, 2) {
        this->_operands[0] = operandLeft;
        this->_operands[1] = operandRight;
    }

    Mnemonic IOperatorBinary::GetMnemonic(void) const {
        return this->_mnemonic + this->_operands[0]->GetMnemonic() + this->_operands[1]->GetMnemonic();
    }

}
