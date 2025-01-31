# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaben-sa <yaben-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 13:58:59 by yaben-sa          #+#    #+#              #
#    Updated: 2025/01/31 13:48:40 by yaben-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -MD -MP

DEPS = $(OBJ:.o=.d)

.DEFAULT_GOAL = all

-include $(DEPS)

SRC		= ft_printf.c \
		  ft_print_conversions.c \
		  ft_print_more.c \
		  ft_print_ptr.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all
