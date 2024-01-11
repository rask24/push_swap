// Copyright 2024 reasuke

#include "gtest/gtest.h"

extern "C" {
  #include "push_swap.h"
}

TEST(is_invalid_argument, one_argument_valid) {
  int argc = 2;
  const char *args[] = { "push_swap", "1" };
  char **argv = const_cast<char **>(args);

  EXPECT_EQ(is_invalid_argument(argc, argv), false);
}

TEST(is_invalid_argument, one_argument_not_digit) {
  int argc = 2;
  const char *args[] = { "push_swap", "abc" };
  char **argv = const_cast<char **>(args);

  EXPECT_EQ(is_invalid_argument(argc, argv), true);
}

TEST(is_invalid_argument, one_argument_including_not_digit) {
  int argc = 2;
  const char *args[] = { "push_swap", "42abc" };
  char **argv = const_cast<char **>(args);

  EXPECT_EQ(is_invalid_argument(argc, argv), true);
}

TEST(is_invalid_argument, one_argument_max_overflow) {
  int argc = 2;
  const char *args[] = { "push_swap", "2147483648" };
  char **argv = const_cast<char **>(args);

  EXPECT_EQ(is_invalid_argument(argc, argv), true);
}

TEST(is_invalid_argument, one_argument_min_overflow) {
  int argc = 2;
  const char *args[] = { "push_swap", "-2147483649" };
  char **argv = const_cast<char **>(args);

  EXPECT_EQ(is_invalid_argument(argc, argv), true);
}

TEST(is_invalid_argument, multiple_argument_has_duplicate) {
  int argc = 5;
  const char *args[] = { "push_swap", "1", "3", "5", "+1" };
  char **argv = const_cast<char **>(args);

  EXPECT_EQ(is_invalid_argument(argc, argv), true);
}
