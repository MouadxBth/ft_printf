# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 12:39:59 by mbouthai          #+#    #+#              #
#    Updated: 2022/02/27 18:00:25 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libprintf.a

CC              = gcc

ARCHIVE = ar -rcs

DEPS    = ft_printf.h

CFLAGS  = -Wall -Wextra

SRCS    = ft_printf_utils.c  \
          ft_handle_char.c ft_handle_str.c \
	  ft_handle_nbr.c ft_handle_ptr.c \
	  ft_printf.c

OBJS    = $(SRCS:.c=.o)

DRIVER	= main.c

all: $(NAME) driver

$(NAME): $(OBJS)
	$(ARCHIVE) $@ $^

driver:
	$(CC) $(CFLAGS) -g $(DRIVER) -L. -l:$(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re
