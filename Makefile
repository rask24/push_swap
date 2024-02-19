# executable files
NAME			= push_swap
CHECKER			= checker
TEST_NAME		= unit_tester

# libraries
LIBFT			= $(LIBFT_DIR)/libft.a

# compilar options
CFLAGS			= -Werror -Wextra -Wall
CXXFLAGS		= -std=c++17 -Wall -Wextra -Werror
PROD_FLAGS		= -O3
DEV_FLAGS		= -O0 -g -fsanitize=address,integer,undefined -D DEV
LEAK_FLAGS		= -D LEAK
DEPFLAGS		= -MMD -MP
INCLUDE			= -I $(INC_DIR)

# flag options
# 1. PROD_FLAGS: flags for production
# 2. DEV_FLAGS: flags for development
# 3. LEAK_FLAGS: flags for checking leaks
FLAGS_OPTION	= $(LEAK_FLAGS)

# directories
SRC_DIR			= src
BUILD_DIR		= build
INC_DIR			= include
LIBFT_DIR		= libft
TEST_DIR		= test/unit
GTEST_DIR		= test/unit/gtest
TEST_BUILD_DIR	= test/build

# mandatory source files
SRC				= $(SRC_DIR)/main.c \
					$(SRC_DIR)/initialization/check_args.c \
					$(SRC_DIR)/initialization/exit_with_error.c \
					$(SRC_DIR)/initialization/generate_stack.c \
					$(SRC_DIR)/sort/sort.c \
					$(SRC_DIR)/sort/micro_sort.c \
					$(SRC_DIR)/sort/nano_sort.c \
					$(SRC_DIR)/sort/is_sorted_stack.c \
					$(SRC_DIR)/sort/large_sort/large_sort.c \
					$(SRC_DIR)/sort/large_sort/push_b_segmented.c \
					$(SRC_DIR)/sort/large_sort/set_cost.c \
					$(SRC_DIR)/sort/large_sort/set_min_cost_opt_method.c \
					$(SRC_DIR)/sort/large_sort/set_is_target.c \
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

# bonus source files
BONUS_SRC		= $(SRC_DIR)/checker/checker_main.c \
					$(SRC_DIR)/checker/sort_based_on_operation.c \
					$(SRC_DIR)/initialization/check_args.c \
					$(SRC_DIR)/initialization/exit_with_error.c \
					$(SRC_DIR)/initialization/generate_stack.c \
					$(SRC_DIR)/sort/is_sorted_stack.c \
					$(SRC_DIR)/stack_operations/push.c \
					$(SRC_DIR)/stack_operations/swap.c \
					$(SRC_DIR)/stack_operations/rotate.c \
					$(SRC_DIR)/stack_operations/reverse_rotate.c \
					$(SRC_DIR)/utils/get_content.c \
					$(SRC_DIR)/utils/stack_size.c \
					$(SRC_DIR)/utils/clear_stack.c
BONUS_OBJ		= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(BONUS_SRC))
BONUS_DEP		= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(BONUS_SRC))

