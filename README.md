<h1 align="center">Push Swap</h1>
<p>This repository contains the implementation of the push_swap project, which focuses on sorting a stack of numbers using a limited set of actions.</p>
<a href="https://codecov.io/gh/rask24/push_swap"><img src="https://codecov.io/gh/rask24/push_swap/branch/main/graph/badge.svg" /></a>
<img src="https://img.shields.io/badge/norminette-passing-success"/> <img src="https://img.shields.io/badge/leaks-none-success" /> <img src="https://img.shields.io/badge/bonus-included-success"/>

### Algorithm
[日本語版](/README-ja.md)

The sorting is done in two stages:

1. Push from stack_a to stack_b, dividing into segments according to the value of the elements.
2. Greedily push from stack_b back to stack_a, starting with the largest segments

First, a rough sort is performed, followed by a more precise sort in the second stage.

#### 1. Pushing to stack_b in Segments
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

#### 2. Greedily Pushing Back to stack_a
From stack_b, push elements back to stack_a, starting with those in the largest segments. Ensure that stack_a always maintains a broadly sorted state during this process. A broadly sorted state means that when the stack's top and bottom are connected to form a ring, the minimum and maximum values are adjacent, and all other elements are sorted.

If there are multiple elements with the same segment number, choose the one that minimizes the number of moves needed to maintain a broadly sorted state and push it. The minimum number of moves refers to calculating all four possible ways of pushing for each element and selecting the one with the smallest number among all elements.
