NAME			= push_swap
CFLAGS			= -Werror -Wextra -Wall
PROD_FLAGS		= -O3
DEV_FLAGS		= -g -O0 -D DEV

SRC_DIR			= ./src
BUILD_DIR		= ./build
INC_DIR			= ./include
LIBFT_DIR		= ./libft
SRC				= $(SRC_DIR)/main.c \
					$(SRC_DIR)/check_args.c \
					$(SRC_DIR)/generate_stack.c \
					$(SRC_DIR)/nano_sort.c \
					$(SRC_DIR)/stack_operations/swap.c \
					$(SRC_DIR)/stack_operations/rotate.c \
					$(SRC_DIR)/utils/exit_with_error.c
OBJ				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEP				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(SRC))
DEPFLAGS		= -MMD -MP
INCLUDE			= -I $(INC_DIR)

CXXFLAGS		= -std=c++20 -Wall -Wextra -Werror
TEST_DIR		= ./test
TEST_SRC		= $(TEST_DIR)/test_is_invalid_argument.cpp \
					$(TEST_DIR)/test_stack_operations.cpp
TEST_OBJ		= $(filter-out $(BUILD_DIR)/main.o, $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC)))
GTEST_VERSION	= 1.14.0
GTEST_DIR		= ./test/gtest
GTEST_ARCHIVE	= v$(GTEST_VERSION).tar.gz
GTEST_SRC_DIR	= googletest-$(GTEST_VERSION)
GTEST_FUSE		= fuse_gtest_files.py

NORM			= norminette

GREEN	=	\033[0;32m
BLUE	=	\033[0;34m
RED		=	\033[0;31m
RESET	=	\033[0m

all: CFLAGS += $(PROD_FLAGS)
all: title $(NAME)

$(NAME): $(OBJ)
	@printf "\n"
	@make -C $(LIBFT_DIR)
	@$(CC) $^ -L $(LIBFT_DIR) -lft -o $@

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

test: $(GTEST_DIR)
	@echo "$(BLUE)test$(RESET)"
	@$(CXX) $(CXXFLAGS) -I $(TEST_DIR) $(INCLUDE) -L $(LIBFT_DIR) -l ft -lpthread -o tester \
		$(TEST_SRC) $(GTEST_DIR)/gtest_main.cc $(GTEST_DIR)/gtest-all.cc $(TEST_OBJ)
	@./tester # --gtest_filter=Vector.other
	@$(RM) tester

$(GTEST_DIR):
	@echo "$(BLUE)fetching google test$(RESET)"
	@curl -#OL https://github.com/google/googletest/archive/refs/tags/$(GTEST_ARCHIVE)
	@echo "$(BLUE)fetching fuse_gtest_files.py$(RESET)"
	@curl -#OL https://raw.githubusercontent.com/google/googletest/ec44c6c1675c25b9827aacd08c02433cccde7780/googletest/scripts/$(GTEST_FUSE)
	@tar -xzf $(GTEST_ARCHIVE) $(GTEST_SRC_DIR)
	@python3 $(GTEST_FUSE) $(GTEST_SRC_DIR)/googletest $(GTEST_DIR)
	@mv $(GTEST_SRC_DIR)/googletest/src/gtest_main.cc $(GTEST_DIR)
	@mv $(GTEST_DIR)/gtest/* $(GTEST_DIR)
	@$(RM) -r $(GTEST_SRC_DIR) $(GTEST_DIR)/gtest $(GTEST_ARCHIVE) $(GTEST_FUSE)

norm:
	$(NORM) $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)

title:
	@echo "$(BLUE)push_swap$(RESET)"

.PHONY: all clean fclean re dev test norm title

-include $(DEP)
