#!/bin/bash

allowed_functions=("read" "write" "malloc" "free" "exit" "error")

# push_swap
undefined_symbols=$(nm -u push_swap | tr -d '_')
for symbol in $undefined_symbols; do
  if [[ ! " ${allowed_functions[@]} " =~ " ${symbol} " ]]; then
    echo "Error: push_swap: Disallowed function used: ${symbol}"
    exit 1
  fi
done

# checker
undefined_symbols=$(nm -u checker | tr -d '_')
for symbol in $undefined_symbols; do
  if [[ ! " ${allowed_functions[@]} " =~ " ${symbol} " ]]; then
    echo "Error: checker: Disallowed function used: ${symbol}"
    exit 1
  fi
done

echo "All used functions are allowed."
