#include "Exceptions.hpp"
#include "ArchitectureSelector.hpp"

#define CMOD_PREFIX "libcmod_"
#define COMPILER_FACTORY_SYM "GetCompiler"

#ifdef _WIN32

#include <windows.h>

td4::Compiler td4::ArchitectureSelector(const std::string &arch) {
    return Compiler();
}

#elif __linux__

#include <vector>
#include <iostream>
#include <filesystem>

#include <dlfcn.h>

namespace td4 {
    ArchitectureSelector::ArchitectureSelector(const std::string &arch)
        : _handle{nullptr}, _function{nullptr} {
        this->Open(arch);
    }

    ArchitectureSelector::~ArchitectureSelector() {
        this->Close();
    }

    void ArchitectureSelector::Close(void) {
        if (this->_handle != nullptr)
            dlclose(this->_handle);

        this->_handle = nullptr;
        this->_function = nullptr;
    }

    Compiler& ArchitectureSelector::Open(const std::string &arch) {
        this->Close();

        std::vector<std::string> modulesDirs{"/usr/share/td4c", "./modules"};

        using CompilerFactory = Compiler (*)(void);

        void *handle{nullptr};
        CompilerFactory function{nullptr};
        std::string modName{CMOD_PREFIX + arch + ".so"};
        for (const auto& dir : modulesDirs) {
            std::filesystem::path pathPrefix{dir};

            handle = dlopen((pathPrefix / modName).c_str(), RTLD_LAZY | RTLD_LOCAL);
            if (handle == nullptr)
                continue;
            
            function = reinterpret_cast<CompilerFactory>(dlsym(handle, COMPILER_FACTORY_SYM));
            if (function != nullptr)
                break;
        }
        
        if (handle == nullptr)
            throw td4::exception::ModuleLoad(modName.c_str());

        if (function == nullptr)
            throw td4::exception::ModuleCall(COMPILER_FACTORY_SYM, modName.c_str());

        _compiler = (*function)();

        return this->_compiler;
    }

    Compiler &ArchitectureSelector::GetCompiler(void) {
        return this->_compiler;
    }

    Compiler::Bytes ArchitectureSelector::operator()(const AbstractSyntaxTree& ast) const {
        return this->_compiler(ast);
    }

}

#endif
