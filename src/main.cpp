#include <string>
#include <sstream>

#include "Compiler.hpp"
#include "AbstractSyntaxTree.hpp"

int main(int argc, char *argv[])
{
    std::istringstream program{
       "IN A\n \
        IN B\n \
        MOV A, B\n \
        MOV B, A\n \
        MOV A, 1111\n \
        MOV B, 1111\n \
        ADD A, 0001\n \
        ADD B, 0001\n \
        JNC 1111\n \
        JMP 0000\n \
        OUT 1100\n \
        OUT B"
    };

    std::string cpu_architecture{"td4"};

    td4::Compiler compiler(cpu_architecture);
    
    td4::AbstractSyntaxTree ast(program);
    
    return 0;
}
