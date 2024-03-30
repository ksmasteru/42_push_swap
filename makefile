
M_SRC_FILES = ft_atoi.c ft_parse.c push_swap_utils1.c free_fs.c ft_split.c is_sorted.c moves.c moves1.c operations.c push_swap_utils.c push_swap.c
M_OBJ_FILES = $(M_SRC_FILES:.c=.o)
M_SRC_FILES_BONUS = checker.c get_next_line.c push_swap_utils1.c free_fs.c get_next_line_utils.c moves1.c ft_strjoin.c moves.c get_instruction.c ft_atoi.c ft_parse.c ft_split.c is_sorted.c operations.c push_swap_utils.c
M_OBJ_FILES_BONUS = $(M_SRC_FILES_BONUS:.c=.o)
NAME = push_swap
CFLAGS =
BONUS = checker
all : $(NAME)
bonus : $(BONUS)
$(NAME) : $(M_OBJ_FILES)
	cc $(CFLAGS) $(M_OBJ_FILES) -o push_swap
$(BONUS) : $(M_OBJ_FILES_BONUS)
	cc $(CFLAGS) $(M_OBJ_FILES_BONUS) -o checker
%.o : %.c
	cc $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(M_OBJ_FILES) $(M_OBJ_FILES_BONUS)
fclean : clean
	rm -rf $(NAME) $(BONUS)
re: fclean all
