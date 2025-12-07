# Grammar Reference

Formal grammar specification for EZ Language.

## Overview

EZ Language uses ANTLR4 for parsing. The complete grammar is defined in `grammar/EZLanguage.g4`.

## Key Non-Terminals

### Program

The top-level structure of an EZ program:

```antlr
program : statement* EOF ;
```

A program consists of zero or more statements followed by end-of-file.

### Statement

Various statement types:

```antlr
statement
    : envDeclaration
    | includeStatement
    | friendDeclaration
    | friendFunctionCall
    | expressionStatement
    | variableDeclaration
    | controlFlow
    | foreachStatement
    ;
```

**Statement types:**
- `envDeclaration` - Environment declaration (`env native;`)
- `includeStatement` - Include directive (future)
- `friendDeclaration` - Friend module declaration
- `friendFunctionCall` - Call to friend function
- `expressionStatement` - Standalone expression
- `variableDeclaration` - Variable declaration
- `controlFlow` - If/while/for (parsed, not executed)
- `foreachStatement` - Foreach loop (parsed, not executed)

### Expression

Expression grammar:

```antlr
expression : primary (OPERATOR primary)* ;
```

Expressions consist of primary expressions connected by operators.

### Primary Expression

```antlr
primaryExpression
    : IDENTIFIER
    | literal
    | functionCall
    | friendFunctionCall
    | '(' expression ')'
    ;
```

**Primary types:**
- **Identifier** - Variable reference
- **Literal** - Number, string, or boolean literal
- **Function call** - `print(...)`, `printf(...)`
- **Friend function call** - `alias.function(...)`
- **Parenthesized expression** - `(expression)`

## Literals

### String Literal

```antlr
STRING : '"' (~["\r\n])* '"' ;
```

**Example:**
```ez
"Hello, World!"
"This is a string"
```

### Number Literal

```antlr
NUMBER : [0-9]+ ('.' [0-9]+)? ;
```

**Examples:**
```ez
42
100
// Note: Floats parsed but not yet interpreted
// 3.14
// 2.5
```

### Boolean Literal

```antlr
BOOLEAN : 'true' | 'false' ;
```

**Examples:**
```ez
true   // Evaluates to 1
false  // Evaluates to 0
```

## Friend Module Syntax

### Friend Declaration

```antlr
friendDeclaration
    : 'friend' IDENTIFIER ':' languageType 'as' IDENTIFIER ';'
    ;

languageType
    : 'c'
    | 'cpp'
    | 'python'
    ;
```

**Examples:**
```ez
friend native_math: cpp as m;
friend utils: c as u;
friend processor: python as proc;
```

**Components:**
- First `IDENTIFIER` - Source stem (filename without extension)
- `languageType` - One of `c`, `cpp`, `python`
- Second `IDENTIFIER` - Alias for calls

### Friend Function Call

```antlr
friendFunctionCall
    : IDENTIFIER '.' IDENTIFIER '(' argumentList? ')'
    ;
```

**Example:**
```ez
m.add(5, 3)
u.process(10)
proc.compute(x, y, z)
```

## Variable Declaration

```antlr
variableDeclaration
    : type IDENTIFIER '=' expression ';'
    ;

type
    : 'int'
    | 'float'
    | 'string'
    | 'bool'
    | 'void'
    | 'map' '<' type ',' type '>'
    ;
```

**Examples:**
```ez
int x = 42;
int y = x + 10;
// float z = 3.14;  // Parsed, not interpreted
```

## Access Modifiers

```antlr
accessModifier
    : 'public'
    | 'private'
    | 'protected'
    ;
```

**Usage:**
- Class members only
- Default: `public`
- `protected` parsed but not enforced

**Example:**
```ez
class Demo() {
    public int getValue() { 42; }
    private int _helper() { 100; }
}
```

## Operators

### Arithmetic Operators

Currently supported and evaluated:

| Operator | Grammar Token | Description |
|----------|---------------|-------------|
| `+` | `PLUS` | Addition |
| `-` | `MINUS` | Subtraction |
| `*` | `MULTIPLY` | Multiplication |
| `/` | `DIVIDE` | Division |

### Boolean and Comparison Operators

Parsed but not yet evaluated:

| Operator | Grammar Token | Description |
|----------|---------------|-------------|
| `==` | `EQ` | Equal to |
| `!=` | `NEQ` | Not equal to |
| `>` | `GT` | Greater than |
| `<` | `LT` | Less than |
| `>=` | `GTE` | Greater than or equal |
| `<=` | `LTE` | Less than or equal |
| `&&` | `AND` | Logical AND |
| `||` | `OR` | Logical OR |
| `!` | `NOT` | Logical NOT |

