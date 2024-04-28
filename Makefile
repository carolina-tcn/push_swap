# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 18:50:52 by ctacconi          #+#    #+#              #
#    Updated: 2024/04/25 16:39:04 by ctacconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

SRC= main.c check_args.c utils.c stack.c swap.c push.c rotate.c reverse_rotate.c sort.c \
sort_utils.c sort_bigs.c 

OBJ=$(SRC:.c=.o)

CC=cc

CFLAGS= -Wall -Wextra -Werror

INCLUDE= Makefile push_swap.h

RM=rm -f

# Implicit method
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

# My methods
all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
