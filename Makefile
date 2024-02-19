# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:35:48 by ozasahin          #+#    #+#              #
#    Updated: 2024/02/19 10:32:35 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL: all

# Executable names
NAME_SERVER =	server
NAME_CLIENT =	client

# Source file paths
SRC_SERVER		=	src/server.c
SRC_CLIENT		=	src/client.c

# Object file paths & names
OBJ_SERVER	=	$(patsubst src/%.c,obj/%.o,$(SRC_SERVER))
OBJ_CLIENT	=	$(patsubst src/%.c,obj/%.o,$(SRC_CLIENT))

# Controls
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:	force $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJ_SERVER) libft/libft.a
		@$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJ_SERVER) -o $(NAME_SERVER) -Llibft -lft

$(NAME_CLIENT):	$(OBJ_CLIENT) libft/libft.a
		@$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJ_CLIENT) -o $(NAME_CLIENT) -Llibft -lft

# BONUS ------------------------------------------------
# Executable names (bonus)
NAME_SERVER_B		=	server_bonus
NAME_CLIENT_B		=	client_bonus

# Source file paths (bonus)
SRC_SERVER_BONUS	=	src/server_bonus.c
SRC_CLIENT_BONUS	=	src/client_bonus.c

# Object file paths & names (bonus)
OBJ_SERVER_BONUS	=	$(patsubst src/%.c,obj/%.o,$(SRC_SERVER_BONUS))
OBJ_CLIENT_BONUS	=	$(patsubst src/%.c,obj/%.o,$(SRC_CLIENT_BONUS))

bonus:	force $(NAME_SERVER_B) $(NAME_CLIENT_B)

$(NAME_SERVER_B):	$(OBJ_SERVER_BONUS) libft/libft.a
		@$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJ_SERVER_BONUS) -o $(NAME_SERVER_B) -Llibft -lft

$(NAME_CLIENT_B):	$(OBJ_CLIENT_BONUS) libft/libft.a
		@$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJ_CLIENT_BONUS) -o $(NAME_CLIENT_B) -Llibft -lft
# END-BONUS -------------------------------------------

obj/%.o:	src/%.c include/minitalk.h libft/libft.h Makefile | obj
		@$(CC) $(CFLAGS) -Iinclude -Ilibft -c $< -o $@

obj:
		mkdir -p obj

clean:
		@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
		@make clean -C libft -s

fclean:		clean
		@$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_B) $(NAME_CLIENT_B)
		@make fclean -C libft -s

force:
		@make -C libft -s

re:			fclean all

reb:		fclean bonus

.PHONY:		all bonus clean fclean force re reb