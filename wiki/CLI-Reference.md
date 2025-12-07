# CLI Reference

Complete command-line interface documentation for EZ Language.

## Overview

The EZ Language interpreter is invoked via the `ez_main` binary.

**Basic usage:**

```bash
./build/ez_main <file.ez> [flags]
```

## Command-Line Flags

### Execution Flags

#### `--run`

Execute the interpreter and run the EZ program.

```bash
./build/ez_main program.ez --run
```

**Output:** User `print` and `printf` statements (quiet mode).

#### `--verbose` / `-v`

Show detailed execution information.

```bash
./build/ez_main program.ez --run --verbose
./build/ez_main program.ez --run -v
```

**Verbose output includes:**
- Environment banner
- Friend module build plan
- Compile and link commands
- Expression evaluation results (`=>`)
- Variable state tracking

### Build Flags

#### `--build`

Build friend modules before execution.

```bash
./build/ez_main program.ez --build
./build/ez_main program.ez --build --run
```

Compiles friend modules and creates shared libraries in `.ezenv/build/`.

#### `--plan`

Show the friend module build plan without actually building.

```bash
./build/ez_main program.ez --plan
```

**Recommended:** Use with `--verbose` for detailed output:

```bash
./build/ez_main program.ez --plan --verbose
```

### Code Generation Flags

#### `--emit-c`

Generate C source code from EZ program.

```bash
./build/ez_main program.ez --emit-c
```

**Output:** C source files in `.ezenv/codegen/`

**Note:** Currently supports integer-only subset.

#### `--build-native`

Compile emitted C code to native executable.

```bash
./build/ez_main program.ez --build-native
```

Implies `--emit-c`. Creates native binary in `.ezenv/codegen/`.

#### `--run-native`

Build and run the native executable.

```bash
./build/ez_main program.ez --run-native
```

Implies `--emit-c` and `--build-native`.

### Environment Flags

#### `--prepare`

Prepare the Nix environment (download dependencies).

```bash
./build/ez_main program.ez --prepare
```

Useful for pre-fetching environment dependencies before running.

#### `--env-info`

Display environment configuration information.

```bash
./build/ez_main program.ez --env-info
```

Shows:
- Environment type
- Configuration source
- Nix environment status

#### `--no-env`

Skip environment activation.

```bash
./build/ez_main program.ez --run --no-env
```

Runs without activating Nix environment (if applicable).

## Quiet vs Verbose Output

### Comparison Matrix

| Feature | Quiet (Default) | Verbose (`--verbose`) |
|---------|-----------------|----------------------|
| Environment banner | Hidden | Shown |
| Friend build plan | Hidden | Shown |
| Compile/link commands | Hidden | Shown |
| Expression results (`=>`) | Hidden | Shown |
| Variable state | Hidden | Shown |
| User `print` output | **Shown** | **Shown** |
| User `printf` output | **Shown** | **Shown** |

### Quiet Mode Example

```bash
./build/ez_main program.ez --run
```

**Output:**
```
Hello, World!
Result: 42
```

### Verbose Mode Example

```bash
./build/ez_main program.ez --run --verbose
```

**Output:**
```
==== Environment: native ====

Friend build plan:
  - native_math (cpp) as m
    Source: examples/native_math.cpp
    Output: .ezenv/build/libm.dylib

Compiling native_math.cpp...
c++ -shared -fPIC -o .ezenv/build/libm.dylib examples/native_math.cpp

=> evaluating: m.add(5, 3)
=> result: 8

Variable x = 8

Hello, World!
Result: 42
```

## Common Command Patterns

### Quick Run

```bash
./build/ez_main program.ez --run
```

### Build and Run

```bash
./build/ez_main program.ez --build --run
```

### Debug Mode

```bash
./build/ez_main program.ez --build --run --verbose
```

### Check Build Plan

```bash
./build/ez_main program.ez --plan --verbose
```

### Generate and Run Native Code

