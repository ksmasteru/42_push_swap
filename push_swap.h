#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define ANSI_COLOR_RED          "\x1b[31m"
typedef struct s_stack{
  int data;
  struct s_stack *next;
  struct s_stack *prev;
}t_stack;

void print_stack(t_stack *head);
t_stack *ft_lst_new(int data);
t_stack *ft_lstadd_back(t_stack *old, int data);
int *pop_stack(t_stack **head);
int push_value(int a, t_stack **head);
void sa(t_stack **stack_a_head);
void sb(t_stack **stack_b_head);
void ra(t_stack **stack_a_head);
void rb(t_stack **stack_b_head);
void rra(t_stack **stack_a_head);
void rrb(t_stack **stack_b_head);
void rrr(t_stack **stack_a_head, t_stack **stack_b_head);
void pa(t_stack **stack_a_head, t_stack **stack_b_head);
void pb(t_stack **stack_a_head, t_stack **stack_b_head);
t_stack *ft_parse(int ac, char **av);
int check_duplicates(int* values, int size);
int check_erros(char *str);
int ft_error(int *values, int index);
void args_4(int len, t_stack **head);
void args_5(int len, t_stack **head);
void args_3(int len, t_stack **head);
void args_2(int len, t_stack **head);
void args(int len, t_stack **head);
void args_s(int len, t_stack **head);
long ft_atoi(char *str);
t_stack *get_tail(t_stack *head);
void arr_to_stack(int *values, int size,  t_stack **head);
int *sort_array(int *array, int size);
int get_max_index(t_stack *head, int *max_value);
int stack_len(t_stack *head);
char ***fill_numbers(int ac, char **av, int *num_len);
void	free_splited(char ***res, int i);
char	**ft_split(char *cmd, char sep);
char	*make_words(char *str, char sep);
int	count_words(char *cmd, char sep);
int   *stack_to_array(t_stack *a_head, int size);
void  free_list(t_stack *a_head, int index);
void free_2d_str(char **str);
#endif