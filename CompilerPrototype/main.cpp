#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Lexer/Lexer.h"
#include "Parser/Parser.h"
#include "AST/AST.h"
#include "CodeGenerator/CodeGenerator.h"

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
    if (!file) return "";
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: CompilerPrototype <sources_list.txt>\n";
        return 1;
    }

    auto sources = readSourcesList(argv[1]);
    if (sources.empty()) {
        std::cerr << "No source files found in list.\n";
        return 1;
    }

    int fileIndex = 0;
    for (const auto& sourceFile : sources) {
        std::cout << "Processing: " << sourceFile << std::endl;
        std::string code = readFileToString(sourceFile);
        if (code.empty()) {
            std::cerr << "Cannot read source file: " << sourceFile << std::endl;
            continue;
        }

        Lexer lexer(code);
        Parser parser(lexer);

        auto ast = parser.parseExpression();
        if (!ast) {
            std::cerr << "Parsing failed for file: " << sourceFile << std::endl;
            continue;
        }

        ast->print();

        std::string generatedCpp = generateCppCode(ast.get());

        // Unikalna nazwa pliku cpp i exe
        std::string cppFile = "generated_" + std::to_string(fileIndex) + ".cpp";
        std::string exeFile = "output_" + std::to_string(fileIndex) + ".exe";

        std::ofstream outFile(cppFile);
        outFile << generatedCpp;
        outFile.close();

        // Kompiluj
        std::string compileCmd = "g++ -std=c++20 " + cppFile + " -o " + exeFile;
        int compileRes = system(compileCmd.c_str());
        if (compileRes != 0) {
            std::cerr << "Compilation failed for " << cppFile << std::endl;
            continue;
        }

        // Uruchom
        std::cout << "Running " << exeFile << ":\n";
        int runRes = system(exeFile.c_str());
        if (runRes != 0) {
            std::cerr << "Execution failed for " << exeFile << std::endl;
        }

        ++fileIndex;
    }

    return 0;
}
