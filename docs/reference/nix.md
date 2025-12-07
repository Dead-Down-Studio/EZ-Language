# Nix Environment Reference

EZ automatically prepares and enters a Nix dev shell when `nix-shell` is available.

## Resolution order
- Project-local: `.ez-env.nix` (or `ez-env.nix`) next to your `.ez` sources.
- Built-in: `envs/native.nix` bundled with EZ (clang/clang++, python3.12, cmake, ninja).

## Commands & flags
- `--prepare` prefetches/builds the dev shell (`nix-shell <env> --run true`) and writes `.ezenv/resolved.json`.
- `--env-info` prints availability, whether you are already inside a Nix shell, and the chosen env file.
- Auto-activation: running any command will re-exec under `nix-shell <env> --run ...` unless `--no-env` is set.
- Conflict handling: if your `.ezconfig` overrides compiler/python/output settings, the CLI will prompt to use Nix values, keep config, or abort. Skip prompts with `--ignore-conflicts` (or `-ic`).

## Cache and outputs
- Build artifacts default to `.ezenv/build/` (configurable via `[build] output_dir` in `.ezconfig`).
- Resolved environment metadata is stored in `.ezenv/resolved.json` after prepare/activation.
- Add `.ezenv/` to your ignores (already in the repo `.gitignore`).

## Project-specific environments
Provide `.ez-env.nix` to pin your own toolchain. Example:
```nix
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  packages = with pkgs; [ clang llvmPackages_latest.clang python312 cmake ninja ];
  shellHook = ''
    export CC=clang
    export CXX=clang++
  '';
}
```

## Tips
- Use `--no-env` if you prefer your host toolchain.
- Use `--ignore-conflicts` in CI to skip prompts when `.ezconfig` intentionally diverges.
- Check `.ezenv/resolved.json` into CI logs (not version control) when debugging environment picks.
