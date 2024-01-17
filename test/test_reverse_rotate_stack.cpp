// Copyright 2024, reasuke

#include "gtest/gtest.h"

extern "C" {
  #include "push_swap.h"
}

static void *convert_const_char_to_void(const char *str) {
  const void *const_element = static_cast<const void*>(str);
  void *element = const_cast<void *>(const_element);

  return element;
}

TEST(reverse_rotate, oneElement) {
  t_list *stack;
  void *element0 = convert_const_char_to_void("0");

  stack = NULL;
  ft_lstadd_back(&stack, ft_lstnew(element0));
  reverse_rotate_stack(&stack);
  EXPECT_EQ(stack->content, element0);
  EXPECT_EQ(stack->next, nullptr);
}

TEST(reverse_rotate, twoElements) {
  t_list *stack;
  void *element0 = convert_const_char_to_void("0");
  void *element1 = convert_const_char_to_void("1");

  stack = NULL;
  ft_lstadd_back(&stack, ft_lstnew(element0));
  ft_lstadd_back(&stack, ft_lstnew(element1));
  reverse_rotate_stack(&stack);
  EXPECT_EQ(stack->content, element1);
  EXPECT_EQ(stack->next->content, element0);
  EXPECT_EQ(stack->next->next, nullptr);
}

TEST(reverse_rotate, fiveElements) {
  t_list *stack;
  void *element0 = convert_const_char_to_void("0");
  void *element1 = convert_const_char_to_void("1");
  void *element2 = convert_const_char_to_void("2");
  void *element3 = convert_const_char_to_void("3");
  void *element4 = convert_const_char_to_void("4");

  stack = NULL;
  ft_lstadd_back(&stack, ft_lstnew(element0));
  ft_lstadd_back(&stack, ft_lstnew(element1));
  ft_lstadd_back(&stack, ft_lstnew(element2));
  ft_lstadd_back(&stack, ft_lstnew(element3));
  ft_lstadd_back(&stack, ft_lstnew(element4));
  reverse_rotate_stack(&stack);
  EXPECT_EQ(stack->content, element4);
  EXPECT_EQ(stack->next->content, element0);
  EXPECT_EQ(stack->next->next->content, element1);
  EXPECT_EQ(stack->next->next->next->content, element2);
  EXPECT_EQ(stack->next->next->next->next->content, element3);
  EXPECT_EQ(stack->next->next->next->next->next, nullptr);
}
