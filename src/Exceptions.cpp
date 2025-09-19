#include <cstdio>
#include <cstring>

#include "Exceptions.hpp"

const char *td4::Exception::what(void) const throw() {
    return this->_message;
}

td4::InvalidSyntax::InvalidSyntax(const char *message) {
    std::memset(this->_message, 0, EXCEPTION_MAX_LEN);
    std::sprintf(this->_message, "Unable to parse line: %s\n", message);
}

td4::InvalidToken::InvalidToken(const char *message) {
    std::memset(this->_message, 0, EXCEPTION_MAX_LEN);
    std::sprintf(this->_message, "Unable to recognize a token: %s\n", message);
}

td4::UnknownInstruction::UnknownInstruction(const char* message) {
    std::memset(this->_message, 0, EXCEPTION_MAX_LEN);
    std::sprintf(this->_message, "Unknown combination of operands with operator: %s\n", message);
}
