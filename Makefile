# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:03:02 by javiersa          #+#    #+#              #
#    Updated: 2023/03/31 19:28:41 by javiersa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
PERSONALNAME = Ft_printf
CFLAGS = -Wall -Werror -Wextra
CC = gcc
CLEAN = rm -Rf
SRC = ft_printf.c ft_printf_number.c ft_printf_string.c ft_printf_hex.c

OBJS := $(SRC:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	@echo "$(GREEN)Compiling:$(DEFAULT) $(notdir $<)"
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(MAGENTA)Library $(NAME) created successfully.$(DEFAULT)"
clean:
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)Removing:$(DEFAULT) All objects from $(PERSONALNAME)."
fclean: clean
	@$(CLEAN) ./$(NAME)
	@echo "$(RED)Removing:$(DEFAULT) Library $(NAME)."
re: fclean all

#Personal use
git: fclean gitignore
	git add *
	git commit -m "Little changes"
	git push
	git ls-files
gitignore:
	@echo ".*\n*.out\n*.o\n*.a">.gitignore
	@echo "$(GREEN)Gitignore created successfully.$(DEFAULT)"

.PHONY : all clean fclean re bonus git gitignore

#COLORS
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
DEFAULT	:= \033[0m