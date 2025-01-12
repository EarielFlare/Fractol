# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 21:14:39 by cgregory          #+#    #+#              #
#    Updated: 2022/03/13 21:03:04 by cgregory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol
NAME_BONUS		=	./src_bonus/fractol_bonus
SRCS_DIR		=	./src_main/
SRCS_DIR_BONUS	=	./src_bonus/
SRCS			=	main.c			messages.c\
					aux_funcs.c		hooks.c\
					draw_funcs.c	color.c\
					init.c			libft.c
SRCS_BONUS		=	main.c			messages.c\
					aux_funcs.c		hooks.c\
					draw_funcs.c	color.c\
					init.c			fractol_funcs.c\
					libft.c
FRACTOL_H		=	fractol.h
BONUS_H			=	fractol_bonus.h
HEADERS			=	./inc/
OBJ				=	$(addprefix $(SRCS_DIR), $(SRCS:%.c=%.o))
OBJ_BONUS		=	$(addprefix $(SRCS_DIR_BONUS), $(SRCS_BONUS:%.c=%.o))
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
.PHONY			:	all clean fclean re bonus
all				:	$(NAME)
bonus			:	$(NAME_BONUS)
$(NAME)			:	$(OBJ) $(HEADERS)$(FRACTOL_H)
					@$(RM) $(OBJ_BONUS)
					@$(CC) $(OBJ)\
					-L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)
					@echo "$(BLUE)$(NAME) created!$(DEFAULT)"
$(NAME_BONUS)	:	$(OBJ_BONUS) $(HEADERS)$(BONUS_H)
					@$(RM) $(OBJ)
					@$(CC) $(OBJ_BONUS)\
					-L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)
					@touch $(NAME_BONUS)
					@echo "$(BLUE)$(NAME) (bonus) created!$(DEFAULT)"
%.o:				%.c $(HEADERS)$(FRACTOL_H) $(HEADERS)$(BONUS_H)
					@$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@
clean			:	
					@$(RM) $(OBJ)
					@$(RM) $(OBJ_BONUS)
					@echo "$(YELLOW)object files deleted!$(DEFAULT)"
fclean			:	clean
					@$(RM) $(NAME)
					@$(RM) $(NAME_BONUS)
					@echo "$(RED)all files deleted!$(DEFAULT)"
re				:	fclean all

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
DEFAULT = \033[0m
