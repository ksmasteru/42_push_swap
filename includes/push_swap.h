/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:37:16 by hes-saqu          #+#    #+#             */
/*   Updated: 2024/04/27 22:37:17 by hes-saqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define ANSI_COLOR_RED "\x1b[31m"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;
int					ft_strlen(char *s1);
void				print_stack(t_stack *head);
t_stack				*ft_lst_new(int data);
t_stack				*ft_lstadd_back(t_stack *old, int data);
int					*pop_stack(t_stack **head);
int					push_value(int a, t_stack **head);
int					sa(t_stack **stack_a_head, int is_checker);
int					sb(t_stack **stack_b_head, int is_checker);
int					ra(t_stack **stack_a_head, int is_checker);
int					rb(t_stack **stack_b_head, int is_checker);
int					rra(t_stack **stack_a_head, int is_checker);
int					rrb(t_stack **stack_b_head, int is_checker);
int					ss(t_stack **stack_a_head, t_stack **stack_b_head,
						int is_checker);
int					rr(t_stack **stack_a_head, t_stack **stack_b_head,
						int is_checker);
int					rrr(t_stack **stack_a_head, t_stack **stack_b_head,
						int is_checker);
int					pa(t_stack **stack_a_head, t_stack **stack_b_head,
						int is_checker);
int					pb(t_stack **stack_a_head, t_stack **stack_b_head,
						int is_checker);
t_stack				*ft_parse(int ac, char **av);
int					check_duplicates(int *values, int size);
int					check_erros(char *str);
int					ft_error(int *values, t_stack *head, int index);
void				print_error(char *str);
void				args_2(t_stack **head);
void				args(int len, t_stack **head, int *values);
void				args_s(int len, t_stack **head, int *values);
long				ft_atoi(char *str);
t_stack				*get_tail(t_stack *head);
void				arr_to_stack(int *values, int size, t_stack **head);
int					*sort_array(int *array, int size);
int					get_max_index(t_stack *head, int *max_value);
int					stack_len(t_stack *head);
char				***fill_numbers(int ac, char **av, int *num_len);
void				free_splited(char ***res, int i);
char				**ft_split(char *cmd, char sep);
char				*make_words(char *str, char sep);
int					count_words(char *cmd, char sep);
int					*stack_to_array(t_stack *a_head, int size);
void				free_list(t_stack *a_head, int index);
void				free_2d_str(char **str);
void				swap_args_5_1(t_stack **head, int len, t_stack **tail,
						t_stack **b_head);
void				empty_stack_a(t_stack **head, t_stack **b_head, int len,
						int *sorted_array);
void				empty_stack_b(t_stack **head, t_stack **b_head, int len);
int					get_end(int len);
void				increment_border(int *len, int *start, int *end);
int					is_sorted(int *values, int len);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, int len);
void				args_3_new(t_stack **head);
int					get_instruction(t_stack **head, t_stack **b_head);
void				args_4_new(int len, t_stack **head);
int					get_min_index(t_stack *head, int *min_value);
void				args_5_new(int len, t_stack **head);
int					apply_instruction(t_stack **head, t_stack **b_head,
						char *line);
void				checker_error_handle(t_stack **head, t_stack **b_head);
int					check_sorted_stack(t_stack *head, int is_checker);
int					write_move(int move, int is_checker);
int					atoi_get_sign(char **str);
#endif