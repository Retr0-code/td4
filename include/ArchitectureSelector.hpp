#pragma once
#include <string>
#include "Compiler.hpp"

namespace td4 {

    class ArchitectureSelector {
    public:
        ArchitectureSelector(const std::string &arch);

        ~ArchitectureSelector();

        void Close(void);

        Compiler& Open(const std::string &arch);

        Compiler& GetCompiler(void);

        Compiler::Bytes operator()(const AbstractSyntaxTree& ast) const;

    private:
        Compiler _compiler;
        void* _handle;
        void* _function;
    };

}
