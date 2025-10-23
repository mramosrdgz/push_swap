/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:58:31 by mariramo          #+#    #+#             */
/*   Updated: 2025/08/04 10:29:59 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !(*stack_a) || !(*stack_a)-> next)
		return ;
	first = *stack_a;
	*stack_a = first -> next;
	first -> next = NULL;
	last = *stack_a;
	while (last -> next)
		last = last -> next;
	last -> next = first;
	write (1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!stack_b || !(*stack_b) || !(*stack_b)-> next)
		return ;
	first = *stack_b;
	*stack_b = first -> next;
	first -> next = NULL;
	last = *stack_b;
	while (last -> next)
		last = last -> next;
	last -> next = first;
	write (1, "rb\n", 3);
}

void	rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	write (1, "rr\n", 3);
}
