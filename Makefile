NAME			= push_swap
CFLAGS			= -Werror -Wextra -Wall -O3
NORM			= norminette

SRC_DIR			= ./src
BUILD_DIR		= ./build
INC_DIR			= ./include
LIBFT_DIR		= ./libft
SRC				= $(SRC_DIR)/main.c
OBJ				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEP				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(SRC))
DEPFLAGS		= -MMD -MP
INCLUDE			= -I $(INC_DIR)

GTEST_VERSION	= 1.8.0
GTEST_DIR		= ./gtest
GTEST			= $(GTEST_DIR)/gtest $(GTEST_DIR)/googletest-release-$(GTEST_VERSION)
TEST_DIR		= ./test
TEST_SRC		= $(TEST_DIR)/test.cpp
TEST_COMPILE	= clang++ -std=c++11 \
					$(TEST_SRC) \
					$(GTEST_DIR)/googletest-release-$(GTEST_VERSION)/googletest/src/gtest_main.cc \
					$(GTEST_DIR)/gtest/gtest-all.cc \
					-I $(GTEST_DIR) $(INCLUDE) -L $(LIBFT_DIR) -l ft -lpthread -o tester

GREEN	=	\033[0;32m
BLUE	=	\033[0;34m
RED		=	\033[0;31m
RESET	=	\033[0m

all: title $(NAME)

$(NAME): $(OBJ)
	@printf "\n"
	@make -C $(LIBFT_DIR)
	@$(CC) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DEPFLAGS) -c $< -o $@
	@printf "$(GREEN).$(RESET)"

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

test: $(GTEST)
	@echo "$(BLUE)test$(RESET)"
	@$(TEST_COMPILE)
	@./tester # --gtest_filter=Vector.other

$(GTEST):
	@curl -OL https://github.com/google/googletest/archive/refs/tags/release-$(GTEST_VERSION).tar.gz
	@tar -xvzf release-$(GTEST_VERSION).tar.gz googletest-release-$(GTEST_VERSION)
	@$(RM) release-$(GTEST_VERSION).tar.gz
	@python3 googletest-release-$(GTEST_VERSION)/googletest/scripts/fuse_gtest_files.py $(GTEST_DIR)
	@mv googletest-release-$(GTEST_VERSION) $(GTEST_DIR)

norm:
	$(NORM) $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)

title:
	@echo "$(BLUE)push_swap$(RESET)"

.PHONY: all clean fclean re

-include $(DEP)
