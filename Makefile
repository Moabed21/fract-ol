NAME = fractol
CC = cc
CFLAGS = #-Wall -Wextra -Werror
PFLAGS = -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRC = potato.c rendering.c mandlebrot.c init.c handlers.c
OBJ = $(SRC:.c=.o)
RM = rm -f
LIBS = ft_printf/libftprintf.a \
	libft/libft.a \
	minilibx-linux/libmlx_Linux.a \
	minilibx-linux/libmlx.a
all	:	$(LIBS) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) $(LIBS) fractol.h
	$(CC) $(CFLAGS) $(PFLAGS) $(SRC) $(LIBS) -o $(NAME)

$(LIBS):
	make -C ft_printf
	make -C libft
	make -C minilibx-linux

clean:
	$(RM) $(OBJ)
	make -C ft_printf clean
	make -C libft clean
	make -C minilibx-linux clean

fclean : clean
	$(RM) $(NAME)
	make -C ft_printf fclean
	make -C libft fclean
	make -C minilibx-linux clean

re: fclean all

.PHONY: all fclean clean re