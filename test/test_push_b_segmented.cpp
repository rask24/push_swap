// Copyright 2024, reasuke

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "gtest/gtest.h"

extern "C" {
#include "large_sort.h"
#include "push_swap.h"
}

__attribute__((unused)) static void put_void(void *p_content) {
  t_content *c = static_cast<t_content *>(p_content);
  std::cout << c->index << "\n";
}

static void segmented_test_main1() {
  std::vector<int> v = {9,  14, 18, 13, 12, 19, 2, 8,  16, 6,
                        10, 17, 7,  1,  20, 15, 3, 11, 4,  5};
  int size_a = v.size();

  t_stack *stack_a = NULL;
  t_stack *stack_b = NULL;
  for (int &i : v) {
    t_content *c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }

  push_b_segmented(&stack_a, &stack_b, size_a, 5);

  t_stack *st = stack_b;
  for (int i = 0; i < size_a; ++i) {
    if (i < 4) {
      EXPECT_GE(get_content(st)->index, 17);
      EXPECT_LE(get_content(st)->index, 20);
    } else if (4 <= i && i < 8) {
      EXPECT_GE(get_content(st)->index, 9);
      EXPECT_LE(get_content(st)->index, 12);
    } else if (8 <= i && i < 12) {
      EXPECT_GE(get_content(st)->index, 1);
      EXPECT_LE(get_content(st)->index, 4);
    } else if (12 <= i && i < 16) {
      EXPECT_GE(get_content(st)->index, 5);
      EXPECT_LE(get_content(st)->index, 8);
    } else {
      EXPECT_GE(get_content(st)->index, 13);
      EXPECT_LE(get_content(st)->index, 16);
    }
    st = st->next;
  }
}

TEST(push_b_segmented, case1) {
  // save stdout
  int stdout_copy = dup(STDOUT_FILENO);
  // redirect stdout to /dev/null
  int dev_null = open("/dev/null", O_WRONLY);
  dup2(dev_null, 1);
  close(dev_null);

  // execute test
  segmented_test_main1();

  // revert stdout
  dup2(stdout_copy, STDOUT_FILENO);
  close(stdout_copy);
}

static void segmented_test_main2() {
  int N = 20;
  std::vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    v[i] = i + 1;
  }
  // shuffle vector
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::shuffle(v.begin(), v.end(), engine);
  int size_a = N;

  t_stack *stack_a = NULL;
  t_stack *stack_b = NULL;
  for (int &i : v) {
    t_content *c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }

  push_b_segmented(&stack_a, &stack_b, size_a - 3, 5);
  t_stack *st = stack_b;
  for (int i = 0; i < size_a - 3; ++i) {
    if (i < 5) {
      EXPECT_GE(get_content(st)->index, 13);
      EXPECT_LE(get_content(st)->index, 17);
    } else if (5 <= i && i < 8) {
      EXPECT_GE(get_content(st)->index, 7);
      EXPECT_LE(get_content(st)->index, 9);
    } else if (8 <= i && i < 11) {
      EXPECT_GE(get_content(st)->index, 1);
      EXPECT_LE(get_content(st)->index, 3);
    } else if (11 <= i && i < 14) {
      EXPECT_GE(get_content(st)->index, 4);
      EXPECT_LE(get_content(st)->index, 6);
    } else {
      EXPECT_GE(get_content(st)->index, 10);
      EXPECT_LE(get_content(st)->index, 12);
    }
    st = st->next;
  }

  st = stack_a;
  while (st) {
    EXPECT_GE(get_content(st)->index, 18);
    EXPECT_LE(get_content(st)->index, 20);
    st = st->next;
  }
}

TEST(push_b_segmented, case2) {
  // // save stdout
  // int stdout_copy = dup(STDOUT_FILENO);
  // // redirect stdout to /dev/null
  // int dev_null = open("/dev/null", O_WRONLY);
  // dup2(dev_null, 1);
  // close(dev_null);

  // execute test
  segmented_test_main2();

  // // revert stdout
  // dup2(stdout_copy, STDOUT_FILENO);
  // close(stdout_copy);
}
