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

void	rev_rotate_a(t_list **stack_a)
{
	t_list	*prev;
	t_list	*last;

	if (!stack_a || !(*stack_a) || !(*stack_a)-> next)
		return ;
	last = *stack_a;
	prev = NULL;
	while (last -> next)
	{
		prev = last;
		last = last -> next;
	}
	prev -> next = NULL;
	last -> next = *stack_a;
	*stack_a = last;
	write (1, "rra\n", 4);
}

void	rev_rotate_b(t_list **stack_b)
{
	t_list	*prev;
	t_list	*last;

	if (!stack_b || !(*stack_b) || !(*stack_b)-> next)
		return ;
	last = *stack_b;
	prev = NULL;
	while (last -> next)
	{
		prev = last;
		last = last -> next;
	}
	prev -> next = NULL;
	last -> next = *stack_b;
	*stack_b = last;
	write (1, "rrb\n", 4);
}

void	rev_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
	write (1, "rrr\n", 4);
}
