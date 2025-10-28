#include "Compiler.hpp"
#include "Instructions.hpp"
#include "AbstractSyntaxTreeNode.hpp"

#define TD4_MOVAIM  0x30
#define TD4_MOVBIM  0x70
#define TD4_MOVAB   0x10
#define TD4_MOVBA   0x40
#define TD4_ADDAIM  0x00
#define TD4_ADDBIM  0x50
#define TD4_JMPIM   0xf0
#define TD4_JNCIM   0xe0
#define TD4_OUTIM   0xb0
#define TD4_OUTB    0x90
#define TD4_INA     0x20
#define TD4_INB     0x60

#define TD4M_MOVYIM 0xc0
#define TD4M_MOVXIM 0xd0
#define TD4M_JZIM   0xa0
#define TD4M_ADDAB  0x80
#define TD4M_NEGA   0x81
#define TD4M_NOTA   0x82
#define TD4M_ORAB   0x83
#define TD4M_ANDAB  0x84
#define TD4M_XORAB  0x85
#define TD4M_SUBAB  0x86
#define TD4M_OUTA   0x87
#define TD4M_LDA    0x88
#define TD4M_STA    0x89
#define TD4M_LDB    0x8a
#define TD4M_STB    0x8b
#define TD4M_MOVXA  0x8c
#define TD4M_MOVYA  0x8d
#define TD4M_INCXY  0x8e
#define TD4M_JMPXY  0x8f

static uint8_t GetOperandValue(const td4::ASTNodePtr& node, size_t order = 0) {
    using namespace td4;
    IOperator *op{reinterpret_cast<IOperator*>(node.get())};
    
    auto operand{op->begin()};
    for (; order && operand != op->end(); ++operand, --order);

    return (*operand)->GetValue();
}

static inline td4::Compiler::Bytes ConstructBinaryOperation(uint8_t opcode, const td4::ASTNodePtr& node) {
    uint8_t instruction{opcode};
    instruction |= 0x0f & GetOperandValue(node, 1);
    return { instruction };
}

static inline td4::Compiler::Bytes ConstructUnaryOperation(uint8_t opcode, const td4::ASTNodePtr& node) {
    uint8_t instruction{opcode};
    instruction |= 0x0f & GetOperandValue(node);
    return { instruction };
}

extern "C" td4::Compiler GetCompiler(void) {
    using namespace td4;

    Compiler compiler;

    compiler.Register(MOVAIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(TD4_MOVAIM, node);
    })
    .Register(MOVBIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(TD4_MOVBIM, node);
    })
    .Register(MOVAB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(TD4_MOVAB, node);
    })
    .Register(MOVBA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(TD4_MOVBA, node);
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
        return ConstructUnaryOperation(TD4_OUTB, node);
    })
    .Register(INA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructUnaryOperation(TD4_INA, node);
    })
    .Register(INB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructUnaryOperation(TD4_INB, node);
    })
    .Register(MOVXIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(TD4M_MOVXIM, node);
    })
    .Register(MOVYIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(TD4M_MOVYIM, node);
    })
    .Register(JZIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructUnaryOperation(TD4M_JZIM, node);
    })
    .Register(ADDAB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_ADDAB};
    })
    .Register(NEGA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_NEGA};
    })
    .Register(NOTA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_NOTA};
    })
    .Register(ORAB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_ORAB};
    })
    .Register(ANDAB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_ANDAB};
    })
    .Register(XORAB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_XORAB};
    })
    .Register(SUBAB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_SUBAB};
    })
    .Register(OUTA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_OUTA};
    })
    .Register(LDA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_LDA};
    })
    .Register(STA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_STA};
    })
    .Register(LDB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_LDB};
    })
    .Register(STB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_STB};
    })
    .Register(MOVXA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_MOVXA};
    })
    .Register(MOVYA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_MOVYA};
    })
    .Register(INCXY, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_INCXY};
    })
    .Register(JMPXY, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return {TD4M_JMPXY};
    });

    return compiler;
}
