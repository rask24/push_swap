// Copyright 2024, reasuke

#include <iostream>
#include <vector>

#include "gtest/gtest.h"

extern "C" {
#include "push_swap.h"
}

//  stack_a | stack_b
//  0       | 1      <- FF: (0, 1), FR: (0, -4), RF: (0, 1), RR: (0, -4)
//                           1          4            1            4: 1
//  2       | 3      <- FF: (1, 2), FR: (1, -3), RF: (-4, 2), RR: (-4, -3)
//                           2          4             6            4: 2
//  4       | 5      <- FF: (2, 3), FR: (2, -2), RF: (-3, 3), RR: (-3, -2)
//                           3          4             6            3: 3
//  6       | 7      <- FF: (3, 4), FR: (3, -1), RF: (-2, 4), RR: (-2, -1)
//                           4          4            6            2: 2
//  8       | 9      <- FF: (4, 0), FR: (4, 0), RF: (-1, 0), RR: (-1, 0)
//                           4           4           1            1: 1

TEST(set_opt, _set_opt_method1) {
  int N;
  t_stack *stack_a;
  t_stack *stack_b;
  t_content *c;

  N = 5;
  stack_a = NULL;
  stack_b = NULL;
  for (int i = 0; i < 2 * N; ++i) {
    c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    if (i % 2 == 0)
      ft_lstadd_back(&stack_a, ft_lstnew(c));
    else
      ft_lstadd_back(&stack_b, ft_lstnew(c));
  }
  set_cost(&stack_a, &stack_b);
  set_opt(&stack_b);

  t_stack *target;

  target = stack_b;
  EXPECT_EQ(get_content(target)->opt_method, FF);
  target = stack_b->next;
  EXPECT_EQ(get_content(target)->opt_method, FF);
  target = stack_b->next->next;
  EXPECT_EQ(get_content(target)->opt_method, FF);
  target = stack_b->next->next->next;
  EXPECT_EQ(get_content(target)->opt_method, RR);
  target = stack_b->next->next->next->next;
  EXPECT_EQ(get_content(target)->opt_method, RF);
}

TEST(set_opt, _set_min_cost1) {
  int N;
  t_stack *stack_a;
  t_stack *stack_b;
  t_content *c;

  N = 5;
  stack_a = NULL;
  stack_b = NULL;
  for (int i = 0; i < 2 * N; ++i) {
    c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    if (i % 2 == 0)
      ft_lstadd_back(&stack_a, ft_lstnew(c));
    else
      ft_lstadd_back(&stack_b, ft_lstnew(c));
  }
  set_cost(&stack_a, &stack_b);
  set_opt(&stack_b);

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

TEST(set_opt, _set_is_opt1) {
  int N;
  t_stack *stack_a;
  t_stack *stack_b;
  t_content *c;

  N = 5;
  stack_a = NULL;
  stack_b = NULL;
  for (int i = 0; i < 2 * N; ++i) {
    c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    if (i % 2 == 0)
      ft_lstadd_back(&stack_a, ft_lstnew(c));
    else
      ft_lstadd_back(&stack_b, ft_lstnew(c));
  }
  set_cost(&stack_a, &stack_b);
  set_opt(&stack_b);

  t_stack *st = stack_b;

  for (int i = 0; i < N; ++i) {
    if (i == 0)
      EXPECT_EQ(get_content(st)->is_opt, true);
    else
      EXPECT_EQ(get_content(st)->is_opt, false);
    st = st->next;
  }
}

//  stack_a | stack_b
//  6       | 8       <- FF: (0, 2), FR: (0, -3), RF: (0, 2), RR: (0, -3)
//                            2           3            2           3: 2
//  7       | 9       <- FF: (1, 2), FR: (1, -3), RF: (-4, 2), RR: (-4, -3)
//                            2           4            6            4: 2
//  1       | 0       <- FF: (2, 2), FR: (2, -3), RF: (2, 2), RR: (2, -3)
//                            2           5           2           5: 2
//  3       | 2       <- FF: (3, 3), FR: (3, -2), RF: (-2, 3), RR: (-2, -2)
//                            3           5            5            2: 2
//  4       | 5       <- FF: (4, 0), FR: (-1, 0), RF: (4, 0), RR: (-1, 0)
//                            4           1            4           1: 1

TEST(set_opt, _set_opt_method2) {
  t_stack *stack_a;
  t_stack *stack_b;
  t_content *c;

  std::vector<int> v_a = {6, 7, 1, 3, 4};
  std::vector<int> v_b = {8, 9, 0, 2, 5};
  stack_a = NULL;
  stack_b = NULL;
  for (int &i : v_a) {
    c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }
  for (int &i : v_b) {
    c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_b, ft_lstnew(c));
  }

  set_cost(&stack_a, &stack_b);
  set_opt(&stack_b);

  t_stack *target;

  target = stack_b;
  EXPECT_EQ(get_content(target)->opt_method, FF);
  target = stack_b->next;
  EXPECT_EQ(get_content(target)->opt_method, FF);
  target = stack_b->next->next;
  EXPECT_EQ(get_content(target)->opt_method, FF);
  target = stack_b->next->next->next;
  EXPECT_EQ(get_content(target)->opt_method, RR);
  target = stack_b->next->next->next->next;
  EXPECT_EQ(get_content(target)->opt_method, RF);
}

TEST(set_opt, _set_min_cost2) {
  t_stack *stack_a;
  t_stack *stack_b;
  t_content *c;

  std::vector<int> v_a = {6, 7, 1, 3, 4};
  std::vector<int> v_b = {8, 9, 0, 2, 5};
  stack_a = NULL;
  stack_b = NULL;
  for (int &i : v_a) {
    c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }
  for (int &i : v_b) {
    c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_b, ft_lstnew(c));
  }

  set_cost(&stack_a, &stack_b);
  set_opt(&stack_b);

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

TEST(set_opt, _set_is_opt2) {
  int N = 5;
  t_stack *stack_a;
  t_stack *stack_b;
  t_content *c;

  std::vector<int> v_a = {6, 7, 1, 3, 4};
  std::vector<int> v_b = {8, 9, 0, 2, 5};
  stack_a = NULL;
  stack_b = NULL;
  for (int &i : v_a) {
    c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }
  for (int &i : v_b) {
    c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_b, ft_lstnew(c));
  }

  set_cost(&stack_a, &stack_b);
  set_opt(&stack_b);

  t_stack *st = stack_b;

  for (int i = 0; i < N; ++i) {
    if (i == 4)
      EXPECT_EQ(get_content(st)->is_opt, true);
    else
      EXPECT_EQ(get_content(st)->is_opt, false);
    st = st->next;
  }
}
