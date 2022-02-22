NAME = libftprintf.a
LIBFT_DIR = ./libft/
HEADER = printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c ft_parse.c ft_print_type.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_O = $(SOURCES_BONUS:.c=.o)

D_FILES = $(patsubst %.c, %.d, $(SOURCES) $(SOURCES_BONUS))

all: libft $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $? $(LIBFT_DIR)*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -MMD

include $(wildcard *.d)

libft:
	@make -C $(LIBFT_DIR)
clean:
	@rm -f *.o *.d
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all libft clean fclean re
