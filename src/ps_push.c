/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:45:31 by mariramo          #+#    #+#             */
/*   Updated: 2025/08/03 11:12:28 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	if (!stack_b || !(*stack_b))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)-> next;
	temp -> next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_a || !(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)-> next;
	temp -> next = *stack_b;
	*stack_b = temp;
	write (1, "pb\n", 3);
}
