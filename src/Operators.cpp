#include "Operators.hpp"

namespace td4 {
    
    OperatorMov::OperatorMov(void) : IOperatorBinary("mov") {  }

    OperatorMov::OperatorMov(const OperandPtr &operandLeft, const OperandPtr &operandRight)
        : IOperatorBinary("mov", operandLeft, operandRight) {  }

    OperatorAdd::OperatorAdd(void) : IOperatorBinary("add") {  }

    OperatorAdd::OperatorAdd(const OperandPtr &operandLeft, const OperandPtr &operandRight)
        : IOperatorBinary("add", operandLeft, operandRight) {  }

    OperatorSub::OperatorSub(void) : IOperatorBinary("sub") {  }

    OperatorSub::OperatorSub(const OperandPtr &operandLeft, const OperandPtr &operandRight)
        : IOperatorBinary("sub", operandLeft, operandRight) {  }

    OperatorAnd::OperatorAnd(void) : IOperatorBinary("and") {  }

    OperatorAnd::OperatorAnd(const OperandPtr &operandLeft, const OperandPtr &operandRight)
        : IOperatorBinary("and", operandLeft, operandRight) {  }

    OperatorXor::OperatorXor(void) : IOperatorBinary("xor") {  }

    OperatorXor::OperatorXor(const OperandPtr &operandLeft, const OperandPtr &operandRight)
        : IOperatorBinary("xor", operandLeft, operandRight) {  }

    OperatorOr::OperatorOr(void) : IOperatorBinary("or") {  }

    OperatorOr::OperatorOr(const OperandPtr &operandLeft, const OperandPtr &operandRight)
        : IOperatorBinary("or", operandLeft, operandRight) {  }

    OperatorJmp::OperatorJmp(void) : IOperatorUnary("jmp") {  }

    OperatorJmp::OperatorJmp(const OperandPtr &operand)
        : IOperatorUnary("jmp", operand) {  }

    OperatorJnc::OperatorJnc(void) : IOperatorUnary("jnc") {  }

    OperatorJnc::OperatorJnc(const OperandPtr &operand)
        : IOperatorUnary("jnc", operand) {  }

    OperatorJz::OperatorJz(void) : IOperatorUnary("jz") {  }

    OperatorJz::OperatorJz(const OperandPtr &operand)
        : IOperatorUnary("jz", operand) {  }

    OperatorOut::OperatorOut(void) : IOperatorUnary("out") {  }

    OperatorOut::OperatorOut(const OperandPtr &operand)
        : IOperatorUnary("out", operand) {  }

    OperatorIn::OperatorIn(void) : IOperatorUnary("in") {  }

    OperatorIn::OperatorIn(const OperandPtr &operand)
        : IOperatorUnary("in", operand) {  }

    OperatorNeg::OperatorNeg(void) : IOperatorUnary("neg") {  }

    OperatorNeg::OperatorNeg(const OperandPtr &operand)
        : IOperatorUnary("neg", operand) {  }

    OperatorNot::OperatorNot(void) : IOperatorUnary("not") {  }

    OperatorNot::OperatorNot(const OperandPtr &operand)
        : IOperatorUnary("not", operand) {  }

    OperatorLd::OperatorLd(void) : IOperatorUnary("ld") {  }

    OperatorLd::OperatorLd(const OperandPtr &operand)
        : IOperatorUnary("ld", operand) {  }

    OperatorSt::OperatorSt(void) : IOperatorUnary("st") {  }

    OperatorSt::OperatorSt(const OperandPtr &operand)
        : IOperatorUnary("st", operand) {  }

}
