NAME		= push_swap

PRINTF		= lib/ft_printf/
LIBFT		= lib/libft/
INCLUDES	= includes
SRC_DIR		= src/

SRC			= main.c $(SRC_DIR)validation.c $(SRC_DIR)utils.c $(SRC_DIR)stack.c $(SRC_DIR)free.c \
			  $(SRC_DIR)shift_down.c $(SRC_DIR)swap.c $(SRC_DIR)shift_up.c $(SRC_DIR)push.c \
			  $(SRC_DIR)logic.c
		
OBJ			= $(SRC:%.c=%.o)

LIB_FLAGS	= -L$(LIBFT) -lft -L$(PRINTF) -lftprintf
IFLAG		= -I$(INCLUDES) -I$(LIBFT) -I$(PRINTF)
CFLAG		= -Wall -Wextra -Werror

CC			= cc
AR			= ar rcs
RM			= rm -rf


all:				$(NAME)

.c.o:
					$(CC) $(CFLAG) $(IFLAG) -I/usr/include -O3 -c $< -o $(<:.c=.o)

$(NAME):			$(OBJ)
					make -C $(PRINTF)
					make -C $(LIBFT)
					$(CC) $(CFLAG) $(OBJ) $(LIB_FLAGS) -o $(NAME)

clean:				
					make -C $(PRINTF) clean
					make -C $(LIBFT) clean
					$(RM) $(OBJ)

fclean: 			clean
					make -C $(PRINTF) fclean
					make -C $(LIBFT) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY: 			all mainclean clean fclean re