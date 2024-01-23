// Copyright 2024, reasuke

#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

extern "C" {
  #include "push_swap.h"
}

static void sort_test_main(int N) {
  // initialize vector
  // e.g. N = 3 -> v = {1, 2, 3}
  std::vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    v[i] = i + 1;
  }

  // generate permutation of v (N! patterns)
  // e.g. N = 3, generate the below vectors (3! = 6 patterns)
  // {1, 2, 3}
  // {1, 3, 2}
  // {2, 1, 3}
  // {2, 3, 1}
  // {3, 1, 2}
  // {3, 2, 1}
  do {
    // initialize stack
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    for (int &i : v) {
      ft_lstadd_back(&stack_a, ft_lstnew(new int(i)));
    }
    // sort
    sort(&stack_a, &stack_b, N);
    // check if the order is appropreate
    for (int i = 1; stack_a; ++i, stack_a = stack_a->next) {
      EXPECT_EQ(*(int *)stack_a->content, i);
    }
  } while (std::next_permutation(v.begin(), v.end()));
}

static void sort_test(int N) {
  // save stdout
  int stdout_copy = dup(STDOUT_FILENO);
  // redirect stdout to /dev/null
  int dev_null = open("/dev/null", O_WRONLY);
  dup2(dev_null, 1);
  close(dev_null);

  // execute test
  sort_test_main(N);

  // revert stdout
  dup2(stdout_copy, STDOUT_FILENO);
  close(stdout_copy);
}

TEST(sort, oneElement) {
  sort_test(1);
}

TEST(sort, twoElements) {
  sort_test(2);
}

TEST(sort, threeEelments) {
  sort_test(3);
}

TEST(sort, fourElements) {
  sort_test(4);
}

TEST(sort, fiveElements) {
  sort_test(5);
}
