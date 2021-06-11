# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 16:35:42 by rmartins          #+#    #+#              #
#    Updated: 2021/06/09 14:05:48 by rmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CFLAGS = -Wall -Wextra -Werror -g
OBJ_DIR = obj
SRC_DIR = src
OBJ_SERVER = $(SRC_SERVER:%.c=$(OBJ_DIR)/%.o)
OBJ_COMMON = $(SRC_COMMON:%.c=$(OBJ_DIR)/%.o)
OBJ_CLIENT = $(SRC_CLIENT:%.c=$(OBJ_DIR)/%.o)

HEADER = ft_ansi.h \
	minitalk.h

SRC_SERVER = server/main.c

SRC_COMMON = common/ft_putchar.c \
	common/ft_putnbr.c \
	common/ft_putstr.c \
	common/ft_atoi.c

SRC_CLIENT = client/main.c

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(OBJ_COMMON)
	@echo $(ANSI_B_BGREEN) "compile executables" $(ANSI_RESET)$(ANSI_F_BBLACK)
	gcc $(CFLAGS) $(OBJ_SERVER) $(OBJ_COMMON) -o $(NAME_SERVER)
	@echo $(ANSI_RESET) ""

$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_COMMON)
	@echo $(ANSI_B_BGREEN) "compile executables" $(ANSI_RESET)$(ANSI_F_BBLACK)
	gcc $(CFLAGS) $(OBJ_CLIENT) $(OBJ_COMMON) -o $(NAME_CLIENT)
	@echo $(ANSI_RESET) ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(addprefix inc/,$(HEADER))
	@echo $(ANSI_B_BGREEN) "compile objects" $(ANSI_RESET)$(ANSI_F_BBLACK)
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -Iinc -c $< -o $@
	@echo $(ANSI_RESET)

clean:
	@echo $(ANSI_B_RED) "clean" $(ANSI_RESET)$(ANSI_F_BRED)
	rm -rf $(OBJ_DIR)
	@echo $(ANSI_RESET) ""

fclean: clean
	@echo $(ANSI_B_RED) "fclean" $(ANSI_RESET)$(ANSI_F_BRED)
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)
	@echo $(ANSI_RESET) ""

re: fclean all

.PHONY: all clean fclean

# colors
ANSI_RESET = "\033[0m"
ANSI_B_RED = "\033[41m"
ANSI_B_BGREEN = "\033[42;1m"
ANSI_F_BRED = "\033[31;1m"
ANSI_F_BBLACK = "\033[30;1m"


lib:
	$(MAKE) -C libft

norm:
	@echo $(ANSI_B_RED) "norminette v3" $(ANSI_RESET)
	$(MAKE) norm -C libft
	@norminette $(addprefix inc/,$(HEADER)) \
		$(addprefix src/,$(SRC_SERVER)) \
		$(addprefix src/,$(SRC_COMMON)) \
		$(addprefix src/,$(SRC_CLIENT))

run: all
	@echo $(ANSI_B_RED) "Running for debbuger without sanitize" $(ANSI_RESET)
	./$(NAME_SERVER)

runv: all
	@echo $(ANSI_B_RED) "Valgrind RESULT" $(ANSI_RESET)
	#valgrind -q --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME_SERVER)
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME_SERVER)

runs: all
	@echo $(ANSI_B_RED) "Running with sanitize" $(ANSI_RESET)
	gcc $(CFLAGS) -fsanitize=address $(OBJ_SERVER) $(OBJ_COMMON) $(LIBFT) -o server_s
	./server_s