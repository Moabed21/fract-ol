NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC	=	ft_printf.c ft_printhex.c ft_printnbr.c ft_printptr.c \
		ft_printchar.c ft_printstr.c ft_printudecimal.c ft_printshex.c

OBJ = $(SRC:.c=.o)

all	:	$(NAME)

$(NAME) :	$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean	:
	$(RM) $(OBJ)

fclean	: 	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re 