#include "Compiler.hpp"
#include "Instructions.hpp"
#include "AbstractSyntaxTreeNode.hpp"

#define TD4_MOVAIM { 0xb8 }
#define TD4_MOVBIM { 0xbb }
#define TD4_MOVAB  { 0x89, 0xd8 }
#define TD4_MOVBA  { 0x89, 0xc3 }
#define TD4_ADDAIM { 0x0d, 0xf0, 0x00, 0x00, 0x00, 0x83, 0xc0 }
#define TD4_ADDBIM { 0x81, 0xcb, 0xf0, 0x00, 0x00, 0x00, 0x83, 0xc0 }
#define TD4_JMPIM  {  }
#define TD4_JNCIM  {  }
#define TD4_OUTIM  {  }
#define TD4_OUTB   {  }
#define TD4_INA    {  }
#define TD4_INB    {  }

using Bytes = td4::Compiler::Bytes;

static Bytes& AddValue(Bytes& payload, int value) {
    uint8_t *valuePtr{reinterpret_cast<uint8_t*>(&value)};
    for (uint8_t i{0}; i < sizeof(value); ++i, ++valuePtr)
        payload.emplace_back(*valuePtr);

    return payload;
}

static uint8_t GetOperandValue(const td4::ASTNodePtr& node, size_t order = 0) {
    using namespace td4;
    IOperator *op{reinterpret_cast<IOperator*>(node.get())};
    
    auto operand{op->begin()};
    for (; order && operand != op->end(); ++operand, --order);

    return (*operand)->GetValue();
}

static inline Bytes ConstructBinaryOperation(Bytes instruction, const td4::ASTNodePtr& node) {
    return AddValue(instruction, GetOperandValue(node, 1));
}

static inline Bytes ConstructUnaryOperation(Bytes instruction, const td4::ASTNodePtr& node) {
    return AddValue(instruction, GetOperandValue(node));
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
        return TD4_MOVAB;
    })
    .Register(MOVBA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return TD4_MOVBA;
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
        return TD4_OUTB;
    })
    .Register(INA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return TD4_INA;
    })
    .Register(INB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return TD4_INB;
    });

    return compiler;
}
