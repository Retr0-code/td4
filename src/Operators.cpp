#include "Operators.hpp"

namespace td4 {
    
    OperatorMov::OperatorMov(void) : IOperatorBinary("mov") {  }

    OperatorMov::OperatorMov(const OperandPtr &operandLeft, const OperandPtr &operandRight)
        : IOperatorBinary("mov", operandLeft, operandRight) {  }

    OperatorAdd::OperatorAdd(void) : IOperatorBinary("add") {  }

    OperatorAdd::OperatorAdd(const OperandPtr &operandLeft, const OperandPtr &operandRight)
        : IOperatorBinary("add", operandLeft, operandRight) {  }

    OperatorJmp::OperatorJmp(void) : IOperatorUnary("jmp") {  }

    OperatorJmp::OperatorJmp(const OperandPtr &operand)
        : IOperatorUnary("jmp", operand) {  }

    OperatorJnc::OperatorJnc(void) : IOperatorUnary("jnc") {  }

    OperatorJnc::OperatorJnc(const OperandPtr &operand)
        : IOperatorUnary("jnc", operand) {  }

    OperatorOut::OperatorOut(void) : IOperatorUnary("out") {  }

    OperatorOut::OperatorOut(const OperandPtr &operand)
        : IOperatorUnary("out", operand) {  }

    OperatorIn::OperatorIn(void) : IOperatorUnary("in") {  }

    OperatorIn::OperatorIn(const OperandPtr &operand)
        : IOperatorUnary("in", operand) {  }

}
