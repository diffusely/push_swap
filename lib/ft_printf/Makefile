NAME		=	libftprintf.a 

INCLUDES	=	../../includes

LIBFT		= 	../libft/

SDIR		=	src/

ODIR		=	obj/

CC			=	cc

SRC			=	$(SDIR)ft_find_type.c $(SDIR)ft_printf.c $(SDIR)ft_putstr.c \
				$(SDIR)ft_putnbr.c $(SDIR)ft_check_flags.c

CFLAG		=	-Wall -Wextra -Werror -I$(INCLUDES)

OBJ         =	$(SRC:$(SDIR)%.c=$(ODIR)%.o)

RM			=	rm -rf

AR			=	ar rcs

all:				$(NAME)

$(ODIR)%.o:			$(SDIR)%.c
					mkdir -p $(ODIR)
					$(CC) $(CFLAG) -c $< -o $@

$(NAME):			$(OBJ)
					make -C $(LIBFT)
					mv $(LIBFT)libft.a ../ft_printf/$(NAME)
					$(AR) $(NAME) $^
clean:
					$(RM) $(OBJ) $(ODIR)

fclean: 			clean
					$(RM) $(NAME)

re:					fclean all

.PHONY: 			all clean fclean re bonus