# header files
HEADER			= $(wildcard $(INC_DIR)/*.h)

# test files
TEST_SRC		= $(TEST_DIR)/test_check_args.cpp \
					$(TEST_DIR)/test_push_stack.cpp \
					$(TEST_DIR)/test_reverse_rotate_stack.cpp \
					$(TEST_DIR)/test_rotate_stack.cpp \
					$(TEST_DIR)/test_swap_stack.cpp \
					$(TEST_DIR)/test_push_b_segmented.cpp \
					$(TEST_DIR)/test_set_cost.cpp \
					$(TEST_DIR)/test_set_min_cost_opt_method.cpp \
					$(TEST_DIR)/test_set_is_target.cpp \
					$(TEST_DIR)/test_greedy_operation.cpp \
					$(TEST_DIR)/test_is_sorted_stack.cpp \
					$(TEST_DIR)/test_sort.cpp
TEST_OBJ		= $(patsubst $(TEST_DIR)/%.cpp, $(TEST_BUILD_DIR)/%.o, $(TEST_SRC))
GTEST_SRC		= $(GTEST_DIR)/gtest_main.cc $(GTEST_DIR)/gtest-all.cc
GTEST_OBJ		= $(patsubst $(GTEST_DIR)/%.cc, $(TEST_BUILD_DIR)/%.o, $(GTEST_SRC))

# google test version: 1.14.0
GTEST_ARCHIVE	= v1.14.0.tar.gz
GTEST_REPO_URL	= https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
GTEST_SRC_DIR	= googletest-1.14.0
GTEST_FUSE_URL	= https://raw.githubusercontent.com/google/googletest/ec44c6c1675c25b9827aacd08c02433cccde7780/googletest/scripts/fuse_gtest_files.py
GTEST_FUSE		= fuse_gtest_files.py

# colors
RESET			= \033[0m
ORANGE			= \033[0;33m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[1;92m
YELLOW			= \033[1;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

# rules for mandatory
.PHONY: all
all: CFLAGS += $(FLAGS_OPTION)
all: $(NAME)

$(NAME): $(LIBFT) $(SRC) $(HEADER)
	@make _main CFLAGS="$(CFLAGS)"

.PHONY: _main
_main:
	@echo "$(BLUE)[$(NAME)]\t./$(NAME)$(RESET)\t$(WHITE)compling...$(RESET)"
	@make _build CFLAGS="$(CFLAGS)"

.PHONY: _build
_build: $(OBJ)
	@$(CC) $(CFLAGS) $^ -L $(LIBFT_DIR) -lft -o $(NAME)
	@echo "\n$(BLUE)[$(NAME)]\t./$(NAME)$(RESET)\t$(GREEN)compiled ✔$(RESET)"

# rules for bonus
.PHONY: bonus
bonus: CFLAGS += $(FLAGS_OPTION)
bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(BONUS_SRC) $(HEADER)
	@make _checker_main CFLAGS="$(CFLAGS)"

.PHONY: _checker_main
_checker_main:
	@echo "$(BLUE)[$(CHECKER)]\t./$(CHECKER)$(RESET)\t$(WHITE)compling...$(RESET)"
	@make _checker_build CFLAGS="$(CFLAGS)"

.PHONY: _checker_build
_checker_build: $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $^ -L $(LIBFT_DIR) -lft -o $(CHECKER)
	@echo "\n$(BLUE)[$(CHECKER)]\t./$(CHECKER)$(RESET)\t$(GREEN)compiled ✔$(RESET)"

# util
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DEPFLAGS) -c $< -o $@
	@printf "$(GREEN)─$(RESET)"

$(LIBFT): $(LIBFT_DIR)
	@make -C $(@D)

$(LIBFT_DIR):
	@git submodule update --init

.PHONY: clean
clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ) $(DEP)
	@echo "$(BLUE)[$(NAME)]\tobject files$(RESET)\t$(GREEN)deleted ✔$(RESET)"
	@$(RM) $(BONUS_OBJ) $(BONUS_DEP)
	@echo "$(BLUE)[$(CHECKER)]\tobject files$(RESET)\t$(GREEN)deleted ✔$(RESET)"

.PHONY: fclean
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "$(BLUE)[$(NAME)]\t./$(NAME)$(RESET)\t$(GREEN)deleted ✔$(RESET)"
	@$(RM) $(CHECKER)
	@echo "$(BLUE)[$(CHECKER)]\t./$(NAME)$(RESET)\t$(GREEN)deleted ✔$(RESET)"

.PHONY: re
re: fclean all

# rules for test
.PHONY: test
test: all $(GTEST_OBJ) $(TEST_OBJ)
	@$(CXX) -L $(LIBFT_DIR) -lft -lpthread $(OBJ_FILTER_MAIN) $(TEST_OBJ) $(GTEST_OBJ) -o $(TEST_NAME)
	@echo "\n$(BLUE)[gtest]\t\t./$(TEST_NAME)$(RESET)\t$(GREEN)compiled ✔$(RESET)"
	./$(TEST_NAME)

.PHONY: test_clean
test_clean:
	@$(RM) -r $(TEST_BUILD_DIR)
	@echo "$(BLUE)[gtest]\t\t./$(TEST_NAME)$(RESET)\t$(GREEN)deleted ✔$(RESET)"

.PHONY: retest
retest: test_clean test

$(TEST_BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -I $(TEST_DIR) $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)─$(RESET)"

$(GTEST_OBJ): $(GTEST_DIR)
	@echo "$(BLUE)[gtest]\t\t./$(TEST_NAME)$(RESET)\t$(WHITE)compling...$(RESET)"
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -I $(TEST_DIR) $(INCLUDE) -c $(GTEST_DIR)/gtest-all.cc -o $(TEST_BUILD_DIR)/gtest-all.o
	@printf "$(GREEN)─$(RESET)"
	@$(CXX) $(CXXFLAGS) -I $(TEST_DIR) $(INCLUDE) -c $(GTEST_DIR)/gtest_main.cc -o $(TEST_BUILD_DIR)/gtest_main.o
	@printf "$(GREEN)─$(RESET)"

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

.PHONY: norm
norm:
	norminette $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)

-include $(DEP)
