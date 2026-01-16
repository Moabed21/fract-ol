NAME    = fractol
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -O3
INCLUDES = -Imlx_linux
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11
SRC     = potato.c rendering.c equations.c handlers.c
OBJ     = $(SRC:.c=.o)
RM      = rm -f
LIBS    = libft/libft.a minilibx-linux/libmlx_Linux.a
all: $(LIBS) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(LIBS):
	make -C libft
	make -C minilibx-linux

clean:
	$(RM) $(OBJ)
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean
	make -C minilibx-linux clean

re: fclean all

.PHONY: all fclean clean re