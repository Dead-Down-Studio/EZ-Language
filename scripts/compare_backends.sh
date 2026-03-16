#!/bin/bash
# Compare interpreter output with compiled-native output for the same EZ program.

set -euo pipefail

EZ_BIN="./build/ez_main"
SOURCE_FILE="${1:-./tests/test_simple_printf.ez}"

if [[ ! -x "$EZ_BIN" ]]; then
  echo "Error: $EZ_BIN not found. Build first with: cmake -S . -B build && cmake --build build" >&2
  exit 1
fi

if [[ ! -f "$SOURCE_FILE" ]]; then
  echo "Error: source file not found: $SOURCE_FILE" >&2
  exit 1
fi

TMP_DIR="$(mktemp -d)"
trap 'rm -rf "$TMP_DIR"' EXIT

INTERP_OUT="$TMP_DIR/interpreter.out"
NATIVE_OUT="$TMP_DIR/native.out"
BUILD_LOG="$TMP_DIR/build.log"

"$EZ_BIN" "$SOURCE_FILE" --run --no-env --quiet > "$INTERP_OUT" 2>&1
"$EZ_BIN" "$SOURCE_FILE" --build-native --no-env --quiet > "$BUILD_LOG" 2>&1

NATIVE_BIN="$(sed -n 's/^Native binary written to //p' "$BUILD_LOG" | tail -n 1)"
NATIVE_BIN="${NATIVE_BIN%\"}"
NATIVE_BIN="${NATIVE_BIN#\"}"
if [[ -z "$NATIVE_BIN" ]]; then
  echo "Error: failed to detect native binary path from build output" >&2
  cat "$BUILD_LOG" >&2
  exit 1
fi

if [[ ! -x "$NATIVE_BIN" ]]; then
  echo "Error: native binary was not produced or is not executable: $NATIVE_BIN" >&2
  cat "$BUILD_LOG" >&2
  exit 1
fi

"$NATIVE_BIN" > "$NATIVE_OUT" 2>&1

if diff -u "$INTERP_OUT" "$NATIVE_OUT" > "$TMP_DIR/output.diff"; then
  echo "Backend comparison passed"
  echo "Source: $SOURCE_FILE"
  echo "Interpreter output matches compiled-native output"
  exit 0
fi

echo "Backend comparison failed" >&2
echo "Source: $SOURCE_FILE" >&2
cat "$TMP_DIR/output.diff" >&2
exit 1
