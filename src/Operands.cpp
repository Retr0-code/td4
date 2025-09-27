#include "Operands.hpp"

td4::Immediate::Immediate(void) : IOperand("im") {  }

td4::Immediate::Immediate(uint8_t value) : IOperand("im") {
    this->SetValue(value);
}

td4::RegisterA::RegisterA(void) : IOperand("a") {  }

td4::RegisterB::RegisterB(void) : IOperand("b") {  }

td4::RegisterX::RegisterX(void) : IOperand("x") {  }

td4::RegisterY::RegisterY(void) : IOperand("y") {  }
