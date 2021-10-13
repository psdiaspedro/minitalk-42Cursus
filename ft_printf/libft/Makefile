NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = ft_itoa.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_itoa_base.c\
		ft_atoi.c\
		ft_isdigit.c\

OBJECTS = $(SRC:.c=.o)

RE = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

