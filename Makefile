SRCS	=	ft_printf.c src/ft_printf_c.c src/ft_printf_s.c src/ft_printf_p.c src/ft_printf_d.c src/ft_printf_u.c src/ft_printf_x.c src/ft_printf_x_upper.c
OBJS	=	$(SRCS:.c=.o)
LIBDIR	=	libft
LIB		=	libft.a
NAME	=	libftprintf.a
CC		=	cc
CFLAG	=	-Wall -Wextra -Werror

.DEFAULT_GOAL := all

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBDIR)/$(LIB)

%.o: %.c $(LIBDIR)/$(LIB)
	$(CC) $(CFLAG) -c $< -o $@

clean: libft_clean
	rm -f $(OBJS)

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all

all: libft_all $(NAME)

$(LIBDIR)/$(LIB):
	make -C $(LIBDIR) all

libft_all: $(LIBDIR)/$(LIB)

libft_clean:
	make -C $(LIBDIR) clean

libft_fclean:
	make -C $(LIBDIR) fclean

libft_re:
	make -C $(LIBDIR) re

libft_bonus:
	make -C $(LIBDIR) bonus

.PHONY: all clean fclean re libft_all libft_clean libft_fclean libft_re libft_bonus
