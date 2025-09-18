#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {

    AbstractSyntaxTreeNode::AbstractSyntaxTreeNode(const Mnemonic &mnemonic)
        : _mnemonic{mnemonic} {  }

    Mnemonic AbstractSyntaxTreeNode::GetMnemonic(void) const {
        return this->_mnemonic;
    }

}
