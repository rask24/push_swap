// Copyright 2024 reasuke

#include "gtest/gtest.h"

extern "C" {
  #include "push_swap.h"
}

TEST(is_invalid_argument, OneArgumentValid) {
  int argc = 2;
  const char *args[] = { "push_swap", "1" };
  char **argv = const_cast<char **>(args);

  EXPECT_FALSE(is_invalid_argument(argc, argv));
}

TEST(is_invalid_argument, ArgumentIsZero) {
  int argc = 2;
  const char *args[] = { "push_swap", "0" };
  char **argv = const_cast<char **>(args);

  EXPECT_FALSE(is_invalid_argument(argc, argv));
}

TEST(is_invalid_argument, ArgumentIsNegative) {
  int argc = 2;
  const char *args[] = { "push_swap", "-42" };
  char **argv = const_cast<char **>(args);

  EXPECT_FALSE(is_invalid_argument(argc, argv));
}

TEST(is_invalid_argument, OneArgumentNonDigit) {
  int argc = 2;
  const char *args[] = { "push_swap", "abc" };
  char **argv = const_cast<char **>(args);

  EXPECT_TRUE(is_invalid_argument(argc, argv));
}

TEST(is_invalid_argument, OneArgumentIncludingNonDigit) {
  int argc = 2;
  const char *args[] = { "push_swap", "42abc" };
  char **argv = const_cast<char **>(args);

  EXPECT_TRUE(is_invalid_argument(argc, argv));
}

TEST(is_invalid_argument, OneArgumentMaxOverflow) {
  int argc = 2;
  const char *args[] = { "push_swap", "2147483648" };  // INT_MAX + 1
  char **argv = const_cast<char **>(args);

  EXPECT_TRUE(is_invalid_argument(argc, argv));
}

TEST(is_invalid_argument, OneArgumentMinOverflow) {
  int argc = 2;
  const char *args[] = { "push_swap", "-2147483649" };  // INT_MIN - 1
  char **argv = const_cast<char **>(args);

  EXPECT_TRUE(is_invalid_argument(argc, argv));
}

TEST(is_invalid_argument, MultipleArgumentsWithDuplicate) {
  int argc = 5;
  const char *args[] = { "push_swap", "1", "3", "5", "1" };  // Duplicate '1'
  char **argv = const_cast<char **>(args);

  EXPECT_TRUE(is_invalid_argument(argc, argv));
}
