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

### Przyklady
```rise
func int32_t add(int32 x, int32 y) {
    return 0; // default
}

func void add(int32 x, int32 y) {
    return; // early exit (default none)
}

func bool add(int32 x, int32 y) {
    return false/true // default retun false;
}
```

### Types
Rise wspiera następujące typy liczb całkowitych oraz zmiennoprzecinkowych o różnej precyzji:

| Typ        | Zakres (przykładowy)                | Rozmiar w bitach | Opis                                |
|------------|-----------------------------------|------------------|------------------------------------|
| `int8`     | -128 do 127                       | 8                | Signed 8-bit integer                |
| `uint8`    | 0 do 255                         | 8                | Unsigned 8-bit integer              |
| `int16`    | -32,768 do 32,767                | 16               | Signed 16-bit integer               |
| `uint16`   | 0 do 65,535                     | 16               | Unsigned 16-bit integer             |
| `int32`    | -2,147,483,648 do 2,147,483,647 | 32               | Signed 32-bit integer               |
| `uint32`   | 0 do 4,294,967,295              | 32               | Unsigned 32-bit integer             |
| `int64`    | -9,223,372,036,854,775,808 do 9,223,372,036,854,775,807 | 64 | Signed 64-bit integer       |
| `uint64`   | 0 do 18,446,744,073,709,551,615  | 64               | Unsigned 64-bit integer             |
| `int128`   | bardzo duża liczba                | 128              | Signed 128-bit integer              |
| `uint128`  | bardzo duża liczba (0 do 2^128-1) | 128              | Unsigned 128-bit integer            |
| `int256`   | bardzo duża liczba                | 256              | Signed 256-bit integer              |
| `uint256`  | bardzo duża liczba (0 do 2^256-1) | 256              | Unsigned 256-bit integer            |
| `int512`   | bardzo duża liczba                | 512              | Signed 512-bit integer              |
| `uint512`  | bardzo duża liczba (0 do 2^512-1) | 512              | Unsigned 512-bit integer            |
| `int1024`  | bardzo duża liczba                | 1024             | Signed 1024-bit integer             |
| `uint1024` | bardzo duża liczba (0 do 2^1024-1) | 1024             | Unsigned 1024-bit integer           |

### Floating-point Types (Typy zmiennoprzecinkowe)

| Typ         | Rozmiar w bitach | Zakres (przykładowy)                | Opis                                           |
|-------------|------------------|------------------------------------|------------------------------------------------|
| `float8`    | 8                | ~±8.0e-2 (ok. 2-3 cyfry znaczące) | Bardzo niska precyzja, typ eksperymentalny. Wymaga własnej implementacji. Przydatny do ultra-szybkich obliczeń lub ML. |
| `float16`   | 16               | ±6.55e-5 do ±6.55e4 (ok. 3-4 cyfry znaczące) | Półprecyzyjny (half precision), zgodny z IEEE 754. Często stosowany w grafice i ML. |
| `float32`   | 32               | ±1.4e-45 do ±3.4e38 (ok. 6-9 cyfr znaczących) | Pojedyncza precyzja, standard IEEE 754 float. Najczęściej używany typ zmiennoprzecinkowy. |
| `float64`   | 64               | ±4.9e-324 do ±1.8e308 (ok. 15-17 cyfr znaczących) | Podwójna precyzja, standard IEEE 754 double. Standard w większości zastosowań naukowych i inżynierskich. |
| `float128`  | 128              | Bardzo szeroki zakres i wysoka precyzja       | Czterokrotna precyzja (quadruple precision). Wymaga specjalnych bibliotek lub własnej implementacji. |

### Double Precision Types (Typy podwójnej precyzji)

| Typ          | Rozmiar w bitach | Zakres (przykładowy)                      | Opis                                                                                  |
|--------------|------------------|------------------------------------------|---------------------------------------------------------------------------------------|
| `double8`    | 8                | Bardzo ograniczony zakres i precyzja     | Eksperymentalny typ double, odpowiednik `int8` w świecie zmiennoprzecinkowym. Wymaga własnej implementacji. |
| `double16`   | 16               | ±6.55e-5 do ±6.55e4 (ok. 3-4 cyfry znaczące) | Półprecyzyjny (half precision) double, eksperymentalny. Wymaga własnej implementacji. |
| `double32`   | 32               | ±1.4e-45 do ±3.4e38 (ok. 6-9 cyfr znaczących) | Single precision, zgodny ze standardem IEEE 754 float. Odpowiednik `int32`.            |
| `double64`   | 64               | ±4.9e-324 do ±1.8e308 (ok. 15-17 cyfr znaczących) | Podwójna precyzja, standard IEEE 754 double. Odpowiednik `int64`.                     |
| `double128`  | 128              | Bardzo szeroki zakres i wysoka precyzja  | Czterokrotna precyzja (quadruple precision). Wymaga specjalnych bibliotek lub własnej implementacji. Odpowiednik `int128`. |