## Comments

### Line Comments

```antlr
LINE_COMMENT : '//' ~[\r\n]* -> skip ;
```

**Example:**
```ez
// This is a line comment
int x = 42;  // Comment after code
```

### Block Comments

```antlr
BLOCK_COMMENT : '/*' .*? '*/' -> skip ;
```

**Example:**
```ez
/*
 * This is a
 * block comment
 */
int y = 10;
```

## Whitespace

```antlr
WS : [ \t\r\n]+ -> skip ;
```

Whitespace is skipped and not significant in the grammar.

## Environment Declaration

```antlr
envDeclaration : 'env' IDENTIFIER ';' ;
```

**Example:**
```ez
env native;
```

**Constraint:** Only `native` is currently supported.

## Function Declarations (Classes)

```antlr
classDeclaration
    : 'class' IDENTIFIER '(' parameterList? ')' '{' classMember* '}'
    ;

classMember
    : accessModifier? functionDeclaration
    | accessModifier? variableDeclaration
    ;

functionDeclaration
    : type IDENTIFIER '(' parameterList? ')' '{' statement* '}'
    ;
```

**Example:**
```ez
class Calculator() {
    public int add(int a, int b) {
        a + b;
    }
    
    private int multiply(int x, int y) {
        x * y;
    }
}
```

**Note:** Function execution is not yet implemented.

## Built-in Functions

### print

```ez
print(expression1, expression2, ...);
```

Outputs values separated by spaces, followed by newline.

### printf

```ez
printf("format string", expression);
```

Formatted output (currently `%d` for integers).

## Grammar File Location

The complete, formal grammar is available at:

```
grammar/EZLanguage.g4
```

View it in the repository: [grammar/EZLanguage.g4](https://github.com/RedLeZ/EZ-Language/blob/main/grammar/EZLanguage.g4)

## Grammar Evolution

### Current (MVP)

- ✅ Environment declaration
- ✅ Friend module declarations
- ✅ Variable declarations (int only)
- ✅ Arithmetic expressions
- ✅ Boolean literals
- ✅ Function declarations (parsed)
- ✅ Comments

### Coming Soon

- ⏳ Boolean operators evaluation
- ⏳ Function execution
- ⏳ Control flow execution (if/while/for)
- ⏳ String variables
- ⏳ Arrays and maps

### Future

- 🔮 Generics
- 🔮 Pattern matching
- 🔮 Async/await
- 🔮 Traits/interfaces

## Precedence and Associativity

### Arithmetic Operators

Standard mathematical precedence:

1. `*`, `/` - Multiplication, Division (left-associative)
2. `+`, `-` - Addition, Subtraction (left-associative)

**Examples:**
```ez
1 + 2 * 3      // 7 (not 9)
10 / 2 * 3     // 15 (left-to-right)
(1 + 2) * 3    // 9 (parentheses override)
```

## Reserved Keywords

Keywords that cannot be used as identifiers:

```
env, friend, as, class, public, private, protected,
int, float, string, bool, void, map,
true, false,
if, else, while, for, foreach, in,
return, break, continue,
print, printf
```

## Identifiers

```antlr
IDENTIFIER : [a-zA-Z_][a-zA-Z0-9_]* ;
```

**Valid identifiers:**
- Must start with letter or underscore
- Can contain letters, digits, underscores
- Case-sensitive

**Examples:**
```ez
myVariable
_privateHelper
value123
MAX_SIZE
```

## Examples

### Complete Program

```ez
env native;

// Friend module
friend native_math: cpp as m;

// Variables
int x = 10;
int y = 20;

// Expression with friend call
int sum = m.add(x, y);
int product = x * y;

// Output
print("Sum:", sum);
print("Product:", product);
```

### Class with Functions

```ez
env native;

class Calculator() {
    public int add(int a, int b) {
        a + b;
    }
    
    private int multiply(int x, int y) {
        x * y;
    }
}

// Note: Function calls not yet executable
```

## Related Topics

- [Types](Types) - Type system details
- [Expressions](Expressions) - Expression evaluation
- [Friend Modules](Friend-Modules) - Friend module syntax
- [Functions](Functions) - Function declarations

---

**See Also:** [Types](Types) | [Expressions](Expressions) | [Friend Modules](Friend-Modules)
