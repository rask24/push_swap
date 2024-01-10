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

CXXFLAGS		= -std=c++20
GTEST_VERSION	= 1.14.0
GTEST_DIR		= ./gtest
GTEST			= $(GTEST_DIR)/gtest
TEST_DIR		= ./test
TEST_SRC		= $(TEST_DIR)/test.cpp
TEST_COMPILE	= $(CXX) $(CXXFLAGS) \
					$(TEST_SRC) \
					$(GTEST_DIR)/googletest-$(GTEST_VERSION)/googletest/src/gtest_main.cc \
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
	@curl -OL https://github.com/google/googletest/archive/refs/tags/v$(GTEST_VERSION).tar.gz
	@curl -OL https://raw.githubusercontent.com/google/googletest/ec44c6c1675c25b9827aacd08c02433cccde7780/googletest/scripts/fuse_gtest_files.py
	@tar -xvzf v$(GTEST_VERSION).tar.gz googletest-$(GTEST_VERSION)
	@python3 fuse_gtest_files.py googletest-1.14.0/googletest $(GTEST_DIR)
	@$(RM) v$(GTEST_VERSION).tar.gz
	@$(RM) fuse_gtest_files.py
	@mv googletest-$(GTEST_VERSION) $(GTEST_DIR)

norm:
	$(NORM) $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)

title:
	@echo "$(BLUE)push_swap$(RESET)"

.PHONY: all clean fclean re

-include $(DEP)
