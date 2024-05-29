SRCS		=	ft_printf.c \
				src/ft_printf_c.c \
				src/ft_printf_s.c \
				src/ft_printf_p.c \
				src/ft_printf_d.c \
				src/ft_printf_u.c \
				src/ft_printf_x.c \
				src/ft_printf_x_upper.c
BONUS_SRCS	=	ft_printf_bonus.c \
				src_bonus/ft_printf_c_bonus.c \
				src_bonus/ft_printf_s_bonus.c \
				src_bonus/ft_printf_d_bonus.c \
				src_bonus/ft_printf_u_bonus.c \
				src_bonus/ft_printf_x_bonus.c \
				src_bonus/ft_printf_p_bonus.c \
				src_bonus/ft_printf_utils_bonus.c
OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)
LIBDIR		=	libft
LIB			=	libft.a
NAME		=	libftprintf.a
CC			=	cc
CFLAG		=	-Wall -Wextra -Werror

.DEFAULT_GOAL := all

ifeq ($(filter bonus,$(MAKECMDGOALS)),bonus)
	SRCS = $(BONUS)
	OBJS = $(BONUS_OBJS)
endif

$(NAME): $(OBJS) 
	make -C libft
	cp $(LIBDIR)/$(LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	make fclean -C libft
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

bonus: $(NAME)

.PHONY: all clean fclean re libft_all libft_clean libft_fclean libft_re libft_bonus
