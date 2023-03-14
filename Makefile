# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:03:02 by javiersa          #+#    #+#              #
#    Updated: 2023/03/14 20:34:03 by javiersa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
CC = gcc
CLEAN = rm -Rf
SRC = ft_printf.c ft_printf_number.c ft_printf_string.c ft_printf_hex.c

OBJS := $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
clean:
	$(CLEAN) ./$(OBJS)
fclean: clean
	$(CLEAN) ./$(NAME)
re: fclean all

#Personal use
git: fclean gitignore
	git add *
	git commit -m "AUTOMATIC COMMIT"
	git push
	git ls-files
gitignore:
	echo ".*\n*.out\n*.o\n*.a">.gitignore
	

.PHONY : all clean fclean re bonus compile git gitignore