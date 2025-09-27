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

    class RegisterX : public IOperand {
    public:
        RegisterX(void);
    };

    class RegisterY : public IOperand {
    public:
        RegisterY(void);
    };

    class RegisterXY : public IOperand {
    public:
        RegisterXY(void);
    };


}
