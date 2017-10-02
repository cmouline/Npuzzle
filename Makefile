# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/16 20:34:01 by ecouderc          #+#    #+#              #
#    Updated: 2015/07/05 10:46:49 by cmouline         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = npuzzle

SRCS = npuzzle.c ft_error.c ft_remove.c ft_add.c ft_astar.c ft_elem.c \
	   ft_heuristic.c ft_find.c ft_read.c get_next_line/get_next_line.c \
	   ft_manhattan.c ft_goal.c ft_print_grid.c ft_check.c ft_astar_0.c \
	   ft_tab.c ft_state.c ft_hash.c ft_count.c ft_sort.c ft_solvability.c \
	   ft_outof.c ft_hamming.c ft_linear_conflict.c ft_maxswap.c ft_ncurses.c \
	   ft_color.c ft_init.c ft_print_info.c

OBJS = $(SRCS:.c=.o)

HDRS = npuzzle.h get_next_line/get_next_line.h libft/libft.h

all : $(NAME)

$(NAME) : $(OBJS) $(HDRS)
	@make -C libft/
	@gcc -Wall -Wextra -Werror -Ofast -o $(NAME) $(OBJS) -L./libft -lft -lncurses

%.o : %.c $(HDRS)
	@gcc -Wall -Wextra -Werror -Ofast -o $@ -c $<

clean :
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean : clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re : fclean all
