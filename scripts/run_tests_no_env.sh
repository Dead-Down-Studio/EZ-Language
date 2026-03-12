#!/bin/bash
# Convenience wrapper to run tests without Nix environment prompts.

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
"$SCRIPT_DIR/run_tests.sh" --no-env "$@"
