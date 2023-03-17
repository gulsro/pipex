NAME = pipex

SRC = pipex.c \
		utils_pipex.c \
		main.c 

HEADER = pipex.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft

LIBFT = libft.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -O $(NAME) $(OBJ) $(LIBFT_DIR)/$(LIBFT)

%.o: %.c $(HEARDER)
	$(CC) -c $< -o $(<:.c=.o)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all clean fclean re bonus


