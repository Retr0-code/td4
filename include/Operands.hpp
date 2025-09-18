#pragma once
#include "IOperand.hpp"

namespace td4 {

    class Immediate : public IOperand {
    public:
        Immediate(void);
        
        Immediate(uint8_t value);
    };

    class RegisterA : public IOperand {
    public:
        RegisterA(void);
    };

    class RegisterB : public IOperand {
    public:
        RegisterB(void);
    };

}