```bash
./build/ez_main program.ez --run-native
```

### Prepare Environment

```bash
./build/ez_main program.ez --prepare
./build/ez_main program.ez --run
```

## Flag Combinations

### Compatible Combinations

```bash
# Build friend modules and run with verbose output
./build/ez_main program.ez --build --run --verbose

# Generate C and build native
./build/ez_main program.ez --emit-c --build-native

# Prepare environment and run
./build/ez_main program.ez --prepare --run

# Show plan in verbose mode
./build/ez_main program.ez --plan --verbose
```

### Exclusive Flags

Some flags don't make sense together:

```bash
# Don't use --run and --run-native together
# Choose one execution mode
./build/ez_main program.ez --run        # Interpret
./build/ez_main program.ez --run-native # Native execution
```

## Output Directories

### `.ezenv/`

Main EZ environment directory created in the project root:

```
.ezenv/
├── build/          # Friend module shared libraries
│   ├── libm.dylib
│   └── libutils.so
├── codegen/        # Generated C code
│   ├── program.c
│   └── program_native
└── cache/          # Build cache (future)
```

### Build Artifacts

**Friend modules:**
- macOS: `.ezenv/build/lib<alias>.dylib`
- Linux: `.ezenv/build/lib<alias>.so`
- Windows: `.ezenv/build/<alias>.dll`

**Generated C code:**
- Source: `.ezenv/codegen/<program>.c`
- Binary: `.ezenv/codegen/<program>_native`

## Exit Codes

| Code | Meaning |
|------|---------|
| `0` | Success |
| `1` | General error (parse error, semantic error, etc.) |
| `2` | File not found |
| `3` | Build error (friend module compilation failed) |

## Environment Variables

### Python Configuration

- **`PYTHON`** - Python executable path (overrides `.ezconfig`)
- **`PY_CFLAGS`** - Python compile flags
- **`PY_LDFLAGS`** - Python linker flags

**Example:**

```bash
export PYTHON="/usr/local/bin/python3.11"
./build/ez_main program.ez --build --run
```

### Compiler Configuration

Set custom compilers:

```bash
export CC="gcc"
export CXX="g++"
./build/ez_main program.ez --build --run
```

Learn more: [Configuration](Configuration)

## Examples

### Example 1: Simple Run

```bash
./build/ez_main examples/hello.ez --run
```

### Example 2: Friend Module Build

```bash
./build/ez_main examples/demo.ez --build --run
```

### Example 3: Debug Build

```bash
./build/ez_main examples/demo.ez --build --run --verbose
```

### Example 4: Check Build Plan

```bash
./build/ez_main examples/demo.ez --plan --verbose
```

### Example 5: Native Code Generation

```bash
./build/ez_main examples/math.ez --emit-c
cat .ezenv/codegen/math.c
```

### Example 6: Native Execution

```bash
./build/ez_main examples/math.ez --run-native
```

### Example 7: Environment Info

```bash
./build/ez_main examples/demo.ez --env-info
```

## Troubleshooting

### Command Not Found

```
bash: ./build/ez_main: No such file or directory
```

**Fix:** Build the project first:

```bash
cmake -S . -B build
cmake --build build
```

### Permission Denied

```
bash: ./build/ez_main: Permission denied
```

**Fix:** Make the binary executable:

```bash
chmod +x ./build/ez_main
```

### File Not Found

```
Error: could not open file: program.ez
```

**Fix:** Check the file path:

```bash
ls -l program.ez
./build/ez_main ./program.ez --run
```

## Related Topics

- [Quickstart](Quickstart) - Get started quickly
- [Configuration](Configuration) - Configure compilers and tools
- [Printing and Debugging](Printing-and-Debugging) - Verbose mode details
- [Friend Modules](Friend-Modules) - Build flags for friend modules

---

**See Also:** [Configuration](Configuration) | [Quickstart](Quickstart) | [Printing and Debugging](Printing-and-Debugging)
