#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../Lexer/Lexer.h"
#include "../Parser/Parser.h"
#include "../AST/AST.h"

// Wczytaj pliki z listy
std::vector<std::string> readSourcesList(const std::string& listFile) {
    std::ifstream file(listFile);
    std::vector<std::string> sources;
    if (!file) {
        std::cerr << "Error: Cannot open sources list file: " << listFile << "\n";
        return sources;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty())
            sources.push_back(line);
    }
    return sources;
}

std::string readFileToString(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Prosty "interpreter" tylko dla CallExpr displayConsole
void interpret(const ASTNode* node) {
    if (auto call = dynamic_cast<const CallExpr*>(node)) {
        if (call->callee == "displayConsole" && call->args.size() == 1) {
            if (auto strArg = dynamic_cast<const StringExpr*>(call->args[0].get())) {
                std::cout << strArg->value << std::endl;
            }
            else {
                std::cerr << "displayConsole expects a string argument\n";
            }
        }
        else {
            std::cerr << "Unknown function or wrong arguments\n";
        }
    }
    else {
        std::cerr << "Unsupported AST node for interpretation\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: RiseCompiler <sources_list.txt>\n";
        return 1;
    }

    std::string listFile = argv[1];
    auto sources = readSourcesList(listFile);

    if (sources.empty()) {
        std::cerr << "No source files listed in " << listFile << "\n";
        return 1;
    }

    for (const auto& sourceFile : sources) {
        std::string code = readFileToString(sourceFile);
        if (code.empty()) {
            std::cerr << "Error: Cannot open or empty source file: " << sourceFile << "\n";
            continue;
        }
        std::cout << "Processing file: " << sourceFile << "\n";

        Lexer lexer(code);
        Parser parser(lexer);

        auto ast = parser.parseExpression();
        if (!ast) {
            std::cerr << "Parsing failed for file: " << sourceFile << "\n";
            continue;
        }

        ast->print();
        interpret(ast.get());
    }

    std::cout << "All files processed.\n";
    std::cout << "Press Enter to exit...\n";
    std::cin.get();

    return 0;
}

