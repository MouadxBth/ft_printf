# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Settings.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 16:21:18 by mbouthai          #+#    #+#              #
#    Updated: 2022/05/06 22:00:31 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef SETTINGS_MK
	SETTINGS_MK = 1

INC_DIR	:= inc/

SRC_DIR	:= src/

OBJ_DIR	:= obj/

DEP_DIR	:= dep/

INC_FS	:= ft_printf.h

SRC_FS	:= ft_printf_utils.c ft_handle_char.c \
		ft_handle_str.c ft_handle_nbr.c \
		ft_handle_ptr.c ft_printf.c

INCS	= $(addprefix $(INC_DIR), $(INC_FS))

SRCS	= $(addprefix $(SRC_DIR), $(SRC_FS))

OBJS	= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:%=%.o)))

DEPS	= $(addprefix $(DEP_DIR), $(notdir $(SRCS:%=%.d)))

endif
