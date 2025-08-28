# RiseLanguagePrototype

Prototype of the Rise programming language compiler implemented in C++20.  
A high-performance programming language aiming to beat C++ in execution speed by 100x or more.

## Project Goals

- Design a new programming language focused on extreme runtime performance.  
- Build a compiler prototype in C++20 covering lexing, parsing, AST, semantic analysis, optimization, IR, code generation, and linking.  
- Develop a custom runtime library for efficient memory management and standard functions.  
- Create thorough unit and integration tests for each component.  
- Document language specifications and design decisions clearly.

## Project Structure

RiseLanguagePrototype/
├── 1. Source/
│    └── Programs written in Rise language syntax
│
├── 2. CompilerPrototype/
│    ├── Lexer/                  # Tokenizer: breaks source code into tokens
│    ├── Parser/                 # Parses tokens and builds the AST (Abstract Syntax Tree)
│    ├── AST/                    # Defines AST node structures and manipulation functions
│    ├── SemanticAnalyzer/       # Checks types, scopes, and language rules for correctness
│    ├── Optimizer/              # Implements code optimizations (optional but recommended)
│    ├── IntermediateRepresentation/  # Designs custom IR or direct machine code generation
│    ├── CodeGenerator/          # Generates machine code or binary executable for target CPU
│    └── Linker/                 # Combines machine code modules into final executable (if needed)
│
├── 3. Runtime/
│    └── Runtime libraries: memory management, standard library functions
│
├── 4. Tests/
│    └── Unit and integration tests for each compiler component
│
└── 5. Docs/
     └── Language specification, design docs, tutorials
