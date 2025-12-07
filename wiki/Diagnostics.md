# Diagnostics

Complete error and warning messages reference for EZ Language.

## Overview

EZ Language provides clear diagnostic messages to help you identify and fix issues in your code. This page catalogs all diagnostic messages with their causes and fixes.

## Environment Errors

### Missing Environment Declaration

**Message:**
```
Error: missing environment declaration
```

**Cause:** Your program doesn't start with an environment declaration.

**Fix:** Add `env native;` as the first line:

```ez
env native;
int x = 42;
print("x:", x);
```

### Unsupported Environment

**Message:**
```
Error: only the 'native' environment is supported
```

**Cause:** You specified an environment other than `native`.

**Example:**
```ez
env vm;  // Not supported
```

**Fix:** Change to `env native;`:

```ez
env native;
```

## Friend Module Errors

### Friend Source File Not Found

**Message:**
```
Error: friend source file not found: <filename>
```

**Cause:** The declared friend module source file doesn't exist.

**Example:**
```ez
friend math_utils: cpp as m;  // math_utils.cpp not found
```

**Fix:**
1. Create the source file with the correct name
2. Ensure the file is in the correct directory
3. Check for typos in the friend declaration

```bash
# Create the file
touch math_utils.cpp

# Or fix the name in your .ez file
friend native_math: cpp as m;  # Correct name
```

### Unsupported Friend Language

**Message:**
```
Error: unsupported friend language: <language>
```

**Cause:** You specified a language that isn't supported.

**Example:**
```ez
friend utils: rust as r;  // Rust not yet supported
```

**Supported languages:** `c`, `cpp`, `python`

**Fix:** Use a supported language:

```ez
friend utils: cpp as r;
```

### Duplicate Friend Alias

**Message:**
```
Error: duplicate friend module alias: <alias>
```

**Cause:** Same alias used for multiple friend modules.

**Example:**
```ez
friend math_a: cpp as m;
friend math_b: cpp as m;  // Error: 'm' already used
```

**Fix:** Use unique aliases:

```ez
friend math_a: cpp as ma;
friend math_b: cpp as mb;
```

### Inconsistent Argument Count

**Message:**
```
Error: inconsistent argument count for function '<function>'
```

**Cause:** Same friend function called with different number of arguments.

**Example:**
```ez
friend native_math: cpp as m;
int x = m.add(1, 2);      // 2 arguments
int y = m.add(3, 4, 5);   // 3 arguments - inconsistent!
```

**Fix:** Ensure all calls use the same number of arguments:

```ez
int x = m.add(1, 2);
int y = m.add(3, 4);
```

### Dynamic Library Loading Failed

**Message:**
```
Error: dlopen failed: <library>
```

**Cause:** Shared library for friend module not built or not found.

**Fix:** Use `--build` flag before `--run`:

```bash
./build/ez_main program.ez --build --run
```

## Variable Errors

### Unknown Identifier

**Message:**
```
Error: unknown identifier '<name>'
```

**Cause:** Variable not declared before use.

**Example:**
```ez
env native;
print(x);  // Error: x not declared
```

**Fix:** Declare the variable first:

```ez
env native;
int x = 42;
print(x);
```

### Variable Already Declared

**Message:**
```
Error: variable '<name>' already declared
```

**Cause:** Duplicate variable declaration.

**Example:**
```ez
env native;
int x = 10;
int x = 20;  // Error: x already declared
```

**Fix:** Use different names or remove the duplicate:

```ez
env native;
int x = 10;
int y = 20;
```

### Unsupported Variable Type

**Message:**
```
Error: only 'int' variables are supported in interpreter
```

**Cause:** Trying to declare a non-int variable.

**Example:**
```ez
env native;
float x = 3.14;  // Error: float not yet supported
```

**Fix:** Use `int` type:

```ez
env native;
int x = 3;
```

## Expression Errors

### Division by Zero

**Message:**
```
Error: division by zero
```

**Cause:** Division or modulo operation with zero divisor.

**Example:**
```ez
env native;
int x = 10 / 0;  // Error
```

**Fix:** Ensure divisor is non-zero:

```ez
env native;
int divisor = 5;
int x = 10 / divisor;
```

### Operator Not Supported

**Message:**
```
Error: operator '<op>' not supported
```

**Cause:** Using an operator that exists in grammar but isn't yet evaluated.

**Example:**
```ez
env native;
int result = (5 > 3);  // Error: '>' not yet implemented
```

**Supported operators:** `+`, `-`, `*`, `/`

**Fix:** Use supported operators or wait for future support:

```ez
env native;
int result = 5 + 3;
```

### Unsupported Literal

**Message:**
```
Error: floating point literals not supported yet
```

**Cause:** Using float literal.

**Example:**
```ez
env native;
int x = 3.14;  // Error
```

**Fix:** Use integer literals:

```ez
env native;
int x = 3;
```

### Unsupported Primary Expression

**Message:**
```
Error: unsupported primary expression
```

**Cause:** Expression form not yet implemented.

