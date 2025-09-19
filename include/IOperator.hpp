#pragma once
#include "AbstractSyntaxTreeNode.hpp"
#include "IOperand.hpp"

namespace td4 {

    class IOperator : public AbstractSyntaxTreeNode {
    public:
        IOperator(const Mnemonic& mnemonic, size_t operandsAmount);

        virtual ~IOperator() = default;

        using Iterator = std::vector<OperandPtr>::iterator;

        Iterator begin(void);

        Iterator end(void);

    protected:
        std::vector<OperandPtr> _operands;
    };

    using OperatorPtr = std::shared_ptr<IOperator>;

    class IOperatorUnary : public IOperator {
    public:
        IOperatorUnary(const Mnemonic& mnemonic);

        IOperatorUnary(const Mnemonic& mnemonic, const OperandPtr& operand);

        Mnemonic GetMnemonic(void) const override;
    };
    
    class IOperatorBinary : public IOperator {
    public:
        IOperatorBinary(const Mnemonic& mnemonic);

        IOperatorBinary(
            const Mnemonic& mnemonic,
            const OperandPtr& operandLeft,
            const OperandPtr& operandRight
        );

        Mnemonic GetMnemonic(void) const override;
    };

}
