NAME = mlx

CFLAGS = -Wall -Wextra -Werror

INCLUDES = .

SRCS = main.c

OBJ = $(SRCS:.c=.o)

LIBFTDIR = libft/

all: $(NAME)

$(NAME) : $(LIBFTDIR)libftprintf.a $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o  $(NAME) -L./$(LIBFTDIR) -lftprintf -lmlx -framework OpenGL -framework AppKit

%.o: %.c 
	gcc $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

$(LIBFTDIR)libftprintf.a: libft/Makefile
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTDIR)libftprintf.a

re: fclean all
