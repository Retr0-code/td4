#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {
    
    class AbstractSyntaxTree {
    public:
        void Parse(std::string code);

    private:
        std::string GetMnemonic(const AbstractSyntaxTreeNode& node);
    };

}
