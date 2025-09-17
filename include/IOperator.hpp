#pragma once
#include "AbstractSyntaxTreeNode.hpp"
#include "IOperand.hpp"

namespace td4 {

    class IOperatorUnary : public AbstractSyntaxTreeNode {
    public:
        IOperatorUnary(const Mnemonic& mnemonic, const OperandPtr& operand);

        const Mnemonic &GetMnemonic(void) const override;

    protected:
        OperandPtr _operand;
    };
    
    class IOperatorBinary : public AbstractSyntaxTreeNode {
    public:
        IOperatorBinary(
            const Mnemonic& mnemonic,
            const OperandPtr& operandLeft,
            const OperandPtr& operandRight
        );

        const Mnemonic &GetMnemonic(void) const override;

    protected:
        OperandPtr _operandLeft;
        OperandPtr _operandRight;
    };

}
