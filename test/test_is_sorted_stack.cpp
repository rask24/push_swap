// Copyright 2024, reasuke

#include <iostream>
#include <vector>

#include "gtest/gtest.h"

extern "C" {
#include "push_swap.h"
#include "sort.h"
}

// st: sorted
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9

TEST(is_sorted_stack, sorted) {
  int N = 10;
  t_stack *st;

  st = NULL;
  for (int i = 0; i < N; ++i) {
    t_content *c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&st, ft_lstnew(c));
  }

  EXPECT_TRUE(is_sorted_stack(st));
}

// st: not sorted
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 9
// 8

TEST(is_sorted_stack, not_sorted) {
  std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
  t_stack *st;

  st = NULL;
  for (int &i : v) {
    t_content *c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&st, ft_lstnew(c));
  }

  EXPECT_FALSE(is_sorted_stack(st));
}
