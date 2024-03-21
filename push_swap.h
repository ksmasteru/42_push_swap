#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_stack{
  int data;
  struct s_stack *next;
  struct s_stack *prev;
}t_stack;

void print_stack(t_stack *head);
t_stack *ft_lst_new(int data);
t_stack *ft_lstadd_back(t_stack *old);
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
int *ft_parse(int ac, char **av);
int check_duplicates(int* values, int size);
int check_erros(char *str);
int ft_error(int *values, int index);
int *args_4(int ac, int *values);
int *args_5(int ac, int *values);
int *args_3(int ac, int *values);
int *args_2(int ac, int *values);
int *args(int ac, int *values);
int *args_s(int ac, int *values);
int ft_atoi(char *str);
t_stack *get_tail(t_stack *head);
void arr_to_stack(int *values, int size,  t_stack **head);
int *sort_array(int *array, int size);
#endif