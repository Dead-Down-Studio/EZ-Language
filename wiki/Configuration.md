# Configuration

Configuration system for EZ Language: customize compilers, Python interpreter, and build settings.

## Overview

EZ Language uses configuration files to control toolchain settings, allowing you to specify which Python interpreter, C/C++ compilers, and build options to use for your projects.

## Configuration Files

Configuration is loaded in priority order (later overrides earlier):

1. **User-level config:** `~/.ezconfig` (optional)
   - Sets defaults for all your EZ projects
   - Good for personal preferences

2. **Project-level config:** `<project>/.ezconfig` (optional)
   - Overrides user config for this specific project
   - Commit to version control for team consistency

3. **Environment variables:** (highest priority)
   - `PYTHON` - Python executable path
   - `PY_CFLAGS` - Python compile flags
   - `PY_LDFLAGS` - Python linker flags
   - `CC` - C compiler
   - `CXX` - C++ compiler

## Configuration Format

`.ezconfig` uses a simple TOML-like key-value format with sections:

```toml
[python]
# Python interpreter to use (default: python3)
executable = "python3"

[c]
# C compiler (default: clang)
compiler = "clang"
# C standard (default: c11)
standard = "c11"
# Extra compiler flags (optional)
flags = "-O2 -Wall"

[cpp]
# C++ compiler (default: clang++)
compiler = "clang++"
# C++ standard (default: c++17)
standard = "c++17"
# Extra compiler flags (optional)
flags = "-O2 -Wall"

[build]
# Output directory for compiled friend modules (default: .ezbuild)
output_dir = ".ezbuild"
# Verbose build output (default: false)
verbose = false
```

## Configuration Sections

### `[python]` Section

Configure Python interpreter for Python friend modules.

**Options:**

- **`executable`** - Path to Python interpreter
  - Default: `python3`
  - Examples: `python3.11`, `/usr/local/bin/python3.12`

**Example:**

```toml
[python]
executable = "python3.11"
```

### `[c]` Section

Configure C compiler settings.

**Options:**

- **`compiler`** - C compiler command
  - Default: `clang`
  - Examples: `gcc`, `cc`

- **`standard`** - C language standard
  - Default: `c11`
  - Examples: `c99`, `c11`, `c17`

- **`flags`** - Additional compiler flags
  - Default: (none)
  - Example: `"-O2 -Wall -Wextra"`

**Example:**

```toml
[c]
compiler = "gcc"
standard = "c11"
flags = "-O2 -Wall"
```

### `[cpp]` Section

Configure C++ compiler settings.

**Options:**

- **`compiler`** - C++ compiler command
  - Default: `clang++`
  - Examples: `g++`, `c++`

- **`standard`** - C++ language standard
  - Default: `c++17`
  - Examples: `c++11`, `c++14`, `c++17`, `c++20`

- **`flags`** - Additional compiler flags
  - Default: (none)
  - Example: `"-O2 -Wall -Wextra"`

**Example:**

```toml
[cpp]
compiler = "g++"
standard = "c++20"
flags = "-O3 -march=native"
```

### `[build]` Section

Configure build output and behavior.

**Options:**

- **`output_dir`** - Directory for compiled friend modules
  - Default: `.ezbuild`
  - Example: `build/friends`

- **`verbose`** - Show verbose build output by default
  - Default: `false`
  - Values: `true`, `false`

**Example:**

```toml
[build]
output_dir = "build/friends"
verbose = true
```

## Common Use Cases

### Use Specific Python Version

**Pyenv:**

```toml
[python]
executable = "/Users/you/.pyenv/versions/3.11.5/bin/python3"
```

**Anaconda:**

```toml
[python]
executable = "/Users/you/anaconda3/bin/python"
```

**System Python:**

```toml
[python]
executable = "/usr/local/bin/python3.11"
```

**Alternatively**, activate desired Python environment first:

```bash
pyenv shell 3.11.5
./build/ez_main program.ez --build --run
```

### Use GCC Instead of Clang

```toml
[c]
compiler = "gcc"

[cpp]
compiler = "g++"
```

### Use Different C++ Standard

```toml
[cpp]
standard = "c++20"
```

### Custom Build Directory

```toml
[build]
output_dir = "build/friends"
```

### Optimization Flags

```toml
[c]
flags = "-O3 -march=native"

[cpp]
flags = "-O3 -march=native"
```

### Debug Build

