#include "Compiler.hpp"
#include "Instructions.hpp"
#include "AbstractSyntaxTreeNode.hpp"

#define TD4_MOVAIM 0x30
#define TD4_MOVBIM 0x70
#define TD4_MOVAB  0x10
#define TD4_MOVBA  0x40
#define TD4_ADDAIM 0x00
#define TD4_ADDBIM 0x50
#define TD4_JMPIM  0xf0
#define TD4_JNCIM  0xe0
#define TD4_OUTIM  0xb0
#define TD4_OUTB   0x90
#define TD4_INA    0x20
#define TD4_INB    0x60

static inline uint8_t GetRightOperandValue(const td4::ASTNodePtr& node) {
    return (*(++reinterpret_cast<td4::IOperatorBinary*>(node.get())->begin()))->GetValue();
}

static uint8_t GetOperandValue(const td4::ASTNodePtr& node, size_t order = 0) {
    using namespace td4;
    IOperator *op{reinterpret_cast<IOperator*>(node.get())};
    
    auto operand{op->begin()};
    for (; order && operand != op->end(); ++operand, --order);

    return (*operand)->GetValue();
}

static inline td4::Compiler::Bytes ConstructBinaryOperation(uint8_t opcode, const td4::ASTNodePtr& node) {
    uint8_t instruction{opcode};
    instruction &= 0x0f & GetOperandValue(node, 1);
    return { instruction };
}

static inline td4::Compiler::Bytes ConstructUnaryOperation(uint8_t opcode, const td4::ASTNodePtr& node) {
    uint8_t instruction{opcode};
    instruction &= 0x0f & GetOperandValue(node);
    return { instruction };
}

td4::Compiler GetCompiler() {
    using namespace td4;

    Compiler compiler;
    
    compiler.Register(MOVAIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(TD4_MOVAIM, node);
    })
    .Register(MOVBIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(TD4_MOVBIM, node);
    })
    .Register(MOVAB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return { TD4_MOVAB };
    })
    .Register(MOVBA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return { TD4_MOVBA };
    })
    .Register(ADDAIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(TD4_ADDAIM, node);
    })
    .Register(ADDBIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(TD4_ADDBIM, node);
    })
    .Register(JMPIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructUnaryOperation(TD4_JMPIM, node);
    })
    .Register(JNCIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructUnaryOperation(TD4_JNCIM, node);
    })
    .Register(OUTIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructUnaryOperation(TD4_OUTIM, node);
    })
    .Register(OUTB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return { TD4_OUTB };
    })
    .Register(INA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return { TD4_INA };
    })
    .Register(INB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return { TD4_INB };
    });

    return compiler;
}
