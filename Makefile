NAME = pipex

SRC = pipex.c \
		utils_pipex.c \
	       error_functions.c \
	       main.c

HEADER = pipex.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft

LIBFT = libft.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_DIR)/$(LIBFT)

%.o: %.c $(HEARDER)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all clean fclean re bonus


