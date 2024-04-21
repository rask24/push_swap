// Copyright 2024, reasuke

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "gtest/gtest.h"

extern "C" {
#include <fcntl.h>

#include "large_sort.h"
#include "push_swap.h"
}

__attribute__((unused)) static void put_void(void *p_content) {
  t_content *c = static_cast<t_content *>(p_content);
  std::cout << c->index << "\n";
}

static void segmented_test_main1() {
  std::vector<int> v = {2, 7,  4,  9, 10, 0,  17, 19, 13, 8,
                        1, 15, 11, 3, 5,  18, 16, 12, 14, 6};
  int size_a = v.size();

  t_stack *stack_a = NULL;
  t_stack *stack_b = NULL;
  for (int &i : v) {
    t_content *c = new t_content({i, -1, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }

  push_b_segmented(&stack_a, &stack_b, size_a, 5);

  t_stack *st = stack_b;
  for (int i = 0; i < size_a; ++i) {
    if (i < 4) {
      EXPECT_EQ(get_content(st)->segment, 4);
      EXPECT_GE(get_content(st)->index, 16);
      EXPECT_LE(get_content(st)->index, 19);
    } else if (4 <= i && i < 8) {
      EXPECT_EQ(get_content(st)->segment, 2);
      EXPECT_GE(get_content(st)->index, 8);
      EXPECT_LE(get_content(st)->index, 11);
    } else if (8 <= i && i < 12) {
      EXPECT_EQ(get_content(st)->segment, 0);
      EXPECT_GE(get_content(st)->index, 0);
      EXPECT_LE(get_content(st)->index, 3);
    } else if (12 <= i && i < 16) {
      EXPECT_EQ(get_content(st)->segment, 1);
      EXPECT_GE(get_content(st)->index, 4);
      EXPECT_LE(get_content(st)->index, 7);
    } else {
      EXPECT_EQ(get_content(st)->segment, 3);
      EXPECT_GE(get_content(st)->index, 12);
      EXPECT_LE(get_content(st)->index, 15);
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
    v[i] = i;
  }
  // shuffle vector
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::shuffle(v.begin(), v.end(), engine);
  int size_a = N;

  t_stack *stack_a = NULL;
  t_stack *stack_b = NULL;
  for (int &i : v) {
    t_content *c = new t_content({i, -1, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }

  push_b_segmented(&stack_a, &stack_b, size_a - 3, 5);
  t_stack *st = stack_b;
  for (int i = 0; i < size_a - 3; ++i) {
    if (i < 5) {
      EXPECT_EQ(get_content(st)->segment, 4);
      EXPECT_GE(get_content(st)->index, 12);
      EXPECT_LE(get_content(st)->index, 19);
    } else if (5 <= i && i < 8) {
      EXPECT_EQ(get_content(st)->segment, 2);
      EXPECT_GE(get_content(st)->index, 6);
      EXPECT_LE(get_content(st)->index, 8);
    } else if (8 <= i && i < 11) {
      EXPECT_EQ(get_content(st)->segment, 0);
      EXPECT_GE(get_content(st)->index, 0);
      EXPECT_LE(get_content(st)->index, 2);
    } else if (11 <= i && i < 14) {
      EXPECT_EQ(get_content(st)->segment, 1);
      EXPECT_GE(get_content(st)->index, 3);
      EXPECT_LE(get_content(st)->index, 5);
    } else {
      EXPECT_EQ(get_content(st)->segment, 3);
      EXPECT_GE(get_content(st)->index, 9);
      EXPECT_LE(get_content(st)->index, 11);
    }
    st = st->next;
  }

  st = stack_a;
  while (st) {
    EXPECT_EQ(get_content(st)->segment, -1);
    EXPECT_GE(get_content(st)->index, 12);
    EXPECT_LE(get_content(st)->index, 19);
    st = st->next;
  }
}

TEST(push_b_segmented, case2) {
  // save stdout
  int stdout_copy = dup(STDOUT_FILENO);
  // redirect stdout to /dev/null
  int dev_null = open("/dev/null", O_WRONLY);
  dup2(dev_null, 1);
  close(dev_null);

  // execute test
  segmented_test_main2();

  // revert stdout
  dup2(stdout_copy, STDOUT_FILENO);
  close(stdout_copy);
}
