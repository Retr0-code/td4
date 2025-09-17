#pragma once
#include <memory>

#include "IOperator.hpp"

namespace td4 {

    class OperatorMov : public IOperatorBinary {
    public:
        OperatorMov(
            const OperandPtr& operandLeft,
            const OperandPtr& operandRight);
    };
    
    class OperatorAdd : public IOperatorBinary {
        OperatorAdd(
            const OperandPtr& operandLeft,
            const OperandPtr& operandRight);
    };
    
    class OperatorJmp : public IOperatorUnary {
        OperatorJmp(const OperandPtr& operand);
    };
    
    class OperatorJnc : public IOperatorUnary {
        OperatorJnc(const OperandPtr& operand);
    };
    
    class OperatorOut : public IOperatorUnary {
        OperatorOut(const OperandPtr& operand);
    };
    
    class OperatorIn : public IOperatorUnary {
        OperatorIn(const OperandPtr& operand);
    };

}
