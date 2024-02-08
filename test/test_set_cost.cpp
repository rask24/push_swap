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
  int sf_cost = get_content(target)->sf_cost;
  int sr_cost = get_content(target)->sr_cost;
  EXPECT_EQ(sf_cost, 2);
  EXPECT_EQ(sr_cost, -3);
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
    t_content *c = new t_content({i, 0, 0, 0, 0});
    if (i % 2 == 0)
      ft_lstadd_back(&stack_a, ft_lstnew(c));
    else
      ft_lstadd_back(&stack_b, ft_lstnew(c));
  }

  set_insertion_cost(&stack_a, &stack_b);

  t_stack *target;
  int if_cost;
  int ir_cost;

  target = stack_b;
  if_cost = get_content(target)->if_cost;
  ir_cost = get_content(target)->ir_cost;
  EXPECT_EQ(if_cost, 1);
  EXPECT_EQ(ir_cost, -4);

  target = stack_b->next->next;
  if_cost = get_content(target)->if_cost;
  ir_cost = get_content(target)->ir_cost;
  EXPECT_EQ(if_cost, 3);
  EXPECT_EQ(ir_cost, -2);

  target = stack_b->next->next->next->next;
  if_cost = get_content(target)->if_cost;
  ir_cost = get_content(target)->ir_cost;
  EXPECT_EQ(if_cost, 0);
  EXPECT_EQ(ir_cost, 0);
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
    t_content *c = new t_content({i, 0, 0, 0, 0});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }
  for (int &i : v_b) {
    t_content *c = new t_content({i, 0, 0, 0, 0});
    ft_lstadd_back(&stack_b, ft_lstnew(c));
  }

  set_insertion_cost(&stack_a, &stack_b);

  t_stack *target;
  int if_cost;
  int ir_cost;

  target = stack_b;
  if_cost = get_content(target)->if_cost;
  ir_cost = get_content(target)->ir_cost;
  EXPECT_EQ(if_cost, 2);
  EXPECT_EQ(ir_cost, -3);

  target = stack_b->next->next;
  if_cost = get_content(target)->if_cost;
  ir_cost = get_content(target)->ir_cost;
  EXPECT_EQ(if_cost, 2);
  EXPECT_EQ(ir_cost, -3);

  target = stack_b->next->next->next->next;
  if_cost = get_content(target)->if_cost;
  ir_cost = get_content(target)->ir_cost;
  EXPECT_EQ(if_cost, 0);
  EXPECT_EQ(ir_cost, 0);
}
