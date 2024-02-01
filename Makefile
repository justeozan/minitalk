# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 15:05:31 by marvin            #+#    #+#              #
#    Updated: 2024/01/29 15:05:31 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = src/server.c
CLIENT = src/client.c

O_SERVER = ${SERVER:.c=.o}
O_CLIENT = ${CLIENT:.c=.o}

NAME_SERVER = server
NAME_CLIENT = client

all : ${NAME_SERVER} $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	@$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJS_SERVER) -o $(NAME_SERVER) -Llibft -lft

$(NAME_CLIENT): $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJS_CLIENT) -o $(NAME_CLIENT) -Llibft -lft

%.o: %.c include/minitalk.h
	@$(CC) $(CFLAGS) -Iinclude -Ilibft -c $< -o $@

clean:
	@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: clean fclean re all