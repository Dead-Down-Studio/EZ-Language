# Nix Environments

Reproducible development environments with Nix integration in EZ Language.

## Overview

EZ Language automatically integrates with Nix when available, providing reproducible development environments with guaranteed consistent toolchain versions across different machines.

## Why Nix?

**Benefits:**
- **Reproducible:** Same dependencies everywhere
- **Isolated:** No conflicts with system packages
- **Declarative:** Environment specified as code
- **Pinned:** Exact versions guaranteed

## Auto-Activation

When `nix-shell` is available, EZ automatically:

1. Detects Nix availability
2. Resolves appropriate environment file
3. Enters Nix shell before execution
4. Runs your program with guaranteed toolchain

**No manual setup required!**

## Environment Resolution Order

EZ searches for environment files in this order:

1. **Project-local:** `.ez-env.nix` or `ez-env.nix` in your project directory
2. **Built-in:** `envs/native.nix` bundled with EZ

**First match wins.**

### Project-Local Environment

Create `.ez-env.nix` in your project root for custom toolchain:

```nix
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  packages = with pkgs; [
    clang
    llvmPackages_latest.clang
    python312
    cmake
    ninja
  ];
  
  shellHook = ''
    export CC=clang
    export CXX=clang++
  '';
}
```

### Built-in Environment

If no project-local environment exists, EZ uses `envs/native.nix`:

```nix
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  packages = with pkgs; [
    clang
    clang-tools
    python312
    cmake
    ninja
  ];
}
```

## Commands and Flags

### `--prepare`

Pre-fetch and build the Nix environment:

```bash
./build/ez_main program.ez --prepare
```

**What it does:**
1. Evaluates Nix environment
2. Downloads dependencies
3. Builds environment
4. Writes `.ezenv/resolved.json` with metadata

**Use cases:**
- First-time setup
- CI/CD pipelines
- Pre-downloading before offline work

### `--env-info`

Display environment information:

```bash
./build/ez_main program.ez --env-info
```

**Output includes:**
- Nix availability
- Whether already inside Nix shell
- Chosen environment file path
- Environment source

**Example output:**
```
Environment Info:
  Nix available: yes
  Inside nix-shell: no
  Environment file: .ez-env.nix
  Source: project-local
```

### `--no-env`

Skip environment activation:

```bash
./build/ez_main program.ez --run --no-env
```

**Use cases:**
- Using host toolchain intentionally
- Debugging environment issues
- CI with pre-configured tools

### Auto-Activation (Default)

Running without flags auto-activates environment:

```bash
./build/ez_main program.ez --run
```

If Nix is available and you're not in a Nix shell, EZ re-executes under:

```bash
nix-shell <env> --run 'ez_main program.ez --run'
```

## Cache and Outputs

### `.ezenv/` Directory

EZ creates `.ezenv/` in your project root:

```
.ezenv/
├── build/           # Friend module shared libraries
├── codegen/         # Generated C code
└── resolved.json    # Environment metadata
```

**Add to `.gitignore`:**

```gitignore
.ezenv/
```

(Already included in the repository `.gitignore`)

### `resolved.json`

Created by `--prepare`, contains:

```json
{
  "env_file": ".ez-env.nix",
  "source": "project-local",
  "timestamp": "2025-12-07T12:00:00Z",
  "nix_version": "2.18.1"
}
```

**Use in CI:** Log this file for debugging which environment was used.

## Configuration Conflicts

### Conflict Detection

If both `.ezconfig` and Nix environment specify toolchain settings, EZ detects the conflict.

**Example conflict:**

**.ezconfig:**
```toml
[cpp]
compiler = "g++"
```

**Nix environment:**
```nix
shellHook = ''
  export CXX=clang++
'';
```

### Resolution

EZ will prompt:

```
Conflict detected: .ezconfig specifies g++, Nix environment provides clang++
Options:
  1. Use Nix value (clang++)
  2. Keep .ezconfig value (g++)
  3. Abort
Choice [1/2/3]:
```

### `--ignore-conflicts` / `-ic`

Skip conflict prompts (useful in CI):

```bash
./build/ez_main program.ez --build --run --ignore-conflicts
```

**Behavior:** Uses Nix values by default when conflicts exist.

## Project-Specific Environments

### Basic Custom Environment

```nix
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  packages = with pkgs; [
    gcc
    python311
  ];
}
```

### Pin Nixpkgs Version

