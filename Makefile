SERVER = src/server.c
CLIENT = src/client.c

O_SERVER = ${SERVER:.c=.o}
O_CLIENT = ${CLIENT:.c=.o}

NAME_SERVER = server
NAME_CLIENT = client

CFLAGS = -Werror -Wextra -Wall

all: ${NAME_SERVER} $(NAME_CLIENT)

$(NAME_SERVER): $(O_SERVER)
	@$(CC) $(CFLAGS) -Iinclude -Ilibft $(O_SERVER) -o $(NAME_SERVER) -Llibft -lft

$(NAME_CLIENT): $(O_CLIENT)
	@$(CC) $(CFLAGS) -Iinclude -Ilibft $(O_CLIENT) -o $(NAME_CLIENT) -Llibft -lft

# BONUS ------------------------------------------------
B_SERVER = src/server_bonus.c
B_CLIENT = src/client_bonus.c

O_B_SERVER = ${B_SERVER:.c=.o}
O_B_CLIENT = ${B_CLIENT:.c=.o}

NAME_SERVER_B = serverb
NAME_CLIENT_B = clientb

bonus: ${NAME_SERVER_B} $(NAME_CLIENT_B)

$(NAME_SERVER_B): $(O_B_SERVER)
	@$(CC) $(CFLAGS) -Iinclude -Ilibft $(O_B_SERVER) -o $(NAME_SERVER_B) -Llibft -lft

$(NAME_CLIENT_B): $(O_B_CLIENT)
	@$(CC) $(CFLAGS) -Iinclude -Ilibft $(O_B_CLIENT) -o $(NAME_CLIENT_B) -Llibft -lft
# FIN-BONUS -------------------------------------------

%.o: %.c include/minitalk.h
	@$(CC) $(CFLAGS) -Iinclude -Ilibft -c $< -o $@

clean:
	@$(RM) $(O_SERVER) $(O_CLIENT) $(O_B_SERVER) $(O_B_CLIENT)

fclean: clean
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_B) $(NAME_CLIENT_B)

re: fclean all

reb: fclean bonus

.PHONY: clean fclean re all