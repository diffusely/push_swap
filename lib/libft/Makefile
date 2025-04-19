NAME		=	libft.a

INCLUDES	=	../../includes

SDIR		=	src/

ODIR		=	obj/

MFILES		= 	$(SDIR)ft_isalpha.c $(SDIR)ft_isdigit.c $(SDIR)ft_isalnum.c $(SDIR)ft_isascii.c \
				$(SDIR)ft_isprint.c $(SDIR)ft_strlen.c $(SDIR)ft_memset.c \
	  			$(SDIR)ft_bzero.c $(SDIR)ft_memcpy.c $(SDIR)ft_memmove.c $(SDIR)ft_strlcpy.c \
				$(SDIR)ft_strlcat.c $(SDIR)ft_toupper.c $(SDIR)ft_tolower.c \
	  			$(SDIR)ft_strchr.c $(SDIR)ft_strrchr.c $(SDIR)ft_strncmp.c $(SDIR)ft_memchr.c \
				$(SDIR)ft_memcmp.c $(SDIR)ft_strnstr.c $(SDIR)ft_atoi.c \
	  			$(SDIR)ft_calloc.c $(SDIR)ft_strdup.c $(SDIR)ft_substr.c $(SDIR)ft_strjoin.c \
				$(SDIR)ft_strtrim.c $(SDIR)ft_split.c $(SDIR)ft_itoa.c $(SDIR)ft_strmapi.c \
	  			$(SDIR)ft_striteri.c $(SDIR)ft_putchar_fd.c $(SDIR)ft_putstr_fd.c $(SDIR)ft_putendl_fd.c \
				$(SDIR)ft_putnbr_fd.c $(SDIR)get_next_line_utils.c $(SDIR)get_next_line.c

BFILES 		= 	$(SDIR)ft_lstnew_bonus.c $(SDIR)ft_lstadd_front_bonus.c $(SDIR)ft_lstsize_bonus.c \
				$(SDIR)ft_lstlast_bonus.c $(SDIR)ft_lstadd_back_bonus.c $(SDIR)ft_lstdelone_bonus.c \
				$(SDIR)ft_lstclear_bonus.c $(SDIR)ft_lstiter_bonus.c $(SDIR)ft_lstmap_bonus.c

MOBJ 		= 	$(MFILES:$(SDIR)%.c=$(ODIR)%.o)

BOBJ 		=	$(BFILES:$(SDIR)%.c=$(ODIR)%.o)

CC			=	cc

CFLAG		=	-Wall -Wextra -Werror -I$(INCLUDES)

RM			=	rm -rf

AR			=	ar rcs

all: 			$(NAME)

bonus:			$(BOBJ)
				$(AR) $(NAME) $^

$(ODIR)%.o:		$(SDIR)%.c
				mkdir -p $(ODIR)
				$(CC) $(CFLAG) -c $< -o $@

$(NAME):		$(MOBJ) $(BOBJ)
				$(AR) $(NAME) $^

clean:
				$(RM) $(MOBJ) $(BOBJ) $(ODIR)

fclean: 		clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: 	all clean fclean re bonus