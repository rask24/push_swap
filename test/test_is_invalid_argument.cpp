// Copyright 2024 reasuke

#include "gtest/gtest.h"

extern "C" {
  #include "push_swap.h"
}

TEST(check_args, OneArgumentValid) {
  int argc = 2;
  const char *args[] = { "push_swap", "1" };
  char **argv = const_cast<char **>(args);

  EXPECT_EQ(check_args(argc, argv), 0);
}

TEST(check_args, ArgumentIsZero) {
  int argc = 2;
  const char *args[] = { "push_swap", "0" };
  char **argv = const_cast<char **>(args);

  EXPECT_EQ(check_args(argc, argv), 0);
}

TEST(check_args, ArgumentIsNegative) {
  int argc = 2;
  const char *args[] = { "push_swap", "-42" };
  char **argv = const_cast<char **>(args);

  EXPECT_EQ(check_args(argc, argv), 0);
}

TEST(check_args, OneArgumentNonDigit) {
  int argc = 2;
  const char *args[] = { "push_swap", "abc" };
  char **argv = const_cast<char **>(args);

  EXPECT_EXIT(check_args(argc, argv), ::testing::ExitedWithCode(1), "Error\n");
}

TEST(check_args, OneArgumentIncludingNonDigit) {
  int argc = 2;
  const char *args[] = { "push_swap", "42abc" };
  char **argv = const_cast<char **>(args);

  EXPECT_EXIT(check_args(argc, argv), ::testing::ExitedWithCode(1), "Error\n");
}

TEST(check_args, OneArgumentMaxOverflow) {
  int argc = 2;
  const char *args[] = { "push_swap", "2147483648" };  // INT_MAX + 1
  char **argv = const_cast<char **>(args);

  EXPECT_EXIT(check_args(argc, argv), ::testing::ExitedWithCode(1), "Error\n");
}

TEST(check_args, OneArgumentMinOverflow) {
  int argc = 2;
  const char *args[] = { "push_swap", "-2147483649" };  // INT_MIN - 1
  char **argv = const_cast<char **>(args);

  EXPECT_EXIT(check_args(argc, argv), ::testing::ExitedWithCode(1), "Error\n");
}

TEST(check_args, MultipleArgumentsWithDuplicate) {
  int argc = 5;
  const char *args[] = { "push_swap", "1", "3", "5", "1" };  // Duplicate '1'
  char **argv = const_cast<char **>(args);

  EXPECT_EXIT(check_args(argc, argv), ::testing::ExitedWithCode(1), "Error\n");
}
