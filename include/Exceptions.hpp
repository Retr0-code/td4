#pragma once
#include <exception>

#define EXCEPTION_MAX_LEN 128

namespace td4 {
    namespace exception {

        class Exception : public std::exception {
        public:
            Exception(void);

            virtual ~Exception() = default;

            const char *what(void) const throw () override;

        protected:
            char _message[EXCEPTION_MAX_LEN];
        };

        class InvalidSyntax : public Exception {
        public:
            InvalidSyntax(const char* message);
        };

        class InvalidToken : public Exception {
        public:
            InvalidToken(const char* message);
        };

        class ExpectedToken : public Exception {
        public:
            ExpectedToken(const char* message);
        };

        class UnknownInstruction : public Exception {
        public:
            UnknownInstruction(const char* message);
        };

        class ModuleLoad : public Exception {
        public:
            ModuleLoad(const char* message);
        };

        class ModuleCall : public Exception {
        public:
            ModuleCall(const char* function, const char *module);
        };

    }
}
