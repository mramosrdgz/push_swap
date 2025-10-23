/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:23:22 by mariramo          #+#    #+#             */
/*   Updated: 2025/08/03 10:44:54 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (!stack_a || !(*stack_a) || !(*stack_a)-> next)
		return ;
	first = *stack_a;
	second = first -> next;
	temp = first -> content -> value;
	first -> content -> value = second -> content -> value;
	second -> content -> value = temp;
	write (1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (!stack_b || !(*stack_b) || !(*stack_b)-> next)
		return ;
	first = *stack_b;
	second = first -> next;
	temp = first -> content -> value;
	first -> content -> value = second -> content -> value;
	second -> content -> value = temp;
	write (1, "sb\n", 3);
}

void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	write (1, "ss\n", 3);
}
