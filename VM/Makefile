# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 17:55:29 by nlavrine          #+#    #+#              #
#    Updated: 2019/09/13 15:48:38 by nlavrine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# need to fix func dir

NAME = corewar

SRC =	main.c				\
		sys_out.c			\
		parse_argv.c		\
		errors.c			\
		parse_file.c 		\
		cursor.c			\
		engine.c			\
		op.c				\
		check_func.c		\
		vis_main.c			\
		func/ft_live.c		\
		func/ft_ld.c		\
		func/ft_st.c		\
		func/ft_add.c		\
		func/ft_sub.c		\
		func/ft_or.c		\
		func/ft_xor.c		\
		func/ft_and.c		\
		func/ft_zjmp.c		\
		func/ft_ldi.c		\
		func/ft_sti.c		\
		func/ft_fork.c		\
		func/ft_lld.c		\
		func/ft_lldi.c		\
		func/ft_lfork.c		\
		func/ft_aff.c		\
		func/func.c			\
		set_color.c 		\

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
H_DIR = includes
OBJ_DIR = obj
LIB = libft/libft.a
PRINTF = libft/ft_printf/libftprintf.a

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME) 

$(NAME): $(LIB) $(PRINTF) $(OBJS)
		@$(CC) $(FLAGS) $(OBJS) $(PRINTF) $(LIB) -o $(NAME) -g -lncurses
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@mkdir -p $(OBJ_DIR)/func
		@$(CC) $(FLAGS) -o $@ -c $< -I $(H_DIR) -g

$(LIB):
	@make -C ./libft/

$(PRINTF):
	@make -C ./libft/ft_printf/

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make -C ./libft/ clean
	@make -C ./libft/ft_printf/ clean

fclean: clean
	@rm $(NAME)
	@make -C ./libft/ fclean
	@make -C ./libft/ft_printf/ fclean

re: fclean all
	@make -C ./libft/ re
	@make -C ./libft/ft_printf/ re