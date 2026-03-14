#!/bin/bash
# Test harness for EZ-Language
# Runs all .ez test files and reports PASS/FAIL status

set -eo pipefail

# Parse arguments
VERBOSE=0
NO_ENV=0
for arg in "$@"; do
    case "$arg" in
        -v|--verbose)
            VERBOSE=1
            ;;
        --no-env)
            NO_ENV=1
            ;;
    esac
done

# Ensure build directory exists
if [ ! -f "./build/ez_main" ]; then
    echo "Error: ./build/ez_main not found. Please run: cmake -S . -B build && cmake --build build"
    exit 1
fi

EZ_BINARY="./build/ez_main"
TESTS_DIR="./tests"
EXPECTED_DIR="./tests/expected_outputs"
PASSED=0
FAILED=0
XFAILED=0
ERRORS=()
XFAIL_TESTS=("test_codegen_advanced.ez")

# Build interpreter args
EZ_ARGS=(--run --non-interactive --quiet)
if [ $NO_ENV -eq 1 ]; then
    EZ_ARGS+=(--no-env)
fi

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

if [ $VERBOSE -eq 1 ]; then
    echo "EZ-Language Test Suite (Verbose Mode)"
else
    echo "EZ-Language Test Suite"
fi
echo "=========================================="
echo ""

is_xfail_test() {
    local test_name="$1"
    for expected in "${XFAIL_TESTS[@]}"; do
        if [ "$test_name" = "$expected" ]; then
            return 0
        fi
    done
    return 1
}

# Find all .ez test files
for test_file in $(find "$TESTS_DIR" -name "test_*.ez" | sort); do
    test_name=$(basename "$test_file")
    expected_file="$EXPECTED_DIR/${test_name}.out"
    output_file=$(mktemp)
    diff_file=$(mktemp)
    
    if [ $VERBOSE -eq 1 ]; then
        echo "Running: $test_name"
        # Run the test and capture output for optional golden comparison.
        if $EZ_BINARY "$test_file" "${EZ_ARGS[@]}" 2>&1 | tee "$output_file"; then
            if is_xfail_test "$test_name"; then
                echo -e "${YELLOW}! XPASS${NC} - $test_name (expected failure, now passing)"
                ((FAILED++))
                ERRORS+=("$test_file (unexpected pass)")
                rm -f "$output_file" "$diff_file"
                echo ""
                continue
            fi
            if [ -f "$expected_file" ]; then
                if diff -u "$expected_file" "$output_file" > "$diff_file"; then
                    echo -e "${GREEN}✓ PASS${NC} - $test_name"
                    ((PASSED++))
                else
                    echo -e "${RED}✗ FAIL${NC} - $test_name"
                    echo "  output mismatch against $expected_file"
                    cat "$diff_file"
                    ((FAILED++))
                    ERRORS+=("$test_file")
                fi
            else
                echo -e "${GREEN}✓ PASS${NC} - $test_name"
                ((PASSED++))
            fi
        else
            if is_xfail_test "$test_name"; then
                echo -e "${YELLOW}~ XFAIL${NC} - $test_name"
                ((XFAILED++))
            else
                echo -e "${RED}✗ FAIL${NC} - $test_name"
                ((FAILED++))
                ERRORS+=("$test_file")
            fi
        fi
        echo ""
    else
        # Run the test; validate output if a golden file exists.
        if $EZ_BINARY "$test_file" "${EZ_ARGS[@]}" > "$output_file" 2>&1; then
            if is_xfail_test "$test_name"; then
                echo -e "${YELLOW}! XPASS${NC} - $test_name (expected failure, now passing)"
                ((FAILED++))
                ERRORS+=("$test_file (unexpected pass)")
                rm -f "$output_file" "$diff_file"
                continue
            fi
            if [ -f "$expected_file" ]; then
                if diff -u "$expected_file" "$output_file" > "$diff_file"; then
                    echo -e "${GREEN}✓ PASS${NC} - $test_name"
                    ((PASSED++))
                else
                    echo -e "${RED}✗ FAIL${NC} - $test_name"
                    echo "  output mismatch against $expected_file"
                    ((FAILED++))
                    ERRORS+=("$test_file")
                fi
            else
                echo -e "${GREEN}✓ PASS${NC} - $test_name"
                ((PASSED++))
            fi
        else
            if is_xfail_test "$test_name"; then
                echo -e "${YELLOW}~ XFAIL${NC} - $test_name"
                ((XFAILED++))
            else
                echo -e "${RED}✗ FAIL${NC} - $test_name"
                ((FAILED++))
                ERRORS+=("$test_file")
            fi
        fi
    fi

    rm -f "$output_file" "$diff_file"
done

echo ""
echo "=========================================="
echo "Test Results: $PASSED PASSED, $FAILED FAILED, $XFAILED XFAIL"
echo "=========================================="

if [ $FAILED -gt 0 ]; then
    echo ""
    echo -e "${YELLOW}Failed tests:${NC}"
    for error in "${ERRORS[@]}"; do
        echo "  - $error"
    done
    exit 1
else
    echo ""
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
fi
