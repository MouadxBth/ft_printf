# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 12:57:41 by mbouthai          #+#    #+#              #
#    Updated: 2022/02/20 13:02:01 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libprintf.a

CC		= gcc

ARCHIVE	= ar -rcs

DEPS	= ft_printf.h

CFLAGS	= -Wall -Werror -Wextra -include $(DEPS)

SRCS	= ft_printf.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(ARCHIVE) $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
