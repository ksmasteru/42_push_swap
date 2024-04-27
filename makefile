SRCS = srcs/ft_parse.c \
	srcs/push_swap_utils1.c \
	srcs/free_fs.c \
	srcs/ft_split.c \
	srcs/is_sorted.c \
	srcs/moves.c \
	srcs/moves1.c \
	srcs/operations.c \
	srcs/operations1.c \
	srcs/push_swap_utils.c \
	srcs/push_swap.c

SRCS_BONUS = srcs_bonus/checker.c \
	      srcs_bonus/get_next_line.c \
	      srcs_bonus/push_swap_utils1.c \
	      srcs_bonus/free_fs.c \
	      srcs_bonus/get_next_line_utils.c \
	      srcs_bonus/moves1.c \
	      srcs_bonus/ft_strjoin.c \
	      srcs_bonus/moves.c \
	      srcs_bonus/ft_parse.c \
	      srcs_bonus/ft_split.c \
	      srcs_bonus/is_sorted.c \
	      srcs_bonus/operations.c \
	      srcs_bonus/operations1.c \
	      srcs_bonus/push_swap_utils.c

NAME = push_swap
NAME_B = checker
OBJS_DIR = objs/
OBJS_DIR_B = objs_b/
OBJ = $(SRCS:.c=.o)
OBJS_B = $(SRCS_BONUS:.c=.o)
cc = gcc
CFLAGS = -Wall -Werror -Wextra

%.o : %.c
	$(cc) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(cc) -o $(NAME) $(OBJ)
$(NAME_B): $(OBJS_B)
	$(cc) -o $(NAME_B) $(OBJS_B)
all : $(NAME)

bonus : $(NAME_B)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJS_B)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)

re: fclean all

.PHONY: all clean fclean re
