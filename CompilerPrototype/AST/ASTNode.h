#pragma once
#include <memory>
#include <string>
#include <vector>

namespace Rise {

    class ASTNode {
    public:
        virtual ~ASTNode() = default;
        virtual void print(int indent = 0) const = 0;
    };

    using ASTNodePtr = std::unique_ptr<ASTNode>;

    class Expression : public ASTNode {
    };

    class NumberExpr : public Expression {
    public:
        int value;
        NumberExpr(int val) : value(val) {}

        void print(int indent = 0) const override;
    };

    class IdentifierExpr : public Expression {
    public:
        std::string name;
        IdentifierExpr(const std::string& n) : name(n) {}

        void print(int indent = 0) const override;
    };

    class BinaryExpr : public Expression {
    public:
        std::string op;
        ASTNodePtr left;
        ASTNodePtr right;

        BinaryExpr(std::string oper, ASTNodePtr lhs, ASTNodePtr rhs)
            : op(std::move(oper)), left(std::move(lhs)), right(std::move(rhs)) {
        }

        void print(int indent = 0) const override;
    };

}
