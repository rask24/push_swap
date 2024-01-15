// Copyright 2024, reasuke

#include "gtest/gtest.h"

extern "C" {
  #include "push_swap.h"
}

void *convert_const_char_to_void(const char *str) {
  const void *const_element = static_cast<const void*>(str);
  void *element = const_cast<void *>(const_element);

  return element;
}

TEST(swap, oneElement) {
  t_list *stack;
  void *element0 = convert_const_char_to_void("0");

  stack = NULL;
  ft_lstadd_back(&stack, ft_lstnew(element0));
  swap_stack(&stack);
  EXPECT_EQ(stack->content, element0);
  EXPECT_EQ(stack->next, nullptr);
}

TEST(swap, twoElements) {
  t_list *stack;
  void *element0 = convert_const_char_to_void("0");
  void *element1 = convert_const_char_to_void("1");

  stack = NULL;
  ft_lstadd_back(&stack, ft_lstnew(element0));
  ft_lstadd_back(&stack, ft_lstnew(element1));
  swap_stack(&stack);
  EXPECT_EQ(stack->content, element1);
  EXPECT_EQ(stack->next->content, element0);
  EXPECT_EQ(stack->next->next, nullptr);
}

TEST(swap, fiveElements) {
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
  swap_stack(&stack);
  EXPECT_EQ(stack->content, element1);
  EXPECT_EQ(stack->next->content, element0);
  EXPECT_EQ(stack->next->next->content, element2);
  EXPECT_EQ(stack->next->next->next->content, element3);
  EXPECT_EQ(stack->next->next->next->next->content, element4);
  EXPECT_EQ(stack->next->next->next->next->next, nullptr);
}

TEST(rotate, oneElement) {
  t_list *stack;
  void *element0 = convert_const_char_to_void("0");

  stack = NULL;
  ft_lstadd_back(&stack, ft_lstnew(element0));
  rotate_stack(&stack);
  EXPECT_EQ(stack->content, element0);
  EXPECT_EQ(stack->next, nullptr);
}

TEST(rotate, twoElements) {
  t_list *stack;
  void *element0 = convert_const_char_to_void("0");
  void *element1 = convert_const_char_to_void("1");

  stack = NULL;
  ft_lstadd_back(&stack, ft_lstnew(element0));
  ft_lstadd_back(&stack, ft_lstnew(element1));
  rotate_stack(&stack);
  EXPECT_EQ(stack->content, element1);
  EXPECT_EQ(stack->next->content, element0);
  EXPECT_EQ(stack->next->next, nullptr);
}

TEST(rotate, fiveElements) {
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
  rotate_stack(&stack);
  EXPECT_EQ(stack->content, element1);
  EXPECT_EQ(stack->next->content, element2);
  EXPECT_EQ(stack->next->next->content, element3);
  EXPECT_EQ(stack->next->next->next->content, element4);
  EXPECT_EQ(stack->next->next->next->next->content, element0);
  EXPECT_EQ(stack->next->next->next->next->next, nullptr);
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

TEST(ft_lst_before, test) {
  t_list *stack;
  void *element0 = convert_const_char_to_void("0");
  void *element1 = convert_const_char_to_void("1");
  void *element2 = convert_const_char_to_void("2");
  void *element3 = convert_const_char_to_void("3");
  void *element4 = convert_const_char_to_void("4");
  t_list *lst0 = ft_lstnew(element0);
  t_list *lst1 = ft_lstnew(element1);
  t_list *lst2 = ft_lstnew(element2);
  t_list *lst3 = ft_lstnew(element3);
  t_list *lst4 = ft_lstnew(element4);
  t_list *dummy = ft_lstnew(convert_const_char_to_void("dummy"));


  stack = NULL;
  ft_lstadd_back(&stack, lst0);
  ft_lstadd_back(&stack, lst1);
  ft_lstadd_back(&stack, lst2);
  ft_lstadd_back(&stack, lst3);
  ft_lstadd_back(&stack, lst4);

  // not found
  EXPECT_EQ(ft_lst_before(stack, lst0), nullptr);
  EXPECT_EQ(ft_lst_before(stack, dummy), nullptr);

  // found
  EXPECT_EQ(ft_lst_before(stack, lst1)->content, element0);
  EXPECT_EQ(ft_lst_before(stack, lst2)->content, element1);
  EXPECT_EQ(ft_lst_before(stack, lst3)->content, element2);
  EXPECT_EQ(ft_lst_before(stack, lst4)->content, element3);
}
