#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include "Exceptions.hpp"
#include "AbstractSyntaxTree.hpp"
#include "ArchitectureSelector.hpp"

#include "ArgumentsParser.hpp"

int main(int argc, const char** argv)
{
    // Parse parameters ([-m<architecture> -o<output file>] {input file})
    arguments_parser arg_parser("Compiler for TD4 4-bit processor.");
    
    arg_parser.add_argument(
        "-o",
        argument::type::parameter,
        argument::declaration::single,
        "Writes result to specified file",
        argument::mode::optional,
        "out.td4"
    );
    arg_parser.add_argument(
        "--help",
        argument::type::help,
        argument::declaration::single,
        "Shows help message"
    );
    arg_parser.add_argument(
        "-m",
        argument::type::parameter,
        argument::declaration::single,
        "Selects an architecture to compile for",
        argument::mode::optional,
        "td4"
    );
    arg_parser.add_argument(
        "-i",
        argument::type::parameter,
        argument::declaration::single,
        "Specifies file to compile",
        argument::mode::required
    );

    try {
        arg_parser.parse(argc, argv);
    } catch (const unknown_argument& e) {
        std::cerr << e.what();
        return 1;
    } catch (const required_arguments& e) {
        std::cerr << e.what();
        std::cout << "Check manual using <--help> flag\n";
        return 1;
    } catch (const usage_message& e) {
        if (arg_parser["--help"]->get_value() == nullptr)
            arg_parser.show_help();
        else
            arg_parser.show_help(arg_parser["--help"]->get_value());
        
        return 0;
    }

    std::string inFilePath{arg_parser["-i"]->get_value()};
    std::string outFilePath{arg_parser["-o"]->get_value()};
    std::string cpu_architecture{arg_parser["-m"]->get_value()};

    // Open file
    if (inFilePath.empty()) {
        std::cerr << "E: No source file was specifiedn\n";
        return 1;
    }

    std::ifstream inFile(inFilePath);
    if (!inFile.is_open()) {
        std::cerr << "E: Failed to open source file\n";
        return 1;
    }

    std::ofstream outFile(outFilePath, std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "E: Failed to open output file\n";
        return 1;
    }

    // Parse AST
    td4::ASTNodeFactoryPtr nodeFactory{new td4::ASTNodeFactory()};
    td4::AbstractSyntaxTree ast(nodeFactory);
    
    try {
        ast.Parse(inFile);
    } catch (td4::exception::Exception &err) {
        std::cerr << "E: Unable to read input file:\n\t" << err.what();
        return 1;
    } catch (std::exception &err) {
        std::cerr << "E: Fatal error while parsing file\n\t" << err.what();
        return 1;
    }

    inFile.close();

    // Use compiler for specified architecture
    try {
        td4::ArchitectureSelector compilerSelector(cpu_architecture);
        td4::Compiler::Bytes payload{compilerSelector(ast)};

        for (auto byte : payload)
            outFile << byte;
    } catch (td4::exception::Exception &err) {
        std::cerr << "E: Error loading compiler module\n\t" << err.what();
        return 1;
    } catch (std::exception &err) {
        std::cerr << "E: Fatal error while compiling\n\t" << err.what();
        return 1;
    }
    
    outFile.close();
    return 0;
}
