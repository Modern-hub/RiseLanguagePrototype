#include "ASTNode.h"
#include <iostream>

namespace Rise {

    void printIndent(int indent) {
        for (int i = 0; i < indent; ++i) std::cout << "  ";
    }

    void NumberExpr::print(int indent) const {
        printIndent(indent);
        std::cout << "Number: " << value << "\n";
    }

    void IdentifierExpr::print(int indent) const {
        printIndent(indent);
        std::cout << "Identifier: " << name << "\n";
    }

    void BinaryExpr::print(int indent) const {
        printIndent(indent);
        std::cout << "BinaryExpr: " << op << "\n";
        if (left) left->print(indent + 1);
        if (right) right->print(indent + 1);
    }

}
