#pragma once
#include <memory>
#include <string>
#include "../AST/AST.h"


std::string generateCppCode(const ASTNode* ast);
