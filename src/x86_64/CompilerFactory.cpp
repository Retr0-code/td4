#include "Compiler.hpp"
#include "Instructions.hpp"
#include "AbstractSyntaxTreeNode.hpp"

#define X86_MOVAIM { 0xb8 }
#define X86_MOVBIM { 0xbb }
#define X86_MOVAB  { 0x89, 0xd8 }
#define X86_MOVBA  { 0x89, 0xc3 }
#define X86_ADDAIM { 0x0d, 0xf0, 0x00, 0x00, 0x00, 0x83, 0xc0 }
#define X86_ADDBIM { 0x81, 0xcb, 0xf0, 0x00, 0x00, 0x00, 0x83, 0xc3 }
#define X86_JMPIM  {  }
#define X86_JNCIM  {  }
#define X86_OUTIM  {  }
#define X86_OUTB   {  }
#define X86_INA    {  }
#define X86_INB    {  }

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
        return ConstructBinaryOperation(X86_MOVAIM, node);
    })
    .Register(MOVBIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(X86_MOVBIM, node);
    })
    .Register(MOVAB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return X86_MOVAB;
    })
    .Register(MOVBA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return X86_MOVBA;
    })
    .Register(ADDAIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(X86_ADDAIM, node);
    })
    .Register(ADDBIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructBinaryOperation(X86_ADDBIM, node);
    })
    .Register(JMPIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructUnaryOperation(X86_JMPIM, node);
    })
    .Register(JNCIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructUnaryOperation(X86_JNCIM, node);
    })
    .Register(OUTIM, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return ConstructUnaryOperation(X86_OUTIM, node);
    })
    .Register(OUTB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return X86_OUTB;
    })
    .Register(INA, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return X86_INA;
    })
    .Register(INB, [](const td4::ASTNodePtr& node) -> Compiler::Bytes {
        return X86_INB;
    });

    return compiler;
}
