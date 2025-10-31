/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:31:45 by mariramo          #+#    #+#             */
/*   Updated: 2025/08/04 11:28:17 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rev_rotate_nodes(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)-> next)
		return ;
	last = *stack;
	prev = NULL;
	while (last -> next)
	{
		prev = last;
		last = last -> next;
	}
	prev -> next = NULL;
	last -> next = *stack;
	*stack = last;
}

void	rev_rotate_a(t_list **stack_a)
{
	rev_rotate_nodes(stack_a);
	write (1, "rra\n", 4);
}

void	rev_rotate_b(t_list **stack_b)
{
	rev_rotate_nodes(stack_b);
	write (1, "rrb\n", 4);
}

void	rev_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_nodes(stack_a);
	rev_rotate_nodes(stack_b);
	write (1, "rrr\n", 4);
}
