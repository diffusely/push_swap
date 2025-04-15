NAME		= push_swap

GNL			= lib/get_next_line/
LIBFT		= lib/libft/
INCLUDES	= includes
SRC_DIR		= src/

SRC			= main.c $(SRC_DIR)validation.c
		
OBJ			= $(SRC:%.c=%.o)

LIB_FLAGS	= -L$(GNL) -lgnl -L$(LIBFT) -lft
IFLAG		= -I $(INCLUDES) -I$(LIBFT) -I$(GNL)
CFLAG		= -Wall -Wextra -Werror

CC			= cc
AR			= ar rcs
RM			= rm -rf


all:				$(NAME)

.c.o:
					$(CC) $(CFLAG) $(IFLAG) -I/usr/include -O3 -c $< -o $(<:.c=.o)

$(NAME):			$(OBJ)
					make -C $(LIBFT)
					make -C $(GNL)
					$(CC) $(CFLAG) $(OBJ) $(LIB_FLAGS) -o $(NAME)

clean:				
					make -C $(GNL) clean
					make -C $(LIBFT) clean
					$(RM) $(OBJ)

fclean: 			clean
					make -C $(GNL) fclean
					make -C $(LIBFT) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY: 			all mainclean clean fclean re