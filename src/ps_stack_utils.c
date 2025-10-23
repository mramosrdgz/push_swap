/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:07:00 by mariramo          #+#    #+#             */
/*   Updated: 2025/08/07 12:40:27 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_min_value_pos(t_list *stack)
{
	int	min;
	int	pos;
	int	min_pos;

	if (!stack)
		return (-1);
	min = stack -> content -> value;
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack -> content -> value < min)
		{
			min = stack -> content -> value;
			min_pos = pos;
		}
		stack = stack -> next;
		pos++;
	}
	return (min_pos);
}

int	get_max_value_pos(t_list *stack)
{
	int	max;
	int	pos;
	int	max_pos;

	if (!stack)
		return (-1);
	max = stack -> content -> value;
	max_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack -> content -> value > max)
		{
			max = stack -> content -> value;
			max_pos = pos;
		}
		stack = stack -> next;
		pos++;
	}
	return (max_pos);
}

int	get_rotate_cost(t_list **stack, int pos)
{
	int	size;

	size = stack_size(*stack);
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}
