#include <cstdio>
#include <cstring>

#include "Exceptions.hpp"

using namespace td4::exception;

Exception::Exception(void) {
    std::memset(this->_message, 0, EXCEPTION_MAX_LEN);
};

const char *Exception::what(void) const throw() {
    return this->_message;
}

InvalidSyntax::InvalidSyntax(const char *message) {
    std::sprintf(this->_message, "Unable to parse line: %s\n", message);
}

InvalidToken::InvalidToken(const char *message) {
    std::sprintf(this->_message, "Unable to recognize a token: %s\n", message);
}

UnknownInstruction::UnknownInstruction(const char* message) {
    std::sprintf(this->_message, "Unknown combination of operands with operator: %s\n", message);
}

ModuleLoad::ModuleLoad(const char* message) {
    std::sprintf(this->_message, "Unable to locate or load module \"%s\"\n", message);
}

ModuleCall::ModuleCall(const char* function, const char *module) {
    std::sprintf(this->_message, "Unable to call function \"%s\" from module %s\n", function, module);
}
