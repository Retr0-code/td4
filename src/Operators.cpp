#include "Operators.hpp"

namespace td4 {
    OperatorMov::OperatorMov(const OperandPtr &operandLeft, const OperandPtr &operandRight)
        : IOperatorBinary("mov", operandLeft, operandRight) {  }

    OperatorAdd::OperatorAdd(const OperandPtr &operandLeft, const OperandPtr &operandRight)
        : IOperatorBinary("add", operandLeft, operandRight) {  }

    OperatorJmp::OperatorJmp(const OperandPtr &operand)
        : IOperatorUnary("jmp", operand) {  }

    OperatorJnc::OperatorJnc(const OperandPtr &operand)
        : IOperatorUnary("jnc", operand) {  }

    OperatorOut::OperatorOut(const OperandPtr &operand)
        : IOperatorUnary("out", operand) {  }

    OperatorIn::OperatorIn(const OperandPtr &operand)
        : IOperatorUnary("in", operand) {  }

}
