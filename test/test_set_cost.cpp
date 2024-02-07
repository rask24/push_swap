// Copyright 2024, reasuke

#include <iostream>
#include <vector>

#include "gtest/gtest.h"

extern "C" {
#include "push_swap.h"
}

// stack_b
// 0
// 1
// 2 selection forward: 2, selection reverse: -3
// 3
// 4

TEST(set_selection_cost, selection) {
  int N = 5;
  t_stack *stack_b = NULL;
  for (int i = 0; i < N; ++i) {
    t_content *c = new t_content({i, 0, 0, 0, 0});
    ft_lstadd_back(&stack_b, ft_lstnew(c));
  }

  set_selection_cost(&stack_b);

  // index: 2
  t_stack *target = stack_b->next->next;
  int sf_cost = ((t_content *)target->content)->sf_cost;
  int sr_cost = ((t_content *)target->content)->sr_cost;
  EXPECT_EQ(sf_cost, 2);
  EXPECT_EQ(sr_cost, -3);
}
