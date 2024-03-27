
M_SRC_FILES = ft_atoi.c ft_parse.c ft_split.c is_sorted.c moves.c operations.c push_swap_utils.c push_swap.c
M_OBJ_FILES = $(M_SRC_FILES:.c=.o)
M_SRC_FILES_BONUS = get_next_line.c get_next_line_utils.c ft_strjoin.c get_instruction.c ft_atoi.c ft_parse.c ft_split.c is_sorted.c moves.c operations.c push_swap_utils.c
M_OBJ_FILES_BONUS = $(M_SRC_FILES_BONUS:.c=.o)
NAME = push_swap
BONUS = checker
all : $(NAME)
bonus : $(BONUS)
$(NAME) : $(M_OBJ_FILES)
$(BONUS) : $(M_OBJ_FILES_BONUS)
%.o : %.c
	cc -c $< -o $@
clean:
	rm -rf $(M_OBJ_FILES) $(M_OBJ_FILES_BONUS)
fclean : clean
	rm -rf $(NAME) $(BONUS)
re: fclean all
