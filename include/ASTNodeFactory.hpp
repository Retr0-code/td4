#pragma once
#include <memory>
#include <optional>
#include <functional>
#include <unordered_map>

#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {
    
    class ASTNodeFactory {
    public:
        ASTNodeFactory(void);

        virtual ~ASTNodeFactory() = default;

        virtual AbstractSyntaxTreeNode* operator()(const std::string &token) const;

        typedef enum NumericalSystemMarker : char {
            NumericalSystemBin = 'b',
            NumericalSystemOct = 'o',
            NumericalSystemHex = 'h'
        } NumericalSystemMarker;

        using ConstructorFunc = std::function<AbstractSyntaxTreeNode* ()>;

        std::optional<uint8_t> TryParseImmediate(const std::string &token) const;

    private:
        std::unordered_map<std::string, ConstructorFunc> _registry;
    };

    using ASTNodeFactoryPtr = std::shared_ptr<ASTNodeFactory>;

}
