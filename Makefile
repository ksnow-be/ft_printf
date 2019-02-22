# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 09:09:09 by ksnow-be          #+#    #+#              #
#    Updated: 2019/02/22 16:00:43 by ksnow-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST = ft_printf.out
SRCS = ft_putnbr.c printer.c ft_printf.c char.c point.c o.c x.c u.c f.c \
	   parser.c parser2.c inits.c addit.c pushers.c d.c d2.c priors.c itoas.c \
	   rounders.c f2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME):
	@gcc -c -Wall -Werror -Wextra libft/*.c -I libft/libft.h
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) *.o
	@echo "\033[32mUsage: make test"
	

test:
	@gcc -g -L. -lftprintf $(SRCS) main.c -o $(TEST)
	@./ft_printf.out 
 
clean:
	@rm -rf *.o libft/*.o

fclean: clean
	@rm -rf $(NAME) libft/libft.a
re: fclean all
