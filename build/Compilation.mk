# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Compilation.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 16:18:04 by mbouthai          #+#    #+#              #
#    Updated: 2022/05/06 21:46:17 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef COMPILATION_MK
	COMPILATION_MK = 1

NAME	:= libftprintf.a

CC	:= gcc

CFLAGS	= -Wall -Werror -Wextra

ARCHIVE	:= ar

ARFLAGS	= -rcs

LDFLAGS = 

RM	:= rm -f

RMDIR	:= rmdir

endif
