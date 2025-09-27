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

    class OperatorSub : public IOperatorBinary {
    public:
        OperatorSub(void);

        OperatorSub(
            const OperandPtr& operandLeft,
            const OperandPtr& operandRight);
    };

    class OperatorAnd : public IOperatorBinary {
    public:
        OperatorAnd(void);

        OperatorAnd(
            const OperandPtr& operandLeft,
            const OperandPtr& operandRight);
    };

    class OperatorXor : public IOperatorBinary {
    public:
        OperatorXor(void);

        OperatorXor(
            const OperandPtr& operandLeft,
            const OperandPtr& operandRight);
    };

    class OperatorOr : public IOperatorBinary {
    public:
        OperatorOr(void);

        OperatorOr(
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

    class OperatorJz : public IOperatorUnary {
    public:
        OperatorJz(void);
        
        OperatorJz(const OperandPtr& operand);
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

    class OperatorNeg : public IOperatorUnary {
    public:
        OperatorNeg(void);

        OperatorNeg(const OperandPtr& operand);
    };
    
    class OperatorNot : public IOperatorUnary {
    public:
        OperatorNot(void);
        
        OperatorNot(const OperandPtr& operand);
    };

    class OperatorLd : public IOperatorUnary {
    public:
        OperatorLd(void);
        
        OperatorLd(const OperandPtr& operand);
    };

    class OperatorSt : public IOperatorUnary {
    public:
        OperatorSt(void);
        
        OperatorSt(const OperandPtr& operand);
    };

}
