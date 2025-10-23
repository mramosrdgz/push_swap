/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:06:25 by mariramo          #+#    #+#             */
/*   Updated: 2025/08/08 18:44:01 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_content
{
	int	value;
	int	sorted_pos;
}	t_content;

typedef struct s_list
{
	t_content		*content;
	struct s_list	*next;
}	t_list;

//ps_list_utils.c
t_list	*create_node(int value);
void	add_node_back(t_list **stack, t_list *new_node);
void	free_stack(t_list **stack);
int		stack_size(t_list *stack);
int		is_sorted(t_list *stack);

//ps_input_utils.c
int		is_valid_number(char *str);
int		atoi_safe(const char *str, int *result);
int		has_duplicates(t_list *stack);
t_list	*load_stack(int argc, char **argv);

//ps_swap.c
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a_b(t_list **stack_a, t_list **stack_b);

//ps_push.c
void	push_a(t_list **swap_b, t_list **swap_a);
void	push_b(t_list **swap_a, t_list **swap_b);

//ps_rotate.c
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_b(t_list **stack_a, t_list **stack_b);

//ps_rev_rotate.c
void	rev_rotate_a(t_list **stack_a);
void	rev_rotate_b(t_list **stack_b);
void	rev_rotate_a_b(t_list **stack_a, t_list **stack_b);

//ps_stack_utils.c
int		get_min_value_pos(t_list *stack);
int		get_max_value_pos(t_list *stack);
int		get_rotate_cost(t_list **stack, int pos);

//ps_array_utils.c
int		*create_array(t_list **stack, int size);
int		*sort_array(int *array, int size);
int		get_value_pos(int *array, int value, int size);
int		load_sorted_positions(t_list **stack, int size);

//ps_sort.c
void	three_sort(t_list **stack);
void	mini_sort(t_list **stack_a, t_list **stack_b, int size);

//ps_k_sort.c
void	k_sort(t_list **stack_a, t_list **stack_b);

#endif
