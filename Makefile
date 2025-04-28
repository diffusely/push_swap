NAME		= push_swap
BNAME		= checker

PRINTF		= lib/ft_printf/
LIBFT		= lib/libft/
INCLUDES	= includes
SRC_DIR		= src/
BDIR		= bonus/

SRC			= $(SRC_DIR)validation.c $(SRC_DIR)utils.c $(SRC_DIR)stack.c $(SRC_DIR)free.c \
			  $(SRC_DIR)shift_down.c $(SRC_DIR)swap.c $(SRC_DIR)shift_up.c $(SRC_DIR)push.c \
			  $(SRC_DIR)logic.c $(SRC_DIR)sort.c $(SRC_DIR)optimaze.c

BONUS		= main_bonus.c $(BDIR)input_bonus.c

MAIN		= main.c

OBJ			= $(SRC:%.c=%.o)
BOBJ		= $(BONUS:%.c=%.o)
MOBJ		= $(MAIN:%.c=%.o)

LIB_FLAGS	= -L$(LIBFT) -lft -L$(PRINTF) -lftprintf
IFLAG		= -I$(INCLUDES) -I$(LIBFT) -I$(PRINTF)
CFLAG		= -Wall -Wextra -Werror

CC			= cc
AR			= ar rcs
RM			= rm -rf


all:				$(NAME)

.c.o:
					$(CC) -c $(CFLAG) $(IFLAG) -I/usr/include -O3 -c $< -o $(<:.c=.o)

$(NAME):			$(OBJ) $(MOBJ)
					make -C $(PRINTF)
					make -C $(LIBFT)
					$(CC) $(CFLAG) $(OBJ) $(MOBJ) $(LIB_FLAGS) -o $(NAME)

bonus:				$(OBJ) $(BOBJ)
					make -C $(PRINTF)
					make -C $(LIBFT)
					$(CC) $(CFLAG) $(OBJ) $(BOBJ) $(LIB_FLAGS) -o $(BNAME)

clean:				
					make -C $(PRINTF) clean
					make -C $(LIBFT) clean
					$(RM) $(OBJ) $(BOBJ) $(MOBJ)

fclean: 			clean
					make -C $(PRINTF) fclean
					make -C $(LIBFT) fclean
					$(RM) $(NAME) $(BNAME) 

re:					fclean all

.PHONY: 			all bonus mainclean clean fclean re