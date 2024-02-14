// Copyright 2024, reasuke

#include <iostream>
#include <vector>

#include "gtest/gtest.h"

extern "C" {
#include "large_sort.h"
#include "push_swap.h"
}

//  stack_a | stack_b
//  0       | 1      <- RA_RB: (0, 1), RRA_RB: (0, -4), RA_RRB: (0, 1), RRA_RRB:
//  (0, -4)
//                           1          4            1            4: 1
//  2       | 3      <- RA_RB: (1, 2), RRA_RB: (1, -3), RA_RRB: (-4, 2),
//  RRA_RRB: (-4, -3)
//                           2          4             6            4: 2
//  4       | 5      <- RA_RB: (2, 3), RRA_RB: (2, -2), RA_RRB: (-3, 3),
//  RRA_RRB: (-3, -2)
//                           3          4             6            3: 3
//  6       | 7      <- RA_RB: (3, 4), RRA_RB: (3, -1), RA_RRB: (-2, 4),
//  RRA_RRB: (-2, -1)
//                           4          4            6            2: 2
//  8       | 9      <- RA_RB: (4, 0), RRA_RB: (4, 0), RA_RRB: (-1, 0), RRA_RRB:
//  (-1, 0)
//                           4           4           1            1: 1

TEST(set_min_cost_opt_method, _set_opt_method1) {
  int N;
  t_stack *stack_a;
  t_stack *stack_b;
  t_content *c;

  N = 5;
  stack_a = NULL;
  stack_b = NULL;
  for (int i = 0; i < 2 * N; ++i) {
    c = new t_content({i, -1, 0, 0, 0, 0, 0, INIT, false});
    if (i % 2 == 0)
      ft_lstadd_back(&stack_a, ft_lstnew(c));
    else
      ft_lstadd_back(&stack_b, ft_lstnew(c));
  }
  set_cost(&stack_a, &stack_b);
  set_min_cost_opt_method(&stack_b);

  t_stack *target;

  target = stack_b;
  EXPECT_EQ(get_content(target)->opt_method, RA_RB);
  target = stack_b->next;
  EXPECT_EQ(get_content(target)->opt_method, RA_RB);
  target = stack_b->next->next;
  EXPECT_EQ(get_content(target)->opt_method, RA_RB);
  target = stack_b->next->next->next;
  EXPECT_EQ(get_content(target)->opt_method, RRA_RRB);
  target = stack_b->next->next->next->next;
  EXPECT_EQ(get_content(target)->opt_method, RA_RRB);
}

TEST(set_min_cost_opt_method, _set_min_cost1) {
  int N;
  t_stack *stack_a;
  t_stack *stack_b;
  t_content *c;

  N = 5;
  stack_a = NULL;
  stack_b = NULL;
  for (int i = 0; i < 2 * N; ++i) {
    c = new t_content({i, -1, 0, 0, 0, 0, 0, INIT, false});
    if (i % 2 == 0)
      ft_lstadd_back(&stack_a, ft_lstnew(c));
    else
      ft_lstadd_back(&stack_b, ft_lstnew(c));
  }
  set_cost(&stack_a, &stack_b);
  set_min_cost_opt_method(&stack_b);

  t_stack *target;

  target = stack_b;
  EXPECT_EQ(get_content(target)->min_cost, 1);
  target = stack_b->next;
  EXPECT_EQ(get_content(target)->min_cost, 2);
  target = stack_b->next->next;
  EXPECT_EQ(get_content(target)->min_cost, 3);
  target = stack_b->next->next->next;
  EXPECT_EQ(get_content(target)->min_cost, 2);
  target = stack_b->next->next->next->next;
  EXPECT_EQ(get_content(target)->min_cost, 1);
}

//  stack_a | stack_b
//  6       | 8       <- RA_RB: (0, 2), RRA_RB: (0, -3), RA_RRB: (0, 2),
//  RRA_RRB: (0, -3)
//                            2           3            2           3: 2
//  7       | 9       <- RA_RB: (1, 2), RRA_RB: (1, -3), RA_RRB: (-4, 2),
//  RRA_RRB: (-4, -3)
//                            2           4            6            4: 2
//  1       | 0       <- RA_RB: (2, 2), RRA_RB: (2, -3), RA_RRB: (2, 2),
//  RRA_RRB: (2, -3)
//                            2           5           2           5: 2
//  3       | 2       <- RA_RB: (3, 3), RRA_RB: (3, -2), RA_RRB: (-2, 3),
//  RRA_RRB: (-2, -2)
//                            3           5            5            2: 2
//  4       | 5       <- RA_RB: (4, 0), RRA_RB: (-1, 0), RA_RRB: (4, 0),
//  RRA_RRB: (-1, 0)
//                            4           1            4           1: 1

TEST(set_min_cost_opt_method, _set_opt_method2) {
  t_stack *stack_a;
  t_stack *stack_b;
  t_content *c;

  std::vector<int> v_a = {6, 7, 1, 3, 4};
  std::vector<int> v_b = {8, 9, 0, 2, 5};
  stack_a = NULL;
  stack_b = NULL;
  for (int &i : v_a) {
    c = new t_content({i, -1, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }
  for (int &i : v_b) {
    c = new t_content({i, -1, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_b, ft_lstnew(c));
  }

  set_cost(&stack_a, &stack_b);
  set_min_cost_opt_method(&stack_b);

  t_stack *target;

  target = stack_b;
  EXPECT_EQ(get_content(target)->opt_method, RA_RB);
  target = stack_b->next;
  EXPECT_EQ(get_content(target)->opt_method, RA_RB);
  target = stack_b->next->next;
  EXPECT_EQ(get_content(target)->opt_method, RA_RB);
  target = stack_b->next->next->next;
  EXPECT_EQ(get_content(target)->opt_method, RRA_RRB);
  target = stack_b->next->next->next->next;
  EXPECT_EQ(get_content(target)->opt_method, RA_RRB);
}

TEST(set_min_cost_opt_method, _set_min_cost2) {
  t_stack *stack_a;
  t_stack *stack_b;
  t_content *c;

  std::vector<int> v_a = {6, 7, 1, 3, 4};
  std::vector<int> v_b = {8, 9, 0, 2, 5};
  stack_a = NULL;
  stack_b = NULL;
  for (int &i : v_a) {
    c = new t_content({i, -1, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }
  for (int &i : v_b) {
    c = new t_content({i, -1, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_b, ft_lstnew(c));
  }

  set_cost(&stack_a, &stack_b);
  set_min_cost_opt_method(&stack_b);

  t_stack *target;

  target = stack_b;
  EXPECT_EQ(get_content(target)->min_cost, 2);
  target = stack_b->next;
  EXPECT_EQ(get_content(target)->min_cost, 2);
  target = stack_b->next->next;
  EXPECT_EQ(get_content(target)->min_cost, 2);
  target = stack_b->next->next->next;
  EXPECT_EQ(get_content(target)->min_cost, 2);
  target = stack_b->next->next->next->next;
  EXPECT_EQ(get_content(target)->min_cost, 1);
}
