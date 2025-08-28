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
```md
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
```

# Project Road Map
## 🚀 RiseLanguage: Self-Hosting Roadmap

This document outlines the complete plan to turn the [RiseLanguagePrototype](https://github.com/Modern-hub/RiseLanguagePrototype) into a **self-hosting compiler** — capable of compiling itself. Tasks are organized by development phase and can be tracked using checkboxes.

---

## 🧱 Phase 1: Environment & Project Setup
- [ ] Clone the repository and set up a C++20 toolchain (GCC, Clang, or MSVC)
- [ ] Run a basic `main.cpp` to verify setup
- [ ] Configure a build system (e.g., **CMake**)
- [ ] Create folder structure:
  - `/src`
  - `/include`
  - `/runtime`
  - `/tests`
- [ ] Add a simple CLI tool (e.g., `risec <file.rise>`)

---

## ✏️ Phase 2: Frontend (Lexer, Parser, AST, Semantic Analysis)

### Lexer
- [ ] Define `Token` struct
- [ ] Recognize identifiers, literals, keywords, operators, punctuation
- [ ] Handle whitespace and comments
- [ ] Error handling for invalid tokens
- [ ] Write unit tests for the lexer

### Parser
- [ ] Define AST node structure
- [ ] Implement grammar rules for:
  - Expressions
  - Variable declarations
  - Function definitions
  - Control structures (`if`, `while`, etc.)
- [ ] Add AST printing for debugging
- [ ] Write parser unit tests

### Semantic Analysis
- [ ] Symbol table
- [ ] Type checking
- [ ] Scope handling
- [ ] Error reporting for semantic issues
- [ ] Semantic analysis unit tests

---

## ⚙️ Phase 3: Intermediate Representation (IR) & Optimizations
- [ ] Design a custom IR or three-address code
- [ ] Translate AST → IR
- [ ] Implement IR printing for debugging
- [ ] Basic optimizations:
  - [ ] Constant folding
  - [ ] Dead code elimination

---

## 🛠️ Phase 4: Code Generation (Backend)

### Option A: LLVM Backend (recommended for early progress)
- [ ] Map custom IR → LLVM IR
- [ ] Integrate LLVM backend
- [ ] Emit object files / executables
- [ ] Link with system linker

### Option B: Custom Backend (for full self-hosting)
- [ ] Generate basic x86-64 or RISC-V assembly
- [ ] Emit `.s` files or binary code directly

---

## 🧰 Phase 5: Runtime Library
- [ ] Basic I/O functions (print, input)
- [ ] Memory allocation helpers (malloc/free or custom)
- [ ] Entry point (`main` or `start`)
- [ ] Link runtime with compiled Rise programs

---

## 🧪 Phase 6: Testing & CI
- [ ] Unit tests (lexer, parser, semantic analyzer)
- [ ] Integration tests (compile + run Rise programs)
- [ ] `/tests` directory with `.rise` test files
- [ ] Set up CI (GitHub Actions or similar)
- [ ] Auto-run tests on push / pull requests

---

## 📚 Phase 7: Documentation
- [ ] Language syntax reference
- [ ] Semantics overview
- [ ] Compiler architecture (how each module works)
- [ ] Developer guide (how to build, test, contribute)
- [ ] Example programs written in Rise

---

## 📦 Phase 8: CLI Tooling & Packaging
- [ ] Compile Rise source via `risec`
- [ ] Support flags: `--emit-llvm`, `--run`, `--debug-ast`
- [ ] Provide prebuilt binaries (Linux, macOS, Windows)
- [ ] Package release archive (tarball, installer, script)

---

## 🌀 Phase 9: Self-Hosting Milestone
- [ ] Rewrite key compiler components in Rise:
  - IR / AST definitions
  - Lexer or parser implemented in Rise
- [ ] Compile the Rise compiler using Rise itself
- [ ] Verify output matches the C++-based version
- [ ] 🎉 Celebrate full self-hosting!

---

## ✅ Progress Overview

| Component           | Status        |
|--------------------|---------------|
| Lexer              | ☐ Not started |
| Parser             | ☐ Not started |
| Semantic Analyzer  | ☐ Not started |
| IR Generator       | ☐ Not started |
| Code Generation    | ☐ Not started |
| Runtime Library    | ☐ Not started |
| Testing & CI       | ☐ Not started |
| Documentation      | ☐ Not started |
| CLI & Packaging    | ☐ Not started |
| Self-Hosting       | ☐ Not started |

---
