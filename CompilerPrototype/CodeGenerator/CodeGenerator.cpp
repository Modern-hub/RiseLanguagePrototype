#include "CodeGenerator.h"
#include <sstream>

std::string generateCppCode(const ASTNode* ast) {
    std::stringstream ss;

    ss << "#include <iostream>\n";
    ss << "int main() {\n";

    if (auto call = dynamic_cast<const CallExpr*>(ast)) {
        if (call->callee == "displayConsole" && call->args.size() == 1) {
            if (auto strArg = dynamic_cast<const StringExpr*>(call->args[0].get())) {
                ss << "    std::cout << \"" << strArg->value << "\" << std::endl;\n";
            }
            else {
                ss << "    // Unsupported argument type\n";
            }
        }
        else {
            ss << "    // Unknown function or arguments\n";
        }
    }
    else {
        ss << "    // Unsupported AST node\n";
    }

    ss << "    return 0;\n";
    ss << "}\n";

    return ss.str();
}
