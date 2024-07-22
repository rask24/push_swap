# Push Swap

This repository contains the implementation of the push_swap project, which focuses on sorting a stack of numbers using a limited set of actions.

[![Codecov](https://codecov.io/gh/rask24/push_swap/branch/main/graph/badge.svg)](https://codecov.io/gh/rask24/push_swap)
![Norminette](https://img.shields.io/badge/norminette-passing-success)
![Leaks](https://img.shields.io/badge/leaks-none-success)
![Bonus](https://img.shields.io/badge/bonus-included-success)

## Build

### Prerequisites

- GCC or Clang compiler
- Make
- Git (for submodule management)

### Compilation

- Clone the repository and initialize submodules

```sh
clone <repository-url>
cd <repository-directory>
git submodule update --init
```

- Compile the main program

```sh
make
```

This will create the `push_swap` executable.

- Compile the checker (bonus):

```sh
make bonus
```

This will create the checker executable.

### Additional Targets

- Clean object files

```sh
make clean
```

- Remove all generated files

```sh
make fclean
```

- Recompile everything

```sh
make re
```

### Development Options

- To compile with development flags (including sanitizers)

```sh
make DEV_FLAGS="-O0 -g -fsanitize=address,integer,undefined -D DEV"
```

- To compile with leak checking

```sh
make LEAK_FLAGS="-D LEAK"
```

### Testing

- Run unit tests

```sh
make test
```

- Generate code coverage

```sh
make coverage
make report_coverage
```

### Norminette

- Check code style:

```sh
make norm
```

Note: Ensure you have all necessary dependencies installed before building and running the project.

## Algorithm

[日本語版](/README-ja.md)

The sorting is done in two stages:

1. Push from stack_a to stack_b, dividing into segments according to the value of the elements.
2. Greedily push from stack_b back to stack_a, starting with the largest segments

First, a rough sort is performed, followed by a more precise sort in the second stage.

### 1. Pushing to stack_b in Segments

Determine the number of segments as shown in the table below.

| Number of Elements in Stack | Number of Segments |
| ---- | ---- |
| ~ 99 | 1 |
| 100 ~ 249 | 3 |
| 250 ~ 499 | 5 |
| 500 ~ 749 | 7 |
| ... | ... |

Segments are rough groupings, where smaller element numbers in the stack correspond to smaller segment numbers.

In this process, rotate stack_a and sequentially push elements with smaller segment numbers to stack_b.

### 2. Greedily Pushing Back to stack_a

From stack_b, push elements back to stack_a, starting with those in the largest segments. Ensure that stack_a always maintains a broadly sorted state during this process. A broadly sorted state means that when the stack's top and bottom are connected to form a ring, the minimum and maximum values are adjacent, and all other elements are sorted.

If there are multiple elements with the same segment number, choose the one that minimizes the number of moves needed to maintain a broadly sorted state and push it. The minimum number of moves refers to calculating all four possible ways of pushing for each element and selecting the one with the smallest number among all elements.
