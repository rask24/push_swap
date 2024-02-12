// Copyright 2024, reasuke

#include <algorithm>
#include <random>
#include <vector>

#include "gtest/gtest.h"

extern "C" {
#include "push_swap.h"
#include "sort.h"
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
      t_content *c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
      ft_lstadd_back(&stack_a, ft_lstnew(c));
    }
    // sort
    sort(&stack_a, &stack_b);
    // check if the order is appropreate
    for (int i = 1; stack_a; ++i, stack_a = stack_a->next) {
      EXPECT_EQ(get_first_index(&stack_a), i);
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

static void random_sort_test_main(int N) {
  std::vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    v[i] = i + 1;
  }
  // shuffle vector
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::shuffle(v.begin(), v.end(), engine);

  t_list *stack_a = NULL;
  t_list *stack_b = NULL;
  for (int &i : v) {
    t_content *c = new t_content({i, 0, 0, 0, 0, 0, INIT, false});
    ft_lstadd_back(&stack_a, ft_lstnew(c));
  }
  // sort
  sort(&stack_a, &stack_b);
  // check if the order is appropreate
  for (int i = 1; stack_a; ++i, stack_a = stack_a->next) {
    EXPECT_EQ(*(int *)stack_a->content, i);
  }
}

static void random_sort_test(int N) {
  // save stdout
  int stdout_copy = dup(STDOUT_FILENO);
  // redirect stdout to /dev/null
  int dev_null = open("/dev/null", O_WRONLY);
  dup2(dev_null, 1);
  close(dev_null);

  // execute test
  random_sort_test_main(N);

  // revert stdout
  dup2(stdout_copy, STDOUT_FILENO);
  close(stdout_copy);
}

TEST(sort, oneElement) { sort_test(1); }

TEST(sort, twoElements) { sort_test(2); }

TEST(sort, threeEelments) { sort_test(3); }

TEST(sort, fourElements) { sort_test(4); }

TEST(sort, fiveElements) { sort_test(5); }

TEST(sort, sixElements) { sort_test(6); }

TEST(sort, sevenElements) { sort_test(7); }

TEST(sort, eightElementsRandom) { random_sort_test(8); }

TEST(sort, nineElementsRandom) { random_sort_test(9); }

TEST(sort, tenElementsRandom) { random_sort_test(10); }

TEST(sort, hundredElementsRandom) { random_sort_test(100); }

TEST(sort, twoHundredElementsRandom) { random_sort_test(200); }

TEST(sort, thousandElementsRandom) { random_sort_test(500); }
