#include <string>

int main(int argc, char *argv[])
{
    std::string program = 
       "IN A \
        IN B \
        MOV A, B \
        MOV B, A \
        MOV A, 1111 \
        MOV B, 1111 \
        ADD A, 0001 \
        ADD B, 0001 \
        JNC 1111 \
        JMP 0000 \
        OUT 1100 \
        OUT B";
    
    return 0;
}
