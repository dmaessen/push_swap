# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 16:14:01 by dmaessen          #+#    #+#              #
#    Updated: 2023/04/21 13:45:44 by dmaessen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =  main.c check.c error_free.c lists.c little_sort.c big_sort2.c big_sort.c push_moves.c rev_rotate_moves.c rotate_moves.c swap_moves.c index.c \

LIBFT = libft/libft.a

CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIBFT)

$(LIBFT):
	$(MAKE) -C libft/

clean:
	make clean -C libft/
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re