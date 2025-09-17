#include "AbstractSyntaxTreeNode.hpp"

namespace td4 {

    AbstractSyntaxTreeNode::AbstractSyntaxTreeNode(const Mnemonic &mnemonic)
        : _mnemonic{mnemonic} {  }

    const Mnemonic &AbstractSyntaxTreeNode::GetMnemonic(void) const {
        return this->_mnemonic;
    }

}
