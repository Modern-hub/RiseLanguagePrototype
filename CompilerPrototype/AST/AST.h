#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct ASTNode {
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
};

using ASTNodePtr = std::unique_ptr<ASTNode>;

struct Expression : ASTNode {};

struct StringExpr : Expression {
    std::string value;
    explicit StringExpr(std::string val) : value(std::move(val)) {}
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "StringExpr: \"" << value << "\"\n";
    }
};

struct CallExpr : Expression {
    std::string callee;
    std::vector<ASTNodePtr> args;
    CallExpr(std::string calleeName, std::vector<ASTNodePtr> arguments)
        : callee(std::move(calleeName)), args(std::move(arguments)) {
    }
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "CallExpr: " << callee << "\n";
        for (const auto& arg : args)
            arg->print(indent + 2);
    }
};
