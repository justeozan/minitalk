SERVER = src/server.c
CLIENT = src/client.c

O_SERVER = ${SERVER:.c=.o}
O_CLIENT = ${CLIENT:.c=.o}

NAME_SERVER = server
NAME_CLIENT = client

CFLAGS = -Werror -Wextra -Wall

all : ${NAME_SERVER} $(NAME_CLIENT)

$(NAME_SERVER): $(O_SERVER)
	@$(CC) $(CFLAGS) -Iinclude -Ilibft $(O_SERVER) -o $(NAME_SERVER) -Llibft -lft

$(NAME_CLIENT): $(O_CLIENT)
	@$(CC) $(CFLAGS) -Iinclude -Ilibft $(O_CLIENT) -o $(NAME_CLIENT) -Llibft -lft

%.o: %.c include/minitalk.h
	@$(CC) $(CFLAGS) -Iinclude -Ilibft -c $< -o $@

clean:
	@$(RM) $(O_SERVER) $(O_CLIENT)

fclean: clean
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: clean fclean re all