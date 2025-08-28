# Rise Language Syntax

## 1. Introduction
Rise is a high-performance, statically typed programming language designed for speed and efficiency. This document defines the basic syntax and constructs of the language.

---

## 2. Basic Lexical Elements

### 2.1 Identifiers
- Consist of letters (a-z, A-Z), digits (0-9), and underscores (_)
- Must begin with a letter or underscore
- Case-sensitive

# Functions Syntax
## Defining a Function
Funkcje w Rise definiuje się za pomocą prefiksu `func`, następnie podaje się typ zwracany, nazwę funkcji oraz listę parametrów w nawiasach. Ciało funkcji znajduje się w nawiasach klamrowych `{}`.

### Składnia ogólna:
```rise
func <return_type> <function_name>(<parameters>) {
    // ciało funkcji
}
```
