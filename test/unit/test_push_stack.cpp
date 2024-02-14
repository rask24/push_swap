// Copyright 2024, reasuke

#include "gtest/gtest.h"

extern "C" {
#include "push_swap.h"
#include "stack_operations.h"
}

static void *convert_const_char_to_void(const char *str) {
  const void *const_element = static_cast<const void *>(str);
  void *element = const_cast<void *>(const_element);

  return element;
}

TEST(push_stack, noElements) {
  t_stack *stack_a;
  t_stack *stack_b;

  stack_a = NULL;
  stack_b = NULL;

  push_stack(&stack_a, &stack_b);

  EXPECT_EQ(stack_a, nullptr);
  EXPECT_EQ(stack_b, nullptr);
}

TEST(push_stack, nullPush) {
  t_stack *stack_a;
  t_stack *stack_b;
  void *element_10 = convert_const_char_to_void("10");

  stack_a = NULL;
  stack_b = NULL;
  ft_lstadd_back(&stack_b, ft_lstnew(element_10));

  push_stack(&stack_a, &stack_b);

  EXPECT_EQ(stack_a, nullptr);
  EXPECT_EQ(stack_b->content, element_10);
  EXPECT_EQ(stack_b->next, nullptr);
}

TEST(push_stack, pushToNull) {
  t_stack *stack_a;
  void *element_00 = convert_const_char_to_void("00");
  t_stack *stack_b;

  stack_a = NULL;
  ft_lstadd_back(&stack_a, ft_lstnew(element_00));
  stack_b = NULL;

  push_stack(&stack_a, &stack_b);

  EXPECT_EQ(stack_a, nullptr);
  EXPECT_EQ(stack_b->content, element_00);
  EXPECT_EQ(stack_b->next, nullptr);
}

TEST(push_stack, fiveElements) {
  t_stack *stack_a;
  void *element_00 = convert_const_char_to_void("00");
  void *element_01 = convert_const_char_to_void("01");
  void *element_02 = convert_const_char_to_void("02");
  void *element_03 = convert_const_char_to_void("03");
  void *element_04 = convert_const_char_to_void("04");
  t_stack *stack_b;
  void *element_10 = convert_const_char_to_void("10");
  void *element_11 = convert_const_char_to_void("11");
  void *element_12 = convert_const_char_to_void("12");
  void *element_13 = convert_const_char_to_void("13");
  void *element_14 = convert_const_char_to_void("14");

  stack_a = NULL;
  ft_lstadd_back(&stack_a, ft_lstnew(element_00));
  ft_lstadd_back(&stack_a, ft_lstnew(element_01));
  ft_lstadd_back(&stack_a, ft_lstnew(element_02));
  ft_lstadd_back(&stack_a, ft_lstnew(element_03));
  ft_lstadd_back(&stack_a, ft_lstnew(element_04));
  stack_b = NULL;
  ft_lstadd_back(&stack_b, ft_lstnew(element_10));
  ft_lstadd_back(&stack_b, ft_lstnew(element_11));
  ft_lstadd_back(&stack_b, ft_lstnew(element_12));
  ft_lstadd_back(&stack_b, ft_lstnew(element_13));
  ft_lstadd_back(&stack_b, ft_lstnew(element_14));

  push_stack(&stack_a, &stack_b);
  EXPECT_EQ(stack_a->content, element_01);
  EXPECT_EQ(stack_a->next->content, element_02);
  EXPECT_EQ(stack_a->next->next->content, element_03);
  EXPECT_EQ(stack_a->next->next->next->content, element_04);
  EXPECT_EQ(stack_a->next->next->next->next, nullptr);
  EXPECT_EQ(stack_b->content, element_00);
  EXPECT_EQ(stack_b->next->content, element_10);
  EXPECT_EQ(stack_b->next->next->content, element_11);
  EXPECT_EQ(stack_b->next->next->next->content, element_12);
  EXPECT_EQ(stack_b->next->next->next->next->content, element_13);
  EXPECT_EQ(stack_b->next->next->next->next->next->content, element_14);
  EXPECT_EQ(stack_b->next->next->next->next->next->next, nullptr);
}
