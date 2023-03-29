# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:03:02 by javiersa          #+#    #+#              #
#    Updated: 2023/03/29 19:20:15 by javiersa         ###   ########.fr        #
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
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(PERSONALNAME) -> Objects and library created successfully.$(DEFAULT)"
clean:
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)$(PERSONALNAME) -> Objects files deleted.$(DEFAULT)"
fclean:
	@$(CLEAN) ./$(OBJS)
	@$(CLEAN) ./$(NAME)
	@echo "$(RED)$(PERSONALNAME) -> Library and objects files deleted.$(DEFAULT)"
re: fclean all

#Personal use
git: fclean gitignore
	git add *
	git commit -m "AUTOMATIC COMMIT"
	git push
	git ls-files
gitignore:
	@echo ".*\n*.out\n*.o\n*.a">.gitignore
	@echo "$(GREEN)Gitignore created successfully.$(DEFAULT)"

.PHONY : all clean fclean re bonus git gitignore

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m