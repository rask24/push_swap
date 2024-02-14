#!/bin/bash

check_binary_symbols() {
    local binary="$1"
    if [ ! -f $binary ]; then
        echo "Error: Binary file '$binary' not found."
        exit 1
    fi
    local undefined_symbols=$(nm -u "$binary" | tr -d '_')
    for symbol in $undefined_symbols; do
        if [[ ! " ${allowed_functions[@]} " =~ " ${symbol}" ]]; then
            echo "Error: $binary: Disallowed function used: ${symbol}"
            exit 1
        fi
    done
}

allowed_functions=("read" "write" "malloc" "free" "exit" "error" "dyld_stub_binder")

# Check symbols for push_swap
check_binary_symbols "push_swap"

# Check symbols for checker
check_binary_symbols "checker"

echo "All used functions are allowed."