```nix
{ pkgs ? import (fetchTarball {
    url = "https://github.com/NixOS/nixpkgs/archive/23.11.tar.gz";
    sha256 = "...";
  }) {}
}:
pkgs.mkShell {
  packages = with pkgs; [ clang python312 ];
}
```

### Include Additional Tools

```nix
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  packages = with pkgs; [
    clang
    python312
    cmake
    ninja
    gdb           # Debugger
    valgrind      # Memory profiler
    lcov          # Code coverage
  ];
}
```

### Set Environment Variables

```nix
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  packages = with pkgs; [ clang python312 ];
  
  shellHook = ''
    export CC=clang
    export CXX=clang++
    export CFLAGS="-O2 -Wall"
    export PYTHONPATH="$PWD/lib:$PYTHONPATH"
  '';
}
```

## CI/CD Integration

### GitHub Actions Example

```yaml
name: Build and Test

on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      
      - name: Install Nix
        uses: cachix/install-nix-action@v22
      
      - name: Prepare environment
        run: ./build/ez_main program.ez --prepare --ignore-conflicts
      
      - name: Build and run
        run: ./build/ez_main program.ez --build --run --ignore-conflicts
      
      - name: Log resolved environment
        run: cat .ezenv/resolved.json
```

### GitLab CI Example

```yaml
test:
  image: nixos/nix:latest
  script:
    - ./build/ez_main program.ez --prepare --ignore-conflicts
    - ./build/ez_main program.ez --build --run --ignore-conflicts
  artifacts:
    paths:
      - .ezenv/resolved.json
```

## Tips and Best Practices

### 1. Commit `.ez-env.nix`

Commit your project's environment file to version control:

```bash
git add .ez-env.nix
git commit -m "Add Nix environment"
```

### 2. Don't Commit `.ezenv/`

Always ignore build artifacts:

```gitignore
.ezenv/
```

### 3. Use `--no-env` for Debugging

If environment activation causes issues:

```bash
./build/ez_main program.ez --run --no-env
```

### 4. Log `resolved.json` in CI

Helps debug which environment was actually used:

```bash
cat .ezenv/resolved.json
```

### 5. Use `--ignore-conflicts` in CI

Prevents interactive prompts:

```bash
./build/ez_main program.ez --build --run --ignore-conflicts
```

### 6. Pre-fetch Before Offline Work

Download dependencies while online:

```bash
./build/ez_main program.ez --prepare
```

## Checking Nix Availability

### Is Nix Installed?

```bash
which nix-shell
```

If not installed, visit: https://nixos.org/download.html

### Am I Inside a Nix Shell?

```bash
./build/ez_main program.ez --env-info
```

Or check environment variable:

```bash
echo $IN_NIX_SHELL
```

## Build Output Directory

By default, build artifacts go to `.ezenv/build/`.

**Override in `.ezconfig`:**

```toml
[build]
output_dir = "build/friends"
```

**Note:** Nix environment may prompt about conflict if it specifies a different directory.

## Future Enhancements

Planned Nix integration features:

### Flakes Support

```nix
{
  description = "EZ Language Project";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.11";
  outputs = { self, nixpkgs }: {
    devShells.x86_64-linux.default = ...;
  };
}
```

### Automatic Dependency Detection

EZ will automatically generate Nix environments based on friend modules:

```ez
friend numpy_utils: python as np;
# Auto-generates Nix env with Python + NumPy
```

### Environment Templates

```bash
ez init --template python312-clang
```

## Troubleshooting

### Nix Not Found

```
Warning: nix-shell not found, skipping environment activation
```

**Fix:** Install Nix or use `--no-env` to suppress warning.

### Environment Build Failed

```
Error: failed to build Nix environment
```

**Fix:**
1. Check `.ez-env.nix` syntax
2. Verify nixpkgs channel is up to date
3. Use `--verbose` for detailed error

### Wrong Toolchain Used

**Check resolution:**

```bash
./build/ez_main program.ez --env-info
```

**Use project environment:**

```bash
# Ensure .ez-env.nix exists and is valid
cat .ez-env.nix
```

## Related Topics

- [Configuration](Configuration) - Configuration file format
- [CLI Reference](CLI-Reference) - Environment flags
- [Friend Modules](Friend-Modules) - Building with environments
- [Contributing Setup](Setup-Guide) - Development setup

---

**See Also:** [Configuration](Configuration) | [CLI Reference](CLI-Reference) | [Setup-Guide](Setup-Guide)
