BLU = \033[0;34m
GRN = \033[0;32m
RED = \033[0;31m
RST = \033[0m
END = \e[0m

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
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
OBJECTS_PREFIXED_B = $(addprefix $(OBJS_DIR_B), $(OBJS_B))
cc = gcc
CFLAGS = 

$(OBJS_DIR)%.o : %.c includes/push_swap.h
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)srcs
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_DIR_B)%.o : %.c includes/push_swap.h
	mkdir -p $(OBJS_DIR_B)
	mkdir -p $(OBJS_DIR_B)srcs
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	$(CC) -g -o $(NAME) $(OBJECTS_PREFIXED)
$(NAME_B): $(OBJECTS_PREFIXED_B)
	$(CC) -o $(NAME_B) $(OBJECTS_PREFIXED_B)


all : $(NAME)

bonus : $(NAME_B)

clean:
	@rm -f $(OBJ_DIR)
	@rm -f $(OBJ_DIR_B)
	@echo "{GRN}[CLEAN]${RST} done"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@echo "{GRN}[CLEAN]${RST}done"

re: fclean all

.PHONY: all clean fclean re
