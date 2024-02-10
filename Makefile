NAME			= push_swap
CFLAGS			= -Werror -Wextra -Wall
CXXFLAGS		= -std=c++17 -Wall -Wextra -Werror
PROD_FLAGS		= -O3
DEV_FLAGS		= -g -fsanitize=address -O0 -D DEV
LEAK_FLAGS		= -O0 -D DEV -D LEAK
INCLUDE			= -I $(INC_DIR)

SRC_DIR			= src
BUILD_DIR		= build
INC_DIR			= include
LIBFT_DIR		= libft
TEST_DIR		= test
GTEST_DIR		= test/gtest

SRC				= $(SRC_DIR)/main.c \
					$(SRC_DIR)/initialization/check_args.c \
					$(SRC_DIR)/initialization/exit_with_error.c \
					$(SRC_DIR)/initialization/generate_stack.c \
					$(SRC_DIR)/sort/sort.c \
					$(SRC_DIR)/sort/micro_sort.c \
					$(SRC_DIR)/sort/nano_sort.c \
					$(SRC_DIR)/sort/is_sorted_stack.c \
					$(SRC_DIR)/sort/large_sort/large_sort.c \
					$(SRC_DIR)/sort/large_sort/set_cost.c \
					$(SRC_DIR)/sort/large_sort/set_opt.c \
					$(SRC_DIR)/sort/large_sort/greedy_operation.c \
					$(SRC_DIR)/stack_operations/push.c \
					$(SRC_DIR)/stack_operations/swap.c \
					$(SRC_DIR)/stack_operations/rotate.c \
					$(SRC_DIR)/stack_operations/reverse_rotate.c \
					$(SRC_DIR)/stack_operations/do_single_n_operations.c \
					$(SRC_DIR)/stack_operations/do_double_n_operations.c \
					$(SRC_DIR)/utils/get_first_index.c \
					$(SRC_DIR)/utils/get_second_index.c \
					$(SRC_DIR)/utils/get_third_index.c \
					$(SRC_DIR)/utils/clear_stack.c \
					$(SRC_DIR)/utils/get_content.c \
					$(SRC_DIR)/utils/stack_size.c
OBJ				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEP				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(SRC))
OBJ_FILTER_MAIN	= $(filter-out $(BUILD_DIR)/main.o, $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC)))
TEST_NAME		= tester
TEST_SRC		= $(TEST_DIR)/test_check_args.cpp \
					$(TEST_DIR)/test_push_stack.cpp \
					$(TEST_DIR)/test_reverse_rotate_stack.cpp \
					$(TEST_DIR)/test_rotate_stack.cpp \
					$(TEST_DIR)/test_swap_stack.cpp \
					$(TEST_DIR)/test_set_cost.cpp \
					$(TEST_DIR)/test_set_opt_method.cpp \
					$(TEST_DIR)/test_greedy_operation.cpp \
					$(TEST_DIR)/test_is_sorted_stack.cpp \
					$(TEST_DIR)/test_sort.cpp
TEST_OBJ		= $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/$(TEST_DIR)/%.o, $(TEST_SRC))
DEPFLAGS		= -MMD -MP
GTEST_SRC		= $(GTEST_DIR)/gtest_main.cc $(GTEST_DIR)/gtest-all.cc
GTEST_OBJ		= $(patsubst $(GTEST_DIR)/%.cc, $(BUILD_DIR)/$(GTEST_DIR)/%.o, $(GTEST_SRC))

GTEST_VERSION	= 1.14.0
GTEST_ARCHIVE	= v$(GTEST_VERSION).tar.gz
GTEST_REPO_URL	= https://github.com/google/googletest/archive/refs/tags/$(GTEST_ARCHIVE)
GTEST_SRC_DIR	= googletest-$(GTEST_VERSION)
GTEST_FUSE_URL	= https://raw.githubusercontent.com/google/googletest/ec44c6c1675c25b9827aacd08c02433cccde7780/googletest/scripts/$(GTEST_FUSE)
GTEST_FUSE		= fuse_gtest_files.py

NORM			= norminette

GREEN	=	\033[0;32m
BLUE	=	\033[0;34m
RED		=	\033[0;31m
RESET	=	\033[0m

all: CFLAGS += $(PROD_FLAGS)
all: title
all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n"
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $^ -L $(LIBFT_DIR) -lft -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DEPFLAGS) -c $< -o $@
	@printf "$(GREEN).$(RESET)"

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ) $(DEP)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

dev: CFLAGS += $(DEV_FLAGS)
dev: title
dev: $(NAME)

redev: fclean dev

leak: CFLAGS += $(LEAK_FLAGS)
leak: title
leak: $(NAME)

releak: fclean leak

test: test_clean test_main

test_main: all $(GTEST_OBJ) $(TEST_OBJ)
	@echo "$(BLUE)\ntest linking$(RESET)"
	@$(CXX) -L $(LIBFT_DIR) -lft -lpthread $(OBJ_FILTER_MAIN) $(TEST_OBJ) $(GTEST_OBJ) -o $(TEST_NAME)
	./$(TEST_NAME)
	@$(RM) $(TEST_NAME)

test_clean:
	@echo "$(BLUE)test cleaning$(RESET)"
	@$(RM) -r $(BUILD_DIR)/$(TEST_DIR)

$(BUILD_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -I $(TEST_DIR) $(INCLUDE) -c $< -o $@
	@printf "$(GREEN).$(RESET)"

$(GTEST_OBJ): $(GTEST_DIR)
	@echo "$(BLUE)test compiling$(RESET)"
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -I $(TEST_DIR) $(INCLUDE) -c $(GTEST_DIR)/gtest-all.cc -o $(BUILD_DIR)/$(GTEST_DIR)/gtest-all.o
	@printf "$(GREEN).$(RESET)"
	@$(CXX) $(CXXFLAGS) -I $(TEST_DIR) $(INCLUDE) -c $(GTEST_DIR)/gtest_main.cc -o $(BUILD_DIR)/$(GTEST_DIR)/gtest_main.o
	@printf "$(GREEN).$(RESET)"

$(GTEST_DIR):
	@echo "fetching google test"
	@curl -#OL $(GTEST_REPO_URL)
	@echo "fetching fuse_gtest_files.py"
	@curl -#OL $(GTEST_FUSE_URL)
	@tar -xzf $(GTEST_ARCHIVE) $(GTEST_SRC_DIR)
	@python3 $(GTEST_FUSE) $(GTEST_SRC_DIR)/googletest $(GTEST_DIR)
	@mv $(GTEST_SRC_DIR)/googletest/src/gtest_main.cc $(GTEST_DIR)
	@mv $(GTEST_DIR)/gtest/* $(GTEST_DIR)
	@$(RM) -r $(GTEST_SRC_DIR) $(GTEST_DIR)/gtest $(GTEST_ARCHIVE) $(GTEST_FUSE)

norm:
	$(NORM) $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)

title:
	@echo "$(BLUE)push_swap$(RESET)"

.PHONY: all clean fclean re dev redev leak releak test norm title

-include $(DEP)
