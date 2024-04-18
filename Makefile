# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 18:50:52 by ctacconi          #+#    #+#              #
#    Updated: 2024/04/18 18:50:55 by ctacconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

SRC= main.c check_args.c utils.c stack.c swap.c push.c rotate.c reverse_rotate.c sort.c \
sort_utils.c 

OBJ=$(SRC:.c=.o)

CC=cc

CFLAGS= -Wall -Wextra -Werror

INCLUDE= Makefile push_swap.h

#LIB=ar rcs

RM=rm -f

# Metodo implicito
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<


# Mis metodos
#all: make_libs $(NAME)
all:	$(NAME)

#make_libs:
#	Make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	#gcc -Wall -Wextre -Werror main.c -o push_swap
	#cp libft/libft.a $(NAME)
	#$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
#	Make -C libft/ clean

fclean: clean
	$(RM) $(NAME)
#	Make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