```toml
[c]
flags = "-g -O0"

[cpp]
flags = "-g -O0"
```

## Precedence Rules

Configuration values are resolved in this order (highest priority first):

1. **Environment variables** (highest)
2. **Project `.ezconfig`**
3. **User `~/.ezconfig`**
4. **Built-in defaults** (lowest)

### Example: Python Resolution

For the Python executable:

1. `$PYTHON` environment variable (if set)
2. `[python] executable` in `<project>/.ezconfig` (if exists)
3. `[python] executable` in `~/.ezconfig` (if exists)
4. Default: `python3`

### Example: C++ Compiler Resolution

For the C++ compiler:

1. `$CXX` environment variable (if set)
2. `[cpp] compiler` in `<project>/.ezconfig` (if exists)
3. `[cpp] compiler` in `~/.ezconfig` (if exists)
4. Default: `clang++`

## Environment Variables

### Override via Environment

Environment variables always have highest priority:

```bash
export PYTHON="/usr/local/bin/python3.11"
export CXX="g++"
export CC="gcc"
./build/ez_main program.ez --build --run
```

### Python-Specific

```bash
export PYTHON="/path/to/python3"
export PY_CFLAGS="-I/usr/include/python3.11"
export PY_LDFLAGS="-L/usr/lib/python3.11 -lpython3.11"
```

### Compiler-Specific

```bash
export CC="gcc-12"
export CXX="g++-12"
export CFLAGS="-O2 -Wall"
export CXXFLAGS="-O2 -Wall -std=c++20"
```

## Checking Active Configuration

### View Build Plan

See what compilers will be used:

```bash
./build/ez_main program.ez --plan --verbose
```

**Output shows:**
- Compiler commands
- Resolved Python paths
- Compile flags

### Check Environment Info

```bash
./build/ez_main program.ez --env-info
```

Shows active environment configuration.

## Example Configuration Files

### User Config: `~/.ezconfig`

Personal defaults for all projects:

```toml
[python]
executable = "/Users/you/.pyenv/versions/3.11.5/bin/python3"

[cpp]
compiler = "clang++"
standard = "c++20"
flags = "-O2 -Wall"

[build]
verbose = false
```

### Project Config: `.ezconfig`

Project-specific settings (commit to repo):

```toml
[python]
# Use Python 3.11 for this project
executable = "python3.11"

[cpp]
# This project uses C++20 features
compiler = "g++"
standard = "c++20"
flags = "-O2 -Wall -Wextra"

[build]
# Build artifacts in custom directory
output_dir = "build/native"
```

## Template

See `.ezconfig.example` in the repository root for a complete annotated example:

```bash
cat .ezconfig.example
```

## Troubleshooting

### Wrong Python Version Used

**Check precedence:**

1. Is `$PYTHON` environment variable set? (Unset if unwanted)
2. Check project `.ezconfig`
3. Check user `~/.ezconfig`

**Debug:**

```bash
# See what Python is being used
./build/ez_main program.ez --plan --verbose | grep python

# Or use --env-info
./build/ez_main program.ez --env-info
```

### Compiler Not Found

```
Error: compiler 'g++' not found
```

**Fix:**

1. Install the compiler
2. Specify full path in `.ezconfig`:

```toml
[cpp]
compiler = "/usr/local/bin/g++"
```

### Conflicting Configurations

If both `.ezconfig` and environment variables are set, environment variables win.

**To prefer `.ezconfig`:**

```bash
# Unset environment variables
unset PYTHON
unset CC
unset CXX
./build/ez_main program.ez --build --run
```

## Future Extensions

Planned configuration options:

### Additional Languages

```toml
[rust]
compiler = "rustc"
edition = "2021"

[mojo]
compiler = "mojo"
```

### Nix Integration

```toml
[nix]
auto_activate = true
shell_file = ".ez-env.nix"
```

### Package Management

```toml
[package]
name = "my-project"
version = "0.1.0"
dependencies = ["math-utils@1.0"]
```

## Related Topics

- [CLI Reference](CLI-Reference) - Command-line flags
- [Friend Modules](Friend-Modules) - Building friend modules
- [Nix Environments](Nix-Environments) - Nix integration
- [Embedding Native Code](Embedding-Native-Code) - Native code compilation

---

**See Also:** [CLI Reference](CLI-Reference) | [Friend Modules](Friend-Modules) | [Nix Environments](Nix-Environments)
