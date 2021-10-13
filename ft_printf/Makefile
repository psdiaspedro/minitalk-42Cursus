NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDE_DIR = -I./include -I./libft/libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

OBJECTS = $(SRC:.c=.o)

SRC = ./src/ft_convert_c.c\
		./src/ft_convert_d_i.c\
		./src/ft_convert_p.c\
		./src/ft_convert_pct.c\
		./src/ft_convert_s.c\
		./src/ft_convert_u.c\
		./src/ft_convert_u.c\
		./src/ft_convert_x.c\
		./src/ft_init.c\
		./src/ft_placeholder.c\
		./src/ft_printf.c\

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
		ar -rcs $(NAME) $(OBJECTS)

.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(LIBFT):
		make -C $(LIBFT_DIR)
		cp $(LIBFT) $(NAME)

clean:
		make clean -C $(LIBFT_DIR)
		$(RM) $(OBJECTS)

fclean: clean
		make fclean -C $(LIBFT_DIR)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
