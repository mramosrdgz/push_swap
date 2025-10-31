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

static void	swap_nodes(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (!stack || !(*stack) || !(*stack)-> next)
		return ;
	first = *stack;
	second = first -> next;
	temp = first -> content -> value;
	first -> content -> value = second -> content -> value;
	second -> content -> value = temp;
}

void	swap_a(t_list **stack_a)
{
	swap_nodes(stack_a);
	write (1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	swap_nodes(stack_b);
	write (1, "sb\n", 3);
}

void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	write (1, "ss\n", 3);
}