**Fix:** Use supported expression forms (variables, literals, function calls, friend calls, parenthesized expressions).

## Access Control Errors

### Private Method Access

**Message:**
```
Error: cannot call private method '<name>' outside class scope
```

**Cause:** Trying to call a private method from outside its class.

**Example:**
```ez
env native;
class Demo() {
    private int secret() { 42; }
}
secret();  // Error: private method
```

**Fix:**
1. Make the method public
2. Call it from within the class
3. Use a public wrapper method

```ez
class Demo() {
    public int getSecret() {
        secret();
    }
    private int secret() { 42; }
}
```

### Invalid Modifier on Top-Level Declaration

**Message:**
```
Error: access modifiers not allowed on top-level variable declarations
```

**Cause:** Using visibility modifier on top-level variable.

**Example:**
```ez
env native;
private int x = 10;  // Error
```

**Fix:** Remove the modifier:

```ez
env native;
int x = 10;
```

### Private Friend Function Access

**Message:**
```
Error: cannot call private function: <alias>.<function>
```

**Cause:** Trying to call a friend function that starts with underscore (private convention).

**Example:**
```cpp
// native_math.cpp
extern "C" int _internalHelper(int x) { return x * 2; }
```

```ez
friend native_math: cpp as m;
int result = m._internalHelper(5);  // Error: private
```

**Fix:** Don't call functions starting with underscore, or remove the underscore from the C/C++ function name.

## Function Errors

### Function Call Not Supported

**Message:**
```
Error: function calls are not supported in interpreter (only print/printf)
```

**Cause:** Trying to call a user-defined function (not yet implemented).

**Example:**
```ez
class Calculator() {
    public int add(int a, int b) { a + b; }
}
add(5, 3);  // Error: function execution not implemented
```

**Fix:** Use friend modules for now:

```cpp
// calc.cpp
extern "C" int add(int a, int b) { return a + b; }
```

```ez
friend calc: cpp as c;
int result = c.add(5, 3);
```

### Too Many Arguments

**Message:**
```
Error: only up to 4 int arguments supported
```

**Cause:** Friend function call with more than 4 arguments.

**Example:**
```ez
friend utils: cpp as u;
int result = u.compute(1, 2, 3, 4, 5);  // Error: 5 arguments
```

**Fix:** Reduce argument count or refactor function:

```ez
// Option 1: Fewer arguments
int result = u.compute(1, 2, 3, 4);

// Option 2: Pass intermediate result
int partial = u.compute(1, 2, 3, 4);
int result = u.compute(partial, 5, 0, 0);
```

### No Library Found for Alias

**Message:**
```
Error: no library found for alias '<alias>'
```

**Cause:** Friend module not declared or not built.

**Fix:**
1. Ensure friend module is declared
2. Use `--build` flag

```ez
env native;
friend native_math: cpp as m;  // Declare
```

```bash
./build/ez_main program.ez --build --run
```

## Type Errors

### Only Numeric and Boolean Literals Supported

**Message:**
```
Error: only numeric and boolean literals are supported
```

**Cause:** Using unsupported literal type.

**Fix:** Use supported literals (integers, true, false, or strings in print).

## Build Errors

### Compilation Failed

**Message:**
```
Error: compilation failed for <file>
```

**Cause:** C/C++ source code has syntax errors.

**Fix:**
1. Check the compiler output (use `--verbose`)
2. Fix syntax errors in the native code
3. Ensure `extern "C"` for C++ code

```bash
# See detailed error
./build/ez_main program.ez --build --verbose
```

## Summary Table

| Message Pattern | Quick Fix |
|-----------------|-----------|
| missing environment declaration | Add `env native;` first |
| only the 'native' environment is supported | Use `env native;` |
| friend source file not found | Create/check source file |
| unsupported friend language | Use `c`, `cpp`, or `python` |
| duplicate friend alias | Use unique aliases |
| inconsistent argument count | Match argument counts |
| dlopen failed | Use `--build` before `--run` |
| unknown identifier | Declare variable first |
| variable already declared | Rename or remove duplicate |
| division by zero | Check divisor is non-zero |
| operator not supported | Use `+`, `-`, `*`, `/` only |
| cannot call private method | Make public or use wrapper |
| access modifiers not allowed on top-level | Remove modifier |
| function calls not supported | Use friend modules |
| only up to 4 int arguments supported | Reduce arguments |

## Reporting Issues

If you encounter an error message not listed here or believe a diagnostic is incorrect:

1. Enable verbose mode: `--verbose`
2. Check the examples in this wiki
3. [Report an issue](https://github.com/RedLeZ/EZ-Language/issues) with:
   - Full error message
   - Minimal code example
   - Expected vs actual behavior

## Related Topics

- [Quickstart](Quickstart) - Get started without errors
- [Friend Modules](Friend-Modules) - Friend module error details
- [Types](Types) - Type-related errors
- [CLI Reference](CLI-Reference) - Command-line usage

---

**See Also:** [CLI Reference](CLI-Reference) | [Friend Modules](Friend-Modules) | [Quickstart](Quickstart)
