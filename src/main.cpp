#include <string>
#include <sstream>
#include <iostream>

#include "Compiler.hpp"
#include "AbstractSyntaxTree.hpp"
#include "IOperand.hpp"
#include "IOperator.hpp"

int main(int argc, char *argv[])
{
    std::istringstream program{
       "IN A\n \
        IN B\n \
        MOV A, B\n \
        MOV B, A\n \
        MOV A, 1111b\n \
        MOV B, 15\n \
        ADD A, 7o\n \
        ADD B, 0001b\n \
        JNC fh\n \
        JMP 0000b\n \
        OUT 1100b\n \
        OUT B"
    };

    td4::ASTNodeFactoryPtr nodeFactory{new td4::ASTNodeFactory()};
    std::string cpu_architecture{"td4"};

    // td4::Compiler compiler(cpu_architecture);
    
    td4::AbstractSyntaxTree ast(nodeFactory, program);

    for (auto op : ast.GetTree()) {
        std::cout << op->GetMnemonic() << '\n' << "values: ";
        for (auto operand : *reinterpret_cast<td4::IOperator*>(op.get())) {
            std::cout << (int)operand->GetValue() << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}
