#pragma once
#include <memory>

#include "IOperator.hpp"

namespace td4 {

    class OperatorMov : public IOperatorBinary {
    public:
        OperatorMov(void);
        
        OperatorMov(
            const OperandPtr& operandLeft,
            const OperandPtr& operandRight);
    };
    
    class OperatorAdd : public IOperatorBinary {
    public:
        OperatorAdd(void);

        OperatorAdd(
            const OperandPtr& operandLeft,
            const OperandPtr& operandRight);
    };
    
    class OperatorJmp : public IOperatorUnary {
    public:
        OperatorJmp(void);

        OperatorJmp(const OperandPtr& operand);
    };
    
    class OperatorJnc : public IOperatorUnary {
    public:
        OperatorJnc(void);

        OperatorJnc(const OperandPtr& operand);
    };
    
    class OperatorOut : public IOperatorUnary {
    public:
        OperatorOut(void);

        OperatorOut(const OperandPtr& operand);
    };
    
    class OperatorIn : public IOperatorUnary {
    public:
        OperatorIn(void);
        
        OperatorIn(const OperandPtr& operand);
    };

}
