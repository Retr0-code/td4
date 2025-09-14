#include <string>

namespace td4 {

    class Mnemonic {
        
    };

    class AbstractSyntaxTreeNode {
    public:
        AbstractSyntaxTreeNode(const std::string& token);

        virtual const Mnemonic& GetMnemonic(void);
    };

}