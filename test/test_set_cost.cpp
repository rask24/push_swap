// Copyright 2024, reasuke

#include <iostream>
#include <vector>

#include "gtest/gtest.h"

extern "C" {
#include "large_sort.h"
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
  t_stack *stack_a = NULL;
  t_stack *stack_b = NULL;
  for (int i = 0; i < N; ++i) {
    t_content *c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
    ft_lstadd_back(&stack_b, ft_lstnew(c));
  }

  set_cost(&stack_a, &stack_b);

  // index: 2
  t_stack *target = stack_b->next->next;
  int rb_cost = get_content(target)->rb_cost;
  int rrb_cost = get_content(target)->rrb_cost;
  EXPECT_EQ(rb_cost, 2);
  EXPECT_EQ(rrb_cost, -3);
}

//  stack_a | stack_b
//  0       | 1      <- insertion forward: 1, reverse: -4
//  2       | 3
//  4       | 5      <- insertion forward: 3, reverse: -2
//  6       | 7
//  8       | 9      <- insertion forward: 0, reverse: 0

TEST(set_insertion_cost, insertion1) {
  int N = 5;
  t_stack *stack_a = NULL;
  t_stack *stack_b = NULL;
  for (int i = 0; i < 2 * N; ++i) {
    t_content *c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    if (i % 2 == 0)
      ft_lstadd_back(&stack_a, ft_lstnew(c));
    else
      ft_lstadd_back(&stack_b, ft_lstnew(c));
  }

  set_cost(&stack_a, &stack_b);

  t_stack *target;
  int ra_cost;
  int rra_cost;

  target = stack_b;
  ra_cost = get_content(target)->ra_cost;
  rra_cost = get_content(target)->rra_cost;
  EXPECT_EQ(ra_cost, 1);
  EXPECT_EQ(rra_cost, -4);

  target = stack_b->next->next;
  ra_cost = get_content(target)->ra_cost;
  rra_cost = get_content(target)->rra_cost;
  EXPECT_EQ(ra_cost, 3);
  EXPECT_EQ(rra_cost, -2);

  target = stack_b->next->next->next->next;
  ra_cost = get_content(target)->ra_cost;
  rra_cost = get_content(target)->rra_cost;
  EXPECT_EQ(ra_cost, 0);
  EXPECT_EQ(rra_cost, 0);
}

//  stack_a | stack_b
//  6       | 8       <- insertion forward: 2, reverse: -3
//  7       | 9
//  1       | 0       <- insertion forward: 2, reverse: -3
//  3       | 2
//  4       | 5       <- insertion forward: 0, reverse: 0

TEST(set_insertion_cost, insertion2) {
  std::vector<int> v_a = {6, 7, 1, 3, 4};
  std::vector<int> v_b = {8, 9, 0, 2, 5};
  t_stack *stack_a = NULL;
  t_stack *stack_b = NULL;
  for (int &i : v_a) {
    t_content *c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }
  for (int &i : v_b) {
    t_content *c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_b, ft_lstnew(c));
  }

  set_cost(&stack_a, &stack_b);

  t_stack *target;
  int ra_cost;
  int rra_cost;

  target = stack_b;
  ra_cost = get_content(target)->ra_cost;
  rra_cost = get_content(target)->rra_cost;
  EXPECT_EQ(ra_cost, 2);
  EXPECT_EQ(rra_cost, -3);

  target = stack_b->next->next;
  ra_cost = get_content(target)->ra_cost;
  rra_cost = get_content(target)->rra_cost;
  EXPECT_EQ(ra_cost, 2);
  EXPECT_EQ(rra_cost, -3);

  target = stack_b->next->next->next->next;
  ra_cost = get_content(target)->ra_cost;
  rra_cost = get_content(target)->rra_cost;
  EXPECT_EQ(ra_cost, 0);
  EXPECT_EQ(rra_cost, 0);
}
