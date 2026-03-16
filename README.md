# EZ-Language

EZ-Language (EZ) is designed to make programming easy, fast, and universally accessible. Whether you're a beginner or a seasoned developer, EZ empowers you to build complex projects with minimal friction, supporting reproducible environments and multi-language integration out-of-the-box.

## Philosophy

- **Easy:** Simple syntax and setup for rapid development.
- **Universal:** Multi-language support lets you mix and match code across ecosystems.
- **Reproducible:** Nix-powered environments guarantee consistent builds and development experiences.
- **Community-first:** Open, extensible, and driven by contributors.

## Experimental Project Notice

**EZ-Language is an active experimental project.** This codebase is under active development and should be treated accordingly.

### What This Means

- **Rapid iteration:** APIs, behaviors, file structures, and tooling can change significantly between releases without advance notice
- **Unpolished code:** This project includes rapid prototypes, AI-assisted scaffolding, and research utilities that have not undergone the same quality review as production-grade code
- **Instability expected:** Breaking changes are frequent; backward compatibility is not guaranteed
- **Limited testing:** Components may lack comprehensive test coverage and edge-case handling

### Before Using This Project

⚠️ **Do not use in production environments** without careful review and testing. ⚠️

If you choose to use EZ-Language:

1. Thoroughly audit all code before integration
2. Expect breaking changes between versions
3. Be prepared to adapt to API modifications
4. Test extensively in non-critical contexts first
5. Monitor the project regularly for stability improvements

## Status (MVP)

Implemented now:

- `env native;` environment declaration
- `friend <stem>: <c|cpp|python> as <alias>;` native/Python module linking
- Typed variables (`int`, `float`, `boolean`, `string`, `void`) with assignments
- Arithmetic/comparison/logical operators in interpreter mode
- User-defined functions with parameters and return statements
- Control flow: `if`, `while`, C-style `for`, `break`, `continue`
- Built-in `print` / `printf`
- Quiet vs verbose output modes (`--verbose`)
- Semantic checks (types, unknown identifiers, invalid modifiers, duplicate symbols)
- C code emission (`--emit-c`, `--build-native`, `--run-native`)

Known limitations:

- C codegen currently targets a subset and does not support friend calls
- `foreach`, classes, and full `try/catch/finally` runtime behavior are still incomplete
- This repo currently validates friend languages `c`, `cpp`, and `python`

## Quickstart

```bash
cmake -S . -B build
cmake --build build
./build/ez_main examples/demo.ez --run          # quiet
./build/ez_main examples/demo.ez --run --verbose # verbose
./build/ez_main examples/demo.ez --run --non-interactive # no prompts (CI/demo safe)
```

Example `examples/demo.ez`:

```ez
env native;
friend native_math: cpp as m;
int x = 1 + 2 * 3;
print("sum:", m.add(x,2));
```

Build + run (compiles friend first):

```bash
./build/ez_main examples/demo.ez --build --run
```

Nix dev shell (optional, auto-activates when available):

```bash
./build/ez_main examples/demo.ez --prepare   # prefetch/build env
./build/ez_main examples/demo.ez --run       # auto-enters nix-shell unless --no-env
./build/ez_main examples/demo.ez --env-info  # show resolved env file/source
```

For scripted runs and CI, prefer one of:

```bash
./build/ez_main examples/demo.ez --run --no-env
./build/ez_main examples/demo.ez --run --non-interactive
```

## Quiet vs Verbose

Quiet: only user `print/printf` output.
Verbose: environment banner, friend build plan, compile/link commands, evaluation results (`=>`), variable state.

## Friend Modules

Declare and call external native code:

```ez
friend native_math: cpp as m;
print(m.add(3,2));
```

Use `--build` to produce `.ezenv/build/lib<alias>.dylib`.
Python friends also supported (`python` language) via generated shim.

## C Emission

Generate C source and optional native binary from int-only subset:

```bash
./build/ez_main examples/math.ez --emit-c
./build/ez_main examples/math.ez --build-native
./build/ez_main examples/math.ez --run-native
```

Backend parity demo (interpreter vs compiled-native on the same input):

```bash
./scripts/compare_backends.sh ./tests/test_simple_printf.ez
# or omit argument to use the default sample
./scripts/compare_backends.sh
```

## Documentation

Use the project wiki as the canonical documentation source:

- [EZ-Language Wiki](https://github.com/Dead-Down-Studio/EZ-Language/wiki)

## Roadmap & Milestones

This roadmap moves from a minimal core toward a reproducible, multi-language coordination layer with strong tooling and community ecosystem.

### Milestone 1: Core Language & Tooling MVP (DONE/IN-PROGRESS)

- Parser, grammar, tiny interpreter (ints, expressions, print)
- Basic environment declaration (`env native;`)
- Friend modules (C/C++ & Python shim)

### Milestone 2: Rich Environments (Nix Integration)(IN-PROGRESS)

- Map environment declarations to Nix expressions
- Auto-generation/import of Nix files for reproducible builds
- Layered override model (base env + project customizations)

### Milestone 3: Multi-language Foundation

- Expanded friend module types (Rust, JS/WASM, Mojo, Rust, etc..)
- Glue/interface layer with signature introspection & basic type marshaling
- Deterministic build graph visualization

### Milestone 4: Compiler / Translator Evolution

- EZ → C/LLVM/WASM backends (beyond int subset)
- Function execution, returns, boolean operators, richer types (string, array, map)
- Unified error & reporting system (structured diagnostics, machine-readable JSON)

### Milestone 5: Package & Environment Marketplace

- Registry for modules, environments, templates
- CLI search, install, update, verify provenance
- Dependency manifest + lock format

### Milestone 6: IDE & UX Enhancements

- VS Code extension: syntax highlighting, hover docs, inline diagnostics, friend build tasks
- Command palette actions (run, build, emit C, plan)
- Incremental parsing & semantic lint loop

### Milestone 7: Advanced Multi-language & Ecosystem Growth

- High-level glue automation (signature inference, type adapters)
- WASM sandboxed execution path
- Performance profiling & trace export

### Milestone 8: Observability & Tooling Depth

- Unified error/reporting pipeline (colorized CLI, structured logs, JSON output flag)
- Build metadata cache + reproducibility audit
- Test harness integration for friend modules

### Ongoing / Cross-cutting

- Documentation expansion & examples
- Stability & performance passes
- Community feedback loop shaping language additions

Short-term upcoming: execute class functions & returns, boolean operators, extended type system, initial module/package manifest.

## Contributing

Use the wiki contribution and setup pages for the latest workflow details.

## License

See [LICENSE](LICENSE).
