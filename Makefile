NAME = minitalk
CLIENT = client
SERVER = server

CC = clang
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRC_SERVER =	./sources/server.c
SRC_CLIENT =	./sources/client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(FT_PRINTF) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(FT_PRINTF) -o $(CLIENT)

#bonus: all

clean:
	$(RM) $(OBJ_CLIENT)
	$(RM) $(OBJ_SERVER)

fclean: clean
	$(RM) $(CLIENT)
	$(RM) $(SERVER)
	cd $(FT_PRINTF_DIR) && make fclean

re: fclean all

.PHONY: clean fclean all re bonus
