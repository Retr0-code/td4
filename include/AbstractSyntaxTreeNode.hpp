#pragma once
#include <list>
#include <string>
#include <vector>
#include <cstdint>

namespace td4 {

    using Mnemonic = std::string;

    class IOpcodeGenerator {
    public:
        using Bytes = std::vector<uint8_t>;

        virtual Bytes operator()(void) = 0;
    };

    class AbstractSyntaxTreeNode {
    public:
        AbstractSyntaxTreeNode(void) = default;

        AbstractSyntaxTreeNode(const std::string& token) {}

        virtual const Mnemonic& GetMnemonic(void) {};
    };

}
