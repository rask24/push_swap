# executable files
NAME			= push_swap
CHECKER			= checker

# libraries
LIBFT			= $(LIBFT_DIR)/libft.a

# compilar options
CFLAGS			= -Werror -Wextra -Wall
PROD_FLAGS		= -O3
DEV_FLAGS		= -O0 -g -fsanitize=address,integer,undefined -D DEV
LEAK_FLAGS		= -D LEAK
DEP_FLAGS		= -MMD -MP
INCLUDE			= -I$(INC_DIR)
LD_LIBS			= -L$(LIBFT_DIR)
LD_FLAGS		= -lft

# flag options
# 1. PROD_FLAGS: flags for production
# 2. DEV_FLAGS: flags for development
# 3. LEAK_FLAGS: flags for checking leaks
FLAGS_OPTION	= $(PROD_FLAGS)

# directories
SRC_DIR			= src
BUILD_DIR		= build
INC_DIR			= include
LIBFT_DIR		= libft

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
					$(SRC_DIR)/stack_operations/repeat_stack_operations.c \
					$(SRC_DIR)/stack_operations/repeat_dual_stack_operations.c \
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
	@$(CC) $(CFLAGS) $^ $(LD_LIBS) $(LD_FLAGS) -o $(NAME)
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
	@$(CC) $(CFLAGS) $^ $(LD_LIBS) $(LD_FLAGS) -o $(CHECKER)
	@echo "\n$(BLUE)[$(CHECKER)]\t./$(CHECKER)$(RESET)\t$(GREEN)compiled ✔$(RESET)"

# util
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DEP_FLAGS) -c $< -o $@
	@printf "$(GREEN)─$(RESET)"

-include $(DEP)

$(LIBFT):
	@git submodule update --init
	@make -C $(@D)

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

.PHONY: norm
norm:
	norminette $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)

include unit_test.mk
include coverage.mk
