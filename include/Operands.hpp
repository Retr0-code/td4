#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {

    class IOperand : AbstractSyntaxTreeNode {

    };

    class Immediate : public IOperand {

    };

    class Register : public IOperand {

    };

    class RegisterA : public Register {

    };

    class RegisterB : public Register {

    };

}
