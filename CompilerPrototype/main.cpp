#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../CompilerPrototype/Lexer/Lexer.h"
#include "../CompilerPrototype/Parser/Parser.h"
#include "../CompilerPrototype/AST/AST.h"
#include "../CompilerPrototype/CodeGenerator/CodeGenerator.h"

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
        std::cerr << "Usage: CompilerPrototype <source.rise>\n";
        return 1;
    }

    std::string sourceFile = argv[1];

    std::string code = readFileToString(sourceFile);
    if (code.empty()) {
        std::cerr << "Cannot read source file: " << sourceFile << "\n";
        return 1;
    }

    Lexer lexer(code);
    Parser parser(lexer);

    auto ast = parser.parseExpression();
    if (!ast) {
        std::cerr << "Parsing failed\n";
        return 1;
    }

    ast->print();

    std::string generatedCode = generateCppCode(ast.get());

    // Zapisz do pliku
    std::ofstream outFile("generated.cpp");
    outFile << generatedCode;
    outFile.close();

    // Kompiluj generated.cpp do exe
    int buildResult = system("g++ -std=c++20 generated.cpp -o output.exe");
    if (buildResult != 0) {
        std::cerr << "Compilation of generated.cpp failed\n";
        return 1;
    }

    std::cout << "Compilation succeeded. Running output.exe\n";

    int runResult = system("output.exe");
    if (runResult != 0) {
        std::cerr << "Execution failed\n";
        return 1;
    }

    return 0;
}


