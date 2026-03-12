#!/bin/bash
# Test harness for EZ-Language
# Runs all .ez test files and reports PASS/FAIL status

set -e

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
PASSED=0
FAILED=0
ERRORS=()

# Build interpreter args
EZ_ARGS=(--run)
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

# Find all .ez test files
for test_file in $(find "$TESTS_DIR" -name "test_*.ez" | sort); do
    test_name=$(basename "$test_file")
    
    if [ $VERBOSE -eq 1 ]; then
        echo "Running: $test_name"
        # Run the test and capture output
        if $EZ_BINARY "$test_file" "${EZ_ARGS[@]}" 2>&1 | tee /tmp/test_output.txt; then
            echo -e "${GREEN}✓ PASS${NC} - $test_name"
            ((PASSED++))
        else
            echo -e "${RED}✗ FAIL${NC} - $test_name"
            ((FAILED++))
            ERRORS+=("$test_file")
        fi
        echo ""
    else
        # Run the test
        if $EZ_BINARY "$test_file" "${EZ_ARGS[@]}" > /dev/null 2>&1; then
            echo -e "${GREEN}✓ PASS${NC} - $test_name"
            ((PASSED++))
        else
            echo -e "${RED}✗ FAIL${NC} - $test_name"
            ((FAILED++))
            ERRORS+=("$test_file")
        fi
    fi
done

echo ""
echo "=========================================="
echo "Test Results: $PASSED PASSED, $FAILED FAILED"
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